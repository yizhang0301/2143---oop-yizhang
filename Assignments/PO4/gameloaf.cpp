#include<string>
#include<iostream>
#include<fstream>
#include "gameloaf.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
GameOfLife::GameOfLife(int width, int height) {
	World = new golCell[height];
	id = 0;;
	frameCount = 0;
	framert = 50;
	Width = width;
	Height = height; 

	// Creation of our window
	Window.create(VideoMode(width, height), "Game of Life");

	for (int i = 0; i < height; i++) {
		W[i] = new golCell[width];
		for (int j = 0; j < width; j++) {
			W[i][j].setCellPos(i, j);
		}
	}
}
GameOfLife::GameOfLife(int width, int height, int rate) {
	width = width;
	height = height;
	frameCount = 0;

	framert = rate;
	Window.create(VideoMode(width, height), "Game of Life");

	W = new golCell*[height];
	id = 0;

	for (int i = 0; i < height; i++) {
		W[i] = new golCell[width];
		for (int j = 0; j < width; j++) {
			W[i][j].setCellPos(i, j);
		}
	}
}
GameOfLife::~GameOfLife() {
	for (int i = 0; i < worldRows; i++) {
		delete[]W[i];
	}
	delete[]W;
}

void  GameOfLife::drawWorld() {
	Window.clear();
	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			Window.draw(W[i][j].Rect);
		}
	}

	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			cout << *(&W[i][j].isAlive) << "";
		}
		cout << endl;
	}
	sleep(milliseconds(500));
	Window.display();
}
void  GameOfLife::printWorld(string ofileName) {
	ofstream myfile;
	myfile.open(fileName);
	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			myfile << *(&W[i][j].isAlive) << "";
		}
		myfile << endl;
	}
	myfile.close();
}
int GameOfLife::Neighbors(int r, int c) {
	int neighborCount = 0;
	if (onWorld(r - 1, c - 1) && W[r - 1][c - 1].isAlive) {
		neighborCount++;
	}
	if (onWorld(r - 1, c) && W[r - 1][c].isAlive) {
		neighborCount++;
	}
	if (onWorld(r - 1, c + 1) && W[r - 1][c + 1].isAlive) {
		neighborCount++;
	}
	if (onWorld(r, c - 1) && W[r][c - 1].isAlive) {
		neighborCount++;
	}
	if (onWorld(r, c + 1) && W[r][c + 1].isAlive) {
		neighborCount++;
	}
	if (onWorld(r + 1, c - 1) && W[r + 1][c - 1].isAlive) {
		neighborCount++;
	}
	if (onWorld(r + 1, c) && W[r + 1][c].isAlive) {
		neighborCount++;
	}
	if (onWorld(r + 1, c + 1) && W[r + 1][c + 1].isAlive) {
		neighborCount++;
	}
	return neighborCount;
}
bool GameOfLife::onWorld(int row, int col) {
	if ((row >= 0 && row < worldRows) && (col >= 0 && col < worldCols)) {
		return true;
	}
	else {
		return false;
	}
}
void GameOfLife::gengaisquare(int row, int col) {
	W[row][col].neighborCount;
	if (W[row][col].isAlive == true && W[row][col].neighborCount < 2) {
		W[row][col].isAlive = false;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Black);
	}
	if (W[row][col].isAlive == true && W[row][col].neighborCount > 3) {
		W[row][col].isAlive = false;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Black);
	}
	if (W[row][col].isAlive == true && W[row][col].neighborCount == 2 || W[row][col].neighborCount == 3) {
		W[row][col].isAlive = true;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Blue);
	}
	if (W[row][col].isAlive == false && W[row][col].neighborCount == 3) {
		W[row][col].isAlive = true;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Blue);
	}
	else {
		W[row][col].isAlive = W[row][col].isAlive;

		if (W[row][col].isAlive == true) {
			W[row][col].setCellPos(row, col);
			W[row][col].changeColor(Color::Blue);
		}
		else if (W[row][col].isAlive == false) {
			W[row][col].setCellPos(row, col);
			W[row][col].changeColor(Color::Black);
		}

	}
}
ifstream GameOfLife::Readfile(string fileName) {
	ifstream infile;
	infile.open(fileName);
	if (!infile) {
		exit(1);
	}
	return infile;
}
golCell** GameOfLife::Buildarray(ifstream& infile) {
	infile >> worldRows >> worldCols;
	W = new golCell*[worldRows];
	for (int i = 0; i < worldRows; i++) {
		W[i] = new golCell[worldCols];
	}
	int** tempArray = new int *[worldRows];

	for (int i = 0; i < worldRows; i++) {
		tempArray[i] = new int[worldCols];
	}
	char x;
	string myString = "";
	while (!infile.eof()) {
		x = infile.get();
		if (x == '1' || x == '0') {
			myString = myString + x;
		}
	}
	char * characterArray = new char[myString.length() + 1];
	strcpy_s(characterArray, myString.length() + 1, myString.c_str());

	int k = 0;
	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			tempArray[i][j] = (int)characterArray[k] - 48;
			k++;
		}
	}
	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			W[i][j].isAlive = tempArray[i][j];
			if (W[i][j].isAlive == true) {
				W[i][j].setCellPos(i, j);
				W[i][j].changeColor(Color::Blue);
			}
			else if (W[i][j].isAlive == false) {
				W[i][j].setCellPos(i, j);
				W[i][j].changeColor(Color::Black);
			}
		}
	}

	drawWorld();
	return W;

}
void GameOfLife::rsGen(int runAmt) {
	for (int x = 0; x < runAmt; x++) {
		for (int i = 0; i < worldRows; i++) {
			for (int j = 0; j < worldCols; j++) {
				W[i][j].neighborCount = Neighbors(i, j);
			}

		}
		for (int i = 0; i < worldRows; i++) {
			for (int j = 0; j < worldCols; j++) {
				gengaisquare(i, j);
			}

			if (x == 337) {
				printWorld(fileName);
			}
		} 
		cout << "Printing Array to Draw: " << endl;
		cout << "This is the  : " << x + 1 << " run" << endl;
		drawWorld();
	}
}
void GameOfLife::run(string inputFileName, string numberOfRuns, string outputFileName) {
	fileName = outputFileName;
	ifstream fileStream;
	try {
		fileStream = Readfile(inputFileName);
	}
	catch (exception& e) {
		exit(1);
	}
	fileStream = Readfile(inputFileName);
	golCell** World = Buildarray(fileStream);
	int num = stoi(numberOfRuns);
	rsGen(num);

}

