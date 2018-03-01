//Tung Duong
//
//December 5th 2015
//

using namespace std;

#include <stack>
#include <string>
#include <vector>

class card
{
	public:
		
		card(int number = 0, string CardType = "Spade") {m_Number=number, m_CardType=CardType;}
		
		
		int GetNumber() {return m_Number;}
		
	    string GetCardType() {return m_CardType;}

	private:
	
		int m_Number;
		
		string m_CardType;
	
};

class Deck
{
	public:
		//Creates a deck with all the cards wanted for the deck.
		Deck(int Spades=12, int Hearts=12, int Diamonds=12, int Clubs=12); 
		
		~Deck();
		
		//Loads the stack into an array. Shuffles the array and then loads it back into the stack. Note:Anytime it is shuffled it is assumed all original cards are put back.
		void Shuffle();
		
		//Pops off stack and returns cards
		card Draw();
		
		//Recreate everything

		
		void Generate(int number, string cardType);
		
		//Getters and setters
		void SetSpades(int number);
		
		void SetHearts(int number);
		
		void SeDiamonds(int number);
		
		void SetClubs(int number);

		int GetSpades() {return m_Spades;}
		
		int GetHearts() {return m_Hearts;}
		
		int GetDiamonds() {return m_Diamonds;}
		
		int GetClubs() {return m_Clubs;}
		
	private:
	
		int m_Spades;
		
		int m_Hearts;
		
		int m_Diamonds;
		
		int m_Clubs;
		
		stack <card> deckCollection;
		
		vector <card> tempd;
};
