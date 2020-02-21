#include <unistd.h>
#include <iostream>
#include <string>

#include "Src.hpp"

Command::Command(std::string in) {
    if(in == "") std::cout << "WARNING: CONSTRUCTING COMMAND AS BLANK" << std::endl;
    if(this->input != "") std::cout << "WARNING: REPLACING INPUT OF COMMAND. WAS \""
                                    << this->input << "\" SETTING TO \"" << in << std::endl;
    this->input = in;
}

void Command::parse() {
    std::cout << "Parsing: " << this->input << std::endl;
    //Fixme: add function here
    std::string copy = this->input;
    //algorithm deletes while parsing, so keep copy around to replace

    std::vector<std::string> vect;
    for(int i = 0; i < this->input.size(); i++){
        if(this->input.size() > 0){
            if(this->input.at(0) == ' '){
                // std::cout << "DELETING WHITE SPACE" << std::endl;
                this->input.erase(this->input.begin());
                i = 0;
            }

        }

        if(this->input.size() > 0){
            if(this->input.at(0) == '\"'){
                std::string parenstr;// = this->input.substr(0,1); quotes not needed
                int stop = 0;
                int flag = false;
                for(int k = 0; k < this->input.size()-1; k++){
                    if(this->input.at(k+1) != '\"'){
                        parenstr = parenstr + this->input.substr(k+1, 1);
                    }
                    if(this->input.at(k+1) == '\"'){
                        flag = true;
                        break;
                    }
                    stop++;
                }
                // if(flag) //no quotes in final product
                //     parenstr = parenstr + "\"";
                vect.push_back(parenstr);
                this->input.erase(0, stop + 3);
            }
        }

        if(this->input.size() > 0){
            if((this->input.at(0) != ' ') && (this->input.at(0) != '\"')){
                // std::cout << "FOUND CHAR" << std::endl;
                std::string charstring = this->input.substr(0,1);
                int stop = 0;
                for(int k = 0; k < this->input.size()-1; k++){
                    if(this->input.at(k+1) != ' '){
                        charstring = charstring + this->input.substr(k+1, 1);
                    } else{
                        break;
                    }
                    stop++;
                }
                // std::cout << "EXITED LOOP" << std::endl;
                this->input.erase(0, stop+1);
                // std::cout << charstring.size() << std::endl;
                vect.push_back(charstring);
                i = 0;
            }
        }
    }

    /*for(int j = 0; j < vect.size(); j++){
        std::cout << vect.at(j) << std::endl;
    }*/
    std::cout << "Done parsing" << std::endl;
    this->arr = vect;
    this->input = copy;
}

bool Command::execute(bool succ) {
    std::cout << "Executing(" << succ <<  "): " << this->print() << std::endl;
    char* argv[this->arr.size()+1];
        for (int i = 0; i < arr.size(); i++) {
            argv[i] = const_cast<char*>(arr.at(i).c_str());
        }
        argv[arr.size()] = NULL;
        execvp(argv[0], argv);
        return true;
}

std::string Command::print() {
    if(!this->size() && this->input != "") { //has input, not parsed
        return ("{UNPARSED COMMAND: " + this->input + "}");

    } else if(this->size() == 1) { //has parsed, only one item
        return this->arr.at(0);

    } else if(this->size() > 1) { //has parsed, multiple items
        std::string out;
        out += this->arr.at(0);
        for(int i = 1; i < this->arr.size(); i++) {
            out += (" " + this->arr.at(i));
        }
        return out;

    } else { //does not have input or parsed
        std::cout << "ERROR: PRINTING COMMAND THAT HAS NO INPUT" << std::endl;
        return "";
    }
}

int Command::size() const {
    return this->arr.size();
}

void Command::list() {
    std::cout << "Listing command:" << std::endl;
    if(this->arr.size() == 0) std::cout << "WARNING: CALLING LIST ON COMMAND WITH EMPTY ARR" << std::endl;
    for(int i = 0; i < this->arr.size(); i++) {
        std::cout << "{" << this->arr.at(i) << "}" << std::endl;
    }
    std::cout << "End listing command." << std::endl;
}
