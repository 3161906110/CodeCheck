#include "test.h"


const char conifs[][20] = { "aa", "bb" };

void test_func(int count, std::string lable, std::string name)
{

}

void func()
{
	std::string str1 = "123";
	std::string str2("123");

	std::string str3 = str1 + "aa";
	int a = 1;
	test_func(2, str3, "bb");
}