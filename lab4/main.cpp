#include <iostream>
#include "array.hpp"
#include "shapes.hpp"

int main() {
    Array<std::shared_ptr<Figure<double>>> all_figures;

    int cmd;
    while (true) {
        std::cout << "\n1. Add Square\n2. Add Rectangle\n3. Add Trapezoid\n4. Remove by index\n5. Print All\n0. Exit\n> ";
        std::cin >> cmd;
        if (cmd == 0) break;

        if (cmd >= 1 && cmd <= 3) {
            std::shared_ptr<Figure<double>> f;
            if (cmd == 1) f = std::make_shared<Square<double>>();
            else if (cmd == 2) f = std::make_shared<Rectangle<double>>();
            else f = std::make_shared<Trapezoid<double>>();

            std::cout << "Enter 4 pairs of coordinates (x y):\n";
            for (int i = 0; i < 4; ++i) std::cin >> *(f->points[i]);
            all_figures.push_back(std::move(f));
        } 
        else if (cmd == 4) {
            size_t idx; std::cout << "Index: "; std::cin >> idx;
            all_figures.remove(idx);
        } 
        else if (cmd == 5) {
            double total = 0;
            for (size_t i = 0; i < all_figures.size(); ++i) {
                all_figures[i]->printInfo();
                total += static_cast<double>(*(all_figures[i]));
            }
            std::cout << "\nTotal Area of all figures: " << total << "\n";
        }
    }
    return 0;
}
// S 0 0  2 0  2 2  0 2
// R 0 0  3 0  3 1  0 1
