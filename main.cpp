#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tapeCell.h"
#include "tape.h"
#include "command.h"
#include "turingMachine.h"
#include "alphabet.h"
#include <iostream>

//TEST_CASE("TapeCell class test") {
//    TapeCell node;
//    CHECK(node.getData() == ' ');
//    CHECK(node.next == nullptr);
//    CHECK(node.prev == nullptr);
//}
//
TEST_CASE("Tape class test && append/prepend functionality test") {
    Alphabet alphabet({'a', 'b', 'c'});
    Tape tape(alphabet, {'a', 'b', 'a', 'a', 'a'});

//    tape.print();
}

TEST_CASE("Alphabet and checking if letter is in alphabet") {
    std::vector<char> test = {'a', ' '};
    Alphabet a, b(test);

    a.addLetter('a');
    a.addLetter(' ');

    CHECK(a.getLetters() == test);
    CHECK(b.getLetters() == test);
    CHECK(a.hasLetter('a'));
    CHECK(b.hasLetter(' '));
    CHECK(!a.hasLetter('b'));
}

TEST_CASE("Command class test") {
    Command c;

    c.setCommand('R');
    CHECK(c.getCommand() == 'R');
}

//TEST_CASE("Turing machine init") {
//    Alphabet tapeAlphabet({'a'});
//    Tape tape(tapeAlphabet);
//
//    TuringMachine tr1(tape);
//    TuringMachine tr2;
//
//    CHECK(tr1.getTape().getHead() == tr1.getCurrentTapeCell());
//}

TEST_CASE("Moving head of Turing machine") {
    Alphabet alphabet({'0', '1', ' '});
    std::vector<char> content = {'0', '1', '1', '1', '0'};
    Tape tape(alphabet, content);

    std::vector<std::string> states = {"A", "B", "C", "Reject", "Accept"};
    std::vector<std::vector<std::tuple<int, char, Command>>> transitions = {
        {{1, '0', Command('R')}, {3, '1', Command('R')}, {3, ' ', Command('R')}},
        {{2, '0', Command('R')}, {1, '1', Command('R')}, {3, ' ', Command('R')}},
        {{3, '0', Command('R')}, {3, '1', Command('R')}, {4, ' ', Command('R')}}
    };

    TuringMachine tm(tape, states, transitions, 0, 4, 3);
    if (tm.start()) std::cout<<"Accepted";
    else std::cout<<"Rejected";
}

