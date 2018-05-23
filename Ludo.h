#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"

using namespace std;

class Ludo
{
public:
	Ludo(int win_width = 800, int win_height = 539, char* title = "Ludo", int back_width = 542, int back_height = 539,
		int icon_width = 539, int icon_height = 542, int player_width = 40, int player_height = 40,
		char* back_image = "ludo_back.png", char* icon_image = "icon.bmp", char* dice_image = "dice.png",
		char* play_imageBlue = "PlayerBlue.png", char* play_imageRed = "PlayerRed.png", char* play_imageGreen = "PlayerGreen.png", char* play_imageYellow = "PlayerYellow.png",
		int startx = 5, int starty = 5, int p_size = 35,
		char* font_file = "Quivira.otf", char* start_sound = "Start.wav", char* play_sound = "Beep.wav");

	~Ludo();
	int Check();
	void Update();
	void Draw();

	string encodeData();
	void decodeData(string r);

	string encodeD();
	void decodeD(string r);

	void printPos();

	void inGameAvatars();
	int playerColor;

	enum PLAYERCOLORS
	{
		BLUE, RED, GREEN, YELLOW
	};

	void Multiplayer(int dice, int select);


	sf::RenderWindow *window;
	sf::Event event;
protected:
	void Restore();
	void Check_collison();
	void Check_win();
	int calculate_turn();

	sf::RectangleShape background;

	sf::Text Score;
	sf::Text Dice;
	sf::Image icon;
	sf::Texture back;
	sf::Font font;
	sf::SoundBuffer buffer, stBuffer;
	sf::Sound sound, stSound;



	sf::Texture sprite;
	sf::IntRect rectSourceSprite;
	sf::Sprite dice_sprite;

	int dice;
	int sq;
	int select;
	bool check;
	bool run;
	int win;
	int turn;

	int Sx, Sy, Si;

	Player Blue[4];
	Player Red[4];
	Player Green[4];
	Player Yellow[4];

	sf::Image Color[4];
	sf::RectangleShape win_back;
	bool can_kill(Player x);
	bool can_save(Player x);
	void AI_play();
};
