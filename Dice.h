#pragma once
#include<cstdlib>
#include<time.h>
#include "Utility.h"
#include "Board.h"

using namespace std;
class Dice
{

		Texture t0,t1, t2, t3, t4, t5, t6;
		Sprite s0, s1, s2, s3, s4, s5, s6;
public:
	
	Dice();

	void draw_dice(sf::RenderWindow& window, const int& draw_value);
	void draw_dice2(sf::RenderWindow& window, const int& draw_value);
	
	// centre col:412 - 632
	// center row: 320 -530
	bool click_dicr(RenderWindow& window);
	void dice_shake(sf::RenderWindow& window,vector<int>& dice_moves,Board& B,int nob);
	void dice_shake_auto(sf::RenderWindow& window, vector<int>& dice_moves, Board& B, Player** Playerr, int nob, int turn);
	void dice_shake_select(sf::RenderWindow& window, vector<int>& dice_moves, Board& B, Player** P, int nob, int turn);
	  // void because we are storing the moves in dice_moves vector 
	int select_num_of_Dice_number(RenderWindow& window, vector<int>& dice_moves, int& ahmad_index);
	void Animation(sf::RenderWindow& window, vector<int>& dice_moves, Board& B, Player** Playerr, int nob, int turn);
};

