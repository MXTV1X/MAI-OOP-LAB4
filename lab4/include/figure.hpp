#pragma once
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include "point.hpp"

template<Scalar T>
class Figure {
public:
    // По требованию: точки хранятся как std::unique_ptr<Point<T>>
    std::vector<std::unique_ptr<Point<T>>> points;

    virtual ~Figure() = default;
    virtual Point<T> getCenter() const = 0;
    virtual operator double() const = 0; // Площадь
    virtual std::string getName() const = 0;

    void printInfo() const {
        std::cout << "Figure: " << getName() << "\nVertices: ";
        for (const auto& p : points) std::cout << "(" << p->x << ", " << p->y << ") ";
        Point<T> c = getCenter();
        std::cout << "\nCenter: (" << c.x << ", " << c.y << ")";
        std::cout << "\nArea: " << static_cast<double>(*this) << "\n";
    }
};