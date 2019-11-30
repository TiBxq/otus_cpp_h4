#include <iostream>
#include <string>
#include <vector>
#include <list>

const int c_byteSize = 8;

template<typename T>
struct is_vector : public std::false_type {};

template<typename T, typename A>
struct is_vector<std::vector<T, A>> : public std::true_type {};

template<typename T>
struct is_list : public std::false_type {};

template<typename T, typename A>
struct is_list<std::list<T, A>> : public std::true_type {};

template<typename T>
void print_ip(T param, std::ostream& os)
{
    for (int i = sizeof(T) - 1; i >= 0; --i)
    {
        if (i != sizeof(T) - 1)
        {
            os << '.';
        }
        uint8_t value = param >> i * c_byteSize;
        os << int(value);
    }
    os << std::endl;
}

template<>
void print_ip(std::string param, std::ostream& os)
{
    os << param << std::endl;
}

template<template<typename, typename...> typename C, typename T, typename... Rest,
         typename = typename std::enable_if<
            is_vector<C<T, Rest...>>::value || is_list<C<T, Rest...>>::value,
         void>::type
         >
void print_ip(C<T, Rest...> param, std::ostream& os)
{
    for (auto it = param.begin(); it != param.end(); ++it)
    {
        if (it != param.begin())
        {
            os << '.';
        }
        os << *it;
    }
    os << std::endl;
}