#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
    unique_ptr<int> p1(new int(7));

    // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) // [with _Tp = int; _Dp = std::default_delete<int>]'
    // unique_ptr<int> p2 = p1;

    // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) // [with _Tp = int; _Dp = std::default_delete<int>]'
    // unique_ptr<int> p2(p1);

    return 0;
}