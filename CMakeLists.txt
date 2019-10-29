cmake_minimum_required(VERSION 3.2)

project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
#project(print_ip VERSION 0.0.1)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(print_ip print_ip.cpp)
add_executable(print_ip_test print_ip_test.cpp)

set_target_properties(print_ip PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON 
)

target_include_directories(print_ip_test
    PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(print_ip_test
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

if (MSVC)
    target_compile_options(print_ip PRIVATE
        /W4
    )
    target_compile_options(print_ip_test PRIVATE
        /W4
    )
else ()
    target_compile_options(print_ip PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(print_ip_test PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example.example@gmail.com)

include(CPack)

enable_testing()

add_test(print_ip_test print_ip_test)