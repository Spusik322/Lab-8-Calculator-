#pragma once
#include <iostream>
#include <stdexcept>


template <typename T>
class StackMinecraft {
private:
    T* stack;
    int n;
    int t;

public:

    StackMinecraft<T>(int n = 100) : n(n), t(-1) {
        stack = new T[n + 1];
    }

    StackMinecraft<T>(const StackMinecraft& other) : n(other.n), t(other.t) {
        for (int i = 0; i < other.size(); i++) {
            stack[i] = other.stack[i];
        }
    }

    ~StackMinecraft() {
        delete[] stack;
    }

    bool isEmpty() const {
        if (t == -1) {
            return true;
        }
        return false;
    }

    int size() const {
        return t + 1;
    }

    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return stack[t];
    }

    void push(T element) {
        t++;
        stack[t] = element;
    }

    T pop() {
        if (isEmpty())
            throw std::underflow_error("Stack");
        T perm = top();
        t--;
        return perm;
    }

    StackMinecraft& operator << (T element) {
        push(element);
        return *this;
    }

    StackMinecraft& operator >> (T& res) {
        res = pop();
        return *this;
    }

    StackMinecraft& operator = (const StackMinecraft& other) {
        if (&other != this) {
            for (int i = 0; i < other.size(); i++) {
                stack[i] = other.stack[i];
            }
            n = other.n;
            t = other.t;
        }
        return *this;
    }

    T& operator[](const int& position) const {
        if (position > size())
            throw std::underflow_error("Stack flow");
        return stack[position];
    }
};

template<typename T>
bool operator == (const StackMinecraft<T>& left, const StackMinecraft<T>& right) {
    if (left.size() != right.size()) {
        return false;
    }
    for (int i = 0; i < left.size(); i++) {
        if (left[i] == right[i])
            continue;
        return false;
    }
    return true;
}

template<typename T>
bool operator != (const StackMinecraft<T>& left, const StackMinecraft<T>& right) {
    return !(left == right);
}
template<typename T>
bool operator > (const StackMinecraft<T>& left, const StackMinecraft<T>& right) {
    if (left.size() > right.size()) {
        return true;
    }
    return false;
}

template<typename T>
bool operator >= (const StackMinecraft<T>& left, const StackMinecraft<T>& right) {
    if ((left.size() > right.size()) || (left == right)) {
        return true;
    }
    return false;
}

template<typename T>
bool operator < (const StackMinecraft<T>& left, const StackMinecraft<T>& right) {
    return !(left >= right);
}

template<typename T>
bool operator <= (const StackMinecraft<T>& left, const StackMinecraft<T>& right) {
    return !(left > right);
}