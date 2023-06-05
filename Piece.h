#pragma once
#include "SFML/Graphics.hpp"
#include "Utility.h"




class Piece 
{
	int index; // Theoratical position of piece
	int clr;

	char clr_ch;
	bool hasKilled;// does the piece has taken down the opponent piece and is ready to pass

public:
	bool is_Win;// To know if the piece has passed or still in the game
	bool in_mid_row;
	int pi_num; // which piece is it in the 4 pieces of a player
	Piece();
	Piece(const int &clr,int Piece_num);
	int get_clr();
	int& get_Index(); // returning value by reference
	char& getCh_clr();// returning value by reference
	void move_piece_ext(int x, vector<int>& dice_moves, const int& remove_index);
	void set_index(const int& x);
	void move_piece(int index, vector<int>& dice_moves, const int& remove_index); //also known as set_Index
	void Draw_piece(sf::RenderWindow& Window);
	Position index_to_xyBoard();
	int piece_To_Board_index();
	bool get_hasKilled();
	bool getWin_bool();

	//bool isPassable();// to see if the piece has, "has_killed": true so that it can move in the coloured rows inorder to win




};



