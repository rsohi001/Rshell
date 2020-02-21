#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

#include "Src.hpp"

void testCommand(std::string);

int main() {
    testCommand("ls -a");


    return 0;
}


void testCommand(std::string s) {
    //Command testCommand("  echo    \" henlo woldro #yolo  \""); //does not work, need to remove quotes from args
    Command testCommand(s); //works!
    //Command testCommand("ls \"-a\""); //does not work, need to remove quotes from args
    // Command testCommand("test -e cmake_install.cmake");

    testCommand.parse();
    testCommand.list();
    testCommand.execute(true);
}

//basic structure of how an execvp can work, keep for example later
/*std::string a0 = "echo";
std::string a1 = "$PATH";
char* argv[3];//two args, plus NULL at end
argv[0] = const_cast<char*>(a0.c_str());
argv[1] = const_cast<char*>(a1.c_str());
argv[2] = NULL;
execvp(argv[0], argv);*/
