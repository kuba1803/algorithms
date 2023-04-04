//
// Created by Jakub on 01.04.2023.
//

#ifndef ALGORITHMS_MATRIX_H
#define ALGORITHMS_MATRIX_H

#include <cstddef>
#include <initializer_list>
#include <vector>
#include <algorithm>

namespace MATHEMATICAL {
    template<typename T, typename Container = std::vector<T>>
    class Matrix {
    private:
        std::vector<T> vector;
        size_t columnNumber;
        size_t rowNumber;

    public:
#pragma region types

        typedef T value_type;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef T &reference;
        typedef const T &const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

#pragma endregion types

#pragma region constructors

        Matrix(size_type rowNumber, size_type columnNumber) : rowNumber(rowNumber), columnNumber(columnNumber),
                                                              vector(columnNumber * rowNumber) {
        }

        template<typename Function>
        Matrix(Function &function, size_type rowNumber, size_type columnNumber): rowNumber(rowNumber),
                                                                                 columnNumber(columnNumber),
                                                                                 vector(columnNumber * rowNumber) {
            for (size_type col = 0; col < columnNumber; col++) {
                for (size_type row = 0; row < rowNumber; row++) {
                    vector[row * columnNumber + col] = std::move(function(col, row));
                }
            }
        }

        Matrix(std::initializer_list<std::initializer_list<T>> init) : rowNumber(init.size()),
                                                                       columnNumber(init.begin()->size()),
                                                                       vector(columnNumber * rowNumber) {
            size_type countItem = 0;
            for (auto &row: init) {
                for (auto &item: row) {
                    vector[countItem++] = std::move(item);
                }
            }
        }

        template<typename Function>
        Matrix(Function &function, size_type rowStart, size_type rowEnd, size_type colStart, size_type colEnd)
                : rowNumber(rowEnd - rowStart + 1),
                  columnNumber(colEnd - rowStart + 1),
                  vector(columnNumber * rowNumber) {
            size_type rowNum = 0;
            size_type colNum = 0;
            for (size_type col = colStart; col <= colEnd; col++) {
                colNum = 0;
                for (size_type row = rowStart; row <= rowEnd; row++) {
                    vector[rowNum * columnNumber + colNum] = std::move(function(col, row));
                    colNum++;
                }
                rowNum++;
            }
        }

        Matrix(const Matrix &matrix) : rowNumber(matrix.rowNumber), columnNumber(matrix.columnNumber),
                                       vector(matrix.vector) {
        }

        Matrix(Matrix &&matrix) : rowNumber(std::move(matrix.rowNumber)), columnNumber(std::move(matrix.columnNumber)),
                                  vector(std::move(matrix.vector)) {

        }

#pragma endregion constructors

#pragma region destructor

        ~Matrix() {
            delete[] vector;
        }

#pragma endregion destructor

#pragma region operator=

        Matrix &operator=(const Matrix &matrix) {
            rowNumber = matrix.rowNumber;
            columnNumber = matrix.columnNumber;
            vector = matrix.vector;
        }

        Matrix &operator=(Matrix &&matrix) {
            delete[] vector;
            rowNumber = std::move(matrix.rowNumber);
            columnNumber = std::move(matrix.columnNumber);
            vector = std::move(matrix.vector);
        }

#pragma endregion operator=

#pragma region access

        reference operator[](size_type row, size_type col) {
            return vector[row * columnNumber + col];
        }

        reference at(size_type row, size_type col) {
            if (row < 0 || row >= rowNumber) throw std::out_of_range("");
            if (col < 0 || col >= columnNumber) throw std::out_of_range("");
            return vector[row * columnNumber + col];
        }

#pragma endregion access

#pragma region operations

        Matrix &operator+=(const Matrix &matrix) {
            if (columnNumber != matrix.columnNumber || rowNumber != matrix.columnNumber)
                throw std::invalid_argument("");
            for (int i = 0; i < vector.size(); i++) {
                vector[i] += matrix.vector[i];
            }
            return *this;

        }

        Matrix operator+(const Matrix &matrix) {
            if (columnNumber != matrix.columnNumber || rowNumber != matrix.columnNumber)
                throw std::invalid_argument("");
            Matrix temp_matrix = *this;
            temp_matrix += matrix;
            return std::move(temp_matrix);
        }

        Matrix &operator-=(const Matrix &matrix) {
            if (columnNumber != matrix.columnNumber || rowNumber != matrix.columnNumber)
                throw std::invalid_argument("");
            for (int i = 0; i < vector.size(); i++) {
                vector[i] -= matrix.vector[i];
            }
            return *this;
        }

        Matrix operator-(const Matrix &matrix) {
            if (columnNumber != matrix.columnNumber || rowNumber != matrix.columnNumber)
                throw std::invalid_argument("");
            Matrix temp_matrix = *this;
            temp_matrix -= matrix;
            return std::move(temp_matrix);
        }

        Matrix &operator*=(const T &value) {
            for (int i = 0; i < vector.size(); i++) {
                vector[i] *= value;
            }
            return *this;
        }

        Matrix operator*(const T &value) {
            Matrix temp_matrix = *this;
            temp_matrix *= value;
            return std::move(temp_matrix);
        }

        void transposition() {
            bool moreRow = (columnNumber > rowNumber);
            size_type tempRowNumber = columnNumber;
            size_type tempColNumber = rowNumber;
            if (columnNumber > rowNumber) {
                for (size_type col = 0; col < columnNumber; col++) {
                    for (size_type row = col; row < rowNumber; row++) {
                        if (col == row) continue;
                        std::swap(vector[row * columnNumber + col], vector[col * rowNumber + row]);
                    }
                }
            } else {
                for (size_type row = 0; row < rowNumber; row++) {
                    for (size_type col = row; col < columnNumber; col++) {
                        if (col == row) continue;
                        std::swap(vector[row * columnNumber + col], vector[col * rowNumber + row]);
                    }
                }
            }
            std::swap(columnNumber, rowNumber);
        }

        Matrix &operator*=(const Matrix &matrix) {
            if (columnNumber != matrix.rowNumber)
                throw std::invalid_argument("");
            std::vector<T> temp(rowNumber * matrix.columnNumber);
            for (size_type row = 0; row < rowNumber; row++) {
                for (size_type col = 0; col < matrix.columnNumber; col++) {
                    for (int i = 0; i < columnNumber; i++) {
                        temp[row * matrix.columnNumber + col] =
                                vector[row * columnNumber + i] * matrix.vector[i * matrix.columnNumber + col];
                    }
                }
            }
            columnNumber = matrix.columnNumber;
            vector = std::move(temp);
            return *this;
        }

        Matrix operator*(const Matrix matrix) {
            Matrix temp_matrix = *this;
            temp_matrix *= matrix;
            return std::move(temp_matrix);
        }

#pragma region operations

    };

    template<typename Function, typename ValT = typename std::result_of<Function>::type>
    Matrix(Function &function, size_t rowNumber, size_t columnNumber) -> Matrix<ValT>;

    template<typename T>
    Matrix<T> operator*(const T &value, const Matrix<T> matrix) {
        Matrix<T> temp = matrix;
        return std::move(matrix += value);
    }
}
#endif //ALGORITHMS_MATRIX_H
