#include "PhoneBook.hpp"


///////////// Contact class methods
void Contact::setInfo(std::string firstname, std::string lastname, std::string nickname, std:: string phonenumber, std::string darkessecret){
    this->firstName = firstname;
    this->lastName = lastname;
    this->nickname = nickname;
    this->phoneNumber = phonenumber;
    this->darkestSecret = darkessecret;
}

// const mean this func not modify any member var of object
std::string Contact::getFirstName() const // this mean im implementing this func that belongs to class contact // :: scope resolution mean look inside the class contact
{
    return this->firstName; //  means access the firstName member of the current Contact object
}
std::string Contact::getLastName() const
{
    return this->lastName;
}
std::string Contact::getNickName() const
{
    return this->nickname;
}
std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}
std::string Contact::getDarkesSecret() const
{
    return this->darkestSecret;
}


/////////////////////// Phonebook class methods
PhoneBook::PhoneBook()
{
    this->contactCount = 0;
    this->oldContactIndex = 0;
}

void PhoneBook::AddContact()
{
    std::string fname, lname, nick, phone, secret;

    std::cout << "First name   : ";
    fname = getlineHelper();
    std::cout << "Last name    : ";
    lname = getlineHelper();
    std::cout << "Nick name    : ";
    nick = getlineHelper();
    std::cout << "Phone number : ";
    phone = getlineHelper();
    std::cout << "Darkes secret: ";
    secret = getlineHelper();
    if(fname.empty() || lname.empty() || nick.empty() || phone.empty() || secret.empty())
    {
        std::cout << "Error: all fiels must be filled" << std::endl;
        return;
    }
    contact[oldContactIndex].setInfo(fname, lname, nick, phone, secret);
    oldContactIndex = (oldContactIndex + 1) % 8;
    if(contactCount < 8)
        contactCount++;

    std::cout << ">>> Contact added <<<" << std::endl;
}

void PhoneBook::SearchForContact() const
{
    if(contactCount == 0)
    {
        std::cout << "No contact saved" << std::endl;
        return;
    }

    std::cout << "|     Index|First name| Last name| Nick name|" << std::endl;
    for(int i = 0; i < contactCount; i++)
    {
        std::cout << "|" << std::setw(10) << i << "|" << formatField(contact[i].getFirstName()) << "|" << formatField(contact[i].getLastName()) << "|" << formatField(contact[i].getNickName()) << "|\n"; // sets the next output field to 10 char wide,

    }
    std::cout << "For more details enter contact index : ";

    std::string input;
    input = getlineHelper();  // read form console (cin) to check contact index
    if(input.length() != 1 || !isdigit(input[0]))
    {
        std::cout << "Error: invalid index input" << std::endl;
        return;
    }

    int index = input[0] - '0'; // convert the input to numric value

    if(index < 0 || index > contactCount)
    {
        std::cout << "Error: index out of range" << std::endl;
        return;
    }
    std::cout << ">>> Contact details <<<\n";
    std::cout << "First name   :" << contact[index].getFirstName() << "\n";
    std::cout << "Last name    :" << contact[index].getLastName() << "\n";
    std::cout << "Nick name    :" << contact[index].getNickName() << "\n";
    std::cout << "Phone number :" << contact[index].getPhoneNumber() << "\n";
    std::cout << "Darkes secret:" << contact[index].getDarkesSecret() << "\n";
}

std::string getlineHelper() // helper func for getline to check eof
{
    std::string str;
    std::getline(std::cin, str);
    if (std::cin.eof())
        std::exit(0);
    return(str);
}

std::string formatField(const std::string &field){ // helper function to format string to 10 chars
    if(field.length() > 10)
        return(field.substr(0, 9) + ".");
    else
        return(std::string(10 - field.length(), ' ') + field);
}

int main()
{
    PhoneBook PhoneBook;
    std::string command;

    std::cout << "Option : [ADD] - [SEARCH] - [EXIT]\n";
    while(true)
    {
        std::getline(std::cin, command);
        if(std::cin.eof() || command == "EXIT")
            break;
        else if(command == "ADD")
            PhoneBook.AddContact();
        else if(command == "SEARCH")
            PhoneBook.SearchForContact();
        // else if(command == "EXIT")
        //     break;
        else
            std::cout<< "Error: invalid commande" << std:: endl;
    }
}