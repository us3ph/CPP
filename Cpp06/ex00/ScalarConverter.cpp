#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isInt(const std::string &literal)
{
    return literal.back() != 'f' && literal.find('.') == std::string::npos && literal[0] != '\'' && literal.length() == 3;
}
bool ScalarConverter::isChar(const std::string &literal)
{
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}
bool ScalarConverter::isFloat(const std::string &literal)
{
    return literal == "nanf" || literal == "+inff" || literal == "-inff" && literal.find('.') != std::string::npos;
}
bool ScalarConverter::isDouble(const std::string &literal)
{
    return literal == "nan" || literal == "+inf" || literal == "-inf" && literal.find('.') != std::string::npos;
}
int ScalarConverter::stringToInt(const std::string &literal)
{
    int num = 0;
    std::stringstream ss(literal); // class from the <sstream>
    ss >> num;
    if(ss.fail() || !ss.eof())
    {
        std::cerr << "Overflow or invalid input";
        return 0;
    }
    return num;
}
char ScalarConverter::stringToChar(const std::string &literal)
{
    return literal[0];
}
float ScalarConverter::stringToFloat(const std::string &literal)
{
    float num = 0;
    std::stringstream ss(literal);
    ss >> num;
    if(ss.fail() || !ss.eof()) // leftover character check (12bbfg)
    {
        std::cerr << "Overflow or invalid input";
        return 0;
    }
    return num;
}
double ScalarConverter::stringToDouble(const std::string &literal)
{
    double num = 0;
    std::stringstream ss(literal);
    ss >> num;
    if(ss.fail() || !ss.eof())
    {
        std::cerr << "Overflow or invalid input";
        return 0;
    }
    return num;
}

void ScalarConverter::printChar(char value, bool impossible, bool Nondisplayable)
{
    if(impossible)
        std::cout << "char: impossible" << std::endl;
    else if(Nondisplayable)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << value << "'" << std::endl;
}
void ScalarConverter::printInt(int value, bool impossible)
{
    if(impossible)
        std::cout<< "int: impossible" << std::endl;
    std::cout << "int: '" << value << "'" << std::endl;
}


// IEEE 754 is a technical standard for floating-point arithmetic originally established in 1985 by the Institute of Electrical and Electronics Engineers (IEEE).
void ScalarConverter::printFloat(float value)
{
    // in floating-point arithmetic(IEEE 754) dividing zero by zero produces a special value called NaN (0.0f / 0.0f)
    if(value != value) // By IEEE 754 rules, NaN is the only floating-point value where x != x is true
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    else if(value > 1e38f)
    {
        std::cout << "float: +inff" << std::endl;
        return;
    } 
    else if(value < -1e38f)
    {
        std::cout << "float: -inff" << std::endl;
        return;
    }
    if(value = static_cast<int>(value)) // check normal number if decimal part = 0 is true like 42.0 
        std::cout << "float: " << value << "0f" << std::endl;
    else
        std::cout << "float: " << value << "f" << std::endl; 
}
void ScalarConverter::printDouble(double value)
{
    if(value != value)
        std::cout << "double: nan" << std::endl;
    else if(value > 1e308)
    {
        std::
        return;
    }
    else if(value < -1e308)
    {
        std::
        return;
    }
    if()
    
}


void ScalarConverter::convert(const std::string& literal)
{
    if()
}