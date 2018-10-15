#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
struct golCell {
	bool isAlive;
	int neighborCount;
	RectangleShape Rect;
	int Width;
	int Height;
	golCell() {
		isAlive = 0;
		neighborCount = 0;
		Width = 10;
		Height = 10;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Cyan);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
	}
	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}
	void changeColor(Color nameOfColor) {
		Rect.setFillColor(nameOfColor);
	}
};
class GameOfLife {
private:
	golCell* World;	
	int nums[10];
	int id;
public:
	golCell ** W;
	int Width;
	int Height;
	int worldRows;	
	int worldCols;  
	int frameCount;
	int framert;
	RenderWindow Window;
	string fileName;  
	void printWorld(string);
	bool onWorld(int, int);
	int Neighbors(int, int);
	void gengaisquare(int, int);
	ifstream Readfile(string); 
	golCell** Buildarray(ifstream&); 
	void rsGen(int); 
	void run(string, string, string);
	~GameOfLife(); 
	GameOfLife(int width, int height);
	GameOfLife(int width, int height, int rate); 
	void drawWorld();
};
