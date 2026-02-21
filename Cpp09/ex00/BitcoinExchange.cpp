#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {loadDatabase("data.csv");}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
  if (this != &other)
      _database = other._database;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
  std::ifstream file(filename.c_str());
  if(!file.is_open())
  {
    std::cerr << "Error: could not open file" << filename << std::endl;
    return;
  }
  std::string line;
  std::getline(file, line); // skip header
  while (std::getline(file, line))
  {
    size_t commapos = line.find(',');
    if (commapos == std::string::npos) // skip malformed lines
      continue;
    std::string date = line.substr(0, commapos);
    std::string rate_str = line.substr(commapos + 1);

    std::stringstream ss(rate_str);
    float rate;
    ss >> rate;
    _database[date] = rate; // store in map
  }
  file.close();
}


bool BitcoinExchange::isValidDate(const std::string& date)
{
  if(date.length() != 10 || date[4] != '-' || date[7] != '-')
    return false;
  int year, month, day;
  std::string year_str = date.substr(0, 4);
  std::string month_str = date.substr(5, 2);
  std::string day_str = date.substr(8, 2);

  std::stringstream ss_year(year_str);
  std::stringstream ss_month(month_str);
  std::stringstream ss_day(day_str);
  if (!(ss_year >> year) || !(ss_month >> month) || !(ss_day >> day))
    return false;
  if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
    return false;

  // determine max days for the given month
  int maxDay;
  if (month == 2)
  {
    bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    maxDay = leapYear ? 29 : 28;
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11)
    maxDay = 30;
  else
    maxDay = 31;

  if (day > maxDay)
    return false;
  return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date)
{
  std::map<std::string, double>::iterator it = _database.lower_bound(date);
  if(it != _database.end() && it->first == date)
    return it->second;
  if(it == _database.begin())
    return -1.0f;
  --it;
  return it->second;
}

std::string BitcoinExchange::trim(const std::string& str)
{
  size_t start = str.find_first_not_of(" \t\r\n");
  if(start == std::string::npos)
    return "";
  size_t end = str.find_last_not_of(" \t\r\n");
  return str.substr(start, end - start + 1);
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
      std::cerr << "Error: could not open file" << filename << std::endl;
      return;
    }
    std::string line;
    std::getline(file, line);
    while(std::getline(file, line))
    {
      if(line.empty())
        continue;
      size_t pippos = line.find(" | ");
      if(pippos == std::string::npos)
      {
        std::cerr << "Error: bad input => " << line << std::endl;
        continue;
      }
      std::string date = line.substr(0, pippos);
      std::string value_str = line.substr(pippos + 3);
      date = trim(date);
      value_str = trim(value_str);
      if(!isValidDate(date))
      {
        std::cerr << "Error: bad input => " << line << std::endl;
        continue;
      }
      std::stringstream ss(value_str);
      float value;
      if(!(ss >> value))
      {
        std::cerr << "Error: bad input => " << line << std::endl;
        continue;
      }
      if(value < 0)
      {
        std::cerr << "Error: not a positive number." << std::endl;
        continue;
      }
      if(value > 1000)
      {
        std::cerr << "Error: too large a number." << std::endl;
        continue;
      }
      float rate = getExchangeRate(date);
      if(rate == -1.0f)
      {
        std::cerr << "Error: no exchange rate available " << date << std::endl;
        continue;
      }
      std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
    file.close();
}

