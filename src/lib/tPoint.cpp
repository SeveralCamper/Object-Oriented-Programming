#include "tPoint.h"

template <typename T>
void List<T>::appendNode(const T& nodeValueAdress) {
    *Node node = new Node(nodeValueAdress);
    node->next = head;
    head = node;
}

template <typename T>
void List<T>::removeNode() {
    if (head) {
      Node *newHead = head->next;
      delete head;
      head = newHead
    }
}

template <typename T>
void List<T>::printNodeValue() {
  std::cout << T List<T>::getValueNode() << std::endl;
}

template <typename T>
  size_t List<T>::getSize() const {
    size_t s = 0;
    for( Iterator it = begin(); it != end(); ++it ) {
        ++s;
    }
  return s;
}

template <typename T>
bool List<T>::equals(const List& other, Node* node) const {
  if( this == &other ) {
    return true;
  }
  return node == other.node;
}

template <typename T>
bool List<T>::notEquals(const List& other, Node* node) const {
  return !operator==(other);
  }

template <typename T>
void List<T>::moveToNextNode(Node* node) {
  if (m_node) {
    m_node = m_node->m_next;
  }
}

template <typename T>
T List<T>::getValueNode(Node* node) const {
  if (m_node) {
    return m_node->m_t;
  }
  return T();
}