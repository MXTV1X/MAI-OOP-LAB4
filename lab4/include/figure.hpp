#pragma once
#include <iostream>
#include <string>

class Figure {
public:
    virtual ~Figure() = default;

    virtual double area() const = 0;
    virtual std::string getName() const = 0;
    virtual bool isCorrect() const = 0;

    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& f) {
        f.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& f) {
        f.read(is);
        return is;
    }
};
