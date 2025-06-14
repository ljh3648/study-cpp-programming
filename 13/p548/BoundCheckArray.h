#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__
using namespace std;

template <typename T>
class BoundCheckArray {
private:
    T *arr;
    int arrlen;
public:
    BoundCheckArray(int len) {}
    ~BoundCheckArray() {}
    T& operator[](int idx) {}
    T& operator[](int idx) const {}
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len) {
    arr = new T[len];
}

BoundCheckArray::~BoundCheckArray() {
    delete[]arr;
}

template <typename T>
T& BoundCheckArray<T>::operator[](int idx) {
    if (idx < 0 || idx >= arrlen) {
        cout << "Array index out of bound exceptiton" << endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
T& BoundCheckArray<T>::operator[](int idx) const {
    if (idx < 0 || idx >= arrlen) {
        cout << "Array index out of bound exceptiton" << endl;
        exit(1);
    }
    return arr[idx];
}
int BoundCheckArray::GetArrLen() const {
    return arrlen;
}

#endif