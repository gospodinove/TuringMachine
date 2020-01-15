//
// Created by Emanuil Gospodinov on 20.11.19.
//

#include "../tapeCell.h"

TapeCell::TapeCell() {
    data = ' ';
    next = nullptr;
    prev = nullptr;
}
TapeCell::TapeCell(TapeCell const &other) {
    data = other.data;
    next = other.next;
    prev = other.prev;
}
TapeCell& TapeCell::operator=(TapeCell const &other) {
    if (this != &other)
    {
        data = other.data;
        next = other.next;
        prev = other.prev;
    }
    return *this;
}
TapeCell::~TapeCell() {
    next = nullptr;
    prev = nullptr;
};

char TapeCell::getData() {
    return data;
}

void TapeCell::setData(char data) {
    this->data = data;
}