#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	Player(int x, int y, sf::String file_name, int _size = 50, int start_x = 312, int start_y = 10);
	~Player();
	void set_coordinates(int x, int y);
	void set(int x, int y, std::string file_name, int _size = 50, int start_x = 312, int start_y = 10);
	sf::RectangleShape get_shape();
	int getx();
	int gety();
	void setx(int x);
	void sety(int y);
	void set_position(int pos);
	bool calc_position(int dice, int x[58], int y[58]);
	bool update_coordinates(int sq, int dice);
	void init();
	int get_position();
	static int Bluex[59], Bluey[59], Redx[59], Redy[59], Greenx[59], Greeny[59], Yellowx[59], Yellowy[59];
	int color;
	int count;
protected:
	sf::RectangleShape shape;
	sf::Texture texture;
	int position;
	int size, startx, starty;

};

