//
// Created by Emanuil Gospodinov on 19.11.19.
//

#ifndef TURING_MACHINE_TAPECELL_H
#define TURING_MACHINE_TAPECELL_H

class TapeCell {
    char data;
public:
    TapeCell* next;
    TapeCell* prev;

    TapeCell();
    TapeCell(TapeCell const &other);
    TapeCell& operator=(TapeCell const &other);
    ~TapeCell();

    void setData(char data);
    char getData();
};

#endif //TURING_MACHINE_TAPECELL_H
