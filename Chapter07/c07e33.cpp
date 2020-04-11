#include <iostream>
#include <string>
using namespace std;

class Screen
{
public:
    // type alias
    typedef string::size_type pos;

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

    ///////////////////////////////////////////////////////////////////////////
    // if defined inside a class, the scope operator has to be omitted
    // pos Screen::size() const
    /* inside class definition
    pos size() const
    {
        return height * width;
    }*/
    // when defined outside of class declaration
    pos size() const;
    ///////////////////////////////////////////////////////////////////////////

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(ostream &os) const { os << contents; }
};

int main(void)
{
    Screen myScreen(5, 5, 'X');
    cout << myScreen.size() << endl;
    return 0;
}

// when defined outside of class the Screen:: scope specifier has to be added
// before 'pos' to specyfiy that it comes from the Screen class
Screen::pos Screen::size() const
{
    return height * width;
}
/////////////////////////////////////////////////////////////////////////////

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