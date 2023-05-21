#ifndef CARD_ENGINE_H
#define CARD_ENGINE_H

#include <random>
#include <vector>
#include <iostream>

class Deck
{
private:
	//number of cards in a given deck (eg 52 for standard deck)
	int m_deck_size;

	//number of decks used for a given context (eg 104 for 2-deck game of blackjack)
	int m_number_of_decks;

	//how many cards are in a hand for a given deck? 
	//Determines how many cards are drawn when a hand is drawn
	int m_hand_size;

	//to prevent multiple of the same card from being drawn, 
	//drawn cards are stored as a vector and only n = numberOfDecks of that
	//card are allowed to be generated until 'drawing' that card will 
	//prompt a reroll of the draw_card function
	std::vector<int> used_cards{};

	//PRNG seed
	std::mt19937 mt{ std::random_device{}() };

public:
	//default constructor that generates a standard deck and hand made for 'go-fish', the most intellectual of card games. 
	Deck() : m_deck_size{ 52 }, m_number_of_decks{ 1 }, m_hand_size{ 7 }
	{

	}

	Deck(int deck_size, int number_of_decks, int hand_size);

	//clears vector of ints corresponding to used cards, 
	//effectively 'shuffling' ducks
	void reset_deck();


	//generates a number from the seed within bounds determined by deck_size
	//passes this number to check_card() to be checked for duplicate draws
	int draw_card();


	int check_drawn_card(int card_number);

	void print_used_cards();
};















#endif