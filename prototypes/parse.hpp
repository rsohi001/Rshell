#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>


class Parse() {
    public:
        Parse() {}

        ParseFunction(){
            string userStringArray;
            string userInput;

            cout << "$";
            cin >> userStringArray;
            int i = 0;

            istringstream ISS(userStringArray);

            string input;

            while(getline(ISS, input, " ")) {
                userInput = stoi(input, nullptr, 10);
                i++
                cout << userInput << endl;
                cout << "Number of commands: " << i;
            }
        }
}
