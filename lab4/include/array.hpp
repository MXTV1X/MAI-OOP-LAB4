#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>
#include "figure.hpp"

template<typename T>
class Array {
private:
    std::vector<std::shared_ptr<Figure<T>>> arr;
public:
    Array() = default;
    ~Array() = default;
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    void push_back(std::shared_ptr<Figure<T>> f){ arr.push_back(std::move(f)); }
    bool empty() const { return arr.empty(); }
    void remove(size_t idx){
        if(idx >= arr.size()) throw std::out_of_range("Index out of range");
        arr.erase(arr.begin() + idx);
    }
    std::shared_ptr<Figure<T>> operator[](size_t idx) const {
        if(idx >= arr.size()) throw std::out_of_range("Index out of range");
        return arr[idx];
    }
    size_t getSize() const { return arr.size(); }

    double totalArea() const {
        double s = 0.0;
        for(const auto &p : arr) s += static_cast<double>(*p);
        return s;
    }

    void printAll() const {
        if(arr.empty()){ std::cout << "No figures\n"; return; }
        for(size_t i=0;i<arr.size();++i){
            std::cout << "\n=== Figure " << (i+1) << " (" << arr[i]->getName() << ") ===\n";
            const auto &f = *arr[i];
            for(size_t j=0;j<f.getPointCount();++j){
                const auto &p = f.getPoint(j);
                std::cout << "  (" << p.get_x() << ", " << p.get_y() << ")\n";
            }
            auto c = f.getCenter();
            std::cout << "Center: (" << c.get_x() << ", " << c.get_y() << ")\n";
            std::cout << "Area: " << static_cast<double>(f) << "\n";
        }
    }
    void clear(){ arr.clear(); }
};
