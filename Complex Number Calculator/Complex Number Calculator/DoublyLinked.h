#pragma once
#ifndef DOUBLYLINKED
#define DOUBLYLINKED

template<class T>
struct Node
{
	T data; //data of the node
	Node* prev;// pointer to previous node
	Node* next; //pointer to next node

};

template <class T>
class DoublyLinkedList
{
protected:
	Node<T>* head; //pointer to first node
	Node<T>* tail; //pointer to last node
	int size; //size of the list
public:
	DoublyLinkedList();
	void addFront(T d); //add node to beginning of the list
	void popFront(); //remove node from the beginning of the list
	void addBack(T d); //add node to end of the list
	void popBack(); //remove a node at the end of the list
	void addNode(T d, Node<T>* iter); //add a node anywhere
	void deleteNode(T d, Node<T>* iter); //remove a node anywhere
	Node<T>* findNode(T d); //return a pointer to a node, return NULL otherwise
	int getSize() const; //returns size of the list
	bool isEmpty() const; //return true if empty
	void displayList() const; //display the list
};

template<class T>
class StackDoublyLinkedList : public DoublyLinkedList<T>
{
public:
	StackDoublyLinkedList();
	void displayStack() const; //display stack
	T getTop() const; //return element at the top of the stack
};

#endif // !DOUBLYLINKED
