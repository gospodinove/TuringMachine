//
// Created by Emanuil Gospodinov on 20.11.19.
//

#ifndef TURING_MACHINE_COMMAND_H
#define TURING_MACHINE_COMMAND_H

class Command {
    char cmd;

    bool isValidCommand(char cmd);
public:
    Command();
    Command(Command const &other);
    Command& operator=(Command const &other);
    ~Command();

    Command(char cmd);

    // return true if command is set successfully
    bool setCommand(char cmd);
    char getCommand();
};
#endif //TURING_MACHINE_COMMAND_H
