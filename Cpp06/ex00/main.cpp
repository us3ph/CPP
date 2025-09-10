#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    // (void)argc;
    // try
    // {
    //     ScalarConverter::convert(argv[1]);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    if(argc == 2)
    {
        ScalarConverter::convert(argv[1]);
    }
}