#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "cmath"
#include "iostream"
#include "sstream"

class ScalarConverter // static class 
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);
    ~ScalarConverter();


    static bool isInt(const std::string &literal);
    static bool isChar(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);

    static int stringToInt(const std::string &literal);
    static char stringToChar(const std::string &literal);
    static float stringToFloat(const std::string &literal);
    static double stringToDouble(const std::string &literal);

    static void printChar(char value, bool impossible = false, bool Nondisplayable = false);
    static void printInt(int value, bool impossible = false);
    static void printFloat(float value);
    static void printDouble(double value);

public:
    static void convert(const std::string& literal);
};

#endif