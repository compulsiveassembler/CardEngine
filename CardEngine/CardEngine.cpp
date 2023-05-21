#include "CardEngine.h"

Deck::Deck(int deck_size, int number_of_decks, int hand_size)
{
	m_deck_size = deck_size;
	m_number_of_decks = number_of_decks;
	m_hand_size = hand_size;

	//resize vector to the maximum value it will have (all available cards played)
	used_cards.resize(number_of_decks * deck_size);
}

//clears vector of ints corresponding to used cards, 
//effectively 'shuffling' ducks
void Deck::reset_deck()
{
	used_cards.clear();
}


//generates a number from the seed within bounds determined by deck_size
//passes this number to check_card() to be checked for duplicate draws
int Deck::draw_card()
{
	std::uniform_int_distribution<> card{1, m_deck_size};
	used_cards.push_back(card(mt));
	return card(mt);
}

int Deck::check_drawn_card(int card_number)
{

	for (int i : used_cards)
	{
		if (i == card_number)
		{
			draw_card();
		}
	}
	return card_number;
}

void Deck::print_used_cards()
{
	for (int i : used_cards)
	{
		std::cout << i << "\n";
	}
}