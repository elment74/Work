//Tung Duong
//
//December 5th 2015
//

using namespace std;

#include "Deck.h"
#include <iostream>

Deck::Deck(int Spades, int Hearts, int Diamonds, int Clubs)
{
	m_Spades=Spades;
	m_Hearts=Hearts;
	m_Diamonds=Diamonds;
	m_Clubs=Clubs;
	
	tempd.resize(m_Spades+m_Hearts+m_Diamonds+m_Clubs);
	
    PrepGen();
}

void Deck::PrepGen()
{
    Deck::Generate(m_Spades, "Spades");
	Deck::Generate(m_Hearts, "Hearts");
	Deck::Generate(m_Diamonds, "Diamonds");
	Deck::Generate(m_Clubs, "Clubs");
}

void Deck::Generate(int number, string cardType)
{
	for(int i = 1; i <= number; i++)
	{
		card newcard = card(i, cardType);
		int inc = 0;
		while(tempd[inc].GetNumber() != 0)
		{
		    inc++;
		}
		tempd[inc] = newcard;

        deckCollection.push(newcard);
	}
}	
		
Deck::~Deck()
{
    
}
		
void Deck::Shuffle()
{
    int total = m_Diamonds+m_Clubs+m_Hearts+m_Spades;
    

    
    for (int i=0; i<total; i++) 
    {
        int rNumber = rand() % total;
        card temp = tempd[i]; 
        tempd[i] = tempd[rNumber]; 
        tempd[rNumber] = temp;
    }

    while(!deckCollection.empty())
    {
        deckCollection.pop();
    }

    for (int i=0; i<total; i++) 
    {
        deckCollection.push(tempd[i]);
    }
    
}
		
		
card Deck::Draw()
{
    card newcard = deckCollection.top();
    deckCollection.pop();
    return newcard;
}
		
 
void Deck::SetSpades(int number)
{
    m_Spades = number;
    Prepgen();
}
		
void Deck::SetHearts(int number)
{
    m_Hearts = number;
    Prepgen();
}
		
void Deck::SeDiamonds(int number)
{
    m_Diamonds = number;
    Prepgen();
}
		
void Deck::SetClubs(int number)
{
    m_clubs = number;
    PrepGen();
    
}


