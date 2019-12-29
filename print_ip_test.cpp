#include <gtest/gtest.h>
#include <sstream>

#include "print_ip.h"

TEST(print_ip, print_ip_test_char)
{
    std::ostringstream oss;
    print_ip(char(-1), oss);
    ASSERT_EQ(oss.str(), "255\n");
}

TEST(print_ip, print_ip_test_short)
{
    std::ostringstream oss;
    print_ip(short(0), oss);
    ASSERT_EQ(oss.str(), "0.0\n");
}

TEST(print_ip, print_ip_test_int)
{
    std::ostringstream oss;
    print_ip(int(2130706433), oss);
    ASSERT_EQ(oss.str(), "127.0.0.1\n");
}

TEST(print_ip, print_ip_test_long)
{
    std::ostringstream oss;
    print_ip(int64_t(8875824491850138409), oss);
    ASSERT_EQ(oss.str(), "123.45.67.89.101.112.131.41\n");
}

TEST(print_ip, print_ip_test_string)
{
    std::ostringstream oss;
    print_ip(std::string("8.8.8.8"), oss);
    ASSERT_EQ(oss.str(), "8.8.8.8\n");
}

TEST(print_ip, print_ip_test_vector)
{
    std::ostringstream oss;
    print_ip(std::vector<int>{ 192, 168, 0, 1 }, oss);
    ASSERT_EQ(oss.str(), "192.168.0.1\n");
}

TEST(print_ip, print_ip_test_list)
{
    std::ostringstream oss;
    print_ip(std::list<int>{ 192, 168, 1, 1 }, oss);
    ASSERT_EQ(oss.str(), "192.168.1.1\n");
}

TEST(print_ip, print_ip_test_tuple)
{
    std::ostringstream oss;
    print_ip(std::make_tuple(1, 2, 3, 4), oss);
    ASSERT_EQ(oss.str(), "1.2.3.4\n");
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}