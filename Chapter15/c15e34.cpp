#include <iostream>
using namespace std;

// Query q = Query("fiery") & Query("bird") | Query("wind");
// a) List the constructors executed in processing that expression.
// Query("fiery"), Query("bird"), Query("wind") all use the Query::Query(const string)

// (Query("fiery") & Query("bird")) this expression uses the Query operator&
// which allocates the new AndQuery object using AndQuery::AndQuery(const Query &, const Query &)
// which uses the BinaryQuery:BinaryQuery(const Query &, const Query, string)
// constructor and then uses the Query::Query(shared_ptr<Query_base>), which
// the operator& returns

// AND result | Query("wind") uses the Query operator| which allocates the new
// OrQuery object using OrQuery::OrQuery(const Query &, const Query &)
// which uses the BinaryQuery:BinaryQuery(const Query &, const Query, string)
// constructor and then uses the Query::Query(shared_ptr<Query_base>), which
// the operator| returns

// b) List the calls to rep that are made from cout << q.
// q is of type Query so first it will call Query::rep() which calls
// q->rep() which will run rep of every single class that inherited it which'll
// be BinaryQuery::rep(), Query::rep() again and WordQuery::rep()

// c) List the calls to eval made from q.eval().
// Query::eval(const TextQuery &) const, which calls
// q->eval(t) which can call WordQuery::eval()

int main(void)
{
    return 0;
}