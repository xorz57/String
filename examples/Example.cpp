#include "String/String.hpp"

#include <utility> // std::move

int main() {
    // Default Constructor
    String s0;

    // Constructors
    String s1("dead");
    String s2("beef");

    // Copy & Move Constructors
    String s3(s1);
    String s4(std::move(s2));

    // Copy & Move Assignment Operators
    String s5;
    String s6;
    s5 = s3;
    s6 = std::move(s4);

    // Operator Overloads
    std::cout << "s0: " << s0 << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s4: " << s4 << std::endl;
    std::cout << "s5: " << s5 << std::endl;
    std::cout << "s6: " << s6 << std::endl;

    return 0;
}