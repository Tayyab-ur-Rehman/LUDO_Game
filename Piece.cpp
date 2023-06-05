#include "Piece.h"
#include <SFML/Graphics.hpp>
Piece::Piece()
{
	this->pi_num = 0;
	this->index = 0;
	this->clr = -1;
	this->clr_ch = 0;
	this->hasKilled = false;
	this->is_Win = false;
}
Piece::Piece(const int &clr,int piece_num)
{
	char c;
	int initial_index=0;
	if (clr == 4)
	{
		c = 'r';
		initial_index = -200;
	}
	else if (clr == 10)
	{
		c = 'g';
		initial_index = -600;
	}
	else if (clr == 1)
	{
		c = 'B';
		initial_index = -300;
	}
	else if (clr == 9)
	{
		c = 'b';
		initial_index = -100;
	}
	else if (clr == 13)
	{
		c = 'p';
		initial_index = -400;
	}
	else if (clr == 12)
	{
		c = 'y';
		initial_index = -500;
	}
	this->pi_num = piece_num;
	this->clr = clr;
	this->clr_ch = c;
	this->index = initial_index;
	this->hasKilled = false;
	this->is_Win = false;
	this->in_mid_row = false;
}

void Piece::move_piece_ext(int x, vector<int>& dice_moves, const int& remove_index)
{
	if (this->get_clr()=='b')
	{
		 
	}

}

//void Piece::move_piece(int x, vector<int>& dice_moves, const int& remove_index)//dice number
//{
//	Music music;
//	music.openFromFile("snip.ogg");
//	music.play();
//	if (this->get_Index()<0 && this->index>-90)
//	{
//		int remain = 0;
//		this->index += x;
//		remain = this->index % -10;
//		if (remain == 0)
//		{
//			this->is_Win = true;
//		}
//	}
//	else if (this->index < -90)
//	{   // Agr ghr sa bahir aa rha ha piece to x hi us ki destination ho gi
//
//		this->index = x;
//	}
//	else
//	{     // agr board ma move kar rha ha too jab increment ho ga
//		this->index += x;
//		if (this->index > 76)
//		{
//			this->index -= 76;
//		}
//		
//	}
//	dice_moves.erase(dice_moves.begin() + remove_index);
//	
//}
//void Piece::move_piece(int x, vector<int>& dice_moves,const int& remove_index)//dice number
//{
//	if (this->index < -90)
//	{   // Agr ghr sa bahir aa rha ha piece to x hi us ki destination ho gi
//		
//		this->index = x;
//		dice_moves.erase(dice_moves.begin() + remove_index);
//	}
//	else
//	{     // agr board ma move kar rha ha too jab increment ho ga
//		this->index += x;
//		if (this->index > 75)
//		{
//			this->index -= 76;
//		}
//		dice_moves.erase(dice_moves.begin() + remove_index);
//	}
//	
//}
void Piece::move_piece(int x, vector<int>& dice_moves, const int& remove_index)//dice number
{

	if (this->get_Index() < 0 && this->index > -90)
	{
		int remain = 0;
		this->index += x;
		remain = this->index % -10;
		if (remain == 0)
		{
			this->is_Win = true;
		}
	}
	else if (this->index < -90)
	{   // Agr ghr sa bahir aa rha ha piece to x hi us ki destination ho gi

		this->index = x;
	}
	else
	{     // agr board ma move kar rha ha too jab increment ho ga
		this->index += x;
		if (this->index > 76)
		{
			this->index -= 76;
		}

	}
	dice_moves.erase(dice_moves.begin() + remove_index);
}


int& Piece::get_Index()
{
	return this->index ;
}


bool Piece::get_hasKilled()
{
	return this->hasKilled;
}
bool Piece::getWin_bool()
{
	return this->is_Win;
}

int Piece::get_clr()
{
	return clr;
}

void Piece::set_index(const int& x)
{
	this->index = x;

}

void Piece::Draw_piece(sf::RenderWindow& window)
{
	float increse_r = 10;
	float increse_c = 10-3;
	CircleShape shape(9.f);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(3);
	if (clr_ch == 'r')
	{
		shape.setFillColor(Color::Red);
		//shape.setOutlineColor(sf::Color::White); // set the outline color to green
		
		
	}
	if (clr_ch == 'B')
		shape.setFillColor(Color::Blue);
	if (clr_ch == 'y')
		shape.setFillColor(Color::Yellow);
	if (clr_ch == 'g')
		shape.setFillColor(Color::Green);
	if (clr_ch == 'p')
		shape.setFillColor(Color::Magenta);
	if (clr_ch == 'b')
		shape.setFillColor(Color::Cyan); // For light blue

	Position P = this->index_to_xyBoard();
	shape.setPosition( P.y * (50.45) + increse_c,P.x * (50.4) + increse_r);
	window.draw(shape);

}
int Piece::piece_To_Board_index()
{
	if (this->clr_ch == 'b')
		return (this->index) + 19;
	if (this->clr_ch == 'r')
		return (this->index) + 19;
	if (this->clr_ch == 'B')
		return (this->index) + 30;
	if (this->clr_ch == 'p')
		return (this->index) + 46;
	if (this->clr_ch == 'y')
		return (this->index) + 57;
	if (this->clr_ch == 'g')
		return (this->index) + 68;


}
Position Piece::index_to_xyBoard()
{
	Position A;
	int index = this->index;
	/////////////////////////////////////////////
	if (index == 0)
	{
		return A;
	}
	if (index == 76)
		A.x = 8, A.y = 7;
	if (index >= 0 && index <= 4)
	{
		A.x = index + 8; A.y = 7;
	}
	if (index >= 6 && index <= 10)
	{
		A.y = 5;
		A.x = 18 - index;
	}
	if (index >= 22 && index <= 26)
	{
		A.x = 26 - index; A.y = 5;
	}
	if (index >= 28 && index <= 32)
	{
		A.y = 7;
		A.x = index - 28;
	}
	if (index == 5 || index == 27 || (index >= -4 && index <= -1) || (index >= -24 && index <= -21))
	{
		if (index == 5)
			A.x = 12, A.y = 6;
		if (index == 27)
			A.x = 0, A.y = 6;
		if (index >= -4 && index <= -1)
		{
			A.y = 6;
			A.x = (index * -1) + 7;
		}
		if (index >= -24 && index <= -21)
		{
			A.y = 6;
			A.x = 25 - (index * -1);
		}
	}
	if (index >= 33 && index <= 37)
	{
		A.x = 5;
		A.y = index - 25;
	}
	if (index >= 71 && index <= 75)
	{
		A.x = 7;
		A.y = 83 - index;
	}
	if (index >= 38 && index <= 42)
	{
		A.x = 42 - index;
		A.y = 13;
	}
	if (index >= 44 && index <= 48)
	{
		A.x = index - 44;
		A.y = 15;
	}
	/////////////////////////////////////////
	if (index >= 60 && index <= 64)
	{
		A.x = index - 52;
		A.y = 15;
	}
	if (index >= 66 && index <= 70)
	{
		A.x = 78 - index;
		A.y = 13;
	}
	if (index == 65 || index == 43 || (index >= -34 && index <= -31) || (index >= -54 && index <= -51))
	{
		if (index == 43)
			A.x = 0, A.y = 14;
		if (index == 65)
			A.x = 12, A.y = 14;

		if (index >= -34 && index <= -31)
		{
			A.y = 14;
			A.x = (index)+35;
		}
		if (index >= -54 && index <= -51)
		{
			A.y = 14;
			A.x = (index * -1) - 43;
		}
	}
	////////////////////////////////////////
	if (index >= 17 && index <= 21)
	{
		A.x = 5;
		A.y = index - 17;
	}
	if (index >= 49 && index <= 53)
	{
		A.x = 5;
		A.y = index - 33;
	}
	if (index >= 11 && index <= 15)
	{
		A.x = 7;
		A.y = 15 - index;
	}
	////////////////////////////////////////////////////////
	if (index >= 55 && index <= 59)
	{
		A.x = 7;
		A.y = 75 - index;
	}
	if (index == 54)
		A.x = 6, A.y = 20;
	if (index == 16)
		A.x = 6, A.y = 0;


	if (index >= -44 && index <= -41)
	{
		A.x = 6; A.y = (-index) - 25;//;
	}
	if (index >= -14 && index <= -11)
	{
		A.x = 6; A.y = (index)+15;
	}
	if (index == -100)
	{
		if (pi_num == 1)
			A.x = 9, A.y = 1;
		else if (pi_num == 2)
			A.x = 9, A.y = 3;
		else if (pi_num == 3)
			A.x = 11, A.y = 1;
		else
			A.x = 11, A.y = 3;

	}
	if (index == -200)
	{
		if (pi_num == 1)
			A.x = 1, A.y = 1;
		else if (pi_num == 2)
			A.x = 1, A.y = 3;
		else if (pi_num == 3)
			A.x = 3, A.y = 1;
		else
			A.x = 3, A.y = 3;

	}
	if (index == -300)
	{
		if (pi_num == 1)
			A.x = 1, A.y = 9;
		else if (pi_num == 2)
			A.x = 1, A.y = 11;
		else if (pi_num == 3)
			A.x = 3, A.y = 9;
		else
			A.x = 3, A.y = 11;
	}
	if (index == -400)
	{
		if (pi_num == 1)
			A.x = 1, A.y = 17;
		else if (pi_num == 2)
			A.x = 1, A.y = 19;
		else if (pi_num == 3)
			A.x = 3, A.y = 17;
		else
			A.x = 3, A.y = 19;
	}
	if (index == -500)
	{
		if (pi_num == 1)
			A.x = 9, A.y = 17;
		else if (pi_num == 2)
			A.x = 9, A.y = 19;
		else if (pi_num == 3)
			A.x = 11, A.y = 17;
		else
			A.x = 11, A.y = 19;
	}
	if (index == -600)
	{
		if (pi_num == 1)
			A.x = 9, A.y = 9;
		else if (pi_num == 2)
			A.x = 9, A.y = 11;
		else if (pi_num == 3)
			A.x = 11, A.y = 9;
		else
			A.x = 11, A.y = 11;
	}
	return A;
}

char& Piece::getCh_clr()
{
	return this->clr_ch;
}
//       
//void Piece::isKilled(int & enemy_index) // Ka enemy ka piece mara ha to usa confirm kara ga ya function
//{   // This function will be called on every move of the piece 
//	 
//
//}