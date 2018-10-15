//yizhang
//program 4
//2018 / 10 / 15
//github: https://github.com/yizhang0301 
#include <fstream>
#include <cstring>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
struct golCell {
	bool isAlive;
	int neighborCount;
	RectangleShape shape;
	int Width;
	int Height;
	golCell() {
		Width = 10;
		Height = 10;
		shape.setFillColor(Color::Green);
		shape.setOutlineColor(Color::Black);
		shape.setSize(Vector2f(Width, Height));
		shape.setOutlineThickness(1);
		neighborCount = 0;
	}
	void setCellPos(int x, int y) {
		shape.setPosition(x*Width, y*Height);
	}

};

struct gameOfLife {
	int Width;
	int Height;
	int FrameCount;
	int FrameRate;
	RenderWindow Window;
	golCell** World;
	golCell** NWorld;
	gameOfLife(int h, int w) {
		Height = h;
		Width = w;
		FrameCount = 0;
		FrameRate = 5;
		Window.create(VideoMode(Width*10, Height*10), "Game of Life");

		World = new golCell*[h];

		for (int i = 0; i < h; i++) {
			World[i] = new golCell[w];
			for (int j = 0; j < w; j++) {
				World[i][j].setCellPos(i, j);
				World[i][j].isAlive = false;
			}
		}
	}
	void printBoard(ofstream& outfile) {
		outfile << "yizhang\n";
		outfile << "program 4\n";
		outfile << "2018/10/15\n";
		outfile << "github: https://github.com/yizhang0301 \n";
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				if (World[i][j].isAlive) {
					outfile << "1";
				}
				else {
					outfile << "0";
				}
			}
			outfile << "\n";
		}
	}
	void initBoard(ifstream &infile) {
		int Cols;
		int Rows;
		string line;
		infile >> Cols >> Rows;

		NWorld = new golCell*[Rows];

		for (int i = 0; i < Rows; i++) {
			NWorld[i] = new golCell[Cols];
		}

		for (int i = 0; i < Rows; i++) {

			infile >> line;


			for (int j = 0; j < Cols; j++) {
				NWorld[i][j].isAlive = (line[j] == '1');
				World[j][i].isAlive = NWorld[i][j].isAlive;
			}
		}
	}
	void drawWorld() {
		Window.clear();
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				if (World[i][j].isAlive) {
					Window.draw(World[i][j].shape);
				}
			}
		}
		Window.display();
	}
	bool onWorld(int i, int j) {
		if (i < 0) {
			return false;
		}
		else if (i >= Height) {
			return false;
		}
		if (j < 0) {
			return false;
		}
		else if (j >= Width) {
			return false;
		}
		return true;
	}
	void Neighbors() {
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				World[i][j].neighborCount = 0;
				if (onWorld(i - 1, j - 1)) {
					if (World[i - 1][j - 1].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i - 1, j)) {
					if (World[i - 1][j].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i - 1, j + 1)) {
					if (World[i - 1][j + 1].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i, j - 1)) {
					if (World[i][j - 1].isAlive) {
						World[i][j].neighborCount++;
					}
				}
				if (onWorld(i, j + 1)) {
					if (World[i][j + 1].isAlive) {
						World[i][j].neighborCount++;
					}
				}
	if (onWorld(i + 1, j - 1)) {
	if (World[i + 1][j - 1].isAlive) {
	World[i][j].neighborCount++;
}
}
	if (onWorld(i + 1, j)) {
	if (World[i + 1][j].isAlive) {
	World[i][j].neighborCount++;
}
}
	if (onWorld(i + 1, j + 1)) {
	if (World[i + 1][j + 1].isAlive) {
	World[i][j].neighborCount++;
}
}
}
}
}
	void build(int num) {
		for (int i = 0; i < num; i++) {
			Neighbors();
			for (int j = 0; j < Height; j++) {
				for (int k = 0; k < Width; k++) {
					if (World[j][k].neighborCount < 2) {
						World[j][k].isAlive = false;
					}
					else if (World[j][k].neighborCount == 3) {
						World[j][k].isAlive = true;
					}
					else if (World[j][k].neighborCount > 3) {
						World[j][k].isAlive = false;
					}
				}
			}
		}

	}
	
};



int main() {
	gameOfLife Gol(40, 50);
	ifstream infile;
	ofstream outfile;
	infile.open("gen_zero.txt");
	outfile.open("output.txt");
	Gol.initBoard(infile);
	Gol.build(338);
	while (Gol.Window.isOpen())
	{
		Event event;
		while (Gol.Window.pollEvent(event))
		{
			if (Gol.FrameCount % Gol.FrameRate == 0) {
				Gol.drawWorld();
			}
			else if (event.type == Event::Closed)
				Gol.Window.close();
			Gol.FrameCount++;
		}
	}
	Gol.printBoard(outfile);
	infile.close();
	outfile.close();
	return 0;
}
