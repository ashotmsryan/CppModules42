#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *p_str = &str;
    std::string &r_str = str;

    std::cout << "String address = " << &str << std::endl;
    std::cout << "Pointer address = " << &p_str << std::endl;
    std::cout << "Reference address = " << &r_str << std::endl;

    std::cout << "String value = " << str << std::endl;
    std::cout << "Pointer value = " << p_str << std::endl;
    std::cout << "Reference value = " << r_str << std::endl;
}