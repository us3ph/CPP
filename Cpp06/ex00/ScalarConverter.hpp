#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "cmath"
#include "iostream"

class ScalarConverter // static class 
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);
    ~ScalarConverter();

    bool isInt(const std::string &literal);
    bool isChar(const std::string &literal);
    bool isFloat(const std::string &literal);
    bool isDouble(const std::string &literal);

    int stringToInt(const std::string &literal);
    char stringToChar(const std::string &literal);
    float stringToFloat(const std::string &literal);
    double stringToDouble(const std::string &literal);

public:
    static void convert(const std::string& literal);
};

#endif