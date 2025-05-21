#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange
{
    private:
        std::map<const std::string, double> databaseMap;
        std::map<const std::string, double> inputMap;

    public:
        void parseDataBase(const std::string&);
        void parseInput(const std::string&);
        const std::string parseDate(const std::string&);
        void parseRate(const std::string&, const std::string&);
        void printResults();

        //helpers:
        bool isValidDateFormat(const std::string& date);
};



#endif //BITCOINEXCHANGE_HPP
