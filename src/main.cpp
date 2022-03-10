#include "options/options.h"

#include <iostream>

int main() {
    if constexpr (ENABLE_MODULE) {
        std::cout << "Now Enable Module" << std::endl;
    }

    if constexpr (!ENABLE_MODULE) {
        std::cout << "Now Disable Module" << std::endl;
    }

    return 0;
}