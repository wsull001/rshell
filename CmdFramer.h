#ifndef _CMDFRAMER_H
#define _CMDFRAMER_H
#include <iostream>
#include <vector>
#include "Command.h"
#include <sstream>
using namespace std;

class Cmd_Framer {
    public: 
        //creates a command to be executed
        Cmd_Framer() {};
        Command* frame(istringstream& linein) {
            string temp;
            vector<string> v;
            bool hasAllArgs = false;
            bool hasNext = false;
            bool parenCommand = false;
            bool fistItr = true;
            while (!hasAllArgs) {
                
                bool tester = (linein >> temp);
                //deal with quotations
                if (tester && temp.at(0) == '"') {
                    bool keepParsing = true;
                    for (unsigned i = 1; i < temp.size(); i++) {
                        if (temp.at(i) == '"') keepParsing = false;
                    }
                    while (keepParsing) {
                        string tempStr;
                        tester = (linein >> tempStr);
                        while (!tester) {
                            temp = temp + "\n";
                            string newLine;
                            cout << "> ";
                            getline(cin, newLine);
                            linein.str(newLine);
                            linein.clear();
                            tester = linein >> tempStr;
                        }
                        if (temp.at(temp.size() - 1) != '\n')
                            temp = temp + " " + tempStr;
                        else
                            temp = temp + tempStr;
                        for (unsigned i = 0; i < tempStr.size(); i++) {
                            if (tempStr.at(i) == '"') {
                                keepParsing = false;
                            }
                        }
                    }
                    temp = temp.substr(1, temp.size() - 1);
                    int t = temp.find('"');
                    temp.erase(t, 1);
                }
                //deal with command line comments
                else if (tester) {
                    for (unsigned i = 0; i < temp.size(); i++) {
                        if (temp.at(i) == '#') {
                            temp = temp.substr(0, i);
                            string l;
                            while (linein >> l);
                            break;
                        }
                    }
                    if (temp.size() == 0) tester = false;
                }
                
                //check to see if reached the end of line
                if (!tester) {
                    hasAllArgs = true;
                
                }
                else if (temp.compare("&&") == 0 || temp.compare("||") == 0) {
                    hasAllArgs = true;
                }
                else if (temp.at(temp.size() - 1) == ';') {
                    hasAllArgs = true;
                    hasNext = true;
                    temp = temp.substr(0, temp.size() - 1);
                    v.push_back(temp);
                }
                else {
                    v.push_back(temp);
                }
            }
            
            //if no arguments then no command so return null pointer
            if (v.size() == 0) {
                return NULL;
            }
            
            //create the command object
            
            char* cmd = (char*)v.at(0).c_str();
            char** args = new char*[v.size()];
            for (unsigned i = 0; i < v.size(); i++) {
                args[i] = (char*)v.at(i).c_str();
            }
            Command* command = new Command(cmd, args, v.size());
            
            //now add next, success, and failure commands
            if (hasNext) {
                command->addNext(this->frame(linein));
            }
            else if (temp.compare("&&") == 0) {
                command->addSuccess(this->frame(linein));
            }
            else if (temp.compare("||") == 0) {
                command->addFailure(this->frame(linein));
            }
            
            
            //return the framed command
            return command;
        };
        
};
#endif
