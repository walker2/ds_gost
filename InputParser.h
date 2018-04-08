//
// Created by andrew on 08.04.18.
//

#ifndef DS_GOST_INPUTPARSER_H
#define DS_GOST_INPUTPARSER_H

#include <string>
#include <algorithm>
#include <vector>

class InputParser
{
public:
    InputParser(int &argc, char **argv)
    {
        for (int i = 1; i < argc; ++i)
            this->tokens.emplace_back(argv[i]);
    }

    const std::string &getCmdOption(const std::string &option) const
    {
        std::vector<std::string>::const_iterator itr;
        itr = std::find(this->tokens.begin(), this->tokens.end(), option);
        if (itr != this->tokens.end() && ++itr != this->tokens.end())
        {
            return *itr;
        }
        static const std::string empty_string;
        return empty_string;
    }

    bool cmdOptionExists(const std::string &option) const
    {
        return std::find(this->tokens.begin(), this->tokens.end(), option)
               != this->tokens.end();
    }

private:
    std::vector <std::string> tokens;
};

#endif
