#include <iostream>

#include "LinkedList.h"

int main(void)
{
	LinkedList lista;

	lista.add_to_head(43);
	lista.print();
	lista.add_to_head(12);
	lista.print();
	lista.add_to_head(4);
	lista.print();

	lista.add_to_end(7);
	lista.print();

	if (lista.add_at(12, 11))
		std::cout << "Uspeh\n";

	lista.print();
	
	lista.sort_bubble(true);

	lista.print();

	return 0;
}