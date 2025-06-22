#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {  // class phnebook
private:

    Contact contact[8];
    int contactCount;
    int oldContactIndex;

public:

    PhoneBook(); // constructore

    void AddContact();
    void SearchForContact() const;
};

std::string formatField(const std::string &field);
std::string getlineHelper();
#endif