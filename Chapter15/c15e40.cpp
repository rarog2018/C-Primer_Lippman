#include <iostream>
using namespace std;

// If rhs returned an empty set, then the 'right' object would be a QueryResult
// object with an empty set member 'lines', so the line
// ret_lines->insert(right.begin(), right.end());
// would not insert any entries to the ret_lines set

// If lhs returned an empty set, then the 'left' object would be a QueryResult
// object with an empty set member 'lines', so the line
// auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
// would result in 'ret_lines' being an empty set

// If both returned an empty set then the line
// return QueryResult(rep(), ret_lines, left.get_file());
// would result in returning an QueryResult object with an empty set member
// 'lines'

int main(void)
{
    return 0;
}