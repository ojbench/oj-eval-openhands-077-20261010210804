#pragma once
#include <cstring>

namespace sjtu {
class CrossArray {
private:
    int maxLines;          // maximum number of lines (arrays)
    int **arr;             // pointers to each int array (nullptr if not allocated)
    int *sizes;            // size of each line (0 if nullptr)
public:
    explicit CrossArray(int lines);
    CrossArray(const CrossArray &o);
    ~CrossArray();

    bool InsertArrays(const int *Input, int size);
    void AppendArrays(const int *Input, int Line, int size);
    void DoubleCrossLength();
    const int * AtArray(int i);
    int & At(int i, int j);
    CrossArray & WhichGreater(CrossArray &o);
    bool IsSame(const CrossArray &o);
};

// Implementation
inline CrossArray::CrossArray(int lines) : maxLines(lines) {
    arr = new int*[maxLines];
    sizes = new int[maxLines];
    for (int i = 0; i < maxLines; ++i) {
        arr[i] = nullptr;
        sizes[i] = 0;
    }
}

inline CrossArray::CrossArray(const CrossArray &o) : maxLines(o.maxLines) {
    arr = new int*[maxLines];
    sizes = new int[maxLines];
    for (int i = 0; i < maxLines; ++i) {
        if (o.arr[i]) {
            sizes[i] = o.sizes[i];
            arr[i] = new int[sizes[i]];
            std::memcpy(arr[i], o.arr[i], sizeof(int) * sizes[i]);
        } else {
            arr[i] = nullptr;
            sizes[i] = 0;
        }
    }
}

inline CrossArray::~CrossArray() {
    for (int i = 0; i < maxLines; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] sizes;
}

inline bool CrossArray::InsertArrays(const int *Input, int size) {
    for (int i = 0; i < maxLines; ++i) {
        if (!arr[i]) {
            arr[i] = new int[size];
            std::memcpy(arr[i], Input, sizeof(int) * size);
            sizes[i] = size;
            return true;
        }
    }
    return false;
}

inline void CrossArray::AppendArrays(const int *Input, int Line, int size) {
    int oldSize = sizes[Line];
    int newSize = oldSize + size;
    int *newArr = new int[newSize];
    if (oldSize > 0) {
        std::memcpy(newArr, arr[Line], sizeof(int) * oldSize);
    }
    std::memcpy(newArr + oldSize, Input, sizeof(int) * size);
    delete[] arr[Line];
    arr[Line] = newArr;
    sizes[Line] = newSize;
}

inline void CrossArray::DoubleCrossLength() {
    int newMax = maxLines * 2;
    int **newArr = new int*[newMax];
    int *newSizes = new int[newMax];
    for (int i = 0; i < maxLines; ++i) {
        newArr[i] = arr[i];
        newSizes[i] = sizes[i];
    }
    for (int i = maxLines; i < newMax; ++i) {
        newArr[i] = nullptr;
        newSizes[i] = 0;
    }
    delete[] arr;
    delete[] sizes;
    arr = newArr;
    sizes = newSizes;
    maxLines = newMax;
}

inline const int * CrossArray::AtArray(int i) {
    return arr[i];
}

inline int & CrossArray::At(int i, int j) {
    return arr[i][j];
}

inline CrossArray & CrossArray::WhichGreater(CrossArray &o) {
    long long totalThis = 0, totalOther = 0;
    for (int i = 0; i < maxLines; ++i) totalThis += sizes[i];
    for (int i = 0; i < o.maxLines; ++i) totalOther += o.sizes[i];
    if (totalOther > totalThis) return o;
    return *this;
}

inline bool CrossArray::IsSame(const CrossArray &o) {
    return this->arr == o.arr;
}

} // namespace sjtu
