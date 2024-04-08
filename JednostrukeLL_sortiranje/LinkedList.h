#pragma once

#include "Node.h"
#include <iostream>

class LinkedList
{
private:
	Node* head;

public:
	LinkedList(Node* head = nullptr) : head(head) {}
	~LinkedList();

	bool is_empty()
	{
		return head == nullptr;
	}

	void add_to_head(int info);
	void add_to_end(int info);
	bool add_at(int where, int info);

	// menja mesta na ptr i ptr->next
	// prev je prethodni od ptr
	void swap_neighbour(Node* prev, Node* ptr);

	void print()
	{
		Node* tmp = head;
		while (tmp)
		{
			std::cout << tmp->get_info() << " ";
			tmp = tmp->get_link();
		}
		std::cout << "\n";
	}

	void sort_bubble(bool rastuci);
	void sort_selection(bool rastuci);
	void sort_inserion(bool rastuci);
	
};

