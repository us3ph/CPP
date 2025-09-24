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
        std::cout << "copied array size : " << copiedArray.size() << std::endl;

        std::cout << "testing deep copy\n";
        intArray[0] = 999;
        std::cout << "original array[0] " << intArray[0] << std::endl;
        std::cout << "copied array[0] " << copiedArray[0] << std::endl;

        std::cout << "testing assigment op\n";
        copiedArray = intArray;
        std::cout << "copied array[0] " << copiedArray[0] << std::endl;

        std::cout << "testing diffrent type\n";
        Array<std::string> stringArray(3);
        stringArray[0] = "hey";
        stringArray[1] = "its";
        stringArray[2] = "me";
        std::cout << "string array size : " << stringArray.size() << std::endl;
        for(unsigned int i = 0; i < stringArray.size(); i++)
            std::cout << "string [" << i << "] " <<stringArray[i] << std::endl;
        Array<float> floatArray(4);
        floatArray[0] = 0.0f;
        floatArray[1] = 0.5f;
        floatArray[2] = 10.0f;
        floatArray[3] = 13.37f;
        for(unsigned int i = 0; i < floatArray.size(); i++)
            std::cout << "float [" << i << "] " << floatArray[i] << std::endl;

        std::cout << "testing exception handeling\n";
        Array<int> testArray(3);
        testArray[5] = 1337;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception catched successfully : "<< e.what() << '\n';
    }
}


