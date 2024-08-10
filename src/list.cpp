#include <iostream>
#include <string>

#include <list.hpp>

template <typename T> Node<T>::Node(std::initializer_list<T> data) {
  this->data = *data.begin();
  auto it = data.begin();
  ++it;
  for (; it != data.end(); ++it) {
    this->append(*it);
  }
}

template <typename T> void Node<T>::append(T data) {
  if (!next) {
    next = std::make_unique<Node<T>>(data);
  } else {
    Node<T> *temp = next.get();
    while (temp->next) {
      temp = temp->next.get();
    }
    temp->next = std::make_unique<Node<T>>(data);
  }
}

template <typename T> void Node<T>::print() const {
  std::cout << "[" << data;
  Node<T> *temp = next.get();
  while (temp) {
    std::cout << ", " << temp->data;
    temp = temp->next.get();
  }
  std::cout << "]\n";
}

template <typename T> void Node<T>::insert(T data, std::size_t index) {
  Node<T> *temp = this;
  std::size_t i = 0;
  while (temp->next && i + 1 != index) {
    temp = temp->next.get();
    ++i;
  }
  if (i + 1 == index) {
    auto newNode = std::make_unique<Node<T>>(data);
    newNode->next = std::move(temp->next);
    temp->next = std::move(newNode);
  }
}

template <typename T> void Node<T>::remove(std::size_t index) {
  Node<T> *temp = this;
  std::size_t i = 0;
  while (temp->next && i + 1 < index) {
    temp = temp->next.get();
    ++i;
  }
  if (i + 1 == index && temp->next) {
    temp->next = std::move(temp->next->next);
  }
}

template <typename T> void Node<T>::remove_data(T data) {
  Node<T> *temp = this;
  while (temp->next) {
    if (temp->next->data == data) {
      temp->next = std::move(temp->next->next);
      break;
    }
    temp = temp->next.get();
  }
}

template class Node<int>;
template class Node<float>;
template class Node<double>;
template class Node<std::string>;


