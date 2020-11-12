#include <iostream>
#include <list>
using namespace std;

template <typename elemType>
class ListItem;
template <typename elemType>
class List
{
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType> &operator=(const List<elemType> &);
    ~List();
    // void insert(ListItem *ptr, elemType value);
    // ListItem is a template not a type and we have to provide a type for the
    // *ptr parameter, so we have to provide an argument list for ListItem
    void insert(ListItem<elemType> *ptr, elemType value);

private:
    // ListItem *front, *end;
    // same story as above
    ListItem<elemType> *front, *end;
};

int main(void)
{
    return 0;
}