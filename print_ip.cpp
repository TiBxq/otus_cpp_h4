#include <cassert>
#include <cstdlib>
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

int main(/*int argc, char const *argv[]*/)
{
    print_ip(char(-1), std::cout);
	print_ip(short(0), std::cout);
	print_ip(int(2130706433), std::cout);
	print_ip(int64_t(8875824491850138409), std::cout);
	print_ip(std::string("8.8.8.8"), std::cout);
	print_ip(std::vector<int>{ 192, 168, 0, 1 }, std::cout);
	print_ip(std::list<int>{ 192, 168, 1, 1 }, std::cout);
    return 0;
}
