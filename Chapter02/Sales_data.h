#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>

struct Sales_data
{
    std::string isbn;
    unsigned unitsSold = 0;
    double revenue = 0.0;
};
#endif