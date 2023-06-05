#pragma once
#include "Dice.h"
#include <conio.h>
#include <windows.h>
void Dice::dice_shake(sf::RenderWindow& window, vector<int>& dice_moves,Board& B,int nob)
{
	Position P;
	int dice_val=0;
	int index = 0;
	int count = 1; 
	int c = 0;
	do
	{
		
		cout << "Which number do you want use as dice val\n";
		
		do
		{
			cin >> dice_val;
			
				
		} while (!(dice_val > 0 && dice_val <= 6));
			

		
		//_____  for random dice
		//draw_dice(window,dice_val);
		//do
		//{           // Performing and checking the click on dice in the centre of board
		//	P = B.calculate_mouseP(window);
		//} while (!(P.x==6 && P.y==10));
		//srand(time(0));
		//dice_val=(rand() % 6) + 1;
		//_____


		dice_moves.push_back(dice_val);
		//____________ 
		// checking if 3 sixes consecutive dafa aa gai hain too unha delete kar da
		for (int i = 0; i < dice_moves.size(); i++) 
		{
			if (dice_moves[i] == 6)
			{
				index = i;  // checking the next 2 entries excluding the entry i
				for (int j = 1; j < 3 && j<dice_moves.size(); j++)
				{
					if (dice_moves[index + j] == 6)
						count++;
				}
				 // if there are 3 consecutive 6's then delete them
				if (count == 3)
				{           // erasing in a range of three indexes on which 6's are present
					dice_moves.erase(dice_moves.begin(), dice_moves.end());
					dice_moves.shrink_to_fit();
				}
				else
				{
					count = 1; 
					break;
				}
			}
			else
			{
				count = 1;
				break;
			}
			
		}
		//_______________
		//draw_dice(window, dice_val, dice_moves);
		
	} while (dice_val==6);
}
void Dice::dice_shake_auto(sf::RenderWindow& window, vector<int>& dice_moves, Board& B, Player** Playerr, int nob,int turn)
{
	window.clear();
	B.drawBoard(window, "6P board_2.png");
	{
		for (int i = 0; i < nob; i++) {
			for (int j = 0; j < 4; j++) {
				if (!Playerr[i]->Ps[j].getWin_bool())
				{
					Playerr[i]->Ps[j].Draw_piece(window);

				}
			}
		}
	}
	this->draw_dice(window, 0);
	drawDialoge(window);
	TurnMsg(window, turn,nob);

	window.display();
	Position P;
	
	int index = 0;
	int count = 1;
	int dice_val =0;

	int c = 0;
	do
	{
		dice_val = rand() % 6 + 1;
		do {

		} while (!this->click_dicr(window));
		
	  Animation( window, dice_moves,B,  Playerr,nob, turn);
		window.clear();
		B.drawBoard(window, "6P board_2.png");
		{
			for (int i = 0; i < nob; i++) {
				for (int j = 0; j < 4; j++) {
					if (!Playerr[i]->Ps[j].getWin_bool())
					{
						Playerr[i]->Ps[j].Draw_piece(window);

					}
				}
			}
		}
		drawDialoge(window);
		//print_Dice_arr(window, dice_moves);
		this->draw_dice(window, dice_val);
		TurnMsg(window, turn, nob);
		window.display();
		Sleep(1000);
		dice_moves.push_back(dice_val);
		//____________ 
		// checking if 3 sixes consecutive dafa aa gai hain too unha delete kar da
		for (int i = 0; i < dice_moves.size(); i++)
		{
			if (dice_moves[i] == 6)
			{
				index = i;  // checking the next 2 entries excluding the entry i
				for (int j = 1; j < 3 && j < dice_moves.size(); j++)
				{
					if (dice_moves[index + j] == 6)
						count++;
				}
				// if there are 3 consecutive 6's then delete them
				if (count == 3)
				{           // erasing in a range of three indexes on which 6's are present
					dice_moves.erase(dice_moves.begin(), dice_moves.end());
					dice_moves.shrink_to_fit();
				}
				else
				{
					count = 1;
					break;
				}
			}
			else
			{
				count = 1;
				break;
			}

		}
		//_______________
		//draw_dice(window, dice_val, dice_moves);

	} while (dice_val == 6);
	window.clear();
	B.drawBoard(window, "6P board_2.png");
	{
		for (int i = 0; i < nob; i++) {
			for (int j = 0; j < 4; j++) {
				if (!Playerr[i]->Ps[j].getWin_bool())
				{
					Playerr[i]->Ps[j].Draw_piece(window);

				}
			}
		}
	}
	drawDialoge(window);
	TurnMsg(window, turn, nob);
	window.display();
}
void Dice::dice_shake_select(sf::RenderWindow& window, vector<int>& dice_moves, Board& B, Player** Playerr,int nob,int turn)
{
	vector<int>All_vector_dice{ 1,2,3,4,5,6 };//all dice
	int farig_i = 0;
	Position P;
	int dice_val = 0;
	int index = 0;
	int count = 1;
	int c = 0;
	Music m;
	window.clear();
	drawDialoge(window);
	TurnMsg(window, turn, nob);
	B.drawBoard(window, "6P board_2.png");
	print_Dice_arr(window, All_vector_dice);
	{
		for (int i = 0; i < nob; i++) {
			for (int j = 0; j < 4; j++) {
				if (!Playerr[i]->Ps[j].getWin_bool())
				{
					Playerr[i]->Ps[j].Draw_piece(window);

				}
			}
		}
	}
	window.display();
	do
	{
		
	
		
		cout << "Which number do you want use as dice val\n";
		do
		{
			dice_val= this->select_num_of_Dice_number(window, All_vector_dice, farig_i);

		} while (!(dice_val > 0 && dice_val <= 6));
		m.openFromFile("chi.ogg");
		m.play();


		//_____  for random dice
		//draw_dice(window,dice_val);
		//do
		//{           // Performing and checking the click on dice in the centre of board
		//	P = B.calculate_mouseP(window);
		//} while (!(P.x==6 && P.y==10));
		//srand(time(0));
		//dice_val=(rand() % 6) + 1;
		//_____


		dice_moves.push_back(dice_val);
		//____________ 
		// checking if 3 sixes consecutive dafa aa gai hain too unha delete kar da
		for (int i = 0; i < dice_moves.size(); i++)
		{
			if (dice_moves[i] == 6)
			{
				index = i;  // checking the next 2 entries excluding the entry i
				for (int j = 1; j < 3 && j < dice_moves.size(); j++)
				{
					if (dice_moves[index + j] == 6)
						count++;
				}
				// if there are 3 consecutive 6's then delete them
				if (count == 3)
				{           // erasing in a range of three indexes on which 6's are present
					dice_moves.erase(dice_moves.begin(), dice_moves.end());
					dice_moves.shrink_to_fit();
				}
				else
				{
					count = 1;
					break;
				}
			}
			else
			{
				count = 1;
				break;
			}

		}
		//_______________
		//draw_dice(window, dice_val, dice_moves);
		Sleep(80);
	} while (dice_val == 6);
}
// constructor
Dice::Dice()
{
	vector<string> images_names = { {"dice1.png"},{"dice2.png"},{"dice3.png"},{"dice4.png"},{"dice5.png"},{"dice6.png"} };
	if (!t0.loadFromFile("0dice.png")) {
		cout << "Image 1 Not loaded" << endl;
	}
	if (!t1.loadFromFile("dice1.png")) {
		cout << "Image 1 Not loaded" << endl;
	}
	if (!t2.loadFromFile("dice2.png")) {
		cout << "Image 2 Not loaded" << endl;// error handling
	}
	if (!t3.loadFromFile("dice3.png")) {
		cout << "Image 3 Not loaded" << endl;// error handling
	}
	if (!t4.loadFromFile("dice4.png")) {
		cout << "Image 4 Not loaded" << endl;// error handling
	}
	if (!t5.loadFromFile("dice5.png")) {
		cout << "Image 5 Not loaded" << endl;// error handling
	}
	if (!t6.loadFromFile("dice6.png")) {
		cout << "Image 6 Not loaded" << endl;
		// error handling
	}
	
	s0.setTexture(t0);
	s1.setTexture(t1);
	s2.setTexture(t2);
	s3.setTexture(t3);
	s4.setTexture(t4);
	s5.setTexture(t5);
	s6.setTexture(t6);
}
// mid dice 490,293   indexes : Row=6 col=10
void Dice::draw_dice(sf::RenderWindow& window, const int& draw_value)
{



	int a = 505;
	int b = 303-5;

	float f = 0.16;
	if (draw_value == 0)
	{
		f += 0.08;
		b -= 3;
		a -= 5;
		s0.setScale(f, f);
		s0.setPosition(a, b);
		window.draw(s0);
		
	}
	else if (draw_value == 1)
	{
		
		s1.setScale(f, f);
		s1.setPosition(a, b);

		window.draw(s1);
	}
	else if (draw_value == 2)
	{
		s2.setScale(f, f);
		s2.setPosition(a, b);

		window.draw(s2);
	}
	else if (draw_value == 3)
	{
		s3.setScale(f, f);
		s3.setPosition(a, b);

		window.draw(s3);
	}

	else if (draw_value == 4)
	{
		s4.setScale(f, f);
		s4.setPosition(a, b);

		window.draw(s4);
	}
	else if (draw_value == 5)
	{
		s5.setScale(f, f);
		s5.setPosition(a, b);

		window.draw(s5);
	}
	else if (draw_value == 6)
	{
		f /= 3;
		s6.setPosition(a, b);
		s6.setScale(f, f);
		window.draw(s6);
	}
	

}
void Dice::draw_dice2(sf::RenderWindow& window, const int& draw_value)
{
	int aa = rand() % 25;
	int bb = rand() % 25;
	if (aa % 2 == 0)
		aa *= -1;
	if (bb % 2 == 0)
		bb *= -1;
	int a = 505 +aa;
	int b = 303+bb-5;

	float f = 0.16;
	if (draw_value == 0)
	{
		f += 0.08;
		b -= 3;
		a -= 5;
		s0.setScale(f, f);
		s0.setPosition(a, b);
		window.draw(s0);

	}
	else if (draw_value == 1)
	{

		s1.setScale(f, f);
		s1.setPosition(a, b);

		window.draw(s1);
	}
	else if (draw_value == 2)
	{
		s2.setScale(f, f);
		s2.setPosition(a, b);

		window.draw(s2);
	}
	else if (draw_value == 3)
	{
		s3.setScale(f, f);
		s3.setPosition(a, b);

		window.draw(s3);
	}

	else if (draw_value == 4)
	{
		s4.setScale(f, f);
		s4.setPosition(a, b);

		window.draw(s4);
	}
	else if (draw_value == 5)
	{
		s5.setScale(f, f);
		s5.setPosition(a, b);

		window.draw(s5);
	}
	else if (draw_value == 6)
	{
		f /= 3;
		s6.setPosition(a, b);
		s6.setScale(f, f);
		window.draw(s6);
	}

}
bool Dice::click_dicr(RenderWindow& window)
{

	Position A = mouse_positin_Dice(window);
	//cout << A.x << "pppp" << A.y;
	A.x /= 49.1;
	A.y /= 50.2;
	//cout << "\nRow " << A.x << " Col " << A.y << endl << endl;
	if (A.x == 6 && A.y == 10)
		return true;
	return false;
}
int Dice::select_num_of_Dice_number(RenderWindow& window, vector<int>& dice_moves,int &ahmad_index)
{
	Position A{};
	do
	{
		A = calculate_mouseP_utility(window);
	} while (!((A.x >= 0 && A.x < dice_moves.size()) && A.y == 25));
	ahmad_index = A.x;
	return dice_moves[A.x];
}
void Dice::Animation(sf::RenderWindow& window, vector<int>& dice_moves, Board& B, Player** Playerr, int nob, int turn)
{

	Music music;
	music.openFromFile("di.ogg");
	music.play();
	for (int i = 0; i < 10; i++) {
		int dice_val = (rand() % 6) + 1;
		window.clear();
		B.drawBoard(window, "6P board_2.png");
		{
			for (int i = 0; i < nob; i++) {
				for (int j = 0; j < 4; j++) {
					if (!Playerr[i]->Ps[j].getWin_bool())
					{
						Playerr[i]->Ps[j].Draw_piece(window);

					}
				}
			}
		}
		drawDialoge(window);
		//print_Dice_arr(window, dice_moves);
		this->draw_dice2(window, dice_val);
		TurnMsg(window, turn, nob);
		window.display();
		Sleep(35);
	}
}
