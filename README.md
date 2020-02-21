# CS 100 Programming Project
## Year: Fall 2019   
### Rahul Sohi  
SID: 862077577   
Email: rsohi001@ucr.edu   

### Alex Zamora   
SID: 862099131    
Email: azamo021@ucr.edu

# Introduction:
Our project will be able to work as a basic command shell. That will be able to run command prompts by taking in user input, reading in said input, parse the given input into a command, arguements, and connectors. After this we will be using the commands and arguments to execute what the user has inputted. As depicted in Assignment 2 said shell will be named rshell, and it will be programmed using C++ programming language. In addition the project will make use of commands _fork_, _execvp_, and _waitpid_.

# Diagram:
![First OMT Diagram](/images/OMT-0-00-01.png)
Format: ![Alt Text](url)

# Classes:

_Note: we opted to not use any standard design patterns we have learned, as they do not seem to fit the somewhat less "deep" (as far as the structure of a possible input_

1. **Line** - This class will be the point of contact between the user and the program. Line has a private string `input` which is the input from the user before parsing, and `commands` which is a vector of `command`s after parsing. The main functionality of the class is to parse `lines` of input into viable `command`s that our program can use `execute()` on. `execute()` within this class calls `execute()`  for each `command` in `commands`. 

1. **Command** - This class inherits the Base class. This class will hold arguments which is a vector of strings in the order they were input. Past that the function will use `execute` after pulling in data from the **Line** class which will be parsed. This will take in the command and arguments and then process the code. This will work in tandem with **Connector** to ensure that connectors will run commands in the order specified by the given connectors.

1. **Connector** - This class works as a processor for connectors. **Connector** inherits the **Base** class as it connects commands together it will be used to allowed commands to be executed in the defined way of the user. **Connector** has an execute function that is used with it's private variable connector which should be " && ", " || ", or ";". What our `execute` function strives to do is to get a connector and then execute whatever is to the left and right using the specification of the given connector.

1. **Base** - This class is the base for what **Command** and **Connector** inherit. Simply this function has a private member of name, and a getter and setter for the name. Past that there is an execute function that we will use in both **Connector** and **Command** classes. We made `execute` pure virtual function to ensure that only **Command** and **Connector** will be using this function.

# Prototypes/Research
* Learned basics of [waitpid()](https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.1.0/com.ibm.zos.v2r1.bpxbd00/rtwaip.htm) (link provided).
* Learned basics of [execvp()](https://support.sas.com/documentation/onlinedoc/sasc/doc/lr2/execvp.htm) (link provided).
* Learned basics of [fork()](https://www.geeksforgeeks.org/fork-system-call/) (link provided).

# Development and Testing Roadmap:
Tasks for Rahul:
* Continually update the README.md file
* Proofread code and write basic functions in a local program
* Help Alex with testing code
* Fix potential errors with classes when they come up
* Place issues into GitHub

Tasks for Alex:
* Develop testers
* Build unit tests
* Ensure proper appllication of methods and following our OMT diagram
* Help Rahul with local coding
* Proofread testers and code that was written in local programs.
