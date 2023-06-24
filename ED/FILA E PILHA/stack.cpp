#ifndef STACK_CPP
#define STACK_CPP

#include "stack.h"
#include <stdexcept>

template <typename T> Stack<T>::Stack() {
  m_top = nullptr;
  m_size = 0;
}

template <typename T> Stack<T>::Stack(Stack<T> &lst) {
  m_top = nullptr;
  m_size = 0;
  Node<T> *current = lst.m_top;
  while (current != nullptr) {
    push(current->value);
    current = current->next;
  }
}

template <typename T> Stack<T>::~Stack() { 
  clear(); 
}

template <typename T> int Stack<T>::size() {
   return m_size; 
}

template <typename T> bool Stack<T>::empty() { 
  return !m_size; 
}

template <typename T> void Stack<T>::clear() {
  while (!empty()) {
    pop();
  }
}

template <typename T> void Stack<T>::push(T value) {
  Node<T> *newNode = new Node<T>(value, m_top);
  m_top = newNode;
  m_size++;
}

template <typename T> T Stack<T>::pop() {
  if (empty()) {
    throw std::runtime_error("Empty stack.");
  }
  Node<T> *temp = m_top;
  T value = temp->getValue();
  m_top = m_top->getNext();
  delete temp;
  m_size--;
  return value;
}

template <typename T> T Stack<T>::top() {
  if (empty()) {
    throw std::runtime_error("Empty stack.");
  }
  return m_top->getValue();
}

#endif