#ifndef MATRIX_H_
#define MATRIX_H_

#include <cmath>
#include <iostream>
#include <random>

#include "exceptions.h"

namespace s21 {

constexpr unsigned int kDefaultRows = 0;
constexpr unsigned int kDefaultColumns = 0;

template <class T>
class Matrix {
 public:
  using size_type = int;
  using value_type = T;
  using reference = Matrix&;
  using const_reference = const Matrix&;
  using rvalue = Matrix&&;
  using self_type = Matrix;

 public:
  // Constructors
  Matrix();
  Matrix(size_type rows, size_type columns);
  Matrix(size_type rows);
  Matrix(size_type rows, size_type columns, value_type default_value);
  Matrix(const_reference other);
  Matrix(rvalue other);
  ~Matrix();
  reference operator=(const_reference other);
  reference operator=(rvalue other);

  // Functions
  void Resize(const size_type rows, const size_type columns);
  void Randomize();
  void Clear();

  void Print() {
    for (size_type i = 0; i < rows_; ++i) {
      for (size_type j = 0; j < columns_; ++j) {
        std::printf("%8.6lf ", values_[i][j]);
      }
      std::cout << std::endl;
    }
  }

  value_type& GetValue(const int i, const int j) { return values_[i][j]; }

  void SetValue(const int i, const int j, const value_type value) {
    values_[i][j] = value;
  }

  // Getters
  size_type GetRows() const;
  size_type GetColumns() const;

  // Overloads
  value_type& operator()(const size_type i, const size_type j);
  value_type& operator()(const size_type i, const size_type j) const;

 private:
  size_type rows_, columns_;
  value_type** values_;

 private:
  void AllocateValues();
  void DeleteValues();
  void Copy(const_reference other);
  void CopyMatrixValues(const_reference src);
  double GenerateRandomNumber();
};

template <typename T>
Matrix<T>::Matrix()
    : rows_(kDefaultRows), columns_(kDefaultColumns), values_(nullptr) {}

template <typename T>
Matrix<T>::Matrix(size_type rows, size_type columns)
    : rows_(rows), columns_(columns) {
  AllocateValues();
}

template <typename T>
Matrix<T>::Matrix(size_type rows) : rows_(rows), columns_(rows) {
  AllocateValues();
}

template <typename T>
Matrix<T>::Matrix(size_type rows, size_type columns, value_type default_value)
    : rows_(rows), columns_(rows) {
  AllocateValues();
  for (size_type i = 0; i < rows_; ++i) {
    for (size_type j = 0; j < columns_; ++j) {
      values_[i][j] = default_value;
    }
  }
}

template <typename T>
Matrix<T>::Matrix(const_reference other) {
  *this = other;
}

template <typename T>
Matrix<T>::Matrix(rvalue other) {
  *this = std::move(other);
}

template <typename T>
Matrix<T>::~Matrix() {
  DeleteValues();
}

template <typename T>
typename Matrix<T>::reference Matrix<T>::operator=(const_reference other) {
  if (this != &other) {
    Copy(other);
  }
  return *this;
}

template <typename T>
typename Matrix<T>::reference Matrix<T>::operator=(rvalue other) {
  if (this != &other) {
    rows_ = other.rows_;
    columns_ = other.columns_;
    values_ = other.values_;
    other.rows_ = kDefaultRows;
    other.columns_ = kDefaultColumns;
    other.values_ = nullptr;
  }
  return *this;
}

template <typename T>
void Matrix<T>::AllocateValues() {
  // if (rows_ == 0 || columns_ == 0) {
  //   throw InvalidMatrixSizes();
  // }
  values_ = new value_type*[rows_];
  for (size_type i = 0; i < rows_; i++) {
    values_[i] = new value_type[columns_]{};
  }

  for (size_type i = 0; i < rows_; ++i) {
    for (size_type j = 0; j < columns_; ++j) {
      values_[i][j] = 0.0;
    }
  }
}

template <typename T>
void Matrix<T>::DeleteValues() {
  if (values_) {
    for (size_type i = 0; i < rows_; ++i) {
      delete[] values_[i];
    }
    delete[] values_;
    values_ = nullptr;
  }
}

template <typename T>
void Matrix<T>::Copy(const_reference other) {
  rows_ = other.rows_;
  columns_ = other.columns_;
  AllocateValues();
  CopyMatrixValues(other);
}

template <typename T>
void Matrix<T>::CopyMatrixValues(const_reference src) {
  for (size_type n = 0; n < rows_ * columns_; n++) {
    size_type i = n / columns_, j = n % columns_;
    values_[i][j] = src.values_[i][j];
  }
}

template <typename T>
T& Matrix<T>::operator()(const size_type i, const size_type j) {
  return values_[i][j];
}

template <typename T>
T& Matrix<T>::operator()(const size_type i, const size_type j) const {
  return values_[i][j];
}

template <typename T>
typename Matrix<T>::size_type Matrix<T>::GetRows() const {
  return rows_;
}

template <typename T>
typename Matrix<T>::size_type Matrix<T>::GetColumns() const {
  return columns_;
}

template <typename T>
void Matrix<T>::Resize(const size_type rows, const size_type columns) {
  DeleteValues();
  rows_ = rows;
  columns_ = columns;
  AllocateValues();
}

template <typename T>
void Matrix<T>::Clear() {
  DeleteValues();
  rows_ = kDefaultRows;
  columns_ = kDefaultColumns;
}

template <typename T>
void Matrix<T>::Randomize() {
  for (size_type i = 0; i < rows_; ++i) {
    for (size_type j = 0; j < columns_; ++j) {
      values_[i][j] = GenerateRandomNumber();
    }
  }
}

template <typename T>
double Matrix<T>::GenerateRandomNumber() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist6(-50, 50);
  return static_cast<double>(dist6(rng)) / 100.0;
}

}  // namespace s21

#endif  // SRC_MATRIX_H_
