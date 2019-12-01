#include "print_ip.h"

int main(/*int argc, char const *argv[]*/)
{
    print_ip(char(-1), std::cout);
    print_ip(short(0), std::cout);
    print_ip(int(2130706433), std::cout);
    print_ip(int64_t(8875824491850138409), std::cout);
    print_ip(std::string("8.8.8.8"), std::cout);
    print_ip(std::vector<int>{ 192, 168, 0, 1 }, std::cout);
    print_ip(std::list<int>{ 192, 168, 1, 1 }, std::cout);
    print_tuple(std::make_tuple(1, 2, "3", '4'), std::cout);
    return 0;
}
