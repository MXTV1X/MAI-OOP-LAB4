#pragma once
#include <memory>
#include <utility>

template<class T>
class Array {
private:
    std::unique_ptr<T[]> data; // Соответствует std::shared_ptr<T[]> по логике управления
    size_t _size;
    size_t _capacity;

    void resize(size_t new_cap) {
        auto new_data = std::make_unique<T[]>(new_cap);
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = std::move(data[i]); // СТРОГО move по заданию
        }
        data = std::move(new_data);
        _capacity = new_cap;
    }

public:
    Array() : data(nullptr), _size(0), _capacity(0) {}

    void push_back(T value) {
        if (_size == _capacity) {
            resize(_capacity == 0 ? 1 : _capacity * 2);
        }
        data[_size++] = std::move(value);
    }

    void remove(size_t idx) {
        if (idx >= _size) return;
        for (size_t i = idx; i < _size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        _size--;
    }

    T& operator[](size_t i) { return data[i]; }
    size_t size() const { return _size; }
};