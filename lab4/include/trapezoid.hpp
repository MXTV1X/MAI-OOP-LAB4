#pragma once
#include "figure.hpp"
#include "point.hpp"
#include <cmath>

class Trapezoid : public Figure {
public:
    using P = Point<double>;

private:
    P a, b, c, d;

public:
    Trapezoid() = default;
    Trapezoid(P a_, P b_, P c_, P d_) : a(a_), b(b_), c(c_), d(d_) {}

    double area() const override {
        // универсальная формула через шугарин (shoelace)
        double s =
            a.get_x() * b.get_y() + b.get_x() * c.get_y() +
            c.get_x() * d.get_y() + d.get_x() * a.get_y() -
            a.get_y() * b.get_x() - b.get_y() * c.get_x() -
            c.get_y() * d.get_x() - d.get_y() * a.get_x();

        return std::abs(s) / 2.0;
    }

    std::string getName() const override { return "Trapezoid"; }

    bool isCorrect() const override {
        return area() > 1e-9;
    }

    void print(std::ostream& os) const override {
        os << "Trapezoid: "
           << a << " ; " << b << " ; " << c << " ; " << d
           << " | area = " << area();
    }

    void read(std::istream& is) override {
        is >> a >> b >> c >> d;
    }
};
