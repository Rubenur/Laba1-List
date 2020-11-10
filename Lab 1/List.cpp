#include <iostream>
#include "List.h"

Singly_Linked_List::Singly_Linked_List(int data)
{
	head = new Node;
	head->data = data;
	sizeList++;
}

Singly_Linked_List::Singly_Linked_List()
{
	head = NULL;
	sizeList = 0;
}

Singly_Linked_List::~Singly_Linked_List()
{
	clear();
}

void Singly_Linked_List::push_back(int data) // 1 \\ add to the end of the list
{
	if (isEmpty() == true)
	{
		head = new Node;
		head->data = data;
		sizeList++;
	}
	else
	{
		Node* current = this->head;

		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node(data);
		sizeList++;
	}
}

void Singly_Linked_List::push_front(int data) // 2 \\ add to the beginning of the list
{
	if (isEmpty() == true)
	{
		head = new Node;
		head->data = data;
		sizeList++;
	}
	else
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
		sizeList++;
	}
}

void Singly_Linked_List::pop_back() // 3 \\ remove the last element
{
	if (isEmpty() == true)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		Node* current = this->head;
		if (current->next == nullptr)
		{
			clear();
			return;
		}
	    while (current->next->next != nullptr)
		{
			current = current->next;
		}
		delete current->next;
		current->next = NULL;
		sizeList--;
		std::cout << "The last element was deleted" << std::endl;
	}
}

void Singly_Linked_List::pop_front() // 4 \\ remove the first element
{
	if (isEmpty() == true)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		sizeList--;
		std::cout << "The first element was deleted" << std::endl;
	}
}

void Singly_Linked_List::insert(int data, size_t pos) // 5 \\ adding an element by index
{
	if (isEmpty() == true)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		if ((pos > get_size()+1) || (pos < 1))
		{
			std::cout << "Element does not exist!" << std::endl;
		}
		else
		{
			if (pos == 1)
			{
				push_front(data);
			}
			else
			{
				if (pos == get_size()+1)
				{
					push_back(data);
				}
				else
				{
					Node* current = this->head;
					for (size_t i = 1; i != pos - 1; i++)
					{
						current = current->next;
					}
					Node* temp = current->next;
					current->next = new Node(data);
					current->next->next = temp;
					sizeList++;
				}
			}
		}
	}
}

int Singly_Linked_List::at(size_t pos) // 6 \\ get the element by index.
{
	if (isEmpty() == true)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		if ((pos > get_size()) || (pos < 1))
		{
			std::cout << "Element does not exist!" << std::endl;
		}
		else
		{
			Node* current = this->head;

			for (size_t i = 1; i != pos; i++)
			{
				current = current->next;
			}
			return current->data;
		}
	}
}

void Singly_Linked_List::remove(size_t pos) // 7 \\ remove element by index
{
	if (isEmpty() == true)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		if ((pos > get_size()) || (pos < 1))
		{
			std::cout << "Element does not exist!" << std::endl;
		}
		else
		{
			if (pos == 1)
			{
				pop_front();
			}
			else
			{
				Node* current = this->head;
				for (size_t i = 1; i < pos - 1; i++)
				{
					current = current->next;
				}
				Node* temp = current->next->next;
				delete current->next;
				current->next = temp;
				sizeList--;
			}
		}
	}
}

size_t Singly_Linked_List::get_size() // 8 \\ get the size of the list
{
	return (sizeList);
}

void Singly_Linked_List::print_to_console() // 9 \\ output list items to the console through a separator, do not use at
{
	if (isEmpty() == true)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		Node* current = this->head;
		int i = 1;
		int temp = get_size();
		std::cout << "List: ";
		while (current != nullptr)
		{
			if (i == temp)
			{
				std::cout << current->data << std::endl;
			}
			else
			{
				std::cout << current->data << " | ";
			}
			current = current->next;
			i++;
		}
		std::cout << "Total number of elements:" << temp << std::endl;
		std::cout << std::endl;
	}
}

void Singly_Linked_List::clear() // 10 \\ remove all list element
{
	if (isEmpty() == true)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		Node* current = this->head;

		while (current != nullptr)
		{
			Node* temp = current;
			current = current->next;
			delete temp;
		}
		sizeList = 0;
		head = NULL;
		std::cout << "The list was cleared!" << std::endl;
	}
}

void Singly_Linked_List::set(size_t pos, int data) // 11 \\ replace the element by index with the passed element
{
	if (isEmpty() == true)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		if ((pos > get_size()) || (pos < 1))
		{
			std::cout << "Element does not exist!" << std::endl;
		}
		else
		{
			Node* current = this->head;
			for (size_t i = 1; i < pos; i++)
			{
				current = current->next;
			}
			current->data = data;
		}
	}
}

bool Singly_Linked_List::isEmpty() // 12 \\ check if the list is empty
{
	return (head == NULL);
}

void Singly_Linked_List::reverse() // 13 \\ changes the order of the items in the list
{
	if (isEmpty() == true)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		for (int i = 1; i < get_size(); i++)
		{
			Node* current = this->head;
			for (size_t j = 1; j < i; j++)
			{
				current = current->next;
			}
			Node* temp = current->next->next;
			int temp_data = current->next->data;
			//push_front(current->data);
			delete current->next;
			current->next = temp;
			sizeList--;
			push_front(temp_data);
			std::cout << "The list was reversed" << std::endl;
		}
	}
}