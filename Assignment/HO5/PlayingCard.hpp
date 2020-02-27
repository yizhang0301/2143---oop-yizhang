#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card {

private:

	const string spade = "♠";
	const string diamond = "♦";
	const string heart = "♥";
	const string club = "♣";
	const string suits[4] = { "♠", "♦", "♣", "♥" };
	const string colors[4] = { "&18", "&28", "&18", "&28" };
	const string ranks[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	int suitNum;     
	int rank;        
	int number;      
	int value;       
	string suitChar;
	string rankChar; 
	string color; 
public:
	friend ostream;
	Card(int);
	string Repr();
	bool operator<(const Card&);
	bool operator>(const Card&);
	bool operator==(const Card&);
	bool operator!=(const Card&);
	bool operator()(const Card&);

};


Card::Card(int num) {                               
	number = num;
	suitNum = number / 13;
	suitChar = suits[suitNum];
	color = colors[suitNum];
	rank = number % 13;
	rankChar = ranks[rank];
}

string Card::Repr() {
	string s = "";
	s += color + "┌────┐&00 \n";  
	s += color + "│";
	if (rank != 9) {
		s += color + " ";
	}
	s += color + rankChar + " " + suitChar + "│&00 \n";
	s += color + "└────┘&00 ";
	return s; 
}
ostream& operator<<(ostream& os, Card obj) {
	os << obj.Repr();
	return os;
}

bool Card::operator<(const Card& rhs) {
	return this->rank < rhs.rank;
}
bool Card::operator>(const Card& rhs) {
	return this->rank > rhs.rank;
}
bool Card::operator==(const Card& rhs) {
	return this->rank == rhs.rank;
}
bool Card::operator!=(const Card& rhs) {
	return this->rank != rhs.rank;
}
bool Card::operator()(const Card& rhs) {
	return (this->rank < rhs.rank);
}
