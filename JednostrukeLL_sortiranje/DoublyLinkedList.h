#pragma once

#include "NodeDouble.h"
#include <iostream>

class DoublyLinkedList
{
private:
	NodeDouble* head;

public:
	DoublyLinkedList(NodeDouble* head = nullptr): head(head) {}
	~DoublyLinkedList()
	{
		while (!is_empty())
			remove_head();
	}


	bool is_empty()
	{
		return head == nullptr;
	}

	void add_to_head(int info)
	{
		NodeDouble* novi = new NodeDouble(info);

		if (is_empty())
		{
			head = novi;
			return;
		}

		novi->next = head;
		head->prev = novi;
		head = novi;
	}

	void add_to_end(int info)
	{
		if (is_empty())
		{
			add_to_head(info);
			return;
		}

		NodeDouble* tmp = head;

		while (tmp->next)
		{
			tmp = tmp->next;
		}

		NodeDouble* novi = new NodeDouble(info);

		tmp->next = novi;
		novi->prev = tmp;
	}

	void print()
	{
		NodeDouble* tmp = head;

		while (tmp)
		{
			std::cout << tmp->info << " ";
			tmp = tmp->next;
		}
		std::cout << '\n';
	}

	void print_back()
	{
		if (is_empty())
			return;

		NodeDouble* tmp = head;

		while (tmp->next)
		{
			tmp = tmp->next;
		}

		while (tmp)
		{
			std::cout << tmp->info << " ";
			tmp = tmp->prev;
		}
		std::cout << '\n';
	}

	void remove_head()
	{
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		NodeDouble* tmp = head;

		head->next->prev = nullptr;
		head = head->next;

		delete tmp;
	}

	void swap_between(int val1, int val2)
	{
		NodeDouble* tmp = head;

		while (tmp->info != val1)
		{
			tmp = tmp->next;
		}

		NodeDouble* first = tmp;

		while (tmp->info != val2)
		{
			tmp = tmp->next;
		}

		NodeDouble* second = tmp;

		swap(first, second);
	}

	void swap_neighbours(NodeDouble* first)
	{
		NodeDouble* second = first->next;
		if (first->prev != nullptr)
			first->prev->next = second;
		else
			head = second;

		first->next = second->next;
		second->prev = first->prev;
		first->prev = second;

		NodeDouble* tmp = second->next;
		second->next = first;
		if(tmp != nullptr)
			tmp->prev = first;
	}

	void swap(NodeDouble* first, NodeDouble* second)
	{
		if (first->next == second)
		{
			swap_neighbours(first);
			return;
		}

		if (first->prev == nullptr)
			head = second;
		else
			first->prev->next = second;

		second->prev->next = first;

		NodeDouble* tmp = second->prev;
		second->prev = first->prev;
		first->prev = tmp;

		tmp = second->next;
		second->next = first->next;
		first->next = tmp;
	}

	void exchange(int val1, int val2)
	{
		if (is_empty())
			return;

		NodeDouble* tmp = head;

		NodeDouble* first = nullptr;
		NodeDouble* second = nullptr;

		int poz1 = 0;
		while (tmp)
		{
			if (tmp->info == val1)
			{
				first = tmp;
				break;
			}
			poz1++;
			tmp = tmp->next;
		}

		int poz2 = 0;
		tmp = head;
		while (tmp)
		{
			if (tmp->info == val2)
			{
				second = tmp;
				break;
			}
			poz2++;
			tmp = tmp->next;
		}

		if (first == nullptr || second == nullptr)
			return;

		if (poz1 == poz2)
			return;

		if (poz1 > poz2)
		{
			tmp = first;
			first = second;
			second = tmp;
		}

		if (first->next == second)
		{
			// granicni slucajni susednih cvorova
			
			if (first->prev)
				first->prev->next = second;
			else
				head = second;

			first->next = second->next;

			second->prev = first->prev;
			first->prev = second;
			
			if (second->next)
				second->next->prev = first;

			second->next = first;
		}
		else
		{
			if (first->prev)
				first->prev->next = second;
			else
				head = second;
			second->prev->next = first;

			first->next->prev = second;

			if (second->next)
				second->next->prev = first;

			tmp = first->next;
			first->next = second->next;
			second->next = tmp;

			tmp = first->prev;
			first->prev = second->prev;
			second->prev = tmp;
		}
	}

};

