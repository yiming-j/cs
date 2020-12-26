#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

class Person {
    friend istream &read(istream &is, Person &person);
	friend ostream &print(ostream &os, const Person &person);
public:
    Person() = default;
    Person(const string &name, const string &addr) : name(name), addr(addr) {}

    string const& GetName() const {return this->name;}
    string const& GetAddr() const {return this->addr;}
private:
    string name;
    string addr;
};

istream& read(istream &is, Person &p) {
    is >> p.name >> p.addr;
    return is;
}

ostream& print(ostream &os, const Person &p) {
    os << p.name << " " << p.addr;
    return os;
}

#endif