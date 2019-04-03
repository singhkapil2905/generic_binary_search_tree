#include "bst.h"
#include <iostream>

int main() {
  kapil::BST<int> b;

  int ch;
  int el;

  while (1) {
    std::cout << "Enter ch : \n [1] Insert \n [2] Search \n [3] Delete \n [4] Show Tree \n";
    std::cin >> ch;

    switch (ch) {
      case 1:
        std::cout << "Enter the element to insert : \n";
        std::cin >> el;
        b.Insert(el);
        break;
      case 2:
        std::cout << "Enter the element to be searched : \n";
        std::cin >> el;
        if (b.Search(el)) {
          std::cout << "Element found \n";
        } else {
          std::cout << "Element not found \n";
        }
        break;
      case 3:
        std::cout << "Enter the elemet to be deleted : \n";
        std::cin >> el;
        b.Delete(el);
        break;
      case 4:
        b.ShowTree();
        break;
      default:
        return 0;
    }
  }
  return 0;
}
