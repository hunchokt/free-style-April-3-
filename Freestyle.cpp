#include "Freestyle.h"
#include <iostream>
#include <cassert>

namespace Freestyle {
    bool pow_of_two_loop( int num ) {
        if (num <= 0) throw std::runtime_error("Negatives and zeros are invalid.");

        // technically 1 is a power of 2 (2^0)
        if (num == 1 || num == 2)
            return true;
        
        if (num % 2 != 0)
            return false;

        return pow_of_two_loop( num / 2 );
    }

    bool pow_of_two_noloop ( int num ) {
        /*
        Learned the existence and use of bitwise operations from:
        - learncpp.com (this is what i used mainly to teach myself C++ over break)
        - chatgpt (I merely asked it questions as to how it works with powers of two specifically)

        From my understanding:
        - powers of two will only ever have a single '1' in binary form (e.g., 2 = 0010, 16 = 10000)
        - all predecessors of powers of two flip all bits after the 1 (and then the 1 goes to 0)
        - running bitwise AND both will leave no overlapping 1's (therefore returning 0000)
        */

        if (num <= 0) throw std::runtime_error("Negatives and zeros are invalid.");

        return ((num & (num - 1)) == 0);
    }

    void check_if_prime( int num ) {
        if (num <= 1 || (num > 2 && num % 2 == 0)) {
            std::cout << "FAIL" << std::endl;
            return;
        }

        if (num == 2) {
            std::cout << "PASS" << std::endl;
            return;
        }

        for (int i = 3; i < num; ++i) {
            if (num % 2 == 0) 
                continue;

            if (num % i == 0) {
                std::cout << "FAIL" << std::endl;
                return;
            }
        }
        std::cout << "PASS" << std::endl;
    }

    void run_tests() {
        std::cout << "Testing loop version: " << std::endl;
        try {
            std::cout << "Testing TRUE case (4): " << std::boolalpha << Freestyle::pow_of_two_loop(4) << std::endl;
            std::cout << "Testing FALSE case (9): " << std::boolalpha << Freestyle::pow_of_two_loop(9) << std::endl;
            std::cout << "Testing EXCEPTION case (0): " << std::boolalpha << Freestyle::pow_of_two_loop(0) << std::endl;
        } catch (std::runtime_error& exception) {
            std::cerr << "Exception occured: " << exception.what() << std::endl;
        }

        std::cout << '\n';

        std::cout << "Testing non-loop version: " << std::endl;
        try {
            std::cout << "Testing TRUE case (4): " << std::boolalpha << Freestyle::pow_of_two_noloop(4) << std::endl;
            std::cout << "Testing FALSE case (9): " << std::boolalpha << Freestyle::pow_of_two_noloop(9) << std::endl;
            std::cout << "Testing EXCEPTION case (0): " << std::boolalpha << Freestyle::pow_of_two_noloop(0) << std::endl;
        } catch (std::runtime_error& exception) {
            std::cerr << "Exception occured: " << exception.what() << std::endl;
        }

        std::cout << '\n';

        std::cout << "Testing prime check: " << std::endl;
        std::cout << "Testing FAIL case (9): ";
        Freestyle::check_if_prime(9);
        std::cout << "Testing PASS case (7): ";
        Freestyle::check_if_prime(7);
    }
}