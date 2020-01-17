//
// Created by Emanuil Gospodinov on 20.11.19.
//

#include "../tape.h"

Tape::Tape() {
    head = nullptr;
    append(' ');
    current = head;
}
Tape::Tape(Tape const &other) {
    head = other.head;
    alphabet = other.alphabet;
    current = other.current;
}
Tape::Tape(const Alphabet& alphabet) {
    this->alphabet = alphabet;

    head = nullptr;
    append(' ');
    current = head;
}
Tape::Tape(const Alphabet &alphabet, const std::vector<char> &content) {
    this->alphabet = alphabet;

    head = nullptr;

    for (char letter : content) {
        append(letter);
    }

    current = head;
}
Tape& Tape::operator=(Tape const &other) {
    if (this != &other) {
        alphabet = other.alphabet;
        head = other.head;
        current = other.current;
    }
    return *this;
}
Tape::~Tape() {
    current = nullptr;
    while (head != nullptr) {
        TapeCell *move = head;
        head->prev = nullptr;
        head = head->next;
        move = nullptr;
    }
}

void Tape::destroy() {
    current = nullptr;
    while (head != nullptr) {
        TapeCell *move = head;
        head->prev = nullptr;
        head = head->next;
        delete move;
    }
}

void Tape::append(char data) {
    if (!alphabet.hasLetter(data)) {
        return;
    }

    auto* newNode = new TapeCell();

    newNode->setData(data);

    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        current = newNode;
        return;
    }

    TapeCell* perm = head;
    while (perm->next != nullptr)
        perm = perm->next;

    perm->next = newNode;

    newNode->prev = perm;
}
void Tape::prepend(char data) {
    if (!alphabet.hasLetter(data)) {
        std::cout<<"Invalid letter\n";
        return;
    }

    auto* newNode = new TapeCell();

    newNode->setData(data);

    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

bool Tape::isValidMove(char direction) {
    // in case of an empty tape
    if (current == nullptr) {
        return false;
    }

    if (direction == 'L') return current->prev != nullptr;
    if (direction == 'R') return current->next != nullptr;
}

TapeCell* Tape::moveCurrent(char direction) {
    if (!isValidMove(direction)) {
        if (direction == 'L') {
            prepend(' ');
        }
        if (direction == 'R') {
            append(' ');
        }
    }

    if (direction == 'L') current = current->prev;
    if (direction == 'R') current = current->next;

    return current;
}

void Tape::writeOnCurrent(char data) {
    if (alphabet.hasLetter(data)) {
        current->setData(data);
    }
}

TapeCell* Tape::getCurrent() {
    return current;
}

Alphabet& Tape::getAlphabet() {
    return alphabet;
}

std::string Tape::getContent() {
    TapeCell *fakeHead = head;
    std::string result;

    while (fakeHead != nullptr) {
        result += fakeHead->getData();
        result += ',';
        fakeHead = fakeHead->next;
    }
    // remove the last ,
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

std::vector<char> Tape::getContentVector() {
    std::vector<char> content;
    TapeCell* temp = head;

    while (temp != nullptr) {
        content.push_back(temp->getData());
        temp = temp->next;
    }

    return content;
}

void Tape::reset() {
    current = head;
}