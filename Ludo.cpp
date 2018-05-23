#include "Ludo.h"


Ludo::Ludo(int win_width, int win_height, char* title, int back_width, int back_height,
	int icon_width, int icon_height, int player_width, int player_height,
	char* back_image, char* icon_image, char* dice_image,
	char* play_imageBlue, char* play_imageRed, char* play_imageGreen, char* play_imageYellow, int startx, int starty, int p_size,
	char* font_file, char* start_sound, char* play_sound)
{
	for (int i = 0; i < 4; i++)
	{
		Blue[i].color = 1;
		Blue[i].count = i;

		Red[i].color = 2;
		Red[i].count = i;

		Green[i].color = 3;
		Green[i].count = i;

		Yellow[i].color = 4;
		Yellow[i].count = i;
	}

	Sx = startx;
	Sy = starty;
	Si = p_size;

	dice = -1;
	select = -1;
	sq = 0;
	check = false;
	run = false;
	win = 0;
	turn = 0;

	window = new sf::RenderWindow(sf::VideoMode(win_width, win_height), title, sf::Style::None);

	srand(time(NULL));

	background.setSize(sf::Vector2f(back_width, back_height));

	win_back.setSize(sf::Vector2f(win_width, win_height));

	{
		rectSourceSprite.height = 100;
		rectSourceSprite.width = 100;
		rectSourceSprite.left = 0;
		rectSourceSprite.top = 0;
	}

	{
		back.loadFromFile(back_image);
		background.setTexture(&back);


		icon.loadFromFile(icon_image);
		window->setIcon(icon_width, icon_height, icon.getPixelsPtr());
	}

	{
		stBuffer.loadFromFile(start_sound);
		stSound.setBuffer(stBuffer);
		stSound.play();

		buffer.loadFromFile(play_sound);
		sound.setBuffer(buffer);
	}

	{
		font.loadFromFile(font_file);

		Score.setFont(font);
		Score.setOrigin(-((startx + (p_size * 6.5)) / (2.0)), -((starty + (p_size * 6.5)) / (2.0)));
		Score.setColor(sf::Color::Black);
		Score.Bold;
		Score.setScale(2.0, 2.0);

		Dice.setFont(font);
		Dice.setOrigin(-(startx + (p_size * 6.5)), -(starty + (p_size * 6.5)));
		Dice.setColor(sf::Color::Black);
	}

	{
		int bx = startx + (p_size * (1.8)); int by = starty + (p_size * (1.9));
		int rx = startx + (p_size * (10.7)); int ry = starty + (p_size * (1.9));
		int gx = startx + (p_size * (10.8)); int gy = starty + (p_size * (10.8));
		int yx = startx + (p_size * (1.8)); int yy = starty + (p_size * (10.7));



		Blue[0].set(bx, by, play_imageBlue, p_size, startx, starty);
		Blue[1].set((bx + (p_size*(1.25))), by, play_imageBlue, p_size, startx, starty);
		Blue[2].set((bx + (p_size*(1.25))), (by + (p_size*(1.25))), play_imageBlue, p_size, startx, starty);
		Blue[3].set(bx, (by + (p_size*(1.25))), play_imageBlue, p_size, startx, starty);

		Red[0].set(rx, ry, play_imageRed, p_size, startx, starty);
		Red[1].set((rx + (p_size*(1.25))), ry, play_imageRed, p_size, startx, starty);
		Red[2].set((rx + (p_size*(1.25))), (ry + (p_size*(1.25))), play_imageRed, p_size, startx, starty);
		Red[3].set(rx, (ry + (p_size*(1.25))), play_imageRed, p_size, startx, starty);

		Green[0].set(gx, gy, play_imageGreen, p_size, startx, starty);
		Green[1].set((gx + (p_size*(1.25))), gy, play_imageGreen, p_size, startx, starty);
		Green[2].set((gx + (p_size*(1.25))), (gy + (p_size*(1.25))), play_imageGreen, p_size, startx, starty);
		Green[3].set(gx, (gy + (p_size*(1.25))), play_imageGreen, p_size, startx, starty);

		Yellow[0].set(yx, yy, play_imageYellow, p_size, startx, starty);
		Yellow[1].set((yx + (p_size*(1.25))), yy, play_imageYellow, p_size, startx, starty);
		Yellow[2].set((yx + (p_size*(1.25))), (yy + (p_size*(1.25))), play_imageYellow, p_size, startx, starty);
		Yellow[3].set(yx, (yy + (p_size*(1.25))), play_imageYellow, p_size, startx, starty);
	}

	{
		sprite.loadFromFile(dice_image);
		dice_sprite.setTextureRect(rectSourceSprite);
		dice_sprite.setTexture(sprite);
		dice_sprite.setOrigin(-((startx + (p_size * 6.5)) / (2.0 * p_size / 100)), -((starty + (p_size * 6.5)) / (2.0 * p_size / 100)));
		dice_sprite.setScale(sf::Vector2f((2.0 * p_size) / 100, (2.0 * p_size) / 100));
	}

	{
		Color[0].loadFromFile(play_imageBlue);
		Color[1].loadFromFile(play_imageRed);
		Color[2].loadFromFile(play_imageGreen);
		Color[3].loadFromFile(play_imageYellow);
	}
}



void Ludo::Restore()
{
	for (int i = 0; i < 4; i++)
	{
		Blue[i].color = 1;
		Blue[i].count = i;

		Red[i].color = 2;
		Red[i].count = i;

		Green[i].color = 3;
		Green[i].count = i;

		Yellow[i].color = 4;
		Yellow[i].count = i;
	}

	dice = -1;
	select = -1;
	sq = 0;
	check = false;
	run = false;
	win = 0;
	turn = 0;

	stSound.play();

	{
		int bx = Sx + (Si * (1.8)); int by = Sy + (Si * (1.9));
		int rx = Sx + (Si * (10.7)); int ry = Sy + (Si * (1.9));
		int gx = Sx + (Si * (10.8)); int gy = Sy + (Si * (10.8));
		int yx = Sx + (Si * (1.8)); int yy = Sy + (Si * (10.7));



		Blue[0].set_coordinates(bx, by);
		Blue[1].set_coordinates((bx + (Si*(1.25))), by);
		Blue[2].set_coordinates((bx + (Si*(1.25))), (by + (Si*(1.25))));
		Blue[3].set_coordinates(bx, (by + (Si*(1.25))));

		Red[0].set_coordinates(rx, ry);
		Red[1].set_coordinates((rx + (Si*(1.25))), ry);
		Red[2].set_coordinates((rx + (Si*(1.25))), (ry + (Si*(1.25))));
		Red[3].set_coordinates(rx, (ry + (Si*(1.25))));

		Green[0].set_coordinates(gx, gy);
		Green[1].set_coordinates((gx + (Si*(1.25))), gy);
		Green[2].set_coordinates((gx + (Si*(1.25))), (gy + (Si*(1.25))));
		Green[3].set_coordinates(gx, (gy + (Si*(1.25))));

		Yellow[0].set_coordinates(yx, yy);
		Yellow[1].set_coordinates((yx + (Si*(1.25))), yy);
		Yellow[2].set_coordinates((yx + (Si*(1.25))), (yy + (Si*(1.25))));
		Yellow[3].set_coordinates(yx, (yy + (Si*(1.25))));
	}

}

Ludo::~Ludo()
{
	delete window;
}

void Ludo::Update()
{
	if (win > 0)
	{
		switch (win)
		{
		case 1:
			Score.setString(sf::String("Blue Wins"));
			break;
		case 2:
			Score.setString(sf::String("Red Wins"));
			break;
		case 3:
			Score.setString(sf::String("Green Wins"));
			break;
		case 4:
			Score.setString(sf::String("Yellow Wins"));
			break;
		}
	}

	if (win <= 0)
	{


		if (dice == 1 || dice == 2 || dice == 3 || dice == 4 || dice == 5 || dice == 6)
		{
			Dice.setString(sf::String(""));
		}
		else
			Dice.setString(sf::String("Press Enter to\n throw Dice"));

		if (select >= 0 && run == true)
		{
			switch (sq)
			{
			case 1:
				run = Blue[select].update_coordinates(sq, dice);
				break;
			case 2:
				run = Red[select].update_coordinates(sq, dice);
				break;
			case 3:
				run = Green[select].update_coordinates(sq, dice);
				break;
			case 4:
				run = Yellow[select].update_coordinates(sq, dice);
				break;
			}
		}
	}
}

void Ludo::Draw()
{
	if (win > 0)
	{
		window->draw(win_back);
		window->draw(Score);
	}

	if (win <= 0)
	{
		window->draw(background);
		window->draw(Dice);
		this->inGameAvatars();

		switch (sq)
		{
		case 1:
			for (int i = 0; i < 4; i++)
			{
				window->draw(Red[i].get_shape());
				window->draw(Green[i].get_shape());
				window->draw(Yellow[i].get_shape());
			}
			for (int i = 0; i < 4; i++)
			{
				window->draw(Blue[i].get_shape());
			}
			break;
		case 2:
			for (int i = 0; i < 4; i++)
			{
				window->draw(Blue[i].get_shape());
				window->draw(Green[i].get_shape());
				window->draw(Yellow[i].get_shape());
			}
			for (int i = 0; i < 4; i++)
			{
				window->draw(Red[i].get_shape());
			}
			break;
		case 3:
			for (int i = 0; i < 4; i++)
			{
				window->draw(Blue[i].get_shape());
				window->draw(Red[i].get_shape());
				window->draw(Yellow[i].get_shape());
			}
			for (int i = 0; i < 4; i++)
			{
				window->draw(Green[i].get_shape());
			}
			break;
		case 4:
			for (int i = 0; i < 4; i++)
			{
				window->draw(Blue[i].get_shape());
				window->draw(Red[i].get_shape());
				window->draw(Green[i].get_shape());
			}
			for (int i = 0; i < 4; i++)
			{
				window->draw(Yellow[i].get_shape());
			}
			break;
		default:
			for (int i = 0; i < 4; i++)
			{
				window->draw(Blue[i].get_shape());
				window->draw(Red[i].get_shape());
				window->draw(Green[i].get_shape());
				window->draw(Yellow[i].get_shape());
			}
		}

		if (check == true)
		{
			rectSourceSprite.left = 0;
			rectSourceSprite.left = (dice - 1) * 100;
			dice_sprite.setTextureRect(rectSourceSprite);
			window->draw(dice_sprite);
		}
	}
}

int Ludo::Check()
{

	int q = -1;


	if (event.type == sf::Event::Closed)
		window->close();
	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window->close();
			q = 0;
			return q;
		}
		if (win <= 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				run = true;
				sound.play();
				sq++;
				select = -1;
				check = true;
				if (dice == 6)
					turn++;
				dice = rand() % 6 + 1;

				sq -= calculate_turn();

				if (sq > 4)
					sq = 1;
			}
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			win = 1;*/

		}
		if (win > 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				q = 0;
				//Restore();
			}
		}
	}

	if (win <= 0)
	{
		int QWE = 0;
		if (sq == 3){
			QWE = 1;
		}
		if (sq == 4){
			QWE = 1;
		}
		switch (sq)
		{
		case 1:
			dice_sprite.setColor(Color[0].getPixel((Color[0].getSize().x / 2), (Color[0].getSize().y / 2)));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i P = sf::Mouse::getPosition(*window);
				for (int i = 0; i < 4; i++)
				{
					int wx = Blue[i].getx();
					int wy = Blue[i].gety();
					if ((P.x >= wx) && (P.x <= (wx + 40)) && (P.y >= wy) && (P.y <= (wy + 40)))
					{
						select = i; break;
					}
					else
						select = -1;
				}
			}
			if (select >= 0 && select <= 3)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					Blue[select].setx((Blue[select].getx() + 5));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					Blue[select].setx((Blue[select].getx() - 5));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					Blue[select].sety((Blue[select].gety() - 5));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					Blue[select].sety((Blue[select].gety() + 5));
				}
			}
			break;
		case 2:
			dice_sprite.setColor(Color[1].getPixel((Color[1].getSize().x / 2), (Color[1].getSize().y / 2)));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i P = sf::Mouse::getPosition(*window);
				for (int i = 0; i < 4; i++)
				{
					int wx = Red[i].getx();
					int wy = Red[i].gety();
					if ((P.x >= wx) && (P.x <= (wx + 40)) && (P.y >= wy) && (P.y <= (wy + 40)))
					{
						select = i; break;
					}
					else
						select = -1;
				}
			}
			if (select >= 0 && select <= 3)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					Red[select].setx((Red[select].getx() + 5));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					Red[select].setx((Red[select].getx() - 5));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					Red[select].sety((Red[select].gety() - 5));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					Red[select].sety((Red[select].gety() + 5));
				}
			}
			break;
		case 3:
			dice_sprite.setColor(Color[2].getPixel((Color[2].getSize().x / 2), (Color[2].getSize().y / 2)));
			if (QWE == 1)
			{
				AI_play();
			}
			else {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2i P = sf::Mouse::getPosition(*window);
					for (int i = 0; i < 4; i++)
					{
						int wx = Green[i].getx();
						int wy = Green[i].gety();
						if ((P.x >= wx) && (P.x <= (wx + 40)) && (P.y >= wy) && (P.y <= (wy + 40)))
						{
							select = i; break;
						}
						else
							select = -1;
					}
				}
				if (select >= 0 && select <= 4)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						Green[select].setx((Green[select].getx() + 5));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						Green[select].setx((Green[select].getx() - 5));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						Green[select].sety((Green[select].gety() - 5));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						Green[select].sety((Green[select].gety() + 5));
					}
				}
			}
			break;
		case 4:
			dice_sprite.setColor(Color[3].getPixel((Color[3].getSize().x / 2), (Color[3].getSize().y / 2)));
			if (QWE == 1)
			{
				AI_play();
			}
			else {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2i P = sf::Mouse::getPosition(*window);
					for (int i = 0; i < 4; i++)
					{
						int wx = Yellow[i].getx();
						int wy = Yellow[i].gety();
						if ((P.x >= wx) && (P.x <= (wx + 40)) && (P.y >= wy) && (P.y <= (wy + 40)))
						{
							select = i; break;
						}
						else
							select = -1;
					}
				}
				if (select >= 0 && select <= 4)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						Yellow[select].setx((Yellow[select].getx() + 5));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						Yellow[select].setx((Yellow[select].getx() - 5));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						Yellow[select].sety((Yellow[select].gety() - 5));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						Yellow[select].sety((Yellow[select].gety() + 5));
					}
				}
			}
			break;
		}

		Check_collison();
		Check_win();

		q = 1;
	}

	return q;
}

void Ludo::Check_collison()
{
	bool q = false;
	if (sq > 0 && sq < 5 && select >= 0 && select < 4)
	{
		switch (sq)
		{
		case 1:
			if (!((Blue[select].get_position() == 0) || (Blue[select].get_position() == 8) ||
				(Blue[select].get_position() == 13) || (Blue[select].get_position() == 21) ||
				(Blue[select].get_position() == 26) || (Blue[select].get_position() == 34) ||
				(Blue[select].get_position() == 39) || (Blue[select].get_position() == 47)))
			{
				for (int i = 0; i < 4; i++)
				{
					if ((Blue[select].getx() == Red[i].getx()) && (Blue[select].gety() == Red[i].gety()))
					{
						Red[i].set_position(-1); q = true;
					}
					if ((Blue[select].getx() == Green[i].getx()) && (Blue[select].gety() == Green[i].gety()))
					{
						Green[i].set_position(-1); q = true;
					}
					if ((Blue[select].getx() == Yellow[i].getx()) && (Blue[select].gety() == Yellow[i].gety()))
					{
						Yellow[i].set_position(-1); q = true;
					}
				}
			}
			break;
		case 2:
			if (!((Red[select].get_position() == 0) || (Red[select].get_position() == 8) ||
				(Red[select].get_position() == 13) || (Red[select].get_position() == 21) ||
				(Red[select].get_position() == 26) || (Red[select].get_position() == 34) ||
				(Red[select].get_position() == 39) || (Blue[select].get_position() == 47)))
			{
				for (int i = 0; i < 4; i++)
				{
					if ((Red[select].getx() == Blue[i].getx()) && (Red[select].gety() == Blue[i].gety()))
					{
						Blue[i].set_position(-1); q = true;
					}
					if ((Red[select].getx() == Green[i].getx()) && (Red[select].gety() == Green[i].gety()))
					{
						Green[i].set_position(-1); q = true;
					}
					if ((Red[select].getx() == Yellow[i].getx()) && (Red[select].gety() == Yellow[i].gety()))
					{
						Yellow[i].set_position(-1); q = true;
					}
				}
			}
			break;
		case 3:
			if (!((Green[select].get_position() == 0) || (Green[select].get_position() == 8) ||
				(Green[select].get_position() == 13) || (Green[select].get_position() == 21) ||
				(Green[select].get_position() == 26) || (Green[select].get_position() == 34) ||
				(Green[select].get_position() == 39) || (Green[select].get_position() == 47)))
			{
				for (int i = 0; i < 4; i++)
				{
					if ((Green[select].getx() == Red[i].getx()) && (Green[select].gety() == Red[i].gety()))
					{
						Red[i].set_position(-1); q = true;
					}
					if ((Green[select].getx() == Blue[i].getx()) && (Green[select].gety() == Blue[i].gety()))
					{
						Blue[i].set_position(-1); q = true;
					}
					if ((Green[select].getx() == Yellow[i].getx()) && (Green[select].gety() == Yellow[i].gety()))
					{
						Yellow[i].set_position(-1); q = true;
					}
				}
			}
			break;
		case 4:
			if (!((Yellow[select].get_position() == 0) || (Yellow[select].get_position() == 8) ||
				(Yellow[select].get_position() == 13) || (Yellow[select].get_position() == 21) ||
				(Yellow[select].get_position() == 26) || (Yellow[select].get_position() == 34) ||
				(Yellow[select].get_position() == 39) || (Yellow[select].get_position() == 47)))
			{
				for (int i = 0; i < 4; i++)
				{
					if ((Yellow[select].getx() == Red[i].getx()) && (Yellow[select].gety() == Red[i].gety()))
					{
						Red[i].set_position(-1); q = true;
					}
					if ((Yellow[select].getx() == Green[i].getx()) && (Yellow[select].gety() == Green[i].gety()))
					{
						Green[i].set_position(-1); q = true;
					}
					if ((Yellow[select].getx() == Blue[i].getx()) && (Yellow[select].gety() == Blue[i].gety()))
					{
						Blue[i].set_position(-1); q = true;
					}
				}
			}
			break;
		}
	}

	if (q)
	{
		turn++;
	}
}

void Ludo::Check_win()
{
	switch (sq)
	{
	case 1:
		if (((Blue[0].get_position()) == 56) && ((Blue[1].get_position()) == 56) && ((Blue[2].get_position()) == 56) && ((Blue[3].get_position()) == 56))
		{
			win = 1;
			win_back.setFillColor((Color[0].getPixel((Color[0].getSize().x / 2), (Color[0].getSize().y / 2))));
		}
		break;
	case 2:
		if (((Red[0].get_position()) == 56) && ((Red[1].get_position()) == 56) && ((Red[2].get_position()) == 56) && ((Red[3].get_position()) == 56))
		{
			win = 2;
			win_back.setFillColor((Color[1].getPixel((Color[0].getSize().x / 2), (Color[1].getSize().y / 2))));
		}
		break;
	case 3:
		if (((Green[0].get_position()) == 56) && ((Green[1].get_position()) == 56) && ((Green[2].get_position()) == 56) && ((Green[3].get_position()) == 56))
		{
			win = 3;
			win_back.setFillColor((Color[2].getPixel((Color[0].getSize().x / 2), (Color[2].getSize().y / 2))));
		}
		break;
	case 4:
		if (((Yellow[0].get_position()) == 56) && ((Yellow[1].get_position()) == 56) && ((Yellow[2].get_position()) == 56) && ((Yellow[3].get_position()) == 56))
		{
			win = 4;
			win_back.setFillColor((Color[3].getPixel((Color[0].getSize().x / 2), (Color[3].getSize().y / 2))));
		}
		break;
	}
}

int Ludo::calculate_turn()
{
	if (turn > 0)
	{
		turn--;
		return 1;
	}
	else
		return 0;
}

void Ludo::Multiplayer(int d, int s)
{
	/*dice = d;
	select = s;*/
}


string Ludo::encodeData()
{
	string positions = "";

	for (size_t i = 0; i < 4; i++)
	{
		positions.append(to_string(Blue[i].getx()));
		positions.append("-");
		positions.append(to_string(Blue[i].gety()));
		positions.append(" ");
	}
	for (size_t i = 0; i < 4; i++)
	{
		positions.append(to_string(Red[i].getx()));
		positions.append("-");
		positions.append(to_string(Red[i].gety()));
		positions.append(" ");
	}
	for (size_t i = 0; i < 4; i++)
	{
		positions.append(to_string(Yellow[i].getx()));
		positions.append("-");
		positions.append(to_string(Yellow[i].gety()));
		positions.append(" ");
	}
	for (size_t i = 0; i < 4; i++)
	{
		positions.append(to_string(Green[i].getx()));
		positions.append("-");
		positions.append(to_string(Green[i].gety()));
		positions.append(" ");
	}
	cout << "\n============== Encode Start================\n";
	cout << positions;
	cout << "\n============== Encode End================\n";
	return positions;

}

void Ludo::decodeData(string r)
{
	string toBeDecoded = r;

	int i = 0;
	string str = "";
	int m = 100;
	int n = 0;

	cout << "\n============== Decode Start================\n";

	for (int ii = 0; ii < 4; ii++)
	{
		while (toBeDecoded[i] != '-')
		{
			n += (toBeDecoded[i] - 48) * m;
			m /= 10;
			i++;
		} i++;

		Blue[ii].setx(n);
		n = 0;
		m = 100;

		while (toBeDecoded[i] != ' ')
		{
			n += (toBeDecoded[i] - 48) * m;
			m /= 10;
			i++;
		} i++;

		Blue[ii].sety(n);
		n = 0;
		m = 100;

		cout << Blue[ii].getx() << "-" << Blue[ii].gety() << " ";

	}

	for (int ii = 0; ii < 4; ii++)
	{
		while (toBeDecoded[i] != '-')
		{
			n += (toBeDecoded[i] - 48) * m;
			m /= 10;
			i++;
		} i++;

		Red[ii].setx(n);
		n = 0;
		m = 100;

		while (toBeDecoded[i] != ' ')
		{
			n += (toBeDecoded[i] - 48) * m;
			m /= 10;
			i++;
		} i++;

		Red[ii].sety(n);
		n = 0;
		m = 100;

		cout << Red[ii].getx() << "-" << Red[ii].gety() << " ";


	}

	for (int ii = 0; ii < 4; ii++)
	{
		while (toBeDecoded[i] != '-')
		{
			n += (toBeDecoded[i] - 48) * m;
			m /= 10;
			i++;
		} i++;

		Yellow[ii].setx(n);
		n = 0;
		m = 100;

		while (toBeDecoded[i] != ' ')
		{
			n += (toBeDecoded[i] - 48) * m;
			m /= 10;
			i++;
		} i++;

		Yellow[ii].sety(n);
		n = 0;
		m = 100;

		cout << Yellow[ii].getx() << "-" << Yellow[ii].gety() << " ";


	}

	for (int ii = 0; ii < 4; ii++)
	{
		while (toBeDecoded[i] != '-')
		{
			n += (toBeDecoded[i] - 48) * m;
			m /= 10;
			i++;
		} i++;

		Green[ii].setx(n);
		n = 0;
		m = 100;

		while (toBeDecoded[i] != ' ')
		{
			n += (toBeDecoded[i] - 48) * m;
			m /= 10;
			i++;
		} i++;

		Green[ii].sety(n);
		n = 0;
		m = 100;

		cout << Green[ii].getx() << "-" << Green[ii].gety() << " ";
	}

	cout << "\n============== Decode End================\n";

}


string Ludo::encodeD()
{
	string r;
	r.append(to_string(dice));
	r.append(to_string(select));
	r.append(to_string(sq));
	r.append(to_string(check));
	r.append(to_string(run));
	//	r.append(to_string(win));
	r.append(to_string(turn));

	return r;
}

void Ludo::decodeD(string r)
{
	dice = r[0] - 48;
	select = r[1] - 48;
	sq = r[2] - 48;
	check = r[3] - 48;
	run = r[4] - 48;
	//win = r[5] - 48;
	turn = r[5] - 48;
}

void Ludo::printPos()
{
	cout << "\n============== Print Start================\n";
	for (size_t i = 0; i < 4; i++)
	{
		cout << Blue[i].getx() << "-" << Blue[i].gety() << " ";
	}
	for (size_t i = 0; i < 4; i++)
	{
		cout << Red[i].getx() << "-" << Red[i].gety() << " ";
	}
	for (size_t i = 0; i < 4; i++)
	{
		cout << Yellow[i].getx() << "-" << Yellow[i].gety() << " ";
	}
	for (size_t i = 0; i < 4; i++)
	{
		cout << Green[i].getx() << "-" << Green[i].gety() << " ";
	}

	cout << "\n============== Print End================\n";
}


//void Ludo::inGameAvatars()
//{
//	sf::Sprite sAvatars[4];
//	sf::Texture tAvatars;
//
//	tAvatars.loadFromFile("Faces.png");
//
//
//	sAvatars[0].setTexture(tAvatars);
//	sAvatars[1].setTexture(tAvatars);
//	sAvatars[2].setTexture(tAvatars);
//	sAvatars[3].setTexture(tAvatars);
//
//	sAvatars[0].setTextureRect(sf::IntRect(0, 0, 365, 365));
//	sAvatars[1].setTextureRect(sf::IntRect(365, 0, 365, 365));
//	sAvatars[2].setTextureRect(sf::IntRect(0, 365, 365, 365));
//	sAvatars[3].setTextureRect(sf::IntRect(365, 365, 365, 365));
//
//	sAvatars[0].setPosition(0 + 30, 0 + 30);
//	sAvatars[1].setPosition(1110 - 30, 0 + 30);
//	sAvatars[2].setPosition(0 + 30, 512 - 30);
//	sAvatars[3].setPosition(1110 - 30, 512 - 30);
//
//	sAvatars[0].setScale(0.70, 0.70);
//	sAvatars[1].setScale(0.70, 0.70);
//	sAvatars[2].setScale(0.70, 0.70);
//	sAvatars[3].setScale(0.70, 0.70);
//
//	window->draw(sAvatars[0]);
//	window->draw(sAvatars[1]);
//	window->draw(sAvatars[2]);
//	window->draw(sAvatars[3]);
//}

void Ludo::inGameAvatars()
{

	sf::Sprite sAvatarsShaded[4];
	sf::Texture tAvatarsShaded;

	tAvatarsShaded.loadFromFile("FacesShaded.png");

	sAvatarsShaded[0].setTexture(tAvatarsShaded);
	sAvatarsShaded[1].setTexture(tAvatarsShaded);
	sAvatarsShaded[2].setTexture(tAvatarsShaded);
	sAvatarsShaded[3].setTexture(tAvatarsShaded);

	sAvatarsShaded[0].setTextureRect(sf::IntRect(0, 0, 365, 365));
	sAvatarsShaded[1].setTextureRect(sf::IntRect(365, 0, 365, 365));
	sAvatarsShaded[2].setTextureRect(sf::IntRect(0, 365, 365, 365));
	sAvatarsShaded[3].setTextureRect(sf::IntRect(365, 365, 365, 365));

	sAvatarsShaded[0].setPosition(0 + 30, 0 + 30);
	sAvatarsShaded[1].setPosition(1110 - 30, 0 + 30);
	sAvatarsShaded[2].setPosition(0 + 30, 512 - 30);
	sAvatarsShaded[3].setPosition(1110 - 30, 512 - 30);

	sAvatarsShaded[0].setScale(0.70, 0.70);
	sAvatarsShaded[1].setScale(0.70, 0.70);
	sAvatarsShaded[2].setScale(0.70, 0.70);
	sAvatarsShaded[3].setScale(0.70, 0.70);

	window->draw(sAvatarsShaded[0]);
	window->draw(sAvatarsShaded[1]);
	window->draw(sAvatarsShaded[2]);
	window->draw(sAvatarsShaded[3]);

	sf::Sprite sAvatars[4];
	sf::Texture tAvatars;

	tAvatars.loadFromFile("Faces.png");


	sAvatars[0].setTexture(tAvatars);
	sAvatars[1].setTexture(tAvatars);
	sAvatars[2].setTexture(tAvatars);
	sAvatars[3].setTexture(tAvatars);

	sAvatars[0].setTextureRect(sf::IntRect(0, 0, 365, 365));
	sAvatars[1].setTextureRect(sf::IntRect(365, 0, 365, 365));
	sAvatars[2].setTextureRect(sf::IntRect(0, 365, 365, 365));
	sAvatars[3].setTextureRect(sf::IntRect(365, 365, 365, 365));

	sAvatars[0].setPosition(0 + 30, 0 + 30);
	sAvatars[1].setPosition(1110 - 30, 0 + 30);
	sAvatars[2].setPosition(0 + 30, 512 - 30);
	sAvatars[3].setPosition(1110 - 30, 512 - 30);

	sAvatars[0].setScale(0.70, 0.70);
	sAvatars[1].setScale(0.70, 0.70);
	sAvatars[2].setScale(0.70, 0.70);
	sAvatars[3].setScale(0.70, 0.70);

	if ((sq == (PLAYERCOLORS::BLUE + 1)))	window->draw(sAvatars[0]);
	else if ((sq == PLAYERCOLORS::RED + 1))
		window->draw(sAvatars[1]);
	else if ((sq == PLAYERCOLORS::YELLOW + 1))
		window->draw(sAvatars[2]);
	else if ((sq == PLAYERCOLORS::GREEN + 1))
		window->draw(sAvatars[3]);
}