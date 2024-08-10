#pragma once
#include <initializer_list>
#include <memory>

template <typename T> class Node {
public:
  T data;
  std::unique_ptr<Node<T>> next;

  Node(T data) : data(data), next(nullptr) {}
  Node(std::initializer_list<T> data);

  void append(T data);
  void print() const;
  void insert(T data, std::size_t index);
  void remove(std::size_t index);
  void remove_data(T data);
};


