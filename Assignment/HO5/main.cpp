///////////////////////////////////////////////////////////////////////////////
//
// Author:           yizhang
// Email:            zy19950301@126.com
// Course:           CMPS 2143
// Semester:         Spring 2020
// Date:             2/5/2020
//
// Description: card game
//    
//
/////////////////////////////////////////////////////////////////////////////////
#include "PlayingCard.hpp"

int main() {

	Term::IO io;

	Deck D(52);


	for (int i = 0; i < 50; i++) {
		D.Shuffle();
		D.Print(5, true);
		io << Term::sleep(200);
	}

	return 0;
}
