/*
 
  /$$   /$$  /$$$$$$  /$$$$$$$                                                           
 | $$  | $$ /$$$_  $$| $$____/                                                           
 | $$  | $$| $$$$\ $$| $$                                                                
 | $$$$$$$$| $$ $$ $$| $$$$$$$                                                           
 | $$__  $$| $$\ $$$$|_____  $$                                                          
 | $$  | $$| $$ \ $$$ /$$  \ $$                                                          
 | $$  | $$|  $$$$$$/|  $$$$$$/                                                          
 |__/  |__/ \______/  \______/                                                           
                                                                                         
                                                                                         
                                                                                         
   /$$$$$$    /$$ /$$   /$$  /$$$$$$                                                     
  /$$__  $$ /$$$$| $$  | $$ /$$__  $$                                                    
 |__/  \ $$|_  $$| $$  | $$|__/  \ $$                                                    
   /$$$$$$/  | $$| $$$$$$$$   /$$$$$/                                                    
  /$$____/   | $$|_____  $$  |___  $$                                                    
 | $$        | $$      | $$ /$$  \ $$                                                    
 | $$$$$$$$ /$$$$$$    | $$|  $$$$$$/                                                    
 |________/|______/    |__/ \______/                                                     
                                                                                         
                                                                                         
                                                                                         
  /$$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$$ /$$$$$$$  /$$$$$$ /$$$$$$$   /$$$$$$  /$$$$$$$$
 | $$__  $$ /$$__  $$| $$__  $$|__  $$__/| $$__  $$|_  $$_/| $$__  $$ /$$__  $$| $$_____/
 | $$  \ $$| $$  \ $$| $$  \ $$   | $$   | $$  \ $$  | $$  | $$  \ $$| $$  \__/| $$      
 | $$$$$$$/| $$$$$$$$| $$$$$$$/   | $$   | $$$$$$$/  | $$  | $$  | $$| $$ /$$$$| $$$$$   
 | $$____/ | $$__  $$| $$__  $$   | $$   | $$__  $$  | $$  | $$  | $$| $$|_  $$| $$__/   
 | $$      | $$  | $$| $$  \ $$   | $$   | $$  \ $$  | $$  | $$  | $$| $$  \ $$| $$      
 | $$      | $$  | $$| $$  | $$   | $$   | $$  | $$ /$$$$$$| $$$$$$$/|  $$$$$$/| $$$$$$$$
 |__/      |__/  |__/|__/  |__/   |__/   |__/  |__/|______/|_______/  \______/ |________/
                                                                                         
                                                                                         
                                                                                         
 
*/
///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Shaun Partridge
// Email:            spartridgeb15@gmail.com
// Label:            P01
// Title:            Playing Card Class
// Course:           CMPS 2143
// Semester:         Spring 2020
//
// Description:
//       This file will create playing cards that can be used for a variety
//       of card games. This file will also be overloading the ostream
//       operator "<<" to print cards, along with boolean operators to compare
//       cards to one another.
//
// Usage:
//       This file will create playing cards for the game of war.
// Files: 
//
//      PlayingCard.hpp    : Implements a playing card
//
/////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>

#include <string>

#include <vector>


using namespace std;


/*
 
   ______    ______   _______   _______  
  /      \  /      \ /       \ /       \ 
 /$$$$$$  |/$$$$$$  |$$$$$$$  |$$$$$$$  |
 $$ |  $$/ $$ |__$$ |$$ |__$$ |$$ |  $$ |
 $$ |      $$    $$ |$$    $$< $$ |  $$ |
 $$ |   __ $$$$$$$$ |$$$$$$$  |$$ |  $$ |
 $$ \__/  |$$ |  $$ |$$ |  $$ |$$ |__$$ |
 $$    $$/ $$ |  $$ |$$ |  $$ |$$    $$/ 
  $$$$$$/  $$/   $$/ $$/   $$/ $$$$$$$/  
                                         
                                                                          
*/

/**
 * Card
 *
 * Description:
 *      This class will create an actual representation of playing cards
 *      by doing arithmetic to calculate the suit and rank of each card,
 *      along with the giving each card its corresponding color to its suit. 
 *      This class will also overload the "<<" and boolean operators to print
 *      and compare cards.
 *
 * Public Methods:
 * 
 *      friend ostream;
 *                           Card(int);
 *      string               Repr();
 *      bool                 operator<(const Card &);
 *      bool                 operator>(const Card &);
 *      bool                 operator==(const Card &);
 *      bool                 operator!=(const Card &);
 *      bool                 operator()(const Card &);
 *      
 * Private:
 * 
 *      const string         spade
 *      const string         diamond
 *      const string         heart     
 *      const string         club
 *      const string         suits[4]
 *      const string         colors[4]
 *      const string         ranks[13]
 *      int                  suitNum
 *      int                  rank
 *      int                  number
 *      int                  value
 *      string               suitChar
 *      string               rankChar
 *      string               color
 *          
 * Usage:
 *
 *      friend ostream      // Granted access to cards' private data members
 *                              // to print a card
 * 
 *      Card(int)           // Overloaded constructor that initializes a card
 *                          Ex.) Card C1(5) is a 5 of Spades
 *                               Card C2(14) is a Ace of Diamonds
 * 
 *      Repr()              // Returns a string representation of a card
 *      
 *      C1 < C2;             // Compares the cards' rank and results in true
 *      C1 > C2;             // Compares the cards' rank and results in false
 *      C1 == C2;            // Compares the cards' rank and results in false
 *      C1 != C2;            // Compares the cards' rank and results in true
 *
 */
class Card {

private:

    // Card suits
    const string suits[4] = {"♠", "♦", "♣", "♥"};

    // Colored background      black  , red  , black , red
    const string colors[4] = {"&18", "&28", "&18", "&28"};

    // Card labels (could be "Iron Man" or "Charmander" or "Elf" ... anything)
    const string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
                            
    int suitNum;     // value 0-3 : num index of suit

    int rank;        // 0-13      : num value of rank

    int number;      // 1-52      : unique value determines card

    int value;       // 1-14      : numeric value used for comparison

    string suitChar; // "♠", "♦", "♣", "♥"

    string rankChar; // Ace, 1 ,2 ,3 ... Q, K

    string color;    // Spade=black, Diamond=red, etc.

public:

    friend ostream;

    Card();

    Card(int);

    string Repr();

    string Repr2();

    bool operator<(Card *);

    bool operator>(Card *);

    bool operator==(Card *);

    bool operator!=(Card *);

    bool operator()(Card *);

    int Rank();

    void SetForgroundColor(string color);

};

/**
* Public : Constructor
*
* Description:
*      Represents a single card in a deck of cards to include a
*      value along with rank and suit. We are assuming a standard
*      card type in a deck of playing cards.
*
* Params:
*      None
*
* Returns:
*      None
*/
Card::Card(){
   int number;
   int suitNum;
   int suitChar;
   int color;
   int rank;
   int rankChar;
}


/**
* Public : Overloaded Constructor
*
* Description:
*      Represents a single card in a deck of cards to include a
*      value along with rank and suit. We are assuming a standard
*      card type in a deck of playing cards.
*
* Params:
*      int :  value from 0 - 51 that represents a card in a deck.
*
* Returns:
*      None
*/
Card::Card(int num) {                               

    number = num;
    suitNum = number / 13;
    suitChar = suits[suitNum];
    color = colors[suitNum];
    rank = number % 13;
    rankChar = ranks[rank];
}


/**
* Public : Rank()
*
* Description:
*       Returns a cards rank
*
* Params:
*      None
*
* Returns:
*      int :  a cards rank
*/
int Card::Rank(){
    return this->rank;
}


/**
* Public : Repr
*
* Description:
*      Returns a string representation of the card class with
*      colors embedded.
*
* Params:
*      None
*
* Returns:
*      [string] - representation of card
*/
string Card::Repr() {

    // string "s" acts as an accumulator to create an
    // image of a card

    string s = "";

    s += color + "┌────┐&00 \n";    // "&00" means the default color of a card
    s += color + "│";
    if (rank != 9) {
        s += color + " ";
    }
    s += color + rankChar + " " + suitChar + "│&00 \n";
    s += color + "└────┘&00 ";

    return s;                       // return the card

}

// Repr2()
string Card::Repr2() {

    // string "s" acts as an accumulator to create an
    // image of a card

    string s = "";

    s += color + "┌────┐&85 \n";    // "&00" means the default color of a card

    s += color + "│    │&85 \n";

    s += color + "└────┘&85 \n";
    
    return s;               // return the card

}


/**
 * Public : operator <<
 *
 * Description:
 *      Overload ostream and send the string representation "Repr"
 *      of the card.
 *
 *      We don't need the scope resolution operator (Card::) since
 *      this is a "friend" of card.
 *
 * Params:
 *      [ostream&] : os
 *      [Card]     : obj
 *
 * Returns:
 *      [ostream&]
 */
ostream &operator<<(ostream &os, Card obj) {

    // An os object that contains the string
    // representation of a card.

    os << obj.Repr();

    return os;

}



/**
 * Public : operator <
 *
 * Description:
 *      Overloads the "<" operator to compare two cards and returns
 *      true if "this->rank" is less than rhs.rank.
 *
 * Params:
 *      const [Card*]     : rhs
 *
 * Returns:
 *      bool
 */

bool Card::operator<(Card *rhs) {

    return this->rank < rhs->rank;

}



/**
 * Public : operator >
 *
 * Description:
 *      Overloads the ">" operator to compare two cards and returns
 *      true if "this->rank" is greater than rhs.rank.
 *
 * Params:
 *      const [Card*]     : rhs
 *
 * Returns:
 *      bool
 */

bool Card::operator>(Card *rhs) {

    return this->rank > rhs->rank;

}



/**
 * Public : operator ==
 *
 * Description:
 *      Overloads the "==" operator to compare two cards and returns
 *      true if the cards' ranks are eqaul.
 *
 * Params:
 *      const [Card*]     : rhs
 *
 * Returns:
 *      bool
 */

bool Card::operator==(Card *rhs) {

    return this->rank == rhs->rank;

}



/**
 * Public : operator !=
 *
 * Description:
 *      Overloads the "!=" operator to compare two cards and returns 
 *      true if the cards' ranks are not equal.
 *
 * Params:
 *      const [Card*]     : rhs
 *
 * Returns:
 *      bool
 */

bool Card::operator!=(Card *rhs) {

    return this->rank != rhs->rank;

}



/**
 * Public : operator ()
 *
 * Description:
 *      Overloads the "()" operator to compare two Cards witout
 *      using the "<" operator. Returns true if "this->rank" is
 *      less than "rhs.rank".
 * 
 * Params:
 *      const [Card*]     : rhs
 *
 * Returns:
 *      bool
 */

bool Card::operator()(Card *rhs) {

    return (this->rank < rhs->rank);

}