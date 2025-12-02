#include <gtest/gtest.h>
#include "array.hpp"
#include "shapes.hpp"

TEST(ArrayTest, PushBackAndSize) {
    Array<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 10);
}

TEST(FigureTest, SquareArea) {
    auto sq = std::make_shared<Square<double>>();
    sq->points[0] = std::make_unique<Point<double>>(0, 0);
    sq->points[1] = std::make_unique<Point<double>>(2, 0);
    sq->points[2] = std::make_unique<Point<double>>(2, 2);
    sq->points[3] = std::make_unique<Point<double>>(0, 2);
    
    EXPECT_DOUBLE_EQ(static_cast<double>(*sq), 4.0);
    EXPECT_EQ(sq->getCenter().x, 1.0);
}

TEST(ArrayTest, RemoveElement) {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.remove(1); // удаляем '2'
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[1], 3);
}

TEST(FigureTest, ArrayOfFigures) {
    Array<std::shared_ptr<Figure<double>>> arr;
    auto rect = std::make_shared<Rectangle<double>>();
    rect->points[0] = std::make_unique<Point<double>>(0, 0);
    rect->points[1] = std::make_unique<Point<double>>(4, 0);
    rect->points[2] = std::make_unique<Point<double>>(4, 2);
    rect->points[3] = std::make_unique<Point<double>>(0, 2);
    
    arr.push_back(rect);
    EXPECT_DOUBLE_EQ(static_cast<double>(*arr[0]), 8.0);
}