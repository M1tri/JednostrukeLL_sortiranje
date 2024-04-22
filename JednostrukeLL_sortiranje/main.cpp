#include <iostream>
#include <vector>
#include <stdlib.h>

#include "LinkedList.h"
#include "DoublyLinkedList.h"

int main(void)
{
	LinkedList l;

	l.add_to_head(-10);
	l.add_to_head(12);
	l.add_to_head(-4);
	l.add_to_head(0);
	l.add_to_head(13);
	l.add_to_head(rand());
	l.add_to_head(rand());
	l.add_to_head(rand());
	l.add_to_head(rand());

	//l.print();

	//l.sort_bubble(true);

	//l.print();

	//l.sort_bubble(false);

	l.print();

	l.novi_swap(false);

	l.print();

	l.novi_swap(true);

	l.print();


	LinkedList uzastopna;

	uzastopna.add_to_head(1);
	uzastopna.add_to_end(3);
	uzastopna.add_to_end(3);
	uzastopna.add_to_end(7);

	uzastopna.print();
	uzastopna.fill_in();
	uzastopna.print();

	uzastopna.MovePartToEnd(2, 3);
	uzastopna.print();

	DoublyLinkedList dupla;

	dupla.add_to_head(12);
	dupla.add_to_head(6);
	dupla.add_to_head(42);

	dupla.print();

	dupla.add_to_end(2);
	dupla.add_to_end(7);
	dupla.add_to_end(10);

	dupla.print();

	dupla.swap_between(42, 6);

	dupla.print();
	
	dupla.remove_head();

	dupla.print();

	LinkedList nova;
	
	nova.add_to_head(1);
	nova.add_to_end(2);
	nova.add_to_end(3);
	nova.add_to_head(4);
	nova.add_to_head(4);
	nova.add_to_end(5);
	nova.add_to_end(8);
	nova.add_to_end(8);
	nova.add_to_end(9);
	nova.add_to_end(12);

	nova.sort_bubble(true);
	nova.print();

	nova.update(5, 2);

	nova.print();

	nova.add_to_end(10);

	nova.print();

	std::cout << "Swaps: " << nova.swap_pairs(1, 12) << '\n';

	nova.print();


	std::cout << "------------------------\n";

	LinkedList lista3;


	lista3.add_to_end(0);

	lista3.add_to_end(1);
	lista3.add_to_end(1);

	lista3.add_to_end(2);
	lista3.add_to_end(2);

	lista3.add_to_end(3);
	lista3.add_to_end(3);

	lista3.add_to_end(4);
	lista3.add_to_end(4);

	lista3.add_to_end(5);

	lista3.print();

	LinkedList* ll = lista3.SplitOrMove();

	std::cout << "Originalna lista:\n";
	lista3.print();
	std::cout << '\n';

	std::cout << "Novonastala lista:\n";
	ll->print();
	std::cout << '\n';

	delete ll;

	std::cout << "-------------------:\n";

	LinkedList lista4;

	lista4.add_to_end(1);
	lista4.add_to_end(2);
	lista4.add_to_end(3);

	LinkedList sublist;

	sublist.add_to_end(1);
	sublist.add_to_end(2);
	sublist.add_to_end(3);

	std::cout << "Lista:\n";
	lista4.print();
	std::cout << '\n';

	std::cout << "Podlista:\n";
	sublist.print();
	std::cout << '\n';

	lista4.deleteSublist(&sublist);

	std::cout << "Lista nakon brisanja podliste:\n";
	lista4.print();
	std::cout << '\n';

	lista4.add_to_head(2);
	lista4.add_to_head(2);
	lista4.add_to_head(2);

	lista4.print();


	std::cout << "-------------------:\n";


	LinkedList movingMin;

	movingMin.add_to_head(6);
	movingMin.add_to_end(3);
	movingMin.add_to_end(6);

	movingMin.print();

	movingMin.SortList();

	movingMin.print();


	DoublyLinkedList ll2;

	ll2.add_to_end(12);
	ll2.add_to_end(14);
	ll2.add_to_end(16);
	ll2.add_to_end(18);
	ll2.add_to_end(11);
	ll2.add_to_end(23);


	std::cout << "Zamena suseda\n";


	std::cout << "Pre:\n";
	ll2.print();
	std::cout << '\n';
	ll2.print_back();

	ll2.exchange(12, 14);

	std::cout << "Posle:\n";
	ll2.print();
	std::cout << '\n';
	ll2.print_back();

	std::cout << "Zamena suseda\n";

	std::cout << "Pre:\n";
	ll2.print();
	std::cout << '\n';
	ll2.print_back();

	ll2.exchange(11, 23);

	std::cout << "Posle:\n";
	ll2.print();
	std::cout << '\n';
	ll2.print_back();


	std::cout << "----------------------\n\n\n";


	LinkedList original;
	
	original.add_to_end(1);
	original.add_to_end(2);
	original.add_to_end(4);
	original.add_to_end(5);
	original.add_to_end(7);
	original.add_to_end(0);
	original.add_to_end(10);
	original.add_to_head(6);

	std::cout << "Og lista:\n";

	original.print();

	std::cout << '\n';

	LinkedList* even = original.extractEven();

	std::cout << "Even lista:\n";

	even->print();

	std::cout << '\n';

	std::cout << "Og lista:\n";

	original.print();

	std::cout << '\n';

	return 0;
}