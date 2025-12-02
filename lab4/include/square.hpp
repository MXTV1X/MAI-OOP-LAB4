#pragma once
#include "figure.hpp"
#include <cmath>
#include <stdexcept>

template<typename T>
class Square : public Figure<T> {
    using Base = Figure<T>;
public:
    Square(): Base(4) {}
    Square(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) : Base(4) {
        Base::getPointRef(0) = p1;
        Base::getPointRef(1) = p2;
        Base::getPointRef(2) = p3;
        Base::getPointRef(3) = p4;
        if(!isCorrect()) throw std::invalid_argument("Invalid square");
    }
    Point<T> getCenter() const override {
        Point<T> sum(T{},T{});
        for(size_t i=0;i<Base::getPointCount();++i) sum += Base::getPoint(i);
        return Point<T>(sum.get_x()/4, sum.get_y()/4);
    }
    bool isCorrect() const override {
        const double EPS = 1e-6;
        auto p0 = Base::getPoint(0), p1 = Base::getPoint(1), p2 = Base::getPoint(2), p3 = Base::getPoint(3);
        double l0 = std::pow(p1.get_x()-p0.get_x(),2) + std::pow(p1.get_y()-p0.get_y(),2);
        double l1 = std::pow(p2.get_x()-p1.get_x(),2) + std::pow(p2.get_y()-p1.get_y(),2);
        double l2 = std::pow(p3.get_x()-p2.get_x(),2) + std::pow(p3.get_y()-p2.get_y(),2);
        double l3 = std::pow(p0.get_x()-p3.get_x(),2) + std::pow(p0.get_y()-p3.get_y(),2);
        if(std::fabs(l0-l1) > EPS || std::fabs(l1-l2) > EPS || std::fabs(l2-l3) > EPS) return false;
        double dot = (p1.get_x()-p0.get_x())*(p2.get_x()-p1.get_x()) + (p1.get_y()-p0.get_y())*(p2.get_y()-p1.get_y());
        if(std::fabs(dot) > EPS) return false;
        return true;
    }
    operator double() const override {
        auto p0 = Base::getPoint(0), p1 = Base::getPoint(1);
        double side = std::hypot(p1.get_x()-p0.get_x(), p1.get_y()-p0.get_y());
        return side*side;
    }
    const char* getName() const override { return "Square"; }

    friend std::istream& operator>>(std::istream& is, Square& s){
        for(size_t i=0;i<4;++i) is >> s.getPointRef(i);
        return is;
    }
};
