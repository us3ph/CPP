#include "Base.hpp"

int main() {
    // Seed the random number generator once at the beginning of the program
    srand(time(0));

    // Generate and print a few pseudo-random numbers
    for (int i = 0; i < 5; ++i) {
        std::cout << "Random number: " << rand() << std::endl;
    }

    return 0;
}