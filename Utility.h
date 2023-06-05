#pragma once
#include<iostream>
#include "vector"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include <cstdlib>
#include <cstdlib>
#include <windows.h>
#include <Windows.h>


using namespace std;
using namespace sf;
#define black 0
#define brown 6
#define white 15
#define green 2
#define lGreen 10
#define red 4
#define blue 1
#define purple 13
#define yellow 12 // actually skinny
#define lBlue 9


class Position
{
public:
	int y,x;
	Position(int row, int col);
	Position();
	bool cheatPicked();
};
Position mouse_positin_Dice(sf::RenderWindow& window);
Position  calculate_mouseP_utility(sf::RenderWindow& window);
int select_num_of_Dice_number_utility(RenderWindow& window, vector<int>& dice_moves, int& ahmad_index);
void print_Dice_arr(RenderWindow& window, vector<int>& dice_moves);
void drawDialoge(RenderWindow& window);
void TurnMsg(RenderWindow& window, int col,int nop);
void CheatP(RenderWindow& window);
void MUSIX();
void MOVSOUND();


