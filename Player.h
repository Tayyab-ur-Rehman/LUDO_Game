#pragma once

#include"Piece.h"
#include"Utility.h"
using namespace std;

//Position Chess::MouseClick();


class Player
{
	//bool first_move; // agr player ki sari pieces ghar ma han to ya true ho ga otherwise false
	
public:
	
	char ch_clr;
	int home_index = 0;
	int turn;
	char* f_players;  
	bool has_killed = false;// does the player has taken down the opponent piece and is ready to pass
	int No_of_friends;
	//Player **All;
	


	Piece* Ps;
	     // We will later convert it into char
	Player(int col, vector<char> f_players,int turn);
	bool is_friend(const int& x);
	void set_friend(vector<char> f_players);
	void print_All_Player_Dice();
	bool all_pieces_at_home_check();  // keeps count of all pieces are in the house or not 
	bool All_piece_unavaliable();  // keeps count of all pieces are in the house or not 
	//bool& get_firstMove();

};

