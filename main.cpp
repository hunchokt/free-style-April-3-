#include "Freestyle.h"
#include "Fraction.h"
#include <iostream>
#include <vector>

int main() {
    // runs tests that are pre-written in the Freestyle file
    Freestyle::run_tests();

    std::cout << '\n';

    // manual Fraction tests
    std::cout << "Testing Fractions: " << std::endl;
    Fraction test1{2, 4};
    Fraction test2{12, 14};
    Fraction test3{12, 18};

    std::vector<Fraction> fractions {test1, test2, test3};
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
}