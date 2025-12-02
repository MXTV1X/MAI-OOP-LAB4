#pragma once
#include <concepts>
#include <iostream>

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(T _x, T _y) : x(_x), y(_y) {}
};

template<Scalar T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
    return is >> p.x >> p.y;
}