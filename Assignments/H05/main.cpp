#include "poker_game.hpp"



int main() {



    Term::IO io;



    Deck D(52);





    for(int i=0;i<5;i++){

        D.Shuffle();

        D.Print(5,true);

        io << Term::sleep(200); 

    }



    return 0;

}