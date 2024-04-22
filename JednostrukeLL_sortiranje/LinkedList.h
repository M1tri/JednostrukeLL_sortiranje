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

	// Standarne fnje za LL
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

	// Menja mesta na ptr1 i ptr2 koji su bilo gde u list
	void swap(Node* prev1, Node* ptr1, Node* prev2, Node* ptr2);

	void novi_swap(bool rastuci);

	// zad sa kol neki
	void fill_in();

	// isto zad sa kol neki
	void MovePartToEnd(int val1, int val2);

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

	void update(int val, int add);

	int swap_pairs(int val1, int val2);


	// Jun II 2022.
	LinkedList* SplitOrMove();
	//

	// Jun 2023.
	bool deleteSublist(LinkedList* sublist);
	//

	// Oktobar II 2022
	void MoveMinToHead(Node** start);
	void SortList();
	//

	// Jun II 2021
	LinkedList* extractEven();


	// sorting algoritmi
	void sort_bubble(bool rastuci);
	void sort_selection(bool rastuci);
	void sort_inserion(bool rastuci);
	
};

