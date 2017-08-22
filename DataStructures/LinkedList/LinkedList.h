#include <iostream>

template <class T>
class Node {
    private:
        T data;
        Node* nextNode = nullptr;
        Node* prevNode = nullptr;
    public:
        Node(T data);
        ~Node();

        T getData();
        void setData(T);

        Node* getNextNode();
        void setNextNode(Node*);

        Node* getPrevNode();
        void setPrevNode(Node*);
};

template <class T>
Node<T>::Node(T data) {
    this->data = data;
}

template <class T>
Node<T>::~Node() {
    std::cout << std::endl << "I have been deleted" << std::endl;
}

template <class T>
T Node<T>::getData() {
    return data;
}

template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template <class T>
Node<T>* Node<T>::getNextNode() {
    return nextNode;
}

template <class T>
void Node<T>::setNextNode(Node* nextNode) {
    this->nextNode = nextNode;
}

template <class T>
Node<T>* Node<T>::getPrevNode() {
    return prevNode;
}

template <class T>
void Node<T>::setPrevNode(Node* prevNode) {
    this->prevNode = prevNode;
}

template <class T>
class LinkedList {
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int elements = 0;
    public:
        void insertLast(T);
        void insertFirst(T);
        void insertAt(T, int);
        void removeLast();
        void removeFirst();
        void removeAt(int);
        void print();
        void reverse();
        void clear();
        int size();
};

template <class T>
void LinkedList<T>::insertLast(T newElement) {
    Node<T> *newNode = new Node<T>(newElement);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNextNode(newNode);
        newNode->setPrevNode(tail);
        tail = newNode;
    }
    
    elements++;
}

template <class T>
void LinkedList<T>::insertAt(T newElement, int index) {
    Node<T> *newNode = new Node<T>(newElement);
    Node<T> *currPtr = head;

    if (index > elements) {
        insertLast(newElement);
        return;
    }

    if (index <= 0) {
        newNode->setNextNode(head);
        head = newNode;
        return;
    }

    for (int i = 0; i < index - 1; i++) {
        currPtr = currPtr->getNextNode(); 
    }

    newNode->setNextNode(currPtr->getNextNode());
    newNode->setPrevNode(currPtr);
    currPtr->getNextNode()->setPrevNode(newNode);
    currPtr->setNextNode(newNode);

    elements++;
}

template <class T>
void LinkedList<T>::insertFirst(T newElement) {
    inserAt(newElement, 0);
}

template <class T>
void LinkedList<T>::removeFirst() {
    Node<T> *currPtr = head;
    head = head->getNextNode();
    delete currPtr;

    elements--;
}

template <class T>
void LinkedList<T>::removeAt(int index) {
    Node<T> *currPtr = head;

    if (index > elements - 1) {
        removeLast();
        return;
    }

    if (index <= 0) {
        removeFirst();
        return;
    }

    for (int i = 0; i < index - 1; i++) {
        currPtr = currPtr->getNextNode(); 
    }

    Node<T> *oneAfterDeletedNode = currPtr->getNextNode()->getNextNode();
    currPtr->setNextNode(oneAfterDeletedNode);
    delete oneAfterDeletedNode->getPrevNode();
    oneAfterDeletedNode->setPrevNode(currPtr);

    elements--;
}

template <class T>
void LinkedList<T>::removeLast() {
    tail = tail->getPrevNode();
    delete tail->getNextNode();
    tail->setNextNode(nullptr);

    elements--;
}

template <class T>
void LinkedList<T>::print() {
    Node<T> *currPtr = head;
    if (currPtr == nullptr) {
        return;
    } else {
        std::cout << currPtr->getData() << " ";
        while (currPtr->getNextNode() != nullptr) {
            currPtr = currPtr->getNextNode();
            std::cout << currPtr->getData() << " ";
        } 
    }
}

template <class T>
int LinkedList<T>::size() {
    return elements;
}

template <class T>
void LinkedList<T>::clear() {
   Node<T> *currPtr = head;
   Node<T> *nextPtr = head->getNextNode();

   while(currPtr != nullptr) {
        delete currPtr;
        currPtr = nextPtr;
        if (currPtr == nullptr) break;
        nextPtr = nextPtr->getNextNode(); 
   }
   elements = 0;
}

