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
	DoublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	void addFront(T d) //add node to beginning of the list
	{
		Node<T>* n = new Node<T>;
		n->data = d;
		n->prev = nullptr;
		n->next = nullptr;
		if (head == nullptr)
		{
			head = n;
			if (tail == nullptr)
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
		//std::cout << n->data << " added" << std::endl;

		size++;
		//std::cout << "size: " << size << std::endl;
	}
	void popFront() //remove node from the beginning of the list
	{
		Node<T>* n = head;
		//std::cout << n->data << " deleted " << std::endl;
		if (head->next != nullptr)
		{
			head->next->prev = nullptr;
			head = head->next;
			delete n;
		}
		else
		{
			head = nullptr;
			delete n;
		}
		
		
		size--;
		//std::cout << "size: " << size << std::endl;
	}
	void addBack(T d) //add node to end of the list
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
	void popBack() //remove a node at the end of the list
	{
		tail->prev->next = nullptr;
		Node<T>* n = tail;
		tail = tail.prev;
		delete n;
		size--;
	}
	void addNode(T d, Node<T>* iter) //add a node anywhere
	{
		Node<T>* n;
		n->data = d;

		iter->next->prev = n;
		n->next = iter.next;
		iter->next = n;
		n->prev = iter;
		size++;
	}
	void deleteNode(T d, Node<T>* iter) //remove a node anywhere
	{
		iter->prev->next = iter->next;
		iter->next->prev = iter->prev;
		delete iter;
		size--;
	}
	Node<T>* findNode(T d) //return a pointer to a node, return NULL otherwise
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
		return nullptr;
	}
	int getSize() const //returns size of the list
	{
		return size;
	}
	bool isEmpty() const //return true if 
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
	void displayList() const //display the list
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
				std::cout << n->data << std::endl;
			}
			n = n->next;
		}
		
	}
};

template<class T>
class StackDoublyLinkedList : public DoublyLinkedList<T>
{
public:
	StackDoublyLinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	void displayStack() const //display stack
	{
		Node<T>* n = this->head;
		for (int i = 0; i < this->size; i++)
		{
			std::cout << n->data << std::endl;
			n = n->next;
		}
		
	}
	T getTop() const //return and pop element at the top of the stack
	{
		return this->head->data;
	}
};

#endif // !DOUBLYLINKED
