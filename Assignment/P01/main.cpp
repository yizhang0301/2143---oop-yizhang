#include "PlayingCard.hpp"

using namespace std;

int main() {

	Term::IO io;

	Deck D(52);

	for (int i = 0;i < 50;i++) {
		D.Shuffle();
		D.Print(2, true);
		io << "Player 1   Player 2\n";
		break;
		io << Term::sleep(200);
	}

	D.Table();

	system("Pause");
	return 0;	
}
