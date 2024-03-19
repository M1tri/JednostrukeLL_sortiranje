#include "LinkedList.h"


LinkedList::~LinkedList()
{
	while (head)
	{
		Node* tmp = head->get_link();
		delete head;
		head = tmp;
	}
}

void LinkedList::add_to_head(int info)
{
	Node* novi = new Node(info);

	if (is_empty())
	{
		head = novi;
		return;
	}

	novi->set_link(head);
	head = novi;
}

void LinkedList::add_to_end(int info)
{
	Node* novi = new Node(info);

	if (is_empty())
	{
		head = novi;
		return;
	}

	Node* tmp = head;
	while (tmp->get_link())
	{
		tmp = tmp->get_link();
	}
	// Kada izadjemo iz petlje tmp je element koji nema sledeceg odnosno krajnji

	tmp->set_link(novi);
}

// dodaje element nakon onog navedenog
bool LinkedList::add_at(int where, int info)
{
	if (is_empty())
		return false;

	Node* tmp = head;

	while (tmp)
	{
		if (tmp->get_info() == where)
		{
			Node* novi = new Node(info);
			novi->set_link(tmp->get_link());
			tmp->set_link(novi);
			return true;
		}
		tmp = tmp->get_link();
	}

	return false;
}

void LinkedList::sort_bubble(bool rastuci)
{
	if (is_empty())
		return;

	bool sorted = false;

	while (!sorted)
	{
		// todo	
	}
}