#include "WrongCat.hpp"

    WrongCat::WrongCat()
    {
        this->type = "Wrongcat";
    }

    WrongCat::WrongCat(const WrongCat &other)
    {
        *this = other;
    }

    WrongCat& WrongCat::operator=(const WrongCat &other)
    {
        if(this != &other)
            this->type = other.type;
        return *this;
    }

    WrongCat::~WrongCat()
    {

    }

    void WrongCat::makeSound() const
    {
        std::cout << "Wrong cat sound" << std::endl;
    }