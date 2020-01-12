#include <iostream>
#include <string>
std::string global_str; // empty string
int global_int;         // the value is 0
int main()
{
    int local_int;         // garbage value, undefined
    std::string local_str; // empty string
    std::cout << global_str << "\n"
         << global_int << "\n"
         << local_str << "\n"
         << local_int << std::endl;
    return 0;
}