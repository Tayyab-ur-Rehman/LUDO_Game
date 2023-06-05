#pragma once

#include"Board.h"
#include"Player.h"

#include"Dice.h"
#include "Utility.h"


class Ludo
{
	Board B;
	Dice D;
	int turn;
	int NO_player;
	Player** Plr; // Array of players
	bool friend_mode;
	vector<int> dice_moves;
	

public:

	Ludo(RenderWindow& window);
	bool piece_checker_move(Player& plr, Piece* P,const int& dst_index);
	bool empty_destination(Piece* P, const int& dst_index);
	bool  piece_1st_move(Piece* P, const int& dice_val, const int& turn,int& mout_index,bool first_move_bool);
	void play_Ludo(RenderWindow   & window);
	void printAll(sf::RenderWindow& window);
	void printWithVector(sf::RenderWindow& window,vector<int> A);
	bool Win_checker(string& msg);
	bool is_Piece_pick_valid( Piece* P);
	bool redicer_check(Player& P);
	Piece* Piece_picker(RenderWindow& window,const int& turn, const int& val, bool is_out_house);
	bool piece_at_door_check(Player& plr, Piece* P);
	//void move_Piece(Piece& P, const int& dst_index);
	void printAll_dice(sf::RenderWindow& window, int value);
	bool inHouse_move_checker(Player& Plr, Piece* P, const int& index, int& decoy);
	bool OnlyOneLeft();
	////////////////////////////////////////////////////
	bool jota_piece_checker(Piece* P, const int& dst_index);
	bool jota_mover_valid(Piece* P, const int& dst_index);
	bool jota_mover(Piece* P, const int& dst_index, const int& remove_index, vector<int>& dice_moves, int& decoy_num);
	////////////////////////////////////////////////////

	bool p_index_checker(const int& p_index); 
};

 



