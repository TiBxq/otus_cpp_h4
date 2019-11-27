#include <iostream>
#include <string>
#include <vector>
#include <list>

const int c_byteSize = 8;

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

template<typename T>
void print_ip(std::vector<T> param, std::ostream& os)
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

template<typename T>
void print_ip(std::list<T> param, std::ostream& os)
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