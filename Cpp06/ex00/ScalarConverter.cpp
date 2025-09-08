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

}
char ScalarConverter::stringToChar(const std::string &literal)
{
    return literal[1];
}
float ScalarConverter::stringToFloat(const std::string &literal)
{

}
double ScalarConverter::stringToDouble(const std::string &literal)
{
    
}

void ScalarConverter::convert(const std::string& literal)
{

}