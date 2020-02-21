#include <iostream>
#include <string>
#include "Src.hpp"

Connector::Connector(std::string in) {
    this->input = in;
    if(this->input == "&&") {
        this->type = 1;
    } else if(this->input == ";") {
        this->type = 0;
    } else if(this->input == "||") {
        this->type = -1;
    } else {
        std::cout << "ERROR: CONSTRUCTING CONNECTOR WITH INVALID INPUT: " << in << std::endl;
    }
}

void Connector::parse() {
    if(!this->child) {
        std::cout << "ERROR: PARSING CONNECTOR WITH NO CHILD" << std::endl;
    } else {
        this->child->parse();
    }
}

bool Connector::execute(bool succ) {
    //fixme: do logic here to decide if child should execute
    return this->child->execute(succ);
}

std::string Connector::print() {
    if(!this->child) {
        std::cout << "ERROR: PRINTING CONNECTOR WITH NO CHILD" << std::endl;
        return "";
    } else {
        return (this->input + " " + this->child->print());
    }
}

void Connector::setChild(Base* b) {
    if(this->child) {
        std::cout << "WARNING: REPLACING CHILD FOR ALREADY SET CONNECTOR" << std::endl;
        delete[] this->child;
        this->child = b;
    } else {
        this->child = b;
    }
}
