#pragma once
#include"Player.h"
#include"Utility.h"

class Board
{

	int Board_indexes;
	int *stops;
	
	int Red_domain[2]{};
	int SkyBlue_domain[2]{};
	int Blue_domain[2]{};
	int Purple_domain[2]{};                      
	int Yellow_domain[2]{};
	int Green_domain[2]{};
	//////////////////////////////////////
	int Red_house[2]{};
	int SkyBlue_house[2]{};
	int Blue_house[2]{};
	int Purple_house[2]{};
	int Yellow_house[2]{};
	int Green_house[2]{};
	//Player* player;
	//bool killed_Val;
	//char Turn;


public:
	                //////funcion\\\\\\
	      ////////////////|||||||\\\\\\\\\\\\\\\\\\\
	//void move(int Dice_number,int which_piece);// which_piece  1....4
	Board();
	void drawBoard(sf::RenderWindow& window, string img_name);
	bool stop_Checker(Piece* P,const int& dst_index);
	Position mouse_positin(sf::RenderWindow& window);   //overall ri ci
	Position calculate_mouseP(sf::RenderWindow& window);
	int index_provider(sf::RenderWindow& window);

	// Piece Select_Piece();
	// Piece Drop_piece()



};