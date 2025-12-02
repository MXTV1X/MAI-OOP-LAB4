#pragma once
#include "figure.hpp"
#include <cmath>

template<Scalar T>
class Square : public Figure<T> {
public:
    Square() { for(int i=0; i<4; ++i) this->points.push_back(std::make_unique<Point<T>>()); }
    Point<T> getCenter() const override {
        T cx = 0, cy = 0;
        for(const auto& p : this->points) { cx += p->x; cy += p->y; }
        return Point<T>(cx/4, cy/4);
    }
    operator double() const override {
        // Сторона по двум первым точкам
        double side = std::hypot(this->points[0]->x - this->points[1]->x, 
                                 this->points[0]->y - this->points[1]->y);
        return side * side;
    }
    std::string getName() const override { return "Square"; }
};

template<Scalar T>
class Rectangle : public Figure<T> {
public:
    Rectangle() { for(int i=0; i<4; ++i) this->points.push_back(std::make_unique<Point<T>>()); }
    Point<T> getCenter() const override {
        T cx = 0, cy = 0;
        for(const auto& p : this->points) { cx += p->x; cy += p->y; }
        return Point<T>(cx/4, cy/4);
    }
    operator double() const override {
        double side1 = std::hypot(this->points[0]->x - this->points[1]->x, this->points[0]->y - this->points[1]->y);
        double side2 = std::hypot(this->points[1]->x - this->points[2]->x, this->points[1]->y - this->points[2]->y);
        return side1 * side2;
    }
    std::string getName() const override { return "Rectangle"; }
};

template<Scalar T>
class Trapezoid : public Figure<T> {
public:
    Trapezoid() { for(int i=0; i<4; ++i) this->points.push_back(std::make_unique<Point<T>>()); }
    Point<T> getCenter() const override {
        T cx = 0, cy = 0;
        for(const auto& p : this->points) { cx += p->x; cy += p->y; }
        return Point<T>(cx/4, cy/4);
    }
    operator double() const override {
        double area = 0;
        for (int i = 0; i < 4; i++) {
            area += (this->points[i]->x * this->points[(i + 1) % 4]->y) - 
                    (this->points[(i + 1) % 4]->x * this->points[i]->y);
        }
        return std::abs(area) / 2.0;
    }
    std::string getName() const override { return "Trapezoid"; }
};