#include <iostream>
int main(void)
{
    std::cout << "/*"; // legal
    std::cout << "*/"; // legal
    //std::cout << /* "*/ " */; // illegal, there is no closing pair
    std::cout << /* */ "" /* */;
    std::cout << /* "*/ " /* " /*" */; // legal
    return 0;
}