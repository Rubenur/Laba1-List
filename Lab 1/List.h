#pragma once

class Singly_Linked_List
{
public:
	Singly_Linked_List(int data);
	Singly_Linked_List();
	~Singly_Linked_List();

	void push_back(int data);			// 1 \\ add to the end of the list
	void push_front(int data);			// 2 \\ add to the beginning of the list
	void pop_back();					// 3 \\ remove the last element
	void pop_front();					// 4 \\ remove the first element
	void insert(int data, size_t pos);  // 5 \\ adding an element by index
	int at(size_t pos);					// 6 \\ get the element by index.
	void remove(size_t pos);			// 7 \\ remove element by index
	size_t get_size();					// 8 \\ get the size of the list
	void print_to_console();			// 9 \\ output list items to the console through a separator, do not use at
	void clear();						// 10 \\ remove all list element
	void set(size_t pos, int data);		// 11 \\ replace the element by index with the passed element
	bool isEmpty();						// 12 \\ check if the list is empty
	void reverse();						// 13 \\ changes the order of the items in the list

private:
	struct Node // Node List
	{
		Node(int data = 0, Node* prev = nullptr, Node* next = nullptr)
		{
			this->next = next;
			this->data = data;
		};
		int data;
		Node* next; // next element
	};
	size_t sizeList;
	Node* head;
};