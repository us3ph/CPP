#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;   // container to store data
    void loadDatabase(const std::string& filename);
    bool isValidDate(const std::string& date);
    float getExchangeRate(const std::string& date);
    std::string trim(const std::string& str);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    void processInput(const std::string &filename);
};
#endif