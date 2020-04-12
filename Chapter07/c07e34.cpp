#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
// placing the typedef of 'pos' as the last line in the class makes it impossible
// to use up to the line that it appears

class Screen
{

public:
    // constructors
    Screen() = default;
    Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}

    // member functions
    char get() const { return contents[cursor]; }
    inline char get(pos r, pos c) const;
    inline Screen move(pos r, pos c);
    inline Screen set(char c);
    inline Screen set(pos row, pos col, char c);
    Screen display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen display(ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(ostream &os) const { os << contents; }
    //////////////////////////////////////////////////////////////////////////////
    // type alias, placed here generates a bunch of errors
    typedef string::size_type pos;
    ///////////////////////////////////////////////////////////////////////////
};

int main(void)
{
    Screen myScreen(5, 5, 'X');
    return 0;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen Screen::set(char c)
{
    contents[cursor] = c; // by default cursor is 0
    return *this;
}
Screen Screen::set(pos row, pos col, char c)
{
    contents[row * width + col] = c;
    return *this;
}