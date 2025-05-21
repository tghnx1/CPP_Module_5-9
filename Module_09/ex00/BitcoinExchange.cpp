#include "BitcoinExchange.hpp"

//actions::

void BitcoinExchange::printResults()
{
  std::cout << std::fixed << std::setprecision(2);

  for (std::map<const std::string, double>::iterator it = this->databaseMap.begin();
       it != this->databaseMap.end(); ++it)
  {
    std::cout << it->first << ": " << it->second << std::endl;
  }
}

void BitcoinExchange::parseRate(const std::string& line, const std::string& date)
{
  double rate;
  const std::string rateStr = line.substr(line.find(',') + 1, line.size()); // extract the rate
  // convert the rate to double
  std::istringstream ss(rateStr);
  ss >> rate;
  // put the pair to the map
  this->databaseMap[date] = rate;
  //print the result
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

const std::string BitcoinExchange::parseDate(const std::string& line)
{
  const std::string data = line.substr(0, line.find(','));
  if (!this->isValidDateFormat(data))
  {
    std::cerr << "Error: could not parse date." << std::endl;
    exit(1);
  }
    return data;
}

void BitcoinExchange::parseDataBase(const std::string &input)
{
  std::ifstream file(input);  // Relative path

  if (!file) {
    std::cerr << "Failed to open file!" << std::endl;
    return ;
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line))
  {
    this->parseRate(line, this->parseDate(line));
  }
  file.close();
}