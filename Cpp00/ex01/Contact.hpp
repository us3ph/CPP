#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact { // class contact
private:

    std::string firstName;  // attributes
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:



    void setInfo(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string darkessecret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkesSecret() const;
};

#endif