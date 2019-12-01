#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

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
void print_ip(const T& param, std::ostream& os)
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
void print_ip(const std::string& param, std::ostream& os)
{
    os << param << std::endl;
}

template<template<typename, typename...> class C, typename T, typename... Rest,
         typename = typename std::enable_if<
            is_vector<C<T, Rest...>>::value || is_list<C<T, Rest...>>::value,
         void>::type
         >
void print_ip(const C<T, Rest...>& param, std::ostream& os)
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

template<std::size_t I = 0, typename ...Args>
typename std::enable_if<I == sizeof...(Args), void>::type
print_ip(const std::tuple<Args...>&, std::ostream&) {}

template<std::size_t I = 0, typename ...Args>
typename std::enable_if<I < sizeof...(Args), void>::type
print_ip(const std::tuple<Args...>& param, std::ostream& os)
{
    if (I != 0)
    {
        os << '.';
    }
    os << std::get<I>(param);
    print_ip<I + 1, Args...>(param, os);
}