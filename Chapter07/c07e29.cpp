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
    // ex 7.24 constructor
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}

    // member functions
    char get() const { return contents[cursor]; }
    inline char get(pos r, pos c) const;
    inline Screen move(pos r, pos c);
    // added set functions
    inline Screen set(char c);
    inline Screen set(pos row, pos col, char c);
    // added functions that call do_display() on const and nonconst object
    Screen display(ostream &os)
    {
        cout << "Nonconst display()" << endl;
        do_display(os);
        return *this;
    }
    const Screen display(ostream &os) const
    {
        cout << "Const display()" << endl;
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    // function that really displays Screen
    void do_display(ostream &os) const { os << contents; }
};

int main(void)
{
    Screen myScreen(5, 5, 'X');
    const Screen myScreen2(4, 4, '#');
    myScreen2.display(cout);
    cout << endl;
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";

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