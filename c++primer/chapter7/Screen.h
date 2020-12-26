#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>
#include "Window_mgr.h"

using std::ostream;

class Screen
{
    friend void Window_mgr::clear(ScreenIndex);
public:
	using pos = std::string::size_type;
	
    Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht*wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}

	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const { return contents[r*width + c]; }

    Screen& move(pos ht, pos wd) {
        this->cursor = ht * this->width + wd;
        return *this;
    }

    Screen& set(char c) {
        this->contents[this->cursor] = c;
        return *this;
    }

    Screen& set(pos ht, pos wd, char c) {
        this->contents[ht * this->width + wd] = c;
        return *this;
    }

    Screen& display(ostream& os) {
        os << this->contents;
        return *this;
    }

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;

};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif