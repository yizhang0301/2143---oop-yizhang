
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ck.h"
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	ck c = ck(10, 10);
	/*sf::Clock clock;
	sf::Time start;
	sf::Time end;
	sf::Time elapsed;
	start = sf::seconds(50);
	end = sf::seconds(50);*/
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		cout << "Incrementing Clock: " << c.gettime() << endl;

		if (c.refinal())
		{
			window.close();
		}
		window.clear();
		//window.draw(shape);
		window.display();
	}

	return 0;
}
