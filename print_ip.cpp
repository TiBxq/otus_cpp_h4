#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <list>

const int c_byteSize = 8;

template<typename T>
void print_ip(T param)
{
	for (int i = sizeof(T) - 1; i >= 0; --i)
	{
		if (i != sizeof(T) - 1)
		{
			std::cout << '.';
		}
		uint8_t value = param >> i * c_byteSize;
		std::cout << int(value);
	}
	std::cout << std::endl;
}

template<>
void print_ip(std::string param)
{
	std::cout << param << std::endl;
}

template<typename T>
void print_ip(std::vector<T> param)
{
	for (auto it = param.begin(); it != param.end(); ++it)
	{
		if (it != param.begin())
		{
			std::cout << '.';
		}
		std::cout << *it;
	}
	std::cout << std::endl;
}

template<typename T>
void print_ip(std::list<T> param)
{
	for (auto it = param.begin(); it != param.end(); ++it)
	{
		if (it != param.begin())
		{
			std::cout << '.';
		}
		std::cout << *it;
	}
	std::cout << std::endl;
}

int main(/*int argc, char const *argv[]*/)
{
    print_ip(char(-1));
	print_ip(short(0));
	print_ip(int(2130706433));
	print_ip(int64_t(8875824491850138409));
	print_ip(std::string("8.8.8.8"));
	print_ip(std::vector<int>{ 192, 168, 0, 1 });
	print_ip(std::list<int>{ 192, 168, 1, 1 });
    return 0;
}
