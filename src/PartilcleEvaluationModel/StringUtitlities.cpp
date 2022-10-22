//
// Created by moritz on 07.01.22.
//

#include "StringUtitlities.h"
#include <string>
#include <sstream>
#include <algorithm>

std::vector<std::string> Model::Utilities::StringUtitlities::splitStrings(char splitting, std::string string_to_split) {
    std::vector<std::string> returnValue;
    std::istringstream f(string_to_split);
    std::string s;
    while (getline(f, s, splitting)) {
        returnValue.push_back(s);
    }
    return returnValue;
}

bool
Model::Utilities::StringUtitlities::contains(std::string string_to_be_compared, std::string string_to_be_contained) {
    int position = 0;

    return ((string_to_be_compared.find(string_to_be_contained, position)) != std::string::npos);
}

std::string Model::Utilities::StringUtitlities::removeWhitespace(std::string &value) {
    value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
    return value;
}
