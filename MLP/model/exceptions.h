#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

namespace s21 {

class FileDoesNotExists : public std::exception {
 public:
  const char *what() const throw() { return "File does not exists"; }
};

class InvalidMatrixSizes : public std::exception {
 public:
  const char *what() const throw() { return "Invalid matrix sizes"; }
};

class InvalidVertexIndex : public std::exception {
 public:
  const char *what() const throw() { return "Invalid vertex index"; }
};

class InvalidGraphFile : public std::exception {
 public:
  const char *what() const throw() { return "Invalid graph file"; }
};

class InvalidInput : public std::exception {
 public:
  const char *what() const throw() { return "Invalid input"; }
};

class DisconnectedGraph : public std::exception {
 public:
  const char *what() const throw() { return "Disconnected graph"; }
};

class PathDoesNotExists : public std::exception {
 public:
  const char *what() const throw() { return "Path does not exists"; }
};

}  // namespace s21

#endif  // EXCEPTIONS_H_
