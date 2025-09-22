#include "Array.hpp"


int main()
{
    std::cout << "Testing default initialization\n";

    int *a = new int();
    std::cout << "default int value : "<< *a << std::endl;
    delete a;

    try
    {
        std::cout << "testing default constructor\n";
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        std::cout << "testing param constructor\n";
        Array<int> intArray(5);
        std::cout << "int array size : " << intArray.size() << std::endl;
        std::cout << "testing copy constructor\n";
        
        Array<int> copiedArray(intArray);
        std::cout << "copied array size :" << copiedArray.size() << std::endl;

        std::cout << "testing deep copy\n";
        intArray[0] = 999;
        std::cout << "original array[0] " << intArray[0] << std::endl;
        std::cout << "copied array[0] " << copiedArray[0] << std::endl;

        std::cout << "testing assigment op\n";
        copiedArray = intArray;
        std::cout << "copied array[0] " << copiedArray[0] << std::endl;



    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
