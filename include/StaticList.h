//
// Created by Israel on 13/10/2025.
//

#ifndef EJERCICIOSCOLABORATIVOS2_STATICLIST_H
#define EJERCICIOSCOLABORATIVOS2_STATICLIST_H

#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
class StaticList {
private:
    static const int MAX_SIZE = 50;
    T container[MAX_SIZE];
    int num_elements;

    void insertMultiple() {}

    template<typename First, typename... Rest>
    void insertMultiple(First first, Rest... rest) {
        insertAtEnd(first);
        insertMultiple(rest...);
    }

public:
    StaticList() : num_elements(0) {}

    template<typename... Args>
    StaticList(Args... args) : num_elements(0) {
        insertMultiple(args...);
    }

    bool isEmpty() const { return num_elements == 0; }
    bool isFull() const { return num_elements == MAX_SIZE; }
    int size() const { return num_elements; }

    void insertAtEnd(const T &element) {
        if (isFull()) { cout << "List is full\n"; return; }
        container[num_elements++] = element;
    }

    void insertAtBeginning(const T &element) {
        insertAt(element, 0);
    }

    void insertAt(const T &element, int position) {
        if (position < 0 || position > num_elements) { cout << "Invalid position\n"; return; }
        if (isFull()) { cout << "List is full\n"; return; }

        for (int i = num_elements; i > position; --i) {
            container[i] = container[i - 1];
        }
        container[position] = element;
        ++num_elements;
    }

    T extractAtEnd() {
        if (isEmpty()) { cout << "List is empty\n"; return T{}; }
        return container[--num_elements];
    }

    T extractAtBeginning() { return extractAt(0); }

    T extractAt(int position) {
        if (isEmpty()) { cout << "List is empty\n"; return T{}; }
        if (position < 0 || position >= num_elements) { cout << "Invalid position\n"; return T{}; }

        T temp = container[position];
        for (int i = position; i < num_elements - 1; ++i) {
            container[i] = container[i + 1];
        }
        --num_elements;
        return temp;
    }

    T *at(int position) const {
        if (position < 0 || position >= num_elements) return NULL;
        return &container[position];
    }

    T *begin() { return container; }
    T *end() { return container + num_elements; }
    const T *begin() const { return container; }
    const T *end() const { return container + num_elements; }

    std::string toString() const {
        std::string result = "[";
        for (int i = 0; i < num_elements; ++i) {
            std::stringstream ss;
            ss << container[i];
            result += ss.str();
            if (i < num_elements - 1) result += ", ";
        }
        result += "]";
        return result;
    }
};

#endif //EJERCICIOSCOLABORATIVOS2_STATICLIST_H