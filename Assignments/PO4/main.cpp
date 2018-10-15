

#include "pch.h"
#include<fstream>
#include<string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "gameloaf.h"
using namespace sf;
using namespace std;

void printHeader(ofstream& outfile);

int main(int argc, char *argv[]) {
	int rate = 10;
	GameOfLife Gol(500, 500, rate);

	ifstream infile;
	ofstream outfile;
	string ifileName;
	string num;
	string fileName;
	printHeader(outfile);
	if (argc < 4) {
		cout << "usage: " << argv[0] << " <filename>\n";
	}
	else {
		ifileName = argv[1];
		num = argv[2];	
		fileName = argv[3];
	}
	while (Gol.Window.isOpen()) {
		Event event;
		while (Gol.Window.pollEvent(event)) {
			if (Gol.frameCount % Gol.framert == 0) {

				Gol.run(ifileName, num, fileName);
			}
			
			if (event.type == Event::Closed) {
				Gol.Window.close();
			}

		}
		Gol.frameCount++;
	}
	return 0;
}
void printHeader(std::ofstream& outfile)
{
	outfile << "@author yizhang\n";
	outfile << "Version 1.0 10/14/18\n";
	outfile << "@github https://github.com/yizhang0301";
	outfile << "Program 4 - Game of Life\n\n";
}
