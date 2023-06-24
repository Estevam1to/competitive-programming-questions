#include "binarytree.h"
#include <iostream>
#include <string>
#include<queue>
using namespace std;

template <typename T> void bt_pre_ordem_aux(Node<T> *node) {
  if (node == nullptr)
    return;
  cout << node->getValue() << " ";
  bt_pre_ordem_aux(node->getLeft());
  bt_pre_ordem_aux(node->getRight());
}

template <typename T> void bt_pre_ordem(BinaryTree<T> &bt) {
  Node<T> *node = bt.getRoot();
  bt_pre_ordem_aux(node);
}

template <typename T> void bt_pos_ordem_aux(Node<T> *node) {
  if (node == nullptr)
    return;
  bt_pos_ordem_aux(node->getLeft());
  bt_pos_ordem_aux(node->getRight());
  cout << node->getValue() << " ";
}

template <typename T> void bt_pos_ordem(BinaryTree<T> &bt) {
  Node<T> *node = bt.getRoot();
  bt_pos_ordem_aux(node);
}

template <typename T> void bt_ordem_simetrica_aux(Node<T> *node) {
  if (node == nullptr)
    return;

  bt_ordem_simetrica_aux(node->getLeft());
  cout << node->getValue() << " ";
  bt_ordem_simetrica_aux(node->getRight());
}

template <typename T> void bt_ordem_simetrica(BinaryTree<T> &bt) {
  Node<T> *root = bt.getRoot();
  bt_ordem_simetrica_aux(root);
}

template <typename T> void bt_percurso_largura(BinaryTree<T> &bt) {
  Node<T> *node = bt.getnode();
  if (node == nullptr)
    return;

  queue<Node<T> *> q;
  q.push(node);

  while (!q.empty()) {
    Node<T> *u = q.front();
    q.pop();

    cout << u->getValue() << " ";

    if (u->getLeft() != nullptr)
      q.push(u->getLeft());

    if (u->getRight() != nullptr)
      q.push(u->getRight());
  }
}

template <typename T> void execute_all(BinaryTree<T> &bt) {
  bt_pre_ordem(bt);
  bt_pos_ordem(bt);
  bt_ordem_simetrica(bt);
  bt_percurso_largura(bt);
}

int main() {
  Node<int> *no9 = new Node<int>(9, nullptr, nullptr);
  Node<int> *no1 = new Node<int>(1, nullptr, no9);
  Node<int> *no6 = new Node<int>(6, nullptr, nullptr);
  Node<int> *no7 = new Node<int>(7, no1, no6);

  Node<int> *no4 = new Node<int>(4, nullptr, nullptr);
  Node<int> *no8 = new Node<int>(8, no4, nullptr);
  Node<int> *no3 = new Node<int>(3, nullptr, nullptr);
  Node<int> *no5 = new Node<int>(5, no3, no8);

  Node<int> *no2 = new Node<int>(2, no5, no7);

  BinaryTree<int> bt;
  bt.setRoot(no2);
  execute_all(bt);

  return 0;
}
