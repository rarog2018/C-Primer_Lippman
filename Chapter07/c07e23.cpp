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

    // member functions
    char get() const { return contents[cursor]; }
    inline char get(pos r, pos c) const;
    inline Screen &move(pos r, pos c);

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};

int main(void)
{
    Screen ms1(20, 20, '#');
    cout << ms1.get() << endl;
    cout << ms1.get(15, 12) << endl;
    ms1.move(17, 15);
    cout << ms1.get() << endl;
    return 0;
}

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