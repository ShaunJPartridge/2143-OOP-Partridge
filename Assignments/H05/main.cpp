#include "termio.h"
#include "PlayingCard2.hpp"
#include <string>

using namespace std;

int main() {



    Term::IO io;




    for(int i=0;i<50;i++){

      

        io << Term::sleep(200); 

    }



    return 0;

}