#include <string_view>
#include <iostream>
#include <fstream>

#include <utils/file-utils.hpp>

std::string fileutils::loadAsString(std::string_view path) {
    std::ifstream file(path.data());
    if (!file) {
        std::cerr << "[ERROR]: Could not find or access " << path << std::endl;
        return "";
    }
    
    std::string result;
    while (!file.eof() && !file.bad()) {
        char character;
        file >> character;
        result += character;
    }
    
    return result;
}