//
// Created by moritz on 07.01.22.
//

#ifndef CONANFILE_PY_STRINGUTITLITIES_H
#define CONANFILE_PY_STRINGUTITLITIES_H

#include <string>
#include <vector>

namespace Model {
    namespace Utilities {
        class StringUtitlities {
        public:
            static std::vector<std::string> splitStrings(char delimiter, std::string string_to_split);
            static bool contains(std::string string_to_be_compared, std::string string_to_be_contained);
            static std::string removeWhitespace(std::string& value);
        };
    }
}

#endif //CONANFILE_PY_STRINGUTITLITIES_H
