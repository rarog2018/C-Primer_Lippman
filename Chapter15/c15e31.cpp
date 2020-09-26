#include <iostream>
using namespace std;

// a) Query(s1) | Query(s2) & ~ Query(s3);
// Query -> OrQuery, AndQuery, NotQuery -> WordQuery

// b) Query(s1) | (Query(s2) & ~ Query(s3));
// Query -> OrQuery -> WordQuery, AndQuery -> WordQuery, NotQuery -> WordQuery

// c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
// Query -> OrQuery -> AndQuery, AndQuery -> 4 WordQuery objects at bottom

int main(void)
{
    return 0;
}