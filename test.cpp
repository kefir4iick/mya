#include "dioph.h"
#include <iostream>

void runTests() {
    {
        auto [gcd, coef] = gcd_function(48, 18);
        if (gcd != 6) {
            std::cout << "Test failed: gcd_function(48, 18) - expected 6, got " << gcd << std::endl;
        } else {
            std::cout << "Test passed: gcd_function(48, 18)" << std::endl;
        }
        
    }
    {
        auto [gcd, coef] = gcd_function(6, 5);
        if (gcd != 1) {
            std::cout << "Test failed: right answer 6, got " << gcd << std::endl;
        } else {
            std::cout << "Test passed: gcd_function(48, 18)" << std::endl;
        }
    }
    {
        auto [gcd, coef] = gcd_function(134, 78);
        if (gcd != 2) {
            std::cout << "Test failed: right answer 2, got " << gcd << std::endl;
        } else {
            std::cout << "Test passed: gcd_function(48, 18)" << std::endl;
        }
    }
    {
        auto [gcd, coef] = gcd_function(0, 1);
        if (gcd != 1) {
            std::cout << "Test failed: right answer 1, got " << gcd << std::endl;
        } else {
            std::cout << "Test passed: gcd_function(0, 1)" << std::endl;
        }
    }
    {
        auto [gcd, coef] = gcd_function(1, 0);
        if (gcd != 1) {
            std::cout << "Test failed: right answer 1, got " << gcd << std::endl;
        } else {
            std::cout << "Test passed: gcd_function(0, 1)" << std::endl;
        }
    }

}

int main() {
    runTests();
    return 0;
}
