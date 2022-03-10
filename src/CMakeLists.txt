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

set(SRCS
    main.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/options/options.h
)

add_executable(constexpr ${SRCS})