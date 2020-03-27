///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Shaun Partridge
// Email:            spartridgeb15@gmail.com
// Label:            P01
// Title:            WarGame.hpp
// Course:           CMPS 2143
// Semester:         Spring 2020
//
// Description:
//
//       This file is the implementation of the game of war and includes 
//       a Deck class, a Hand class, and a WarGame class to help with the
//       implementation of the game. This file will also
//       implement a deque by adding players' cards to the top of a pile 
//       and removing them from the top of the pile to place in the winner's
//       hands.
//
// Usage:
//       This file includes a Deck class, a Hand class, and a WarGame class.
//       These will represent a deck of cards, two players, and a pile that 
//       accumulates players' cards until there is a winner, who then adds
//       the pile of cards to the back of their hand. 
// Files: 
//
//      WarGame.hpp    : Implements the game of war
//
/////////////////////////////////////////////////////////////////////////////////
#include "termio.h"
#include "PlayingCard.hpp"
#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

/*
 
  _______   ________   ______   __    __ 
 /       \ /        | /      \ /  |  /  |
 $$$$$$$  |$$$$$$$$/ /$$$$$$  |$$ | /$$/ 
 $$ |  $$ |$$ |__    $$ |  $$/ $$ |/$$/  
 $$ |  $$ |$$    |   $$ |      $$  $$<   
 $$ |  $$ |$$$$$/    $$ |   __ $$$$$  \  
 $$ |__$$ |$$ |_____ $$ \__/  |$$ |$$  \ 
 $$    $$/ $$       |$$    $$/ $$ | $$  |
 $$$$$$$/  $$$$$$$$/  $$$$$$/  $$/   $$/ 
                                                                                 
 
*/

/**
 * Deck
 *
 * Description:
 *      This class will implement a deque of card pointers that will be
 *      representing a deck of playing cards. A deque allows front 
 *      removal from a deck just as in real life, as well as putting cards
 *      to the back of the deck. This class will also shuffle a deck,
 *      reset a deck, keep track of a deck's size and check if there's any 
 *      cards in a deck or not, along with printing out a deck of cards.
 *
 * Public Methods:
 * 
 *      Deck();
 *      void LoadDeck(int);
 *      bool isEmpty();
 *      void Order();
 *      Card* Deal();
 *      void Reset();
 *      void Shuffle();
 *      int Size();
 *      void Print(int, bool);
 *      
 * Protected:
 * 
 *      deque<Card*> Cards;
 *      Term::IO io;
 *      int numCards;
 *      struct CardCompare();
 *          
 */
class Deck {

protected:

    Term::IO io;
    deque<Card*> Cards;
    int numCards;
    
    struct CardCompare {

        bool operator()(Card *l, Card *r) {

            return l < r;

        }

    };

public:

    Deck();
    void LoadDeck(int);
    bool isEmpty();
    void Order();
    Card* Deal();
    void Reset();
    void Shuffle();
    int Size();
    void Print(int, bool);

};

/**
 * Public : Constructor
 *
 * Description:
 *      Represents a deck of playing cards.
 * 
 * Params:
 *      None
 *
 * Returns:
 *      None
 */
Deck::Deck(){
    numCards = 0;
}


/**
 * Public : LoadDeck()
 *
 * Description:
 *      Creates a deck of however many playing cards
 * 
 * Params:
 *      int  :  the number of cards to be in the deck
 *
 * Returns:
 *      void
 */
void Deck::LoadDeck(int numCards) {

    for (int i = 0; i < numCards; i++) {

        Cards.push_back(new Card(i)); // Allocate memory for a new card 
        
    }
    
}


/**
 * Public : isEmpty()
 *
 * Description:
 *      Returns true if the deck is empty, false otherwise.
 * 
 * Params:
 *      None
 *
 * Returns:
 *      bool  :  true if the deck is empty
 */
bool Deck::isEmpty() {

    return Cards.empty();

}


/**
 * Public : Order()
 *
 * Description:
 *      Sorts the deck by the cards' rank using deque functions,
 *      begin() and end(), along with the method CardCompare().
 * 
 * Params:
 *      None
 *
 * Returns:
 *      void
 */
void Deck::Order() {

    sort(Cards.begin(), Cards.end(), CardCompare());

}


/**
 * Public : Deal()
 *
 * Description:
 *      Deals a playing card to a player.
 * 
 * Params:
 *      None
 *
 * Returns:
 *      Card*  :  the card off the top of the deck
 */
Card* Deck::Deal() {

    Card *temp = Cards.at(0);   // temp gets the top card
        
    Cards.erase(Cards.begin()); // delete the top card

    return temp;                // return the top card

}


/**
 * Public : Reset()
 *
 * Description:
 *      Clears out the previous deck and creates a new deck.
 * 
 * Params:
 *      None
 *
 * Returns:
 *      void
 */
void Deck::Reset() {

    // For loop to delete old deck and create a new one
    for (int i = 0; i < Cards.size() - 1; i++) {

        delete Cards[i];

        Cards[i] = new Card(i);

    }

}


/**
 * Public : Shuffle()
 *
 * Description:
 *      Shuffles a deck of playing cards.
 * 
 * Params:
 *      None
 *
 * Returns:
 *      void
 */
void Deck::Shuffle() {

    for (int i = 0; i < Cards.size() - 1; i++) {

        // j acts as a random card in the deck
        int j = i + rand() % (Cards.size() - i); 

        // that is to be swapped with i to shuffle the cards
        swap(Cards[i], Cards[j]);

    }

}


/**
 * Public : Size()
 *
 * Description:
 *      Returns the deck's size.
 * 
 * Params:
 *      None
 *
 * Returns:
 *      int  :  the size of the deck
 */
int Deck::Size() {

    return Cards.size();

}


/**
 * Public : Print()
 *
 * Description:
 *      Prints out a deck of cards.
 * 
 * Params:
 *      int   :  the number of columns to print the deck
 *      bool  :  clears the screen before printing the deck, if true
 *
 * Returns:
 *      void
 */
void Deck::Print(int columns = 2, bool clear = false) {

    // Initializing variables
    int i = 0;
    vector<string> cards;

    // clear screen if true
    if (clear) {    

        io << Term::clear;

    }

    // For loop to load the vector of strings
    for (auto c : Cards) {

        cards.push_back(c->Repr()); // Pushes a string representation of a
                                        // card to the vector to printed out.
        i++;                        // Increment i

        if (i == columns) {

            io << Term::fuse(cards) << "\n"; // Prints cards side by side

            i = 0;                  // Set i to 0

            cards.clear();          // Remove strings from vector

        }

    }

    // any cards left in the vector should be
    // printed out

    if (cards.size() > 0) {

        io << Term::fuse(cards) << "\n";

    }

}



/*
 
  __    __   ______   __    __  _______  
 /  |  /  | /      \ /  \  /  |/       \ 
 $$ |  $$ |/$$$$$$  |$$  \ $$ |$$$$$$$  |
 $$ |__$$ |$$ |__$$ |$$$  \$$ |$$ |  $$ |
 $$    $$ |$$    $$ |$$$$  $$ |$$ |  $$ |
 $$$$$$$$ |$$$$$$$$ |$$ $$ $$ |$$ |  $$ |
 $$ |  $$ |$$ |  $$ |$$ |$$$$ |$$ |__$$ |
 $$ |  $$ |$$ |  $$ |$$ | $$$ |$$    $$/ 
 $$/   $$/ $$/   $$/ $$/   $$/ $$$$$$$/  
                                         
                                         
*/

/**
 * Hand
 *
 * Description:
 *      This class will implement a deque of card pointers that will be
 *      representing a players hand in a card game. A deque allows front 
 *      removal from a hand just as in real life, as well as putting cards
 *      to the back of the hand. This class will also keep track of a 
 *      player's hand size and if there's any cards in the hand or not, 
 *      along with printing out a player's hand.
 *
 * Public Methods:
 * 
 *      Hand();
 *      Hand(Card*);
 *      Card* PlayCard();
 *      int Size();
 *      void TakeCard(Card*);
 *      bool Empty();
 *      void PrintH(int,bool);
 *      
 * Private:
 * 
 *      deque<Card*> hand
 *      Term::IO io;
 *          
 */

class Hand{

protected:

    deque<Card*> hand;
    Term::IO io;

public:
 
    Hand();
    Card* PlayCard();
    int Size();
    void TakeCard(Card*);
    bool Empty();
    void PrintH(int,bool);

};

/**
 * Public : Constructor
 *
 * Description:
 *      Represent a hand that holds playing cards.
 * 
 * Params:
 *      None
 *
 * Returns:
 *      None
 */
Hand::Hand(){};


/**
 * Public : Size()
 *
 * Description:
 *      Returns a hands' size.
 * 
 * Params:
 *      None
 *
 * Returns:
 *      int   :  the size of the hand
 */
int Hand::Size(){
    return hand.size();
}


/**
 * Public : Empty()
 *
 * Description:
 *      Returns true if a hand is empty, false otherwise.
 * 
 * Params:
 *      None
 *
 * Returns:
 *      bool  :  true if empty, false if not empty
 */
bool Hand::Empty(){
    return hand.empty();
}


/**
 * Public : PlayCard()
 *
 * Description:
 *      Removes a card from the top a hand.
 * 
 * Params:
 *      None
 *
 * Returns:
 *      Card*  :  the card on top of the hand
 */
Card* Hand::PlayCard(){

    Card *temp = hand.front(); // temp gets the top card

    hand.pop_front();          // delete the top card
    
    return temp;               // return the top card
    
}


/**
 * Public : TakeCard()
 *
 * Description:
 *      Takes a card and puts in the back of the hand.
 * 
 * Params:
 *      Card*  : the card to be placed in the hand
 *
 * Returns:
 *      void
 */
void Hand::TakeCard(Card *c){

    hand.push_back(c);

}


/**
 * Public : PrintH()
 *
 * Description:
 *      Prints out a hand of cards.
 * 
 * Params:
 *      int   :  the number of columns to print the hand
 *      bool  :  clears the screen before printing the hand, if true
 *
 * Returns:
 *      void
 */
void Hand::PrintH(int columns = 5, bool clear = false){
    
    int i = 0;

    vector<string> cards;

    if (clear) {

        io << Term::clear;

    }

    for (auto c : hand) {

        cards.insert(cards.begin(),c->Repr());


        i++;

        if (i == columns) {

            io << Term::fuse(cards) << "\n";

            i = 0;

            cards.clear();

        }

    }

    // any cards left in the vector should be
    // printed out.

    if (cards.size() > 0) {

        io << Term::fuse(cards) << "\n";

    }

}


/*
 
  __       __   ______   _______    ______    ______   __       __  ________ 
 /  |  _  /  | /      \ /       \  /      \  /      \ /  \     /  |/        |
 $$ | / \ $$ |/$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |$$  \   /$$ |$$$$$$$$/ 
 $$ |/$  \$$ |$$ |__$$ |$$ |__$$ |$$ | _$$/ $$ |__$$ |$$$  \ /$$$ |$$ |__    
 $$ /$$$  $$ |$$    $$ |$$    $$< $$ |/    |$$    $$ |$$$$  /$$$$ |$$    |   
 $$ $$/$$ $$ |$$$$$$$$ |$$$$$$$  |$$ |$$$$ |$$$$$$$$ |$$ $$ $$/$$ |$$$$$/    
 $$$$/  $$$$ |$$ |  $$ |$$ |  $$ |$$ \__$$ |$$ |  $$ |$$ |$$$/ $$ |$$ |_____ 
 $$$/    $$$ |$$ |  $$ |$$ |  $$ |$$    $$/ $$ |  $$ |$$ | $/  $$ |$$       |
 $$/      $$/ $$/   $$/ $$/   $$/  $$$$$$/  $$/   $$/ $$/      $$/ $$$$$$$$/ 
                                                                                                                                                       
 
*/

/**
 * WarGame
 *
 * Description:
 *      This class will implement the card game, the game of war. This class
 *      includes a deque of card pointers that represents the pile of cards 
 *      played by the players. This pile will be printed out and will be 
 *      won by the player who plays the card with the higher rank. This class
 *      also includes a Deck object, two Hand objects, and two Card pointer 
 *      objects that will help with the implementation of the card game.
 *
 * Public Methods:
 * 
 *      WarGame();
 *      void Deal();
 *      void Print_Cards(Card*,Card*);
 *      void War();
 *      void Play();
 *      Card* Take_Pile();
 *      void Add_to_Pile(Card*);
 *      bool Empty();
 *      
 * Protected:
 * 
 *      deque<Card*> Pile;
 *      Term::IO io;
 *      Hand Player1;
 *      Hand Player2;
 *      Card *P1Card;
 *      Card *P2Card;
 *      Deck D;
 *          
 */

class WarGame {

protected:

    deque<Card*> Pile;
    Hand Player1;
    Hand Player2;
    Card *P1Card;
    Card *P2Card;
    Term::IO io; 
    Deck D;    

public:

    WarGame();
    void Deal();
    void Print_Cards(Card*,Card*);
    void War();
    void Play();
    Card* Take_Pile();
    void Add_to_Pile(Card*);
    bool Empty();
};


    /**
    * Public : Constructor
    *
    * Description:
    *      Instantiates a deck, two players, two card pointers, 
    *      and a pile to play cards on.
    * 
    * Params:
    *      None
    *
    * Returns:
    *      None
    */
    WarGame::WarGame(){

        D.LoadDeck(52);
        Player1;        // player 1 hand
        Player2;        // player 2 hand
        P1Card = NULL;  // player 1 card
        P2Card = NULL;  // player 2 card
        Pile;           // pile of cards won in the game
    }


    /**
    * Public : Deal()
    *
    * Description:
    *      Shuffles a deck of cards and then deals one card at a time
    *      to both hands.
    * 
    * Params:
    *      None
    *
    * Returns:
    *      void
    */
    void WarGame::Deal(){
             
        D.Shuffle();    // Calls Decks shuffle method 
           
        while(!D.isEmpty()){ 

            // While the deck is not empty deal a card
            // to each player

            Player1.TakeCard(D.Deal());
            Player2.TakeCard(D.Deal());    

        }   
           
    }

    /**
    * Public : Empty()
    *
    * Description:
    *      Returns true if the pile is empty, false otherwise.
    * 
    * Params:
    *      None
    *
    * Returns:
    *      bool  :  true if empty, else false
    */
    bool WarGame::Empty(){

        return Pile.empty();
    }

    /**
    * Public : Play()
    *
    * Description:
    *      Players will each play a card on the pile and whoever has the 
    *      bigger card wins both cards. If both players' cards are of the
    *      same rank then War() will be called. Each player continues to
    *      play a card until one player is out of cards.
    * 
    * Params:
    *      None
    *
    * Returns:
    *      void
    */
    void WarGame::Play(){

        // While both player's hand are not empty 
        while(!Player1.Empty() && !Player2.Empty()){
            
            // Print out each player's hand size
            io << "Cards: " << Player1.Size() << " Cards: " << Player2.Size() << "\n";

            // P1Card and P2Card are the top card of each hand, that is
            // then placed on the pile. 
            P1Card = Player1.PlayCard();
            P2Card = Player2.PlayCard();
            Add_to_Pile(P1Card);
            Add_to_Pile(P2Card);

            // Print the cards of each player along with their names under them
            Print_Cards(P1Card,P2Card);
            io << "Player 1   Player 2\n";

            // First checks to see if both cards are of equal rank
            if (P1Card->Rank() == P2Card->Rank()){

                // Call War function
                io << "WAR!!\n";
                War();
                    
            }

            // Checks if P1Card is greater then P2Card
            else if(P1Card->Rank() > P2Card->Rank()){
                
                // Player1 is the winner and thus gets the pile of cards
                io << "  Winner!\n\n";
                while(!Empty()){

                    Player1.TakeCard(Take_Pile());

                }
            }

            // Checks if P1Card is less than P2Card
            else if(P1Card->Rank() < P2Card->Rank()){
                
                // Player2 is the winner and thus gets the pile of cards
                io << "            Winner!\n\n";
                while(!Empty()){

                    Player2.TakeCard(Take_Pile());

                }
            }

        }

        // Print out hand amounts after the round
        io << "Cards: " << Player1.Size() << " Cards: " << Player2.Size() << "\n";

        // Player2 is out of cards
        if(!Player1.Empty() && Player2.Empty()){  

            io << "Player 1 has won the game!!\n";

        }

        // Player1 is out of cards
        else if(Player1.Empty() && !Player2.Empty()){

            io << "Player 2 has won the game!!\n";

        }

        // Both players are out of cards
        else if(Player1.Empty() && Player2.Empty()){

            io << "Draw!!\n";

        }
        D.Reset(); // Reset the deck
    }


    /**
    * Public : Print_Cards()
    *
    * Description:
    *      Gets passed two cards and prints them side by side.
    * 
    * Params:
    *      Card*  :  Player1's card
    *      Card*  :  Player2's card
    *
    * Returns:
    *      void
    */
    void WarGame::Print_Cards(Card *C1,Card *C2){ 
        
        // Get string versions of cards to be printed together
        string p1 = C1->Repr();
        string p2 = C2->Repr();
        string both = Term::fuse(p1,p2);
        io << both << "\n";

    }

       
    /**
    * Public : Add_to_Pile()
    *
    * Description:
    *      Places the player's top cards onto the pile to be compared.
    * 
    * Params:
    *      Card*  :  a player's top card from their hand
    *
    * Returns:
    *      void
    */
    void WarGame::Add_to_Pile(Card* players_card){

        Pile.push_front(players_card);
    }


    /**
    * Public : Take_Pile()
    *
    * Description:
    *      Takes the cards off the pile from the top.
    * 
    * Params:
    *      None
    *
    * Returns:
    *      Card*  :  the top card from the pile
    */
    Card* WarGame::Take_Pile(){

        Card *temp = Pile.front();  // temp gets the top pile card

        Pile.pop_front();           // delete the top card
    
        return temp;                // return the top card
    }


    /**
    * Public : War()
    *
    * Description:
    *      Each player will play four cards and the fourth card from each
    *      player will be compared to each other and the player with the 
    *      higher card will win all 10 cards that were placed on the pile.
    *      If there is another tie, the players will repeat the process
    *      until their is a winner. If either player runs out of cards
    *      then the other player wins.
    *      
    * Params:
    *      None
    *
    * Returns:
    *      void
    */
    void WarGame::War(){

        for(int i = 0;i < 4; i++)
        {   
            // Players play 4 cards each onto the pile
            P1Card = Player1.PlayCard();
            P2Card = Player2.PlayCard();
            Add_to_Pile(P1Card);
            Add_to_Pile(P2Card);

            // Print the pile
            Print_Cards(P1Card,P2Card);

            // Player 2 is the winner if player 1 is out of cards
            if(Player1.Empty())
            {   
                // While the pile is not empty
                while(!Empty()){
                        Player2.TakeCard(Take_Pile());
                }
                io << "Cards: " << Player1.Size() << " Cards: " << Player2.Size() << "\n";
                io << "Player 1 has ran out of cards\n";
                io << "Player 2 wins!\n\n";
                    

            }

            // Player 1 is the winner if player 2 is out of cards       
            if(Player2.Empty())
            {
                // While the pile is not empty
                while(!Empty()){
                        Player1.TakeCard(Take_Pile());
                }
                io << "Cards: " << Player1.Size() << " Cards: " << Player2.Size() << "\n";
                io << "Player 2 has ran out of cards\n";
                io << "Player 1 wins!\n\n";
                   
            }

            // There's no winner if both players run out of cards
            if(Player1.Empty() && Player2.Empty())
            {
                io << "Player 1 and Player 2 have ran out of cards\n";
            }
            
            // When on the 4th card compare the cards and declare the winner
            if(i == 3)
            {
                io << "Cards: " << Player1.Size() << " Cards: " << Player2.Size() << "\n";
                    
                // If there's a tie go again    
                if(P1Card->Rank() == P2Card->Rank())
                {
                    io << "WAR!!\n";
                        
                }

                // Else player 1 is the winner and gets all the cards
                else if(P1Card->Rank() > P2Card->Rank())
                {
                    io << "  Winner!\n\n";
                    while(!Empty())
                    {
                        Player1.TakeCard(Take_Pile());
                    }
                }

                // Else player 2 is the winner and gets all the cards
                else if(P1Card->Rank() < P2Card->Rank())
                {
                    io << "         Winner!\n\n";
                    while(!Empty())
                    {
                         Player2.TakeCard(Take_Pile());
                    }
                }

            }
                
        }    
                   
    }
