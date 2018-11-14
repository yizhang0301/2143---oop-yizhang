#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class counter : public Text, Font {
private:
	Clock clock;
	Time start;
	Time end;
	Time elapsed;
	Text text;
	Font font;
	float ST;
	float ET;
	float time;



public:
	counter();
	counter(float startime, float endtime);
	counter(float startime, float endtime, float xcord, float ycord);
	Text getTime();
};
counter::counter() {
	X = 50;
	Y = 50;

	frameRate = 0;
	if (X == 50) {
		bounx = -1;
	}
	else if (X == 450) {
		bounx = 1;
	}
	if (Y == 50) {
		bouny = -1;
	}
	else if (Y == 350) {
		bouny = 1;
	}

	start = seconds(0.0);
	ST = 0.0;

	end = seconds(50.0);
	ET = 0.0;
	clock.restart();
	elapsed = clock.getElapsedTime();
	time = start.asSeconds();
	text.setString(to_string(time));
	setRecParam();
	setTextParam();
	this->push_back(rectangle);
	this->push_back(text);
}
counter::counter(int startime, int endtime) {
	X = 50.0;
	Y = 50.0;

	frameRate = 0;
	if (X == 50) {
		bounx = -1;
	}
	else if (X == 450) {
		bounx = 1;
	}
	if (Y == 50) {
		bouny = -1;
	}
	else if (Y == 350) {
		bouny = 1;
	}

	start = seconds(startime);
	ST = startime;

	end = seconds(endtime);
	ET = endtime;
	clock.restart();
	elapsed = clock.getElapsedTime();
	time = start.asSeconds();
	text.setString(to_string(time));
	setRecParam();
	setTextParam();

	this->push_back(rectangle);
	this->push_back(text);
}

counter::counter(int startime, int endtime, float xcord, float ycord) {
	X = xcord；
	Y = ycord;

	frameRate = 0;

	if (X == 50) {
		bounx = -1;
	}
	else if (X == 450) {
		bounx = 1;
	}
	if (Y == 50) {
		bouny = -1;
	}
	else if (Y == 350) {
		bouny = 1;
	}

	start = seconds(startime);
	ST = startime;

	end = seconds(endtime);
	ET = endtime;
	clock.restart();
	elapsed = clock.getElapsedTime();
	time = start.asSeconds();
	text.setString(to_string(time));
	setRecParam();
	setTextParam();
	this->push_back(rectangle);
	this->push_back(text);
}


void counter::updateTime() {

	if (time == ET) { 
		time = end.asSeconds();
		text.setString(to_string(time));
	}
	else if (ST > ET) { 
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() - elapsed.asSeconds();
		text.setString(to_string(time));
	}
	else if (ST > 0) { 
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() - elapsed.asSeconds();
		text.setString(to_string(time));
	}
	else {
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() + elapsed.asSeconds();
		text.setString(to_string(time));
	}

	if (frameRate == 25) {
		bounce();
		frameRate = 0;
	}
	else {
		frameRate++;
	}

	return;
}
void counter::setColors(Color cClock, Color cBackground, Color cBorder) {
	text.setFillColor(cClock);
	rectangle.setFillColor(cBackground);
	rectangle.setOutlineColor(cBorder);
}
bool counter::atEnd() {
	if (time == ET) {
		return true;
	}
	else return false;
}
void counter::bounce() {
	if (X == 50) {
		bounx = -1;
	}
	else if (X == 450) {
		bounx = 1;
	}
	if (Y == 50) {
		bouny = -1;
	}
	else if (Y == 350) {
		bouny = 1;
	}
	X -= bounx;
	Y -= bouny;
	rectangle.setPosition(X, Y);
	text.setPosition(X, Y);
}
void counter::setRecParam() {
	rectangle.setSize(Vector2f(100, 100));
	rectangle.setFillColor(Color::Black);
	rectangle.setOutlineColor(Color::Green);
	rectangle.setOutlineThickness(2);
	rectangle.setOrigin(50, 50);
	rectangle.setPosition(X, Y);
	return;
}
void counter::setTextParam() {
	text.setFont(font);
	text.setCharacterSize(48);
	text.setFillColor(Color::Red);
	text.setOrigin(24, 24);
	text.setPosition(X, Y);
	return;
}
int main()
{
	RenderWindow window(VideoMode(500, 500), "SFML Clock");

	counter clock(25, 0, 50, 50);
	counter clock2(0, 25, 450, 50);

	clock.setColors(Color::Red);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (window.isOpen() && clock.atEnd() && clock2.atEnd())
			window.close();

		window.clear();

		window.draw(clock);
		window.draw(clock2);

		clock.updateTime();
		clock2.updateTime();

		window.display();
	}

	return 0;
}
