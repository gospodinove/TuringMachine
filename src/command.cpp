//
// Created by Emanuil Gospodinov on 20.11.19.
//

#include <iostream>
#include "../command.h"

Command::Command() {

}
Command::Command(Command const &other) {
    cmd = other.cmd;
}
Command& Command::operator=(Command const &other) {
    if (this != &other) {
        cmd = other.cmd;
    }
    return *this;
}
Command::~Command(){

}

Command::Command(char cmd) {
    setCommand(cmd);
}

bool Command::setCommand(char cmd) {
    if (isValidCommand(cmd)) {
        this->cmd = cmd;
        return true;
    } else {
        return false;
    }
}
char Command::getCommand() {
    return cmd;
}

bool Command::isValidCommand(char cmd) {
    return cmd == 'R' || cmd == 'L' || cmd == 'S';
}