#include <iostream>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <utility>
using namespace std;

class Matrix {
    size_t rows, cols;
    int* data;
public:
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(nullptr) {
        if (!r || !c) throw invalid_argument("Matrix dimensions must be positive.");
        data = new int[r * c]{};
    }
    Matrix(const Matrix& other)
        : rows(other.rows), cols(other.cols), data(new int[rows * cols]) {
        copy(other.data, other.data + rows * cols, data);
    }
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            Matrix copyOfOther(other);
            swap(rows, copyOfOther.rows);
            swap(cols, copyOfOther.cols);
            swap(data, copyOfOther.data);
        }
        return *this;
    }
    ~Matrix() { delete[] data; }
    int& at(size_t r, size_t c) {
        if (r >= rows || c >= cols) throw out_of_range("Matrix index out of range.");
        return data[r * cols + c];
    }
    int at(size_t r, size_t c) const {
        if (r >= rows || c >= cols) throw out_of_range("Matrix index out of range.");
        return data[r * cols + c];
    }
    void print() const {
        for (size_t r = 0; r < rows; ++r) {
            for (size_t c = 0; c < cols; ++c) cout << at(r, c) << ' ';
            cout << '\n';
        }
    }
};

int main() {
    Matrix original(2, 2);
    original.at(0, 0) = 1;
    original.at(1, 1) = 4;
    Matrix copied = original;
    copied.at(0, 0) = 99;
    cout << "Original:\n";
    original.print();
    cout << "Deep copy:\n";
    copied.print();
}
