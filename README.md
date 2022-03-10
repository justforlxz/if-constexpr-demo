# constexpr conditional compilation tests

Usually we use define macros to selectively exclude unwanted code.

E.g

```cpp
#ifdef XXX
  std::cout << "hello" << std::endl;
#else
  std::cout << "bye" << std::endl;
#endif
```

If there are too many similar defined macros, it is easy to cause fragmentation of the code, and the workflow cannot be seen intuitively.

In the C++17 standard, if constexpr was introduced, which can realize the calculation operation conditions at compile time. With the definition of macros, we can realize the following functions.

Cooperate with cmake, convert the definition macros into numerical values, and encapsulate the definitions into a header file.

```cpp
#pragma once

#cmakedefine01 ENABLE_MODULE
```

In CMakeLists.txt, add the following definition:

```cmake
option (ENABLE_MODULE "Enable Module" ON)

if(ENABLE_MODULE)
    set(ENABLE_MODULE "1")
else()
    set(ENABLE_MODULE "0")
endif(ENABLE_MODULE)

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/options/options.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/options/options.h"
)
```

The preparations are over, let's write the code!

in main.cpp, we just need to include the options.h header file and it's ready to use.

```cpp
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
```
