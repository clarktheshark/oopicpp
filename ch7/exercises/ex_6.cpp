// ex_6.cpp
// modifies cards such it deals out hands
#include <iostream>
#include <cstdlib> // for srand(), rand()
#include <ctime> // for time for srand()
using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
// from 2 to 10 are integers without names
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
////////////////////////////////////////
class card
{
  int number; // 2 to 10, jack, queen, king, ace
  Suit suit;
public:
  card() // constructor
  { }

  void set(int n, Suit s) // set card
  { suit = s; number = n; }

  void display() // display the card
  {
    if (number >= 2 && number <= 10 )
      cout << number;
    else 
      switch(number)
	{
	case jack: cout << "J"; break;
	case queen: cout << "Q"; break;
	case king: cout << "K"; break;
	case ace: cout << "A"; break;
	}
    switch(suit)
      {
      case clubs: cout << "\u2663"; break;
      case diamonds: cout << "\u2666"; break;
      case hearts: cout << "\u2665"; break;
      case spades: cout << "\u2660"; break;
      }
  }
};
/////////////////////////////////
class bridge
{
  static const int HAND_SIZE = 13;
  static const int NUM_PLAYERS = 4;
  card hands[NUM_PLAYERS][HAND_SIZE];

public:
  void dist_hands(card deck[]) {
    int player, card_idx;
    for (int i = 0; i < 52; i++) {
      player = i / 13;
      card_idx = i % 13;
      hands[player][card_idx] = deck[i];
    }
  }

  void print_hands() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
      cout << "Player " << i + 1 << " Hand" << endl;
      for (int j = 0; j < HAND_SIZE; j++) {
	hands[i][j].display();
	cout << " ";
      }
      cout << endl;
    }
  }
};

////////////////////////////////
int main()
{

  void print_deck(card[], int);

  const int DECK_SIZE = 52;
  card deck[DECK_SIZE];
  int j;

  cout << endl;
  for (j = 0; j < 52; j++) // make an ordered deck
    {
      int num = (j % 13) + 2; // cycles through 2 to 14, 4 times
      Suit suit = Suit(j / 13); // cycles through 0 to 3, 13 times
      deck[j].set(num, suit); // set card
    }
  cout << "\nOrdered deck:\n";
  print_deck(deck, DECK_SIZE);

  srand( time(NULL) ); // seed random numbers with time
  for (j = 0; j < 52; j++) // for each card in the deck
    {
      int k = rand() % 52; // pick another card at random
      card temp = deck[j]; // and swap them
      deck[j] = deck[k];
      deck[k] = temp;
    }
  cout << "Suffled deck:\n";
  print_deck(deck, DECK_SIZE);

  bridge b1;
  b1.dist_hands(deck);
  b1.print_hands();

  return 0;
}

void print_deck(card deck[], int size) {
  for (int i = 0; i < size; i++) {
    deck[i].display();
    cout << " ";
    if ( !( (i+1) % 13) ) // newline every 13 cards
      cout << endl;
  }
}
