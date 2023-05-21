#include <iostream>
#include "CardEngine.h"

int main()
{
	Deck standard;
	for (int i = 0; i < 53; i++)
	{
		standard.draw_card();
	}

	standard.print_used_cards();


	std::cout << "Hey\n";
	return 0;
}

