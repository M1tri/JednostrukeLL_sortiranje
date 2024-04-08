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


void LinkedList::sort_selection(bool rastuci)
{
	if (is_empty())
		return;

	bool sorted = false;

	int lenght = 0;
	Node* tmp1 = head;
	while (tmp1)
	{
		tmp1 = tmp1->get_link();
		lenght++;
	}

	if (lenght <= 1)
		return;

	Node* top = head;
	Node* prev_top = head;
	//Node* min = head;
	//Node* prev_min = nullptr;

	//Node* iter = head->get_link();
	//Node* prev_iter = head;


	Node* iter = head->get_link();
	Node* prev_iter = head;

	Node* min = head;
	Node* prev_min = head;
	bool zamena = false;
	while(iter)
	{
		if (min->get_info() > iter->get_info())
		{
			min = iter;
			prev_min = prev_iter;
			zamena = true;
		}
		prev_iter = iter;
		iter = iter->get_link();
	}
	Node* pom;
	if (min != head->get_link() && zamena)
	{
		pom = min->get_link();
		min->set_link(head->get_link());
		head->set_link(pom);
		prev_min->set_link(head);
		head = min;
	}
	else if (zamena)
	{
		pom = min->get_link();
		min->set_link(head);
		head->set_link(pom);
		head = min;
	}


	while (min->get_link())
	{
		prev_top = min;
		prev_min = min;
		top = min->get_link();
		min = top;


		prev_iter = min;
		iter = top->get_link();

		zamena = false;
		while (iter)
		{
			if (min->get_info() > iter->get_info())
			{
				min = iter;
				prev_min = prev_iter;
				zamena = true;
			}
			prev_iter = iter;
			iter = iter->get_link();
		}

		// ako menjamo dva susedna
		if (top->get_link() == min && zamena)
		{
			pom = min->get_link();
			min->set_link(top);
			top->set_link(pom);
			prev_top->set_link(min);
		}
		else if (zamena)
		{
			pom = min->get_link();
			min->set_link(top->get_link());
			top->set_link(pom);
			prev_min->set_link(top);
			prev_top->set_link(min);
		}
	}
	print();


}

void LinkedList::swap_neighbour(Node* prev, Node* ptr)
{
	if (ptr->get_link() == nullptr)
		return;

	Node* tmp = ptr->get_link();

	ptr->set_link(tmp->get_link());
	tmp->set_link(ptr);

	if (prev == nullptr)
	{
		head = tmp;
	}
	else
	{
		prev->set_link(tmp);
	}
}

void LinkedList::sort_bubble(bool rastuci)
{
	if (is_empty())
		return;

	Node* tmp = head;
	int count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->get_link();
	}

	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		Node* prev = nullptr;
		Node* iter = head;
		int iterations = 0;
		int n = 0;
		while (n < count - iterations - 1)
		{
			if ((iter->get_info() > iter->get_link()->get_info() && rastuci) 
				|| (iter->get_info() < iter->get_link()->get_info() && !rastuci))
			{
				swap_neighbour(prev, iter);
				if (prev == nullptr)
				{
					prev = head;
				}
				else
				{
					prev = prev->get_link();
				}
				sorted = false;
			}
			else
			{
				prev = iter;
				iter = iter->get_link();
			}
			n++;
			//print();
		}
		iterations++;
	}
}

