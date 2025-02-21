#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> elements;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols), elements(rows, vector<int>(cols, 0)) {}

    int getRows() const {
        return rows;
    }

    int getColumns() const {
        return cols;
    }

    int getElement(int i, int j) const {
        return elements[i][j];
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            elements[i][j] = value;
        }
    }

    Matrix add(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices cannot be added");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, getElement(i, j) + other.getElement(i, j));
            }
        }
        return result;
    }

    Matrix multiply(const Matrix &other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrices cannot be multiplied");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += getElement(i, k) * other.getElement(k, j);
                }
                result.setElement(i, j, sum);
            }
        }
        return result;
    }

    void print() const {
        for (const auto &row : elements) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix A(2, 2);
    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(1, 0, 3);
    A.setElement(1, 1, 4);

    Matrix B(2, 2);
    B.setElement(0, 0, 5);
    B.setElement(0, 1, 6);
    B.setElement(1, 0, 7);
    B.setElement(1, 1, 8);

    cout << "Matrix A:" << endl;
    A.print();
    cout << "Matrix B:" << endl;
    B.print();

    Matrix C = A.add(B);
    cout << "A + B:" << endl;
    C.print();

    Matrix D = A.multiply(B);
    cout << "A * B:" << endl;
    D.print();

    return 0;
}
