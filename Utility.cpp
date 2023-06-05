#include "Utility.h"

Position::Position(int row,int col)
{
	this->x = row;
	this->y = col;
}
Position::Position()
{
	this->x = 0;
	this->y = 0;
}
bool Position::cheatPicked()
{
	if (this->x>=10 &&x<=12 && y>=21 && y<=26)
		return 1;
		return 0;
}
Position mouse_positin_Dice(sf::RenderWindow& window)
{
	Position raw{ -1,-1 };
	Event event;
	while (window.waitEvent(event)) {
		switch (event.type) {
		case Event::Closed:
			window.close();
			exit(0);
			break;
		case Event::MouseButtonReleased:
			if (event.mouseButton.button == Mouse::Left) {
				raw.x = event.mouseButton.y;
				raw.y = event.mouseButton.x;
				return raw;
			}
			break;
		default:
			break;
		}
	}
	return raw;
}
Position  calculate_mouseP_utility(sf::RenderWindow& window)
{
	Position A = mouse_positin_Dice(window);
	A.x /= 49.1;
	A.y /= 50.2;
	cout << A.x << "    " << A.y<<endl;

	//cout << "\nRow " << A.x << " Col " << A.y << endl << endl;
	return A;
}
int select_num_of_Dice_number_utility(RenderWindow& window, vector<int>& dice_moves, int& ahmad_index)
{
	Position A{};
	do
	{
		A = calculate_mouseP_utility(window);
	} while (!((A.x >= 0 && A.x < dice_moves.size()) && A.y == 25));
	
	ahmad_index = A.x;
	cout << "\nDice Selected \n";
	return dice_moves[A.x];

}
void print_Dice_arr(RenderWindow & window, vector<int>& All_dice)
{
	//print avaliable 
	Texture t1, t2, t3, t4, t5, t6;
	Sprite s1, s2, s3, s4, s5, s6;
	vector<string> images_names = { {"dice1.png"},{"dice2.png"},{"dice3.png"},{"dice4.png"},{"dice5.png"},{"dice6.png"} };
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

	s1.setTexture(t1);
	s2.setTexture(t2);
	s3.setTexture(t3);
	s4.setTexture(t4);
	s5.setTexture(t5);
	s6.setTexture(t6);
	for (int i = 0; i < All_dice.size(); i++)
	{
		int draw_value = All_dice[i];
		int a = 25 * 50;//cols
		int b = i * 49; //row     


		float f = .16;
		if (draw_value == 1)
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
}
void drawDialoge(RenderWindow& window)
{
	Texture te; te.loadFromFile("dialoge.png");
	Sprite s(te); s.setPosition(21 * 50+20, 0 * 50); s.setScale(.52f, .5f);
	window.draw(s);
}
void TurnMsg(RenderWindow& window,int col,int nop)
{
	/*
									#define green 2
									#define lGreen 10
									#define red 4
									#define blue 1
									#define purple 13
									#define yellow 12 // actually skinny
									#define lBlue 9

	*/

	Font font; font.loadFromFile("abc.ttf");
	Text text;
	String A = "";
	if (nop == 2){
			if (col == 2)
			{
				A += "Purple";
				text.setFillColor(Color::Magenta);

			}
		if (col == 1)
		{
			A += "Light Blur";
			text.setFillColor(Color::Cyan);

		}
}

	if (nop == 4) {
		//lBlue,red,purple,yellow
		if (col == 1)
		{
			A += "Light Blur";
			text.setFillColor(Color::Cyan);

		}
		if (col == 2)
		{
			A += "Red";
			text.setFillColor(Color::Red);
		}
		if (col == 3)
		{
			A += "Purple";
			text.setFillColor(Color::Magenta);


		}
		if (col == 4)
		{
			A += "Yellow";
			text.setFillColor(Color::Yellow);


		}
	}
	
	if (nop == 6) {
		//lBlue,red,blue,purple,yellow,lGreen
		if (col == 1)
		{
			A += "Light Blue";
			text.setFillColor(Color::Cyan);
		}
		if (col == 2)
		{
			A += "Red";
			text.setFillColor(Color::Red);
		}
		if (col == 4)
		{
			A += "Purple";
			text.setFillColor(Color::Magenta);


		}
		if (col == 5)
		{
			A += "Yellow";
			text.setFillColor(Color::Yellow);

		}
		
		if (col == 6)
		{
			A += "Green";
			text.setFillColor(Color::Green);

		}
		
		if (col == 3)
		{
			A += "Blue";
			text.setFillColor(Color::Blue);

		}
	}
	A += " Turn";
	
	text.setFont(font); 
	col==1?text.setCharacterSize(38): text.setCharacterSize(50);  text.setString(A);
	text.setPosition(22 * 50.f, 8 * 50.f);
	window.draw(text);

}
void CheatP(RenderWindow& window)
{
	Texture te; te.loadFromFile("cheat.png"); Sprite si(te);
	si.scale(.91f,.8f); si.setPosition(21 * 50 +20, 10 * 50+8); window.draw(si);
}
void MUSIX()
{
	Music music;
	music.openFromFile("di.ogg");
	music.play();
}
void MOVSOUND()
{
	Music music;
	music.openFromFile("snip.ogg");
	music.play();
}

