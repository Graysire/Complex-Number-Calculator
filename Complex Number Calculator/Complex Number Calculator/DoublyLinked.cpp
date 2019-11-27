#include "pch.h"
#include "DoublyLinked.h"
#include<iostream>

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	size = 0;
	head = NULL;
	tail = NULL;
}

template <class T>
void DoublyLinkedList<T>::addFront(T d)
{
	Node<T>* n;
	n->data = d;
	n->prev = NULL;
	n->next = NULL;
	if (head == NULL)
	{
		head = n;
		if (tail == NULL)
		{
			tail = n;
		}
	}
	else
	{
		n->next = head;
		head->prev = n;
		head = n;
	}

	size++;
}

template<class T>
void DoublyLinkedList<T>::addBack(T d)
{
	Node<T>* n;
	n->data = d;
	n->prev = NULL;
	n->next = NULL;
	if (tail == NULL)
	{
		tail = n;
		if (head == NULL)
		{
			head = n;
		}
	}
	else
	{
		n->prev = tail;
		tail->next = n;
		tail = n;
	}
	size++;
}

template <class T>
void DoublyLinkedList<T>::popFront()
{
	head->next->prev = NULL;
	Node<T>* n = head;
	head = head.next;
	delete n;
	size--;
}

template <class T>
void DoublyLinkedList<T>::popBack()
{
	tail->prev->next = NULL;
	Node<T>* n = tail;
	tail = tail.prev;
	delete n;
	size--;
}

template <class T>
void DoublyLinkedList<T>::addNode(T d, Node<T>* iter)
{
	Node<T>* n;
	n->data = d;
	
	iter->next->prev = n;
	n->next = iter.next;
	iter->next = n;
	n->prev = iter;
	size++;
}

template <class T>
void DoublyLinkedList<T>::deleteNode(T d, Node<T>* iter)
{
	iter->prev->next = iter->next;
	iter->next->prev = iter->prev;
	delete iter;
	size--;
}

template <class T>
Node<T>* DoublyLinkedList<T>::findNode(T d)
{
	Node<T>* n = head;
	for (int i = 0; i < size; i++)
	{
		if (n->data == d)
		{
			return n;
		}
		n = n->next;
	}
	return NULL;
}

template <class T>
int DoublyLinkedList<T>::getSize() const
{
	return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() const
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void DoublyLinkedList<T>::displayList() const
{
	Node<T>* n = head;
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
		{
			std::cout << n->data << ", ";
		}
		else
		{
			std::cout << n->data << endl;
		}
	}
	n = n->next;
}

template <class T>
StackDoublyLinkedList<T>::StackDoublyLinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

template <class T>
T StackDoublyLinkedList<T>::getTop() const
{
	return head->data;
}

template<class T>
void StackDoublyLinkedList<T>::displayStack() const
{
	Node<T>* n = head;
	for (int i = 0; i < size; i++)
	{
		cout << n->data << endl;
	}
	n = n->next;
}