#include <iostream>
#include <vector>
using namespace std;

template <size_t H, size_t W>
class Screen
{
public:
    typedef std::string::size_type pos;

    // constructors
    // Screen() = default; // needed because Screen has another constructor
    // cursor initialized to 0 by its in-class initializer
    Screen() : height(H), width(W), contents(H * W, ' ') {}
    Screen(char c) : height(H), width(W),
                     contents(H * W, c) {}

    // member functions
    char get() const // get the character at the cursor
    {
        return contents[cursor];
    }                                      // implicitly inline
    inline char get(pos ht, pos wd) const; // explicitly inline
    Screen &move(pos r, pos c);            // can be made inline later
    void some_member() const;
    // 7.3.2
    Screen &set(char);
    Screen &set(pos, pos, char);
    // display overloaded on whether the object is const or not
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = H, width = W;
    std::string contents;
    mutable size_t access_ctr; // may change even in a const object
    // function to do the work of displaying a Screen
    void do_display(std::ostream &os) const
    {
        for (int i = 0; i < H; ++i)
        {
            os << contents.substr(i * W, W) << endl;
        }
    }
};

int main(void)
{
    Screen<7, 7> ob('#');
    ob.display(cout);
    cout << endl;

    ob.set(2, 2, '?');
    ob.set(3, 4, 'X');
    ob.set(5, 6, '-');
    ob.display(cout);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
// Screen
template <size_t H, size_t W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c)
{
    pos row = r * width; // compute the row location
    cursor = row + c;    // move cursor to the column within that row
    return *this;        // return this object as an lvalue
}
template <size_t H, size_t W>
char Screen<H, W>::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width;      // compute row location
    return contents[row + c]; // return character at the given column
}

template <size_t H, size_t W>
inline Screen<H, W> &Screen<H, W>::set(char c)
{
    contents[cursor] = c; // set the new value at the current cursor location
    return *this;         // return this object as an lvalue
}

template <size_t H, size_t W>
inline Screen<H, W> &Screen<H, W>::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch; // set specified location to given value
    return *this;                   // return this object as an lvalue
}