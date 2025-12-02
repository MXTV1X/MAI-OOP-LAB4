#pragma once
#include <cmath>
#include <iostream>
#include <type_traits>

template<typename T>
class Point {
    static_assert(std::is_arithmetic_v<T>, "T must be arithmetic");
private:
    T x_, y_;
public:
    Point(): x_(T{}), y_(T{}) {}
    Point(T x, T y): x_(x), y_(y) {}
    Point(const Point& other) = default;
    Point(Point&&) noexcept = default;
    Point& operator=(const Point&) = default;
    Point& operator=(Point&&) noexcept = default;
    ~Point() = default;

    T get_x() const { return x_; }
    T get_y() const { return y_; }
    void set_x(T x){ x_ = x; }
    void set_y(T y){ y_ = y; }

    Point operator+(const Point& r) const { return Point(x_ + r.x_, y_ + r.y_); }
    Point operator-(const Point& r) const { return Point(x_ - r.x_, y_ - r.y_); }
    Point& operator+=(const Point& r){ x_ += r.x_; y_ += r.y_; return *this; }
    Point& operator-=(const Point& r){ x_ -= r.x_; y_ -= r.y_; return *this; }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << p.x_ << " " << p.y_;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x_ >> p.y_;
        return is;
    }
};
