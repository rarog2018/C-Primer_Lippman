#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen; // forward declaration

// added Window_mgr
class Window_mgr
{
public:
    // position of each Screen object in the vector<Screen>
    using screenIndex = vector<Screen>::size_type;

    // constructors
    Window_mgr(); // it has to be done this way, because the Screen is not
    // yet defined, the constructor definition is at the bottom

    // member functions
    void clear(screenIndex);

private:
    // Screen objects this Window_mgr is storing
    vector<Screen> screens;
};

class Screen
{
    // befriend clear()
    friend void Window_mgr::clear(screenIndex);

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
    inline Screen &move(pos r, pos c);
    // added set functions
    inline Screen &set(char c);
    inline Screen &set(pos row, pos col, char c);
    // added functions that call do_display() on const and nonconst object
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const
    {
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
    Window_mgr win;
    win.clear(0); // first object is blank, so there will be no difference
    win.clear(1); // the second however is filled with '#'
    return 0;
}

// Window_mgr functions
// constructor definition
Window_mgr::Window_mgr() : screens{Screen(4, 10, ' '), Screen(4, 10, '#')} {}

void Window_mgr::clear(screenIndex i)
{
    Screen &s = screens[i]; // fetch real Screen object from the vector
    s.display(cout);        // display the screen before reset
    cout << endl;

    s.contents = string(s.height * s.width, ' '); // reset its contents to ' '
    s.display(cout);                              // display the Screen object after reset
    cout << endl;
}
///////////////////////////////////////////////////////////////////////////////

// Screen functions
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen &Screen::set(char c)
{
    contents[cursor] = c; // by default cursor is 0
    return *this;
}
Screen &Screen::set(pos row, pos col, char c)
{
    contents[row * width + col] = c;
    return *this;
}