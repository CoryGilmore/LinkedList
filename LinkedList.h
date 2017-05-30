#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
	//leaving off here

	template <class T>
	class Node
	{
		/*The friend keyword allows the LinkedList class to access
		the private data members of the Node class*/
		friend class LinkedList;

	public:

		//Default Constructor
		Node() {}
		//Overload Constructor
		Node(T _data)
		{
			data = _data;
			next = nullptr;
		}
		//Destructor
		~Node() {}
	
	private:
		T data;
		Node<T> *next;
	};

public:
	//Default Constructor
	LinkedList(void)
	{
		head = tail = nullptr;
		currentSize = 0;
	}
	//Destructor
	~LinkedList(){}

	int getCurrentSize() { return currentSize; }
	
	void addFirst(T data)
	{
		Node<T> *node = new Node<T>(data);
		node->next = head;
		head = node;
		
		if (tail == nullptr)
		{
			tail = node;
		}
		currentSize++;

	}
	
	void addLast(T data) 
	{
		Node<T> *node = new Node<T>(data);
		//If the list is empty
		if (head == nullptr)
		{
			head = tail = node;
			currentSize++;
			return;
		}

		tail->next = node;
		tail = node;
		currentSize++;
	}
	void removeFirst()
	{
		//if the list is empty
		if (head == nullptr)
		{
			cout << "List is empty";
			return;
		}

		//if the list only has one element
		if (head == tail)
			head = tail = nullptr;
		else // More than one element in list
			head = head->next;
	
		currentSize--;

	}
	void removeLast()
	{
		//if the list is empty
		if (head == nullptr)
		{
			cout << "List is empty";
			return;
		}
		//if the list only contains one element
		if (head == tail)
		{
			head = tail = nullptr;
			currentSize--;
			return;
		}
			
		//set up previous and current pointers to traverse the list
		Node<T> *previous = nullptr, *current = head;
		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}

        /*
		current now points to the last element in the list, while previous points
		to the element just before it. Previous will become the new last element,
		and current will be cut off
		*/

		previous->next = nullptr;
		tail->next = previous;
		tail = previous;
		currentSize--;

	}
	bool isEmpty()
	{
		return currentSize == 0;
	}
	void printList()
	{
		Node<T> *tmp = head;
		if (head == nullptr)
		{
			cout << "Empty List" << endl;
			return;
		}
		while (tmp != nullptr)
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
	}

	void makeEmpty()
	{
		head = tail = nullptr;
		currentSize = 0;
	}

private:
	Node<T> *head, *tail;
	int currentSize;

};

#endif


