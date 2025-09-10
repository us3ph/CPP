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
    size_t start = 0;
    if(literal.empty()) return false;
    if(literal[0] == '+' || literal[0] == '-') start = 1;
    if(start >= literal.length()) return false;
    for(size_t i = start; i < literal.length(); ++i)
    {
        if(!isdigit(literal[i]))
            return false;
    }

    long long tmp;
    std::stringstream ss(literal);
    ss >> tmp;
    if(ss.fail() || !ss.eof() || tmp > 2147483647 || tmp < -2147483648)
    {
        std::cerr << "the type conversion is impossible" << std::endl;
        return false;
    }
    return literal[literal.size() -1] != 'f' && literal.find('.') == std::string::npos && literal[0] != '\''; // check if int like this 42'
}


bool ScalarConverter::isChar(const std::string &literal)
{
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}
bool ScalarConverter::isFloat(const std::string &literal)
{
    return (literal == "nanf" || literal == "+inff" || literal == "-inff") || (literal[literal.size() -1] == 'f' && literal.find('.') != std::string::npos);
}
bool ScalarConverter::isDouble(const std::string &literal)
{
    return (literal == "nan" || literal == "+inf" || literal == "-inf") || (literal[literal.size() -1] != 'f' && literal.find('.') != std::string::npos);
}
int ScalarConverter::stringToInt(const std::string &literal)
{
    int num = 0;
    std::stringstream ss(literal); // class from the <sstream>
    ss >> num;
    if(ss.fail() || !ss.eof())
    {
        std::cerr << "Overflow or invalid input" << std::endl;
        return 0;
    }
    return num;
}
char ScalarConverter::stringToChar(const std::string &literal)
{
    return literal[1];
}
float ScalarConverter::stringToFloat(const std::string &literal)
{
    if(literal == "nanf") 
        return 0.0f / 0.0f;
    else if(literal == "+inff") 
        return 1.0f / 0.0f;
    else if(literal == "-inff") 
        return -1.0f / 0.0f;
    float num = 0;
    std::stringstream ss(literal);
    ss >> num;
    if(ss.fail() || !ss.eof()) // leftover character check (12bbfg)
    {
        std::cerr << "Overflow or invalid input" << std::endl;
        return 0;
    }
    return num;
}
double ScalarConverter::stringToDouble(const std::string &literal)
{
    if(literal == "nan")
        return 0.0 / 0.0;
    else if(literal == "+inf")
        return 1.0 / 0.0;
    else if(literal == "-inf")
        return -1.0 / 0.0;
    double num = 0;
    std::stringstream ss(literal);
    ss >> num;
    if(ss.fail() || !ss.eof())
    {
        std::cerr << "Overflow or invalid input" << std::endl;
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
    else
        std::cout << "int: " << value << std::endl;
}

void ScalarConverter::printFloat(float value)
{
    // in floating-point arithmetic(IEEE 754) dividing zero by zero produces a special value called NaN (0.0f / 0.0f)
    if(value != value) // By IEEE 754 rules, NaN is the only floating-point value where x != x is true
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    else if(value > 3.40282e+38f)
    {
        std::cout << "float: +inff" << std::endl;
        return;
    } 
    else if(value < -3.40282e+38f)
    {
        std::cout << "float: -inff" << std::endl;
        return;
    }
    if(value == static_cast<int>(value)) // check normal number if decimal part = 0 is true like 42.0 
        std::cout << "float: " << value << ".0f" << std::endl;
    else
        std::cout << "float: " << value << "f" << std::endl; 
}
void ScalarConverter::printDouble(double value)
{
    if(value != value)
    {
        std::cout << "double: nan" << std::endl;
        return;
    }
    else if(value > 1.79769e+308)
    {
        std::cout << "double: +inf" << std::endl;
        return;
    }
    else if(value < -1.79769e+308)
    {
        std::cout << "double: -inf" << std::endl;
        return;
    }
    if(value == static_cast<int>(value))
        std::cout << "double: " << value << ".0" << std::endl;
    else
        std::cout << "double: " << value <<  std::endl;
    
}

void ScalarConverter::convertFromChar(char c)
{
    printChar(c, false, false);
    printInt(static_cast<int>(c), false);
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}
void ScalarConverter::convertFromInt(int i)
{
    if(i >= 32 && i <= 126)
        printChar(static_cast<char>(i), false, false); // check if i remove the cast here
    else if(i >= 0 && i <= 127)
        printChar(0,false, true); // valid ascii but not displayble
    else
        printChar(0,true, false);       // impossible to convert
    printInt(i, false);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}
void ScalarConverter::convertFromFloat(float f)
{
    if(f != f || f < 0 || f > 127)
        printChar(0, true, false);
    else if(f >= 32 && f <= 127)
        printChar(static_cast<char>(f), false, false);
    else
        printChar(0,false,true);

    
    if(f != f || f > 2147483647.0f || f < -2147483647.0f)
        printInt(0, true);
    else
        printInt(static_cast<int>(f), false);
    printFloat(f);
    printDouble(static_cast<double>(f));
}
void ScalarConverter::convertFromDouble(double d)
{
    if(d != d || d < 0 || d > 127)
        printChar(0, true, false);
    else if(d >= 32 && d <= 127)
        printChar(static_cast<char>(d), false, false);
    else
        printChar(0, false, true);
    if(d != d || d > 2147483647.0 || d < -2147483648.0)
        printInt(0, true);
    else
        printInt(static_cast<int>(d),false);
    printFloat(static_cast<float>(d));
    printDouble(d);
}

void ScalarConverter::convert(const std::string& literal)
{
    if(isChar(literal))
    {
        std::cout << "---> 1\n";
        char c = stringToChar(literal);
        // std::cout << c << std::endl;
        convertFromChar(c);
    }
    else if(isInt(literal))
    {
        std::cout << "---> 2\n";
        int i = stringToInt(literal);
        convertFromInt(i);
    }
    else if(isFloat(literal))
    {
        std::cout << "---> 3\n";
        float f = stringToFloat(literal);
        convertFromFloat(f);
    }
    else if(isDouble(literal))
    {
        std::cout << "---> 4\n";
        double d = stringToDouble(literal);
        convertFromDouble(d);
    }
}