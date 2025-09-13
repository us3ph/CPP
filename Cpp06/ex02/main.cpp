#include "Base.hpp"

int main() {

    srand(time(0));

    for (int i = 0; i < 5; ++i) 
    {
        std::cout << "test" << i + 1 << ":" << std::endl;
        Base* base  = generate();
        std::cout << "identify pointer\n";
        identify(base);
        std::cout << "identify refrence\n";
        identify(*base);
        delete base;
    }
    return 0;
}