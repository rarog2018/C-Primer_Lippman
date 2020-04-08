#include <iostream>
#include <string>
using namespace std;

// An access specifier may appear anywhere in the class definition, although
// we have to remember that each specifies the access level of the succeeding
// members
// There are no constrains on how often the access specifiers can appear in
// the class definition (see code below)
// 'Public' specifier should be applied to members that can be safely accessed
// from all parts of the program f.e. a function that retrieves the value of a
// certain member
// 'Private' specifier should be applied to members that we don't want the user
// to "mess up" with

class Notebook
{
public:
    string cover;

private:
    unsigned pageCount = 96;

public:
    string contents;

private:
    const double price = 2.89;

public:
    unsigned get_pageCount() const { return pageCount; }
    double get_price() const { return price; }
};

ostream &print(ostream &os, const Notebook &obj);

int main(void)
{
    Notebook first;
    print(cout, first) << endl;

    first.cover = "hard";
    first.contents = "Here are the contents of the notebook";
    print(cout, first);

    return 0;
}

ostream &print(ostream &os, const Notebook &obj)
{
    os << "Cover: " << obj.cover << ", Page count: " << obj.get_pageCount()
       << ", Price: " << obj.get_price() << endl;
    os << "Contents: " << obj.contents << endl;
    return os;
}