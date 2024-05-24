#ifndef WORDTREE_H
#define WORDTREE_H

#include "AVLNode.h"
#include "AVLNode.hxx"
#include "AVLTree.h"
#include "AVLTree.hxx"
#include "cabeceras.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>

class WordTree {
public:
  keyValue<char, AVLTree<std::string>> tree;

  WordTree();
  WordTree(char sm);
  AVLTree<std::string> getSubTree();
  void insertWord(std::string word);
  bool searchWord(std::string word);
  std::string returnWord(std::string word);
  void printTree();
  std::list<std::string> lookPrefix(std::string prefix);
  std::list<std::string> lookSufix(std::string sufix);
  bool operator==(const WordTree &other) const;
  bool operator!=(const WordTree &other) const;

  bool operator<(const WordTree &other) const {
    return tree.key < other.tree.key;
  }

  bool operator>(const WordTree &other) const {
    return tree.key > other.tree.key;
  }

  WordTree &operator=(const WordTree other) {
    this->tree.key = other.tree.key;
    return *this;
  }

  friend class AVLTree<WordTree>;
  friend class AVLNode<WordTree>;
  friend std::ostream &operator<<(std::ostream &os, const WordTree &other);
};

std::ostream &operator<<(std::ostream &os, const WordTree &other) {
  os << "Key:" << other.tree.key;
  os << "\n Subtree: \n";
  return os;
}

#include "wordTree.hxx"

#endif