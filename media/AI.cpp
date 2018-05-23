#include "Ludo.h"
#include <stdlib.h>
#include <time.h>



void Ludo::AI_play()
{
	int i = 0;
	//checks if any goti is inside house if a six is rolled.
	if (sq == 3)
	{
		for (i = 0; i < 4; i++)
		{
			if (dice == 6 && Green[i].get_position() <= 0)
			{
				select = i;
				break;
			}
			if (can_save(Green[3])){}
			if (can_kill(Green[3])){
			}
			else{
				//compares distances of all gotis from each other, the one with max distance covered is moved
				if (Green[0].get_position() > Green[1].get_position() && Green[0].get_position() > Green[2].get_position() && Green[0].get_position() > Green[3].get_position()){
					select = 0;
				}
				if (Green[1].get_position() > Green[0].get_position() && Green[1].get_position() > Green[2].get_position() && Green[1].get_position() > Green[3].get_position()){
					select = 1;
				}
				if (Green[2].get_position() > Green[0].get_position() && Green[2].get_position() > Green[1].get_position() && Green[2].get_position() > Green[3].get_position()){
					select = 2;
				}
				if (Green[3].get_position() > Green[0].get_position() && Green[3].get_position() > Green[1].get_position() && Green[3].get_position() > Green[2].get_position()){
					select = 3;
				}
				if (Green[1].get_position() == Green[2].get_position() && Green[1].get_position() == Green[3].get_position() && Green[1].get_position() == Green[4].get_position()){
					srand(time(NULL));
					int i = rand() % 3 ;
					if (Green[i].get_position()==55 || Green[i].get_position()<=0){
						srand(time(NULL));
						i = rand() % 3 ;
					}
					select = i;
				}
				/*if (Green[0].get_position() == Green[1].get_position() && Green[1].get_position()!=0 && Green[0].get_position()!=0)
				{
					select = 0;
				}
				if (Green[1].get_position() == Green[2].get_position() && Green[1].get_position()!=0 && Green[2].get_position()!=0)
				{
					select = 1;
				}
				if (Green[2].get_position() == Green[3].get_position() && Green[3].get_position()!=0 && Green[2].get_position()!=0){
					select = 2;
				}
				if (Green[3].get_position() == Green[0].get_position() && Green[0].get_position()!=0 && Green[3].get_position()!=0){
					select = 0;
				}
				if (Green[2].get_position() == Green[0].get_position() && Green[0].get_position()!=0 && Green[2].get_position()!=0){
					select = 0;
				}
				if (Green[1].get_position() == Green[3].get_position() && Green[1].get_position()!=0 && Green[3].get_position()!=0){
					select = 1;
				}*/
			}
		}
	}
	if (sq == 4)
	{
		for (i = 0; i < 4; i++)
		{
			if (dice == 6 && Yellow[i].get_position() <= 0)
			{
				select = i;
				break;
			}
			if (can_save(Yellow[3])){}
			if (can_kill(Yellow[3])){
			}
			else{
				//compares distances of all gotis from each other, the one with max distance covered is moved
				if (Yellow[0].get_position() > Yellow[1].get_position() && Yellow[0].get_position() > Yellow[2].get_position() && Yellow[0].get_position() > Yellow[3].get_position()){
					select = 0;
				}
				if (Yellow[1].get_position() > Yellow[0].get_position() && Yellow[1].get_position() > Yellow[2].get_position() && Yellow[1].get_position() > Yellow[3].get_position()){
					select = 1;
				}
				if (Yellow[2].get_position() > Yellow[0].get_position() && Yellow[2].get_position() > Yellow[1].get_position() && Yellow[2].get_position() > Yellow[3].get_position()){
					select = 2;
				}
				if (Yellow[3].get_position() > Yellow[0].get_position() && Yellow[3].get_position() > Yellow[2].get_position() && Yellow[3].get_position() > Yellow[1].get_position()){
					select = 3;
				}
				if (Yellow[0].get_position() == Yellow[1].get_position() && Yellow[0].get_position() == Yellow[2].get_position() && Yellow[0].get_position() == Yellow[3].get_position()){
					srand(time(NULL));
					int i = rand()%3  ;
					if (Yellow[i].get_position() == 55 || Yellow[i].get_position()<=0){
						srand(time(NULL));
						i = rand() % 3 ;
					}
					select = i;
				}
		/*		if (Yellow[1].get_position() == Yellow[2].get_position())
				{
					select = 1;
				}
				if (Yellow[2].get_position() == Yellow[3].get_position())
				{
					select = 2;
				}
				if (Yellow[3].get_position() == Yellow[4].get_position()){
					select = 3;
				}
				if (Yellow[4].get_position() == Yellow[1].get_position()){
					select = 1;
				}
				if (Yellow[3].get_position() == Yellow[1].get_position()){
					select = 1;
				}
				if (Yellow[2].get_position() == Yellow[4].get_position()){
					select = 2;
				}*/
			}
		}
	}
}

bool Ludo::can_kill(Player x){
	int goti;
	int found;
	
	switch (x.color)
	{
	case 1:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((Blue[i].Bluex[Blue[i].get_position() + dice] == Red[j].getx()) && (Blue[i].Bluey[Blue[i].get_position() + dice] == Red[j].gety()))
				{
					if (!(Red[j].get_position() == 0 || Red[j].get_position() == 8 || Red[j].get_position() == 13 || Red[j].get_position() == 21 ||
						Red[j].get_position() == 26 || Red[j].get_position() == 34 || Red[j].get_position() == 39 || Red[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if ((Blue[i].Bluex[Blue[i].get_position() + dice] == Green[j].getx()) && (Blue[i].Bluey[Blue[i].get_position() + dice] == Green[j].gety()))
				{
					if (!(Green[j].get_position() == 0 || Green[j].get_position() == 8 || Green[j].get_position() == 13 || Green[j].get_position() == 21 ||
						Green[j].get_position() == 26 || Green[j].get_position() == 34 || Green[j].get_position() == 39 || Green[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if ((Blue[i].Bluex[Blue[i].get_position() + dice] == Yellow[j].getx()) && (Blue[i].Bluey[Blue[i].get_position() + dice] == Yellow[j].gety()))
				{
					if (!(Yellow[j].get_position() == 0 || Yellow[j].get_position() == 8 || Yellow[j].get_position() == 13 || Yellow[j].get_position() == 21 ||
						Yellow[j].get_position() == 26 || Yellow[j].get_position() == 34 || Yellow[j].get_position() == 39 || Yellow[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}
				}
				else {
					found = 0;
				}
			}
		}
	case 2:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((Red[i].Redx[Red[i].get_position() + dice] == Blue[j].getx()) && (Red[i].Redy[Red[i].get_position() + dice] == Blue[j].gety()))
				{
					if (!(Blue[j].get_position() == 0 || Blue[j].get_position() == 8 || Blue[j].get_position() == 13 || Blue[j].get_position() == 21 ||
						Blue[j].get_position() == 26 || Blue[j].get_position() == 34 || Blue[j].get_position() == 39 || Blue[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if ((Red[i].Redx[Red[i].get_position() + dice] == Green[j].getx()) && (Red[i].Redy[Red[i].get_position() + dice] == Green[j].gety()))
				{
					if (!(Green[j].get_position() == 0 || Green[j].get_position() == 8 || Green[j].get_position() == 13 || Green[j].get_position() == 21 ||
						Green[j].get_position() == 26 || Green[j].get_position() == 34 || Green[j].get_position() == 39 || Green[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if ((Red[i].Redx[Red[i].get_position() + dice] == Yellow[j].getx()) && (Red[i].Redy[Red[i].get_position() + dice] == Yellow[j].gety()))
				{
					if (!(Yellow[j].get_position() == 0 || Yellow[j].get_position() == 8 || Yellow[j].get_position() == 13 || Yellow[j].get_position() == 21 ||
						Yellow[j].get_position() == 26 || Yellow[j].get_position() == 34 || Yellow[j].get_position() == 39 || Yellow[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}
				}
				else {
					found = 0;
				}
			}
		}
	case 3:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((Green[i].Greenx[Green[i].get_position() + dice] == Red[j].getx()) && (Green[i].Greenx[Green[i].get_position() + dice] == Red[j].gety()))
				{
					if (!(Red[j].get_position() == 0 || Red[j].get_position() == 8 || Red[j].get_position() == 13 || Red[j].get_position() == 21 ||
						Red[j].get_position() == 26 || Red[j].get_position() == 34 || Red[j].get_position() == 39 || Red[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if ((Green[i].Greenx[Green[i].get_position() + dice] == Blue[j].getx()) && (Green[i].Greeny[Green[i].get_position() + dice] == Blue[j].gety()))
				{
					if (!(Blue[j].get_position() == 0 || Blue[j].get_position() == 8 || Blue[j].get_position() == 13 || Blue[j].get_position() == 21 ||
						Blue[j].get_position() == 26 || Blue[j].get_position() == 34 || Blue[j].get_position() == 39 || Blue[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if ((Green[i].Greenx[Green[i].get_position() + dice] == Yellow[j].getx()) && (Green[i].Greeny[Green[i].get_position() + dice] == Yellow[j].gety()))
				{
					if (!(Yellow[j].get_position() == 0 || Yellow[j].get_position() == 8 || Yellow[j].get_position() == 13 || Yellow[j].get_position() == 21 ||
						Yellow[j].get_position() == 26 || Yellow[j].get_position() == 34 || Yellow[j].get_position() == 39 || Yellow[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}
				}
				else {
					found = 0;
				}
			}
		}
	case 4:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((Yellow[i].Yellowx[Yellow[i].get_position() + dice] == Red[j].getx()) && (Yellow[i].Yellowy[Yellow[i].get_position() + dice] == Red[j].gety()))
				{
					if (!(Red[j].get_position() == 0 || Red[j].get_position() == 8 || Red[j].get_position() == 13 || Red[j].get_position() == 21 ||
						Red[j].get_position() == 26 || Red[j].get_position() == 34 || Red[j].get_position() == 39 || Red[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if ((Yellow[i].Yellowx[Yellow[i].get_position() + dice] == Green[j].getx()) && (Yellow[i].Yellowy[Yellow[i].get_position() + dice] == Green[j].gety()))
				{
					if (!(Green[j].get_position() == 0 || Green[j].get_position() == 8 || Green[j].get_position() == 13 || Green[j].get_position() == 21 ||
						Green[j].get_position() == 26 || Green[j].get_position() == 34 || Green[j].get_position() == 39 || Green[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if ((Yellow[i].Yellowx[Yellow[i].get_position() + dice] == Blue[j].getx()) && (Yellow[i].Yellowy[Yellow[i].get_position() + dice] == Blue[j].gety()))
				{
					if (!(Blue[j].get_position() == 0 || Blue[j].get_position() == 8 || Blue[j].get_position() == 13 || Blue[j].get_position() == 21 ||
						Blue[j].get_position() == 26 || Blue[j].get_position() == 34 || Blue[j].get_position() == 39 || Blue[j].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}
				}
				else {
					found = 0;
				}
			}
		}
	}
	if (found == 1) {
		select = goti;
		return 1;
	}
	else {
		return 0;
	}
}


bool Ludo::can_save(Player x) {
	int goti;
	int found;
	switch (x.color)
	{
	case 1:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (Blue[i].get_position() - Red[j].get_position() <= 6)
				{
					if (!(Blue[i].get_position() == 0 || Blue[i].get_position() == 8 || Blue[i].get_position() == 13 || Blue[i].get_position() == 21 ||
						Blue[i].get_position() == 26 || Blue[i].get_position() == 34 || Blue[i].get_position() == 39 || Blue[i].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if (Blue[i].get_position() - Green[j].get_position() <= 6)
				{
					if (!(Blue[i].get_position() == 0 || Blue[i].get_position() == 8 || Blue[i].get_position() == 13 || Blue[i].get_position() == 21 ||
						Blue[i].get_position() == 26 || Blue[i].get_position() == 34 || Blue[i].get_position() == 39 || Blue[i].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if (Blue[i].get_position() - Yellow[j].get_position() <= 6)
				{
					if (!(Blue[i].get_position() == 0 || Blue[i].get_position() == 8 || Blue[i].get_position() == 13 || Blue[i].get_position() == 21 ||
						Blue[i].get_position() == 26 || Blue[i].get_position() == 34 || Blue[i].get_position() == 39 || Blue[i].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}
				}
				else {
					found = 0;
				}
			}
		}
	case 2:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (Red[i].get_position() - Yellow[j].get_position() <= 6)
				{
					if (!(Red[i].get_position() == 0 || Red[i].get_position() == 8 || Red[i].get_position() == 13 || Red[i].get_position() == 21 ||
						Red[i].get_position() == 26 || Red[i].get_position() == 34 || Red[i].get_position() == 39 || Red[i].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}

				}
				else if (Red[i].get_position() - Green[j].get_position() <= 6)
				{
					if (!(Red[i].get_position() == 0 || Red[i].get_position() == 8 || Red[i].get_position() == 13 || Red[i].get_position() == 21 ||
						Red[i].get_position() == 26 || Red[i].get_position() == 34 || Red[i].get_position() == 39 || Red[i].get_position() == 47)){
						goti = i;
						found = 1;
						break;
					}

				}
				else if (Red[i].get_position() - Blue[j].get_position() <= 6)
				{
					if (!(Red[i].get_position() == 0 || Red[i].get_position() == 8 || Red[i].get_position() == 13 || Red[i].get_position() == 21 ||
						Red[i].get_position() == 26 || Red[i].get_position() == 34 || Red[i].get_position() == 39 || Red[i].get_position() == 47)) {
						goti = i;
						found = 1;
						break;
					}
				}
				else {
					found = 0;
				}
			}
		}
	case 3:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (Red[j].get_position() > 0)
				{
					if (Green[i].get_position() - Red[j].get_position() <= 6)
					{
						if (!(Green[i].get_position() == 0 || Green[i].get_position() == 8 || Green[i].get_position() == 13 || Green[i].get_position() == 21 ||
							Green[i].get_position() == 26 || Green[i].get_position() == 34 || Green[i].get_position() == 39 || Green[i].get_position() == 47)) {
							goti = i;
							found = 1;
							break;
						}
						else{
							found = 0;
						}

					}
					else{
						found = 0;
					}
				}
				else{
					found = 0;
				}
				if (Yellow[j].get_position() > 0)
				{
					if (Green[i].get_position() - Yellow[j].get_position() <= 6)
					{
						if (!(Green[i].get_position() == 0 || Green[i].get_position() == 8 || Green[i].get_position() == 13 || Green[i].get_position() == 21 ||
							Green[i].get_position() == 26 || Green[i].get_position() == 34 || Green[i].get_position() == 39 || Green[i].get_position() == 47)) {
							goti = i;
							found = 1;
							break;
						}
						else{
							found = 0;
						}
					}
					else{
						found = 0;
					}
				}
				else{
					found = 0;
				}
				if (Blue[j].get_position() > 0)
				{
					if (Green[i].get_position() - Blue[j].get_position() <= 6)
					{
						if (!(Green[i].get_position() == 0 || Green[i].get_position() == 8 || Green[i].get_position() == 13 || Green[i].get_position() == 21 ||
							Green[i].get_position() == 26 || Green[i].get_position() == 34 || Green[i].get_position() == 39 || Green[i].get_position() == 47)) {
							goti = i;
							found = 1;
							break;
						}
						else{
							found = 0;
						}
					}
					else{
						found = 0;
					}
				}
				else{
					found = 0;
				}
			}
		}
	case 4:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (Red[j].get_position() > 0)
				{
					if (Yellow[i].get_position() - Red[j].get_position() <= 6)
					{
						if (!(Yellow[i].get_position() == 0 || Yellow[i].get_position() == 8 || Yellow[i].get_position() == 13 || Yellow[i].get_position() == 21 ||
							Yellow[i].get_position() == 26 || Yellow[i].get_position() == 34 || Yellow[i].get_position() == 39 || Yellow[i].get_position() == 47)) {
							goti = i;
							found = 1;
							break;
						}
						else{
							found = 0;
						}

					}
					else{
						found = 0;
					}
				}
				else{
					found = 0;
				}
				if (Green[j].get_position() > 0)
				{
					if (Yellow[i].get_position() - Green[j].get_position() <= 6)
					{
						if (!(Yellow[i].get_position() == 0 || Yellow[i].get_position() == 8 || Yellow[i].get_position() == 13 || Yellow[i].get_position() == 21 ||
							Yellow[i].get_position() == 26 || Yellow[i].get_position() == 34 || Yellow[i].get_position() == 39 || Yellow[i].get_position() == 47)) {
							goti = i;
							found = 1;
							break;
						}
						else{
							found = 0;
						}
					}
					else{
						found = 0;
					}
				}
				else{
					found = 0;
				}
				if (Blue[j].get_position() > 0)
				{
					if (Yellow[i].get_position() - Blue[j].get_position() <= 6)
					{
						if (!(Yellow[i].get_position() == 0 || Yellow[i].get_position() == 8 || Yellow[i].get_position() == 13 || Yellow[i].get_position() == 21 ||
							Yellow[i].get_position() == 26 || Yellow[i].get_position() == 34 || Yellow[i].get_position() == 39 || Yellow[i].get_position() == 47)) {
							goti = i;
							found = 1;
							break;
						}
						else{
							found = 0;
						}
					}
					else{
						found = 0;
					}
				}
				else{
					found = 0;
				}
			}
		}



		if (found == 1) {
			select = goti;
			return 1;
		}
		else {
			return 0;
		}
	}
}