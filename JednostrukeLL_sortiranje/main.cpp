#include <iostream>
#include <vector>
#include <stdlib.h>

#include "LinkedList.h"

int main(void)
{
	LinkedList l;

	l.add_to_head(10);
	l.add_to_head(12);
	l.add_to_head(4);
	l.add_to_head(0);
	l.add_to_head(13);
	l.add_to_head(13);

	l.print();

	l.sort_bubble(true);

	l.print();

	l.sort_bubble(false);

	l.print();

	return 0;
}