#include "termio.h"
#include <algorithm> // std::random_shuffle
#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

/*
  ██████╗ █████╗ ██████╗ ██████╗
 ██╔════╝██╔══██╗██╔══██╗██╔══██╗
 ██║     ███████║██████╔╝██║  ██║
 ██║     ██╔══██║██╔══██╗██║  ██║
 ╚██████╗██║  ██║██║  ██║██████╔╝
  ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝
*/

class Card {
private:
    const string spade = "♠";
    const string diamond = "♦";
    const string heart = "♥";
    const string club = "♣";

    const string suits[4] = {"♠", "♦", "♣", "♥"};

    // Black background        blue ,  red , blue , red
    const string colors2[4] = {"&60", "&20", "&60", "&20"};

    // Colored background      blue  , red  , blue , red
    const string colors[4] = {"&16", "&12", "&16", "&12"};

    // Card labels (could be "Iron Man" or "Charmander" or "Elf" ... anything)
    const string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    int suitNum;     // value 0-3 : num index of suit
    int rank;        // 0-13      : num value of rank
    int number;      // 1-52      : unique value determines card
    int value;       // 1-14      : numeric value used for comparison
    string suitChar; // "♠", "♦", "♣", "♥"
    string rankChar; // Ace, 1 ,2 ,3 ... Q, K
    string color;    // Spade=blue, Diamond=red, etc.
    public:
    friend ostream;

    Card(int);
    string Repr();
    bool operator<(const Card &);
    bool operator>(const Card &);
    bool operator==(const Card &);
    bool operator!=(const Card &);
    bool operator()(const Card &);
    void setForegroundColor(string color);       // set foreground color of card
    void setBackgroundColor(string color);      // set background color of card
    void setColors(string fore,string back);      // set fore and back
    void setCharacterColor(string color);        // set symbol color 
    void setNumberColor(string color);          // set number color
    void setColors(string fore, string back, string symbol, string number);
};
