#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "ck.h"
using namespace std;

ck::ck(int s, int e) {
	if (s > e) {
		decrementing = true;
	}
	else {
		decrementing = false;
	}
	start = sf::seconds(s);
	end = sf::seconds(e);
	final = false;
	isInfinite = false;
}

ck::ck(bool in, int s1, int e1) {
	if (s1 > e1) {
		decrementing = true;
	}
	start = sf::seconds(s1);
	end = sf::seconds(e1);
	final = false;
	isInfinite = true;
}

int ck::Time()
{
	elapsed = clock.Time();

	if (!decrementing) {
		if ((start + elapsed).asSeconds() == end.asSeconds()) {
			final = true;
		}
		return start.asSeconds() + elapsed.asSeconds();
	}
	if ((start - elapsed).asSeconds() == end.asSeconds()) {
		final = true;
	}
	return start.asSeconds() - elapsed.asSeconds();
}


int ck::gettime()
{
	return Time();
}

void ck:: restart() {
	clock.restart();
}
bool ck::refinal() {
	return final;
}


