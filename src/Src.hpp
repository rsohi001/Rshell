#ifndef _SRC_HPP_
#define _SRC_HPP_

#include <vector>
#include <string>

class Base {
protected:
    std::string input;
public:
    virtual void parse() = 0;
        //Group will take input and parse that into strings of commands and connectors
        //Command will take parsed and set that as its argv values so that execution is easier
    virtual bool execute(bool) = 0;
        //Group executes each of its children
        //connector executes its child (based on requirements)

    virtual std::string print() = 0;
        //command executes itself
        //Group returns open '(', calls print on all children, prints close ')'
        //Connector prints itself then its child
        //Command prints itself

    void setInput(std::string s);// { this->input = s; }
    std::string getInput();// { return this-> input; }
};

class Command : public Base {
protected:
    std::vector<std::string> arr;
public:
    Command(std::string s);
        //populates this->input with value in s
    void parse();
        // takes this->input and populates this->arr with string fragments for execution
    bool execute(bool succ);
        // executes with execvp()
    std::string print();
        // returns this->input
    int size() const;
        //returns this->arr.size();
    void list();
        // uses cout to list out this->arr
};

class Connector : public Base {
protected:
    int type;
        //1 for &&
        //0 for ;
        //-1 for ||
    Base* child = 0;
public:
    Connector(std::string s);
        //populates this->input with value in s, then this->type with corresponding int
    void parse();
        //executes on this->child->parse() if it exists
    bool execute(bool succ);
        //this->child->execute() based on type and passed in bool
        //type 1 executes if succ is true
        //type 0 executes regardless
        //type -1 executes if succ is false
    std::string print();
        //returns connector text corresponding to type with child text appended
    void setChild(Base* b);
        //sets this->child to b
};

class Group : public Base {
protected:
    std::vector<std::string> parsed;
    std::vector<Base*> children;
    bool success = false;
    // helpers
    void splitter();
        // takes this->input and populates this->parsed
    void structure();
        // takes this->parsed and populates this->children
public:
    Group(std::string s);
        //populates this->input with value in s
    void parse();
        // calls this->splitter(), this->structure(), then parse on children
        // to parse recursively
    bool execute();
        // calls execute on children iteratively
        // may need to fix to use fork()
        // returns this->success;
    std::string print();
        // if !this->parsed return "(UNPARSED: {this->input})"
        // else return concatination of this->children within parentheses
    void setParsed(std::vector<std::string>);
        // for testing purposes
    Base* at(int i);
        // check i against this->children.size();
        // returns this->children.at(i)
    int size() const;
        // returns the size of this->children
    void list();
        // uses cout to list out this->parsed
};

#endif
