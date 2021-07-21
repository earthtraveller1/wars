#ifndef E147FAFB_20EA_4A08_AFF0_837B725E214E
#define E147FAFB_20EA_4A08_AFF0_837B725E214E

#include <string>

// Contains some file-related utilities that may be useful to some parts of this program
namespace fileutils {
    // Load a file and return it as a string
    std::string loadAsString(std::string_view path);
}

#endif /* E147FAFB_20EA_4A08_AFF0_837B725E214E */
