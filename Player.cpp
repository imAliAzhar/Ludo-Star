#include "Player.h"

///////////initilize static data members/////////////////////// 
int Player::Bluex[59] = {};
int Player::Bluey[59] = {};
int Player::Redx[59] = {};
int Player::Redy[59] = {};
int Player::Greenx[59] = {};
int Player::Greeny[59] = {};
int Player::Yellowx[59] = {};
int Player::Yellowy[59] = {};
///////////////////////////////////////////////////////////////

Player::Player(int x, int y, sf::String file_name, int _size, int start_x, int start_y)
{
	size = _size;
	startx = start_x;
	starty = start_y;

	init();
	shape.setOrigin(-x, -y);
	texture.loadFromFile(file_name);
	shape.setSize(sf::Vector2f(size, size));
	shape.setTexture(&texture);
	position = -1;
}

Player::Player()
{
	init();
	position = -1;
}

Player::~Player()
{

}


void Player::set_coordinates(int x, int y)
{
	shape.setOrigin(-x, -y);
}

void Player::set(int x, int y, std::string file_name, int _size, int start_x, int start_y)
{
	size = _size;
	startx = start_x;
	starty = start_y;

	shape.setOrigin(-x, -y);
	texture.loadFromFile(file_name);
	shape.setSize(sf::Vector2f(size, size));
	shape.setTexture(&texture);

	init();
}

sf::RectangleShape Player::get_shape()
{
	return shape;
}

int  Player::getx()
{
	sf::Vector2f S = shape.getOrigin();

	return -S.x;
}

int  Player::gety()
{
	sf::Vector2f S = shape.getOrigin();

	return -S.y;
}

void Player::setx(int x)
{
	shape.setOrigin(-x, -gety());
}

void Player::sety(int y)
{
	shape.setOrigin(-getx(), -y);
}

bool Player::calc_position(int d, int X[58], int Y[58])
{
	if ((position + d) > 56)
		return true;
	if (position < 0 && d == 6)
		position = 0;
	else if (position >= 0)
		position += d;
	else
		return true;

	if (position >= 0)
	{
		setx(X[position]);
		sety(Y[position]);
	}
	else
		return true;

	return false;
}

bool Player::update_coordinates(int sq, int dice)
{
	bool run;

	switch (sq)
	{
	case 1:
		run = calc_position(dice, Bluex, Bluey);
		break;
	case 2:
		run = calc_position(dice, Redx, Redy);
		break;
	case 3:
		run = calc_position(dice, Greenx, Greeny);
		break;
	case 4:
		run = calc_position(dice, Yellowx, Yellowy);
		break;
	}

	return run;
}

void Player::init()
{

	{//BLUE
		Bluex[58] = startx + (size * (1.8));
		Bluey[58] = starty + (size * (1.9));


		Bluex[0] = startx + size;
		Bluey[0] = starty + (size * 6);

		for (int i = 1; i <= 4; i++)
		{
			Bluex[i] = Bluex[i - 1] + size;
			Bluey[i] = Bluey[0];
		}

		for (int i = 5; i <= 10; i++)
		{
			Bluex[i] = Bluex[4] + size;
			Bluey[i] = Bluey[i - 1] - size;
		}

		Bluex[11] = Bluex[10] + size;
		Bluex[12] = Bluex[11] + size;
		Bluey[12] = Bluey[11] = Bluey[10];

		for (int i = 13; i <= 17; i++)
		{
			Bluex[i] = Bluex[12];
			Bluey[i] = Bluey[i - 1] + size;
		}

		for (int i = 18; i <= 23; i++)
		{
			Bluex[i] = Bluex[i - 1] + size;
			Bluey[i] = Bluey[17] + size;
		}

		Bluex[25] = Bluex[24] = Bluex[23];
		Bluey[24] = Bluey[23] + size;
		Bluey[25] = Bluey[24] + size;

		for (int i = 26; i <= 30; i++)
		{
			Bluex[i] = Bluex[i - 1] - size;
			Bluey[i] = Bluey[25];
		}

		for (int i = 31; i <= 36; i++)
		{
			Bluex[i] = Bluex[30] - size;
			Bluey[i] = Bluey[i - 1] + size;
		}
		Bluex[37] = Bluex[36] - size;
		Bluex[38] = Bluex[37] - size;
		Bluey[38] = Bluey[37] = Bluey[36];

		for (int i = 39; i <= 43; i++)
		{
			Bluex[i] = Bluex[38];
			Bluey[i] = Bluey[i - 1] - size;
		}

		for (int i = 44; i <= 49; i++)
		{
			Bluex[i] = Bluex[i - 1] - size;
			Bluey[i] = Bluey[43] - size;
		}

		Bluex[50] = Bluex[49];
		Bluey[50] = Bluey[49] - size;

		for (int i = 51; i <= 56; i++)
		{
			Bluex[i] = Bluex[i - 1] + size;
			Bluey[i] = Bluey[50];
		}
	}

	{//RED
		Redx[58] = startx + (size * (10.7));
		Redy[58] = starty + (size * (1.9));

		Redx[0] = startx + (size * 8);
		Redy[0] = starty + size;

		for (int i = 1; i <= 4; i++)
		{
			Redx[i] = Redx[0];
			Redy[i] = Redy[i - 1] + size;
		}

		for (int i = 5; i <= 10; i++)
		{
			Redx[i] = Redx[i - 1] + size;
			Redy[i] = Redy[4] + size;
		}

		Redx[12] = Redx[11] = Redx[10];
		Redy[11] = Redy[10] + size;
		Redy[12] = Redy[11] + size;

		for (int i = 13; i <= 17; i++)
		{
			Redx[i] = Redx[i - 1] - size;
			Redy[i] = Redy[12];
		}

		for (int i = 18; i <= 23; i++)
		{
			Redx[i] = Redx[17] - size;
			Redy[i] = Redy[i - 1] + size;
		}

		Redx[24] = Redx[23] - size;
		Redx[25] = Redx[24] - size;
		Redy[25] = Redy[24] = Redy[23];

		for (int i = 26; i <= 30; i++)
		{
			Redx[i] = Redx[25];
			Redy[i] = Redy[i - 1] - size;
		}

		for (int i = 31; i <= 36; i++)
		{
			Redx[i] = Redx[i - 1] - size;
			Redy[i] = Redy[30] - size;
		}

		Redx[38] = Redx[37] = Redx[36];
		Redy[37] = Redy[36] - size;
		Redy[38] = Redy[37] - size;


		for (int i = 39; i <= 43; i++)
		{
			Redx[i] = Redx[i - 1] + size;
			Redy[i] = Redy[38];
		}

		for (int i = 44; i <= 49; i++)
		{
			Redx[i] = Redx[43] + size;
			Redy[i] = Redy[i - 1] - size;
		}

		Redx[50] = Redx[49] + size;
		Redy[50] = Redy[49];

		for (int i = 51; i <= 56; i++)
		{
			Redx[i] = Redx[50];
			Redy[i] = Redy[i - 1] + size;
		}
	}

	{//GREEN
		Greenx[58] = startx + (size * (10.8));
		Greeny[58] = starty + (size * (10.8));

		Greenx[0] = startx + (size * 13);
		Greeny[0] = starty + (size * 8);

		for (int i = 1; i <= 4; i++)
		{
			Greenx[i] = Greenx[i - 1] - size;
			Greeny[i] = Greeny[0];
		}

		for (int i = 5; i <= 10; i++)
		{
			Greenx[i] = Greenx[4] - size;
			Greeny[i] = Greeny[i - 1] + size;
		}

		Greenx[11] = Greenx[10] - size;
		Greenx[12] = Greenx[11] - size;
		Greeny[12] = Greeny[11] = Greeny[10];

		for (int i = 13; i <= 17; i++)
		{
			Greenx[i] = Greenx[12];
			Greeny[i] = Greeny[i - 1] - size;
		}

		for (int i = 18; i <= 23; i++)
		{
			Greenx[i] = Greenx[i - 1] - size;
			Greeny[i] = Greeny[17] - size;
		}

		Greenx[25] = Greenx[24] = Greenx[23];
		Greeny[24] = Greeny[23] - size;
		Greeny[25] = Greeny[24] - size;


		for (int i = 26; i <= 30; i++)
		{
			Greenx[i] = Greenx[i - 1] + size;
			Greeny[i] = Greeny[25];
		}

		for (int i = 31; i <= 36; i++)
		{
			Greenx[i] = Greenx[30] + size;
			Greeny[i] = Greeny[i - 1] - size;
		}

		Greenx[37] = Greenx[36] + size;
		Greenx[38] = Greenx[37] + size;
		Greeny[38] = Greeny[37] = Greeny[36];

		for (int i = 39; i <= 43; i++)
		{
			Greenx[i] = Greenx[38];
			Greeny[i] = Greeny[i - 1] + size;
		}

		for (int i = 44; i <= 49; i++)
		{
			Greenx[i] = Greenx[i - 1] + size;
			Greeny[i] = Greeny[43] + size;
		}

		Greenx[50] = Greenx[49];
		Greeny[50] = Greeny[49] + size;

		for (int i = 51; i <= 56; i++)
		{
			Greenx[i] = Greenx[i - 1] - size;
			Greeny[i] = Greeny[i - 1];
		}

	}

	{//YELLOW
		Yellowx[58] = startx + (size * (1.8));
		Yellowy[58] = starty + (size * (10.7));

		Yellowx[0] = startx + (size * 6);
		Yellowy[0] = starty + (size * 13);

		for (int i = 1; i <= 4; i++)
		{
			Yellowx[i] = Yellowx[0];
			Yellowy[i] = Yellowy[i - 1] - size;
		}

		for (int i = 5; i <= 10; i++)
		{
			Yellowx[i] = Yellowx[i - 1] - size;
			Yellowy[i] = Yellowy[4] - size;
		}

		Yellowx[12] = Yellowx[11] = Yellowx[10];
		Yellowy[11] = Yellowy[10] - size;
		Yellowy[12] = Yellowy[11] - size;


		for (int i = 13; i <= 17; i++)
		{
			Yellowx[i] = Yellowx[i - 1] + size;
			Yellowy[i] = Yellowy[12];
		}

		for (int i = 18; i <= 23; i++)
		{
			Yellowx[i] = Yellowx[17] + size;
			Yellowy[i] = Yellowy[i - 1] - size;
		}

		Yellowx[24] = Yellowx[23] + size;
		Yellowx[25] = Yellowx[24] + size;
		Yellowy[25] = Yellowy[24] = Yellowy[23];

		for (int i = 26; i <= 30; i++)
		{
			Yellowx[i] = Yellowx[25];
			Yellowy[i] = Yellowy[i - 1] + size;
		}

		for (int i = 31; i <= 36; i++)
		{
			Yellowx[i] = Yellowx[i - 1] + size;
			Yellowy[i] = Yellowy[30] + size;
		}

		Yellowx[38] = Yellowx[37] = Yellowx[36];
		Yellowy[37] = Yellowy[36] + size;
		Yellowy[38] = Yellowy[37] + size;

		for (int i = 39; i <= 43; i++)
		{
			Yellowx[i] = Yellowx[i - 1] - size;
			Yellowy[i] = Yellowy[i - 1];
		}

		for (int i = 44; i <= 49; i++)
		{
			Yellowx[i] = Yellowx[43] - size;
			Yellowy[i] = Yellowy[i - 1] + size;
		}

		Yellowx[50] = Yellowx[49] - size;
		Yellowy[50] = Yellowy[49];

		for (int i = 51; i <= 56; i++)
		{
			Yellowx[i] = Yellowx[i - 1];
			Yellowy[i] = Yellowy[i - 1] - size;
		}

	}

}

void Player::set_position(int p)
{
	position = p;

	int bx = startx + (size * (1.8)); int by = starty + (size * (1.9));
	int rx = startx + (size * (10.7)); int ry = starty + (size * (1.9));
	int gx = startx + (size * (10.8)); int gy = starty + (size * (10.8));
	int yx = startx + (size * (1.8)); int yy = starty + (size * (10.7));

	if (position == -1)
	{
		switch (color)
		{
		case 1:
			switch (count)
			{
			case 0:
				set_coordinates(bx, by);
				break;
			case 1:
				set_coordinates((bx + (size*(5.0 / 4.0))), by);
				break;
			case 2:
				set_coordinates((bx + (size*(5.0 / 4.0))), (by + (size*(5.0 / 4.0))));
				break;
			case 3:
				set_coordinates(bx, (by + (size*(5.0 / 4.0))));
				break;
			}
			break;
		case 2:
			switch (count)
			{
			case 0:
				set_coordinates(rx, ry);
				break;
			case 1:
				set_coordinates((rx + (size*(5.0 / 4.0))), ry);
				break;
			case 2:
				set_coordinates((rx + (size*(5.0 / 4.0))), (ry + (size*(5.0 / 4.0))));
				break;
			case 3:
				set_coordinates(rx, (ry + (size*(5.0 / 4.0))));
				break;
			}
			break;
		case 3:
			switch (count)
			{
			case 0:
				set_coordinates(gx, gy);
				break;
			case 1:
				set_coordinates((gx + (size*(5.0 / 4.0))), gy);
				break;
			case 2:
				set_coordinates((gx + (size*(5.0 / 4.0))), (gy + (size*(5.0 / 4.0))));
				break;
			case 3:
				set_coordinates(gx, (gy + (size*(5.0 / 4.0))));
				break;
			}
			break;
		case 4:
			switch (count)
			{
			case 0:
				set_coordinates(yx, yy);
				break;
			case 1:
				set_coordinates((yx + (size*(5.0 / 4.0))), yy);
				break;
			case 2:
				set_coordinates((yx + (size*(5.0 / 4.0))), (yy + (size*(5.0 / 4.0))));
				break;
			case 3:
				set_coordinates(yx, (yy + (size*(5.0 / 4.0))));
				break;
			}
			break;
		}
	}
}

int Player::get_position()
{
	return position;
}