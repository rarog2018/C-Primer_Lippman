#include <iostream>
using namespace std;

int main(void)
{
    int i = 0;
    // top-level const
    const int v2 = 0;
    // no const, because top-level const is ignored when copying an object
    int v1 = v2;
    // no const, although references are kind of always top-level const
    int *p1 = &v1, &r1 = v1;
    // p2 has low-level const, p3 has both top-level and low-level const
    // r2 has both top-level and low-level const
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;
    return 0;
}