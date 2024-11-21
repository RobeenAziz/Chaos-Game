// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
	
	vector<Vector2f> vertices;
	vector<Vector2f> points;

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Font font;
		font.loadFromFile("arial.ttf");
		Text text;
		Text text2;
		text.setFont(font);
		text.setString("Make 3 points for triangle");
		text.setCharacterSize(24);
		text.setFillColor(Color::Red);
		text2.setFont(font);
		text2.setString("point 4th time to start algorithm");
		text2.setCharacterSize(24);
		text2.setFillColor(Color::Red);
		text2.setPosition(0, 25);
		Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == Event::Closed)
		    {
					// Quit the game when the window is closed
					window.close();
		    }
		    if (event.type == sf::Event::MouseButtonPressed)
		    {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			    std::cout << "the left button was pressed" << std::endl;
			    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	
			    if(vertices.size() < 3)
			    {
				vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			    else if(points.size() == 0)
			    {
					points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
				///fourth click
				///push back to points vector
			    }
			}
		    }
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/
	
		if(points.size() > 0)
		{
			int selectedvert = rand() % 3;
			Vector2f vertcord = vertices[selectedvert];
			Vector2f curpoint = points.back();
			Vector2f midpoint((vertcord.x + curpoint.x) / 2,(vertcord.y + curpoint.y) / 2);
			points.push_back(midpoint);
			
		    ///generate more point(s)
		    ///select random vertex
		    ///calculate midpoint between random vertex and the last point in the vector
		    ///push back the newly generated coord.
		}

	
		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();
		for(int i = 0; i < vertices.size(); i++)
		{
		    RectangleShape rect(Vector2f(10,10));
		    rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
		    rect.setFillColor(Color::Blue);
		    window.draw(rect);
		}
		if (points.size() > 0)
		{
			for (int i = 0; i < points.size(); i++)
			{
				RectangleShape rect2(Vector2f(10, 10));
				rect2.setPosition(Vector2f(points[i].x - 5, points[i].y - 5));
				rect2.setFillColor(Color::Blue);
				window.draw(rect2);
			}
		}
		window.draw(text);
		if (vertices.size() == 3)
		{
			window.draw(text2);
		}
		window.display();
	}
}
