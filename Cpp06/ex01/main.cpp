#include "Serializer.hpp"

int main()
{
    Data* data = NULL;
    std::cout << "address of Data pointer     : " << &data << std::endl;

    uintptr_t num = Serializer::serialize(data);
    data = Serializer::deserialize(num);
    std::cout << "return value of deserialize : " << &data << std::endl;

}