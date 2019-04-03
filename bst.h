#ifndef BST_H_
#define BST_H_

#include <iostream>

namespace kapil {
  template <typename T>
  class Node {
    public:
      T data_;
      Node* left_;
      Node* right_;
      Node(const T&) noexcept;
      ~Node();
  };

  template <typename T>
  class BST {
    private:
      Node<T>* root_;
      
    public:
      BST() noexcept;
      ~BST();
      void ShowTreeUtil(Node<T>*) const noexcept;
      void ShowTree() const noexcept;
      void Insert(const T&);
      Node<T>*& SearchUtil(Node<T>*&, const T&);
      bool Search(const T&);
      void Delete(const T&);
      void DeleteUtil(Node<T>*&);
      Node<T>*& GetInorderSuccessor(Node<T>*);
      void DeleteTree(Node<T>*);
  };

  template<typename T>
  Node<T>::Node(const T& data) noexcept : data_{data}, left_{nullptr}, right_{nullptr} {}
  
  template<typename T>
  Node<T>::~Node() {
    left_ = right_ = nullptr;
  }


  // BST
  template<typename T>
  BST<T>::BST() noexcept : root_{nullptr} {}
  
  template<typename T>
  BST<T>::~BST() {
  }

  template<typename T>
  void BST<T>::ShowTreeUtil(Node<T>* p) const noexcept {
    if (!p) {
      return;
    }

    ShowTreeUtil(p->left_);
    std::cout << p->data_ << std::endl;
    ShowTreeUtil(p->right_);
  }
  
  template<typename T>
  void BST<T>::ShowTree() const noexcept {
    std::cout << "Inorder of tree is : \n";
    ShowTreeUtil(root_);
  }
  
  template<typename T>
  void BST<T>::Insert(const T& data) {
    Node<T>*& res = SearchUtil(root_, data);

    if (!res) {
      res = new Node<T>{data};
    }
  }
  
  template <typename T>
  Node<T>*& BST<T>::SearchUtil(Node<T>*& p, const T& data) {
    if (!p) {
      return p;
    }

    if (data == p->data_) {
      return p;
    }

    if (data < p->data_) {
      SearchUtil(p->left_, data);
    } else {
      SearchUtil(p->right_, data);
    }
  }

  template <typename T>
  bool BST<T>::Search(const T& data) {
    Node<T>* p = SearchUtil(root_, data);
    return p != nullptr;
  }

  template <typename T>
  void BST<T>::Delete(const T& data) {
    Node<T>*& ref = SearchUtil(root_, data);

    if (!ref) {
      return;
    }
    DeleteUtil(ref);
  }

  template <typename T>
  void BST<T>::DeleteUtil(Node<T>*& ref) {
    if (!ref->left_ && !ref->right_) {
      delete ref;
      ref = nullptr;
    } else if (ref->left_ && !ref->right_) {
      Node<T>* tmp = ref;
      ref = ref->left_;
      delete tmp;
    } else if (!ref->left_ && ref->right_) {
      Node<T>* tmp = ref;
      ref = ref->right_;
      delete tmp;
    } else {
      Node<T>*& inorder_successor = GetInorderSuccessor(ref);
      ref->data_ = inorder_successor->data_;
      DeleteUtil(inorder_successor);
    }
  }

  template <typename T>
  Node<T>*& BST<T>::GetInorderSuccessor(Node<T>* ref) {
    Node<T>* tmp = ref;

    if (!ref->right_->left_) {
      return ref->right_;
    }

    tmp = ref->right_;

    while (tmp->left_->left_) {
      tmp = tmp->left_;
    }

    return tmp->left_;
  }

  template<typename T>
  void BST<T>::DeleteTree(Node<T>* p) {
  }
} // namespace kapil

#endif // BST_H_
