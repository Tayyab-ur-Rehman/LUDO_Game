#include "Board.h"



Board::Board()
{    // Stops in board
	this->stops=new int[12]{2,7,13,18,24,29,40,45,51,56,62,67};

	this->Board_indexes = 75; // 0-75
	//___
	this->SkyBlue_domain[0] = 0;
	this->SkyBlue_domain[1] = 10;

	//___
	this->Red_domain[0] = 11;
	this->Red_domain[1] = 21;
	//___
	this->Blue_domain[0] = 22;
	this->Blue_domain[1] = 32;
	//___
	this->Purple_domain[0] = 38;
	this->Purple_domain[1] = 48;
	//___
	this->Yellow_domain[0] = 49;
	this->Yellow_domain[1] = 59;
	//___
	this->Green_domain[0] = 60;
	this->Green_domain[1] = 70;
	/////////////////////////////////////////////////////////////////////////////////////////
	this->SkyBlue_house[0] = -4;
	this->SkyBlue_house[1] = -1;
	//
	this->Red_house[0] = -14;
	this->Red_house[1] = -11;
	//
	this->Blue_house[0] = -24;
	this->Blue_house[1] = -21;
	//
	this->Purple_house[0] = -34;
	this->Purple_house[1] = -31;
	//
	this->Yellow_house[0] = -44;
	this->Yellow_house[1] = -41;
	//
	this->Green_house[0] = -54;
	this->Green_house[1] = -51;
	          
	


}
/*
void Board::drawBoard(sf::RenderWindow& window, string img_name)
{
	sf::Texture temp;
	if (!temp.loadFromFile(img_name))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}
	// scale of board are 0.31
	sf::Sprite s(temp);
	s.setScale(.9,.9); //  (width and heigth of image to be printed)

	s.setPosition(100, 50); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	
}
*/
bool Board::stop_Checker(Piece* P,const int& dst_index)
{
	for (int i = 0; i < 12; i++)
	{
		if (P->get_Index()+dst_index == this->stops[i])
		{
			return true;
			// The destination is a stop
		}
	}
	return false;
	// The destination is not a stop
}

Position Board::mouse_positin(sf::RenderWindow& window)   //_______________________
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
Position Board::calculate_mouseP(sf::RenderWindow& window)
{
	Position A = mouse_positin(window);
	A.x /= 49.1;
	A.y /= 50.2;
	cout << "\nRow " << A.x << " Col " << A.y << endl;
	return A;
}

int Board::index_provider(sf::RenderWindow& window)
{
	Position A = calculate_mouseP(window);
	if (A.x == 8 && A.y == 7)
		return 76;


	if (A.y == 5)
	{
		if (A.x >= 0 && A.x <= 4)
			return (26 - A.x);
		if (A.x >= 8 && A.x <= 12)
			return (18 - A.x);
	}
	else if (A.y == 6)
	{
		if (A.x == 0)
			return 27;
		if (A.x == 12)
			return 5;
		if (A.x >= 1 && A.x <= 4)
			return ((5 - A.x) * -1) - 20;
		if (A.x >= 8 && A.x <= 12)
			return  ((A.x - 7) * -1);
	}
	else if (A.y == 7)
	{
		if (A.x >= 0 && A.x <= 4)
			return (28 + A.x);
		if (A.x >= 8 && A.x <= 12)
			return (A.x - 8);
	}

	else if (A.y == 13)
	{
		if (A.x >= 0 && A.x <= 4)
			return (42 - A.x);
		if (A.x >= 8 && A.x <= 12)
			return (78 - A.x);
	}
	else if (A.y == 14)
	{
		if (A.x == 12)
			return 65;
		if (A.x == 0)
			return 43;
		if (A.x >= 8 && A.x <= 11)
			return ((A.x - 7) * -1) - 50;

		if (A.x >= 1 && A.x <= 4)
			return ((5 - A.x) * -1) - 30;
	}
	else if (A.y == 15)
	{
		if (A.x >= 0 && A.x <= 4)
			return (44 + A.x);
		if (A.x >= 8 && A.x <= 12)
			return (52 + A.x);
	}

	if (A.x == 5)
	{
		if (A.y >= 0 && A.y <= 4)
			return (17 + A.y);
		if (A.y >= 8 && A.y <= 12)
			return (25 + A.y);
		if (A.y >= 16 && A.y <= 20)
			return (33 + A.y);


	}
	if (A.x == 6)
	{
		if (A.y == 0)
			return 16;
		if (A.y == 20)
			return 54;
		if (A.y >= 1 && A.y <= 4)
			return ((5 - A.y) * -1) - 10;
		if (A.y >= 16 && A.y <= 20)
			return (-(A.y - 15) + -40);

	}
	if (A.x == 7)
	{
		if (A.y >= 0 && A.y <= 4)
			return (15 - A.y);
		if (A.y >= 8 && A.y <= 12)
			return (83 - A.y);
		if (A.y >= 16 && A.y <= 20)
			return (75 - A.y);
	}
	if ((A.x <= 12 && A.x >= 8) && (A.y <= 4 && A.y >= 0))
		return -100;
	if ((A.x <= 4 && A.x >= 0) && (A.y <= 4 && A.y >= 0))
		return -200;
	if ((A.x <= 4 && A.x >= 0) && (A.y <= 12 && A.y >= 8))
		return -300;
	if ((A.x <= 4 && A.x >= 0) && (A.y <= 20 && A.y >= 16))
		return -400;
	if ((A.x <= 12 && A.x >= 8) && (A.y <= 20 && A.y >= 16))//
		return -500;
	if ((A.x <= 12 && A.x >= 8) && (A.y <= 12 && A.y >= 8))//
		return -600;

	return -1000;
}

void Board::drawBoard(sf::RenderWindow& window, string img_name)
{
	sf::Texture temp;
	if (!temp.loadFromFile(img_name))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}
	// scale of board are 0.31
	sf::Sprite s(temp);
	s.setScale(.9, .9); //  (width and heigth of image to be printed)

	s.setPosition(0, 0); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen

}