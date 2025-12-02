#include <iostream>
#include <memory>
#include "include/array.hpp"
#include "include/trapezoid.hpp"
#include "include/rectangle.hpp"
#include "include/square.hpp"

int main(){
    using T = double;
    Array<T> arr;
    size_t N;
    if(!(std::cin >> N)) return 0;
    for(size_t i=0;i<N;++i){
        char c; std::cin >> c;
        if(c == 'T' || c == 't'){
            auto fig = std::make_shared<Triangle<T>>();
            std::cin >> *fig;
            if(fig->isCorrect()) arr.push_back(fig);
            else std::cerr << "Bad triangle\n";
        } else if(c == 'R' || c == 'r'){
            auto fig = std::make_shared<Rectangle<T>>();
            std::cin >> *fig;
            if(fig->isCorrect()) arr.push_back(fig);
            else std::cerr << "Bad rect\n";
        } else if(c == 'S' || c == 's'){
            auto fig = std::make_shared<Square<T>>();
            std::cin >> *fig;
            if(fig->isCorrect()) arr.push_back(fig);
            else std::cerr << "Bad square\n";
        } else {
            std::cerr << "Unknown type: " << c << "\n";
            --i;
        }
    }
    arr.printAll();
    std::cout << "Total area = " << arr.totalArea() << "\n";
    return 0;
}

// S 0 0  2 0  2 2  0 2
// R 0 0  3 0  3 1  0 1
// T 0 0  4 0  0 3