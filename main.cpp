#include "Freestyle.h"
#include "Fraction.h"
#include <iostream>
#include <vector>

/*
I realize that most of what I did for the included files was probably extra, and unnecessary.
The only reason I did any of it was because I tried to teach myself a lot of C++ over break,
so I mainly used this assignment as an excuse to test some of that knowledge.

All of the 'extra' stuff I used (classes, exceptions, operator overlaods, etc.), 
I learned from learncpp.com over break.
*/

int main() {
    // runs tests that are pre-written in the Freestyle file
    Freestyle::run_tests();

    std::cout << '\n';

    // manual Fraction tests
    std::cout << "Testing Fractions: " << std::endl;

    // these are the test fractions
    Fraction test1{2, 4};
    Fraction test2{12, 14};
    Fraction test3{12, 18};

    std::vector<Fraction> fractions {test1, test2, test3};

    // will compare the test fractions to their correct reduced versions.
    std::vector<Fraction> correct {Fraction{1, 2}, Fraction{6, 7}, Fraction{2, 3}};

    for (std::size_t i = 0; i < fractions.size(); ++i) {
        std::cout << "Reducing " << fractions[i] << ": ";

        fractions[i].reduce();
        if (fractions[i] == correct[i]) {
            std::cout << "PASS" << std::endl;
            continue;
        }
        std::cout << "FAIL" << std::endl;
    }

    return 0;
}