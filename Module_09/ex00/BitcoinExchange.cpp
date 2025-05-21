#include "BitcoinExchange.hpp"

//actions::

void BitcoinExchange::parseCurrency(const std::string& line, const std::string& date)
{
  double currencyValue;
  std::string CurrencyStr = line.substr(line.find('|') + 1, line.size()); // extract the currency
  CurrencyStr.erase(std::remove(CurrencyStr.begin(), CurrencyStr.end(), ' '), CurrencyStr.end());

  // convert the rate to double and validate it
  std::istringstream ss(CurrencyStr);
  if (!(ss >> currencyValue) || !ss.eof())
  {
    std::cerr << "Error: bad input: " << CurrencyStr << std::endl;
  }
  else if (currencyValue < 1)
    std::cerr << "Error: not a positive number." << std::endl;
  else if (currencyValue > 999)
  {
    std::cerr << "Error: too large a number." << std::endl;
  }
  else
  {
    //std::cout << date << " " << rate << std::endl;
    this->printResultLine(date, currencyValue);
  }
}

void BitcoinExchange::parseInput(const std::string& input)
{
  std::ifstream file(input);  // Relative path TODO:rename to the data.csv

  if (!file)
  {
    std::cerr << "Failed to open the input file!" << std::endl;
    return ;
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line))
  {
    if (line.find('|') == std::string::npos) {
      std::cerr << "Error: bad input format" << std::endl;
      return;
    }
    this->parseCurrency(line, this->parseDate(line, '|'));
  }
  file.close();
}

void BitcoinExchange::printOutput(std::map<const std::string, double>::iterator it,
                                  const double& inputValue, const std::string& date)
{
std::cout << date << " => " << inputValue << " = "
          << (it->second * inputValue) << std::endl;
}

void BitcoinExchange::chooseClosestDate(std::map<const std::string, double>::iterator &it, const std::string& date)
{
  if (it == databaseMap.begin()) {
    it = databaseMap.end(); // signal no earlier date
    std::cerr << "Error: no earlier date in database." << std::endl;
    return;
  }
  --it;
}


void BitcoinExchange::printResultLine(const std::string& date, const double &inputValue)
{
  //now we have a line of the input. We have to find the data in the map and prints the result of multiplication
  //if not find choose the closest
  std::map<const std::string, double>::iterator it = this->databaseMap.upper_bound(date);

  this->chooseClosestDate(it, date);
  if (it != databaseMap.end())
      this->printOutput(it, inputValue, date);
  else
      std::cerr << "Error: the closest date not found!" << std::endl;
}


void BitcoinExchange::parseRate(const std::string& line, const std::string& date)
{
  double rate;
  const std::string rateStr = line.substr(line.find(',') + 1, line.size()); // extract the rate
  // convert the rate to double
  std::istringstream ss(rateStr);
  if (!(ss >> rate) || !ss.eof())
  {
    std::cerr << "Error: invalid rate format: " << rateStr << std::endl;
    return;
  }
  // put the pair to the map
  this->databaseMap[date] = rate;
}

bool BitcoinExchange::isValidDateFormat(const std::string& date)
{
    if (date.length() != 10)
      return false;
    if (date[4] != '-' || date[7] != '-')
      return false;
    for (int i = 0; i < 10; ++i) {
      if (i == 4 || i == 7)
        continue;
      if (!isdigit(date[i]))
        return false;
    }
    return true;
}

const std::string BitcoinExchange::parseDate(const std::string& line, char separator)
{
  std::string data = line.substr(0, line.find(separator));
  data.erase(std::remove(data.begin(), data.end(), ' '), data.end());
  if (!this->isValidDateFormat(data))
  {
    std::cerr << "Error: bad input: " << data << std::endl;
    if (separator == ',')
      exit(1);
  }
    return data;
}

void BitcoinExchange::parseDataBase()
{
  std::ifstream file("data.csv");  // Relative path TODO:rename to the data.csv

  if (!file)
  {
    std::cerr << "Failed to open file!" << std::endl;
    return ;
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line))
  {
    this->parseRate(line, this->parseDate(line, ','));
  }
  file.close();
}


//othodox canonical form:
// Default constructor
BitcoinExchange::BitcoinExchange() {}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
  this->databaseMap = other.databaseMap;
}

// Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
  if (this != &other)
    this->databaseMap = other.databaseMap;
  return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}
