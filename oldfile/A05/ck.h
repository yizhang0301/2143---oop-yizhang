#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


using namespace std;

class ck {
private:
	sf::Clock clock;
	sf::Time start;
	sf::Time end;
	sf::Time elapsed;
	bool decrementing;
	bool isInfinite;
	bool final;
public:
	ck();
	ck(int s, int e);
	ck(bool in, int s1, int e1);
	int Time();  
	int gettime();
	void restart();
	bool refinal();
};
#pragma once
