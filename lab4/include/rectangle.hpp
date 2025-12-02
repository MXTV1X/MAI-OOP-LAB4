#pragma once
#include "figure.hpp"
#include "point.hpp"
#include <cmath>

class Rectangle : public Figure {
public:
    using P = Point<double>;

private:
    P a, b;

public:
    Rectangle() = default;
    Rectangle(P a_, P b_) : a(a_), b(b_) {}

    double area() const override {
        return std::abs((b.get_x() - a.get_x()) * (b.get_y() - a.get_y()));
    }

    std::string getName() const override { return "Rectangle"; }

    bool isCorrect() const override {
        return a.get_x() != b.get_x() && a.get_y() != b.get_y();
    }

    void print(std::ostream& os) const override {
        os << "Rectangle: "
           << a << " ; " << b
           << " | area = " << area();
    }

    void read(std::istream& is) override {
        is >> a >> b;
    }
};
