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

void LinkedList::swap(Node* prev1, Node* ptr1, Node* prev2, Node* ptr2)
{
	// Prvo pokrivamo granicne slucajeve ako su cvorovi koje menjamo susedni
	// koristiomo vec postojecu funkciju za menjanje njihovih mesta

	if (ptr1 == prev2)
	{
		swap_neighbour(prev1, ptr1);
		return;
	}

	if (prev1 == ptr2)
	{
		swap_neighbour(prev2, ptr2);
		return;
	}

	Node* tmp = ptr1->get_link();
	ptr1->set_link(ptr2->get_link());
	ptr2->set_link(tmp);

	if (prev1 == nullptr)
		head = ptr2;
	else
		prev1->set_link(ptr2);

	if (prev2 == nullptr)
		head = ptr1;
	else
		prev2->set_link(ptr1);
}

void LinkedList::novi_swap(bool rastuci)
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

	Node* prev_top = nullptr;
	Node* top = head;

	int i = 0;
	while (i < count)
	{
		Node* swapy = top;
		Node* prev_swapy = prev_top;

		Node* iter = swapy->get_link();
		Node* prev_iter = swapy;

		while (iter)
		{
			if ((swapy->get_info() > iter->get_info() && rastuci) ||
				(swapy->get_info() < iter->get_info() && !rastuci))
			{
				prev_swapy = prev_iter;
				swapy = iter;
			}
			prev_iter = iter;
			iter = iter->get_link();
		}

		swap(prev_top, top, prev_swapy, swapy);
		//print();

		prev_top = swapy;
		top = swapy->get_link();
		i++;
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
	int iterations = 0;
	while (!sorted)
	{
		sorted = true;
		Node* prev = nullptr;
		Node* iter = head;
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

void LinkedList::fill_in() 
{
	if (is_empty())
		return;

	Node* iter = head;

	while (iter->get_link())
	{
		if (iter->get_link()->get_info() == iter->get_info())
		{
			Node* tmp = iter->get_link();
			iter->set_link(iter->get_link()->get_link());
			delete tmp;
		}
		else if(iter->get_link()->get_info() != iter->get_info() + 1)
		{
			Node* novi = new Node(iter->get_info() + 1);
			novi->set_link(iter->get_link());
			iter->set_link(novi);
			iter = iter->get_link();
		}
		else
		{
			iter = iter->get_link();
		}
		//print();
	}
}

void LinkedList::MovePartToEnd(int val1, int val2)
{
	Node* tmp = head;
	Node* prev_second = nullptr;

	while (tmp->get_info() != val1)
	{
		prev_second = tmp;
		tmp = tmp->get_link();
	}
	Node* first = tmp;

	while (tmp->get_info() != val2)
	{
		prev_second = tmp;
		tmp = tmp->get_link();
	}
	Node* second = tmp;

	while (tmp->get_link())
	{
		tmp = tmp->get_link();
	}
	Node* tail = tmp;
	
	// Ukoliko nema elemenata izmedju val1 i val2 samo izlazimo
	if (prev_second == first)
		return;

	tmp = first->get_link();

	first->set_link(second);
	tail->set_link(tmp);
	prev_second->set_link(nullptr);

	print();
}


void LinkedList::update(int val, int add)
{
	Node* prev_tmp = nullptr;
	Node* tmp = head;

	while (tmp)
	{
		if (tmp->get_info() == val)
			break;

		prev_tmp = tmp;
		tmp = tmp->get_link();
	}

	tmp->info = tmp->info + add;

	if (tmp->get_link() == nullptr)
	{
		return;
	}
	else if (tmp->get_link()->get_info() > tmp->get_info())
	{
		return;
	}


	if (prev_tmp == nullptr)
	{
		head = tmp->get_link();
	}
	else
	{
		prev_tmp->set_link(tmp->get_link());
	}


	Node* prev_iter = tmp;
	Node* iter = tmp->get_link();

	while (iter && iter->get_info() < tmp->get_info())
	{
		prev_iter = iter;
		iter = iter->get_link();
	}


	if (iter == nullptr)
	{
		prev_iter->set_link(tmp);
		tmp->set_link(nullptr);
	}
	else
	{
		prev_iter->set_link(tmp);
		tmp->set_link(iter);
	}
}

int LinkedList::swap_pairs(int val1, int val2)
{
	if (is_empty())
		return 0;

	Node* tmp = head;

	while (tmp && tmp->info != val1)
	{
		tmp = tmp->link;
	}

	Node* start = tmp;

	if (start == nullptr)
		return 0;

	while (tmp->link && tmp->link->get_info() != val2)
	{
		tmp = tmp->link;
	}

	Node* prev_end = tmp;
	Node* end = prev_end->link;

	Node* prev1 = start;
	Node* prev2 = start->link;

	int swaps = 0;
	while (prev2 != nullptr && prev2 != end)
	{
		tmp = prev2->link;
		prev2->link = tmp->link;

		tmp->link = prev2;
		prev1->link = tmp;

		prev1 = prev1->link->link;
		prev2 = prev2->link;

		swaps++;
		//print();
	}


	return swaps;
}


LinkedList* LinkedList::SplitOrMove()
{
	LinkedList* novaLL = new LinkedList();
	Node* tail_nova = nullptr;

	Node* prev_curr = nullptr;
	Node* curr = head;

	Node* prev_iter;
	Node* iter;


	while (curr)
	{
		prev_iter = curr;
		iter = curr->get_link();

		bool unique = true;
		while (iter)
		{
			if (iter->get_info() == curr->get_info())
			{
				unique = false;
				prev_iter->link = iter->link;

				if (tail_nova == nullptr)
				{
					novaLL->head = iter;
					novaLL->head->link = nullptr;
					tail_nova = novaLL->head;
				}
				else
				{
					tail_nova->link = iter;
					iter->link = nullptr;
					tail_nova = tail_nova->link;
				}
				break;
			}

			prev_iter = iter;
			iter = iter->get_link();
		}

		if (unique)
		{
			if (prev_curr != nullptr)
				prev_curr->link = curr->link;
			else
				head = curr->link;

			if (tail_nova == nullptr)
			{
				novaLL->head = curr;
				novaLL->head->link = nullptr;
				tail_nova = novaLL->head;
			}
			else
			{
				tail_nova->link = curr;
				curr->link = nullptr;
				tail_nova = tail_nova->link;
			}

			if (prev_curr != nullptr)
				curr = prev_curr->link;
			else
				curr = head;

			//std::cout << "Nova lista: ";
			//novaLL->print();
			//std::cout << '\n';
			//std::cout << "Trenutna lista: ";
			//print();
			//std::cout << '\n';

			continue;
		}

		prev_curr = curr;
		curr = curr->link;

		//std::cout << "Nova lista: ";
		//novaLL->print();
		//std::cout << '\n';
		//std::cout << "Trenutna lista: ";
		//print();
		//std::cout << '\n';
	}



	return novaLL;
}

bool LinkedList::deleteSublist(LinkedList* sublist)
{
	if (is_empty())
		return false;

	int lenght1 = 0;
	int lenght2 = 0;

	Node* iter1 = head;
	Node* iter2 = sublist->head;

	// Pravimo se pametni i malo optimizujemo
	// merenje duzine listi
	while (iter1 || iter2)
	{
		if (iter1)
		{
			lenght1++;
			iter1 = iter1->link;
		}

		if (iter2)
		{
			lenght2++;
			iter2 = iter2->link;
		}
	}

	// Ako je podlista duza od liste ili je prazna izazimo
	if (lenght1 < lenght2 || lenght2 == 0)
	{
		return false;
	}

	int iterations = 0;

	Node* prev_iter1 = nullptr;
	iter1 = head;

	bool found = false;
	while (iter1)
	{
		found = true;
		iter2 = sublist->head;
		Node* pom_iter1 = iter1;
		while (iter2)
		{
			if (iter2->info != pom_iter1->info)
			{
				found = false;
				break;
			}
			iter2 = iter2->link;
			pom_iter1 = pom_iter1->link;
		}

		if (found)
		{
			Node* to_remove;
			int i = 0;
			while (i < lenght2)
			{
				if (prev_iter1 != nullptr)
				{
					to_remove = iter1;
					prev_iter1->link = iter1->link;
					iter1 = iter1->link;
					delete to_remove;
				}
				else
				{
					// iter1 = head
					to_remove = head;
					head = head->link;
					if (!is_empty())
						iter1 = head->link;
					delete to_remove;
				}
				i++;
			}
			//iter1 = prev_iter1->link;
			print();
			iterations++;
			continue;
		}
		prev_iter1 = iter1;
		iter1 = iter1->link;
		iterations++;
		print();

	}
}

void LinkedList::MoveMinToHead(Node** start)
{
	Node* iter = *start;

	if (iter->link == nullptr)
		return;

	Node* prev_min = iter;
	Node* min = iter->link;

	Node* prev_iter = nullptr;
	while (iter)
	{
		if (min->info > iter->info)
		{
			prev_min = prev_iter;
			min = iter;
		}
		prev_iter = iter;
		iter = iter->link;
	}

	// min == start
	if (prev_min == nullptr)
		return;

	if (prev_min != *start)
	{
		Node* pom = (*start)->link;
		(*start)->link = min->link;
		min->link = pom;

		prev_min->link = *start;
		*start = min;
	}
	else
	{
		(*start)->link = min->link;
		min->link = *start;
		*start = min;
	}
}

void LinkedList::SortList()
{
	Node* prev_iter = nullptr;
	Node* iter = head;

	while (iter)
	{
		MoveMinToHead(&iter);
		
		if (prev_iter == nullptr)
			head = iter;
		else
			prev_iter->link = iter;

		prev_iter = iter;
		iter = iter->link;
	}
}


LinkedList* LinkedList::extractEven()
{
	LinkedList* nova = new LinkedList();

	Node* prev_iter = nullptr;
	Node* iter = head;

	Node* nova_last = nullptr;

	while (iter)
	{
		if (iter->info % 2 != 0)
		{
			prev_iter = iter;
			iter = iter->link;
			continue;
		}

		if (prev_iter)
		{
			prev_iter->link = iter->link;
		}
		else
		{
			head = iter->link;
		}

		if (nova_last == nullptr)
		{
			nova->head = iter;
			iter->link = nullptr;
			nova_last = iter;
		}
		else
		{
			nova_last->link = iter;
			iter->link = nullptr;
			nova_last = iter;
		}

		if (prev_iter)
			iter = prev_iter->link;
		else
			iter = head;
	}

	return nova;
}


