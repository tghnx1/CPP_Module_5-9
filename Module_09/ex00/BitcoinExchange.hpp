#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

class BitcoinExchange
{
    private:
        std::map<const std::string, double> databaseMap;
    public:
        void parseDataBase();
        void parseInput(const std::string&);
        const std::string parseDate(const std::string&, char);
        void parseRate(const std::string&, const std::string&);
        void parseCurrency(const std::string&, const std::string&);

        void printResultLine(const std::string&, const double&);

        //helpers:
        bool isValidDateFormat(const std::string& date);
        void printOutput(std::map<const std::string, double>::iterator it, const double& inputValue,
                         const std::string& data);
        void chooseClosestDate(std::map<const std::string, double>::iterator&, const std::string&);
       //orthodox canonical form:
        BitcoinExchange();                                   // Default constructor
        BitcoinExchange(const BitcoinExchange& other);       // Copy constructor
        BitcoinExchange& operator=(const BitcoinExchange& other); // Copy assignment
        ~BitcoinExchange();
};



#endif //BITCOINEXCHANGE_HPP
