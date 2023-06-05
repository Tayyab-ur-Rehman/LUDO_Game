#include "Ludo.h"
#include <cstdlib>
#include <windows.h>
#include <Windows.h>
#include<conio.h>


Ludo::Ludo(RenderWindow & window)
{
	char frnd;
	this->turn = 1;
	cout << "How many players are playing (Least is 2 and max 6)\n";
	/////////////////////////////////////////////////
	Music mm; 
	string I = "ludo_pic.png";
	string Ii = "f1.png";//new
	////////////////////////////////////////
	Texture tempi; tempi.loadFromFile(I);
	Sprite imgi(tempi);
	imgi.setScale(.7, .67);
	imgi.setPosition(0, 0);
	////////////////////////////////////////
	Texture temp; temp.loadFromFile(Ii);
	Sprite img(temp);
	img.setScale(.28, .3);
	img.setPosition(0, 0);
	window.draw(imgi);
	Text text;
	Font font; font.loadFromFile("abc.ttf");

	string A = "Produced by";
	text.setFont(font); text.setCharacterSize(50); text.setFillColor(Color::Green); text.setString(A);
	text.setPosition(1 * 50.f, 9.1 * 50.f); window.draw(text);
	A = " M.Ahmad";
	text.setFont(font); text.setCharacterSize(70); text.setFillColor(Color::Black); text.setString(A);
	text.setPosition(0 * 50.f, 10 * 50.f); window.draw(text);
	A = "Directed by";
	text.setFont(font); text.setCharacterSize(50); text.setFillColor(Color::Red); text.setString(A);
	text.setPosition(1 * 50.f, 11.3 * 50.f); window.draw(text);
	A = " TAYYAB ";
	text.setFont(font); text.setCharacterSize(70); text.setFillColor(Color::Black); text.setString(A);
	text.setPosition(0 * 50.f, 12.2 * 50.f); window.draw(text);
	window.display();
	calculate_mouseP_utility(window); 
	mm.openFromFile("notify.ogg");
	mm.play();
    /////////////////////////////////////////////////////////////////////////////////////////////////
	window.clear();
	window.draw(img);
	 A = "2";
	 Text text1;
	text1.setFont(font);text1.setCharacterSize(100); text1.setFillColor(Color::Yellow); text1.setString(A);
	text1.setPosition(15*50.f, 12*50.f); window.draw(text1);
	A = "4";
	Text text2;
	text2.setFont(font);text2.setCharacterSize(100); text2.setFillColor(Color::Red); text2.setString(A);
	text2.setPosition(19 * 50.f, 12 * 50.f); window.draw(text2);
	Text text3;
	A = "6";
	text3.setFont(font);text3.setCharacterSize(100); text3.setFillColor(Color::Green); text3.setString(A);
	text3.setPosition(23 * 50.f, 12 * 50.f); window.draw(text3);
	 A = "PLAYERS ";
	 Text text4;
	 text4.setFont(font); text4.setCharacterSize(80); text4.setFillColor(Color::White); text4.setString(A);
	text4.setPosition(1 * 50.f, 12.1 * 50.f); window.draw(text4);
	A = "Ludo ";
	Text text5;
	text5.setFont(font); text5.setCharacterSize(160); text5.setFillColor(Color::White); text5.setString(A);
	text5.setPosition(4.8 * 50.f, 3.1 * 50.f); window.draw(text5);
	window.display();
	////////////////////////////////////////////////
	
	do
	{
		Position J{-1,-1};
		{
			
			Event event;
			while (window.waitEvent(event)) {
				bool dra = false;
				
				int abc = Mouse::getPosition(window).y / 49;
				if(dra==0)
				if (abc == 13 || abc == 14 || abc == 15)
				{

					int def = sf::Mouse::getPosition(window).x / 50.2;
					if (def == 14 || def == 15)
					{
						mm.openFromFile("notify.ogg");
						mm.play();
						//dra = 1;
						text1.setStyle(sf::Text::Bold | sf::Text::StrikeThrough | sf::Text::Underlined);
						text1.setFillColor(sf::Color::White);
						window.clear();

						window.draw(img);
						window.draw(text5);
						window.draw(text4);
						window.draw(text1); window.draw(text2); window.draw(text3);
						window.display();
					}
					if (def == 18 || def == 19)
					{
						mm.openFromFile("notify.ogg");
						mm.play();

						//dra = 1;
						text2.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::StrikeThrough);
						text2.setFillColor(sf::Color::White);
						window.clear();
						window.draw(img);
						window.draw(text4);
						window.draw(text5);
						window.draw(text1); window.draw(text2); window.draw(text3);
						window.display();
					}
					if (def == 23 || def == 22)
					{
						mm.openFromFile("notify.ogg");
						mm.play();

						//dra = 1;
						text3.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::StrikeThrough);
						text3.setFillColor(sf::Color::White);
						window.clear();
						window.draw(img);
						window.draw(text4);
						window.draw(text5);
						window.draw(text1); window.draw(text2); window.draw(text3);
						window.display();
					}

				}
				else
					dra = 1;
				switch (event.type) {
				case Event::Closed:
					window.close();
					exit(0);
					break;
				case Event::MouseButtonReleased:
					if (event.mouseButton.button == Mouse::Left) {
						J.x = event.mouseButton.y;
						J.y = event.mouseButton.x;
						{
							J.x /= 49.1;
							J.y /= 50.2;
							cout << "x" << J.x << "  y" << J.y;

						}
						goto lable;
					}
					break;
				default:
					break;
				}
				Sleep(70);
				if (dra == 1)
				{
					text1.setStyle(sf::Text::Regular);
					text2.setStyle(sf::Text::Regular);
					text3.setStyle(sf::Text::Regular);
					text1.setFillColor(Color::Yellow);
					text2.setFillColor(Color::Red);
					text3.setFillColor(Color::Green);
					
					window.clear();
					window.draw(img);
					window.draw(text5);
					window.draw(text4);
					window.draw(text1); window.draw(text2); window.draw(text3);
					window.display();
				}
			}
			lable:
			if (J.x >= 13 && J.x <= 15)
			{
				if (J.y == 14 || J.y == 15)
					this->NO_player = 2;

				if (J.y == 18 || J.y == 19)
					this->NO_player = 4;
				if (J.y == 23 || J.y == 22)
					this->NO_player = 6;
			}
			else
				this->NO_player = 0;

		}
	} while (!(this->NO_player==6||this->NO_player==2|| this->NO_player == 4));
	// Board is already created
		   // For 2 player (only solo match)
	if (NO_player == 2)
	{
		vector<int> clr = { lBlue,purple };
		vector<vector<char>> empty = { {} };// No friends
		this->Plr = new Player * [NO_player];
		for (int i = 0; i < NO_player; i++)
		{

			this->Plr[i] = new Player(clr[i], empty[0], i + 1);

		}
	}
	else // if the game is not 2 players
	{
		
	    frnd='s';
		
		(frnd == 'f') ? this->friend_mode = true : this->friend_mode = false;
		if (NO_player == 6)
		{    // if its a friend mode game
			vector<int> clr = { lBlue,red,blue,purple,yellow,lGreen };// Total pieces which are going to be made
			if (frnd == 'f')
			{
				
				                        // B stands for dark blue and b stands for light blue
				vector<vector<char>> frnd = { {'B','y'},{'g','p'},{'b','y'},{'r','g'},{'B','b'},{'r','p'}};
				this->Plr = new Player * [NO_player];
				
				for (int i = 0; i < NO_player; i++)
				{
					
				    this->Plr[i] = new Player(clr[i], frnd[i], i + 1);

				}

			}  // If 6 player solo game
			else
			{
				vector<vector<char>> empty = { {} };// No friends
				this->Plr = new Player * [NO_player];
				for (int i = 0; i < NO_player; i++)
				{

					this->Plr[i] = new Player(clr[i], empty[0],i+1);

				}
			}

		}   // 4 players mode
		if (NO_player==4)
		{
			// Friend mode
			vector<int> clr = { lBlue,red,purple,yellow };// Total pieces which are going to be made (Only 4)
			if(frnd=='f')
			{                             // b stands for light blue
				vector<vector<char>> frnd = { {'p'},{'y'},{'b'},{'g'}};
				this->Plr = new Player * [NO_player];

				for (int i = 0; i < NO_player; i++)
				{

					this->Plr[i] = new Player(clr[i], frnd[i], i + 1);

				}
			} // solo 4 player mode
			else
			{
				vector<vector<char>> empty = { {} };// No friends
				this->Plr = new Player * [NO_player];
				for (int i = 0; i < NO_player; i++)
				{

					this->Plr[i] = new Player(clr[i], empty[0], i + 1);

				}
			}
		} 

	}
	
}
 
bool Ludo::empty_destination(Piece*P,const int& dst_index)
{    // Traversing into the players array
	for (int i = 0; i < NO_player; i++)
	{    // Traversing into the player's pieces array 
		for (int j = 0; j < 4; j++)
		{   // is the piece is in house or has won: no need to check
			if (!(this->Plr[i]->Ps[j].get_Index()<-90|| this->Plr[i]->Ps[j].getWin_bool()))
			{           // Checking the index of all 4 pieces of the Player
				if (P->get_Index()+dst_index == this->Plr[i]->Ps[j].get_Index())
				{
					return false;
				}
			}
			
		}
	}
	return true;

}

    // this will detect that piece is coming out of its box so it will move it
bool  Ludo::piece_1st_move(Piece* P,const int& dice_val,const int& turn, int& out_index, bool first_move_bool)
{    // ya check bahir lagna chia tha                         // ya turn ludo wali ha na ka indvidual player ki
	if (P->get_Index() < -90)
	{
		if (dice_val==6)
		{
			if (NO_player == 6)
			{
				if (turn == 1)
				{
					out_index = 7; // light blues out index
					return true;
				}
				else if (turn == 2)
				{
					out_index = 18; // red  out index
					return true;
				}
				else if (turn == 3)
				{
					out_index = 29; //blue out index
					return true;
				}
				else if (turn == 4)
				{
					out_index = 45; // purple out index
					return true;
				}
				else if (turn == 5)
				{
					out_index = 56; // yellow out index
					return true;
				}
				else if (turn == 6)
				{
					out_index = 67; // green out index
					return true;
				}
				cout << "piece_1st_move 6 pieces has struck return false" << endl;
				return false;
			}  // if 4 player mode
			else if (NO_player == 4)
			{
				if (turn == 1)
				{
					out_index = 7; // light blues out index
					return true;
				}
				else if (turn == 2)
				{
					out_index = 18; // red  out index
					return true;
				}
				else if (turn == 3)
				{
					out_index = 45; //purple out index
					return true;
				}
				else if (turn == 4)
				{
					out_index = 56; // purple out index
					return true;
				}
				cout << "piece_1st_move 4 pieces has struck return false" << endl;
				return false;
			}// if 2 player
			else
			{
				if (turn == 1)
				{
					out_index = 7; // light blues out index
					return true;
				}
				else if (turn == 2)
				{
					out_index = 45; // purple out index
					return true;
				}
				cout << "piece_1st_move 2 pieces has struck return false" << endl;
				return false;
			}

		}
		else
		{   // Agr value 6 nhi ha too piece bahir nhi nikal sakta
			return false;
		}

	}  // koi piece ha hi nhi ghar ma to ksa bahir nikalan 
	return false;

}
// checks if the piece is at its door and valid to enter the middle row (pugna ka lia)
bool Ludo::piece_at_door_check(Player& plr,Piece* P)
{
	if (plr.has_killed == true) // is one piece of a player kills enemy piece all pieces of that player are eligible to go inside
	{          
		if (P->getCh_clr() == 'b' && P->get_Index() == 5)
		{    // blue is at its door step as is ready to go inside.. same for others
			return true;
		}
		if (P->getCh_clr() == 'r' && P->get_Index() == 16)
		{
			return true;
		}
		if (P->getCh_clr() == 'B' && P->get_Index() == 27)
		{
			return true;
		}
		if (P->getCh_clr() == 'p' && P->get_Index() == 43)
		{
			return true;
		}
		if (P->getCh_clr() == 'y' && P->get_Index() == 54)
		{
			return true;
		}
		if (P->getCh_clr() == 'g' && P->get_Index() == 65)
		{
			return true;
		}

	}
	cout << " piece_at_door_check has struck return false\n";
	return false;
}

//    
//bool Ludo::piece_checker_move(Player& plr,Piece* P,const int& dst_index)
//{            // If the destination is not a stop
//	
//		if (!this->B.stop_Checker(P,dst_index))
//		{      // If dst id empty
//			if (empty_destination(P,dst_index))
//			{
//				// Piece will move without any problem
//				return true;
//				
//
//			}
//			else
//			{
//				// Traversing into the players array
//				for (int i = 0; i < NO_player; i++)
//				{    // Traversing into the player's pieces array 
//					for (int j = 0; j < 4; j++)
//					{   // is the piece is in house or has won: no need to check
//						if (!(this->Plr[i]->Ps[j].get_Index()<-90 || this->Plr[i]->Ps[j].getWin_bool()))
//						{           // Checking the index of all 4 pieces of the Player with the indeexes of all 4 pieces of all other Players (ka turn pa jo player ha wo ksi or player ka piece koye to nhi rha)
//							if (P->get_Index()+dst_index == this->Plr[i]->Ps[j].get_Index())
//							{
//								 // reaching here means that there is a piece on the destination of our piece
//								      
//								this->Plr[turn-1]->has_killed = true; // player ha killed the enemy player || turn wla player ki gotian ab pug sakti hain
//			
//								
//								if (this->Plr[i]->Ps[j].getCh_clr() == 'b')
//								{
//									this->Plr[i]->Ps[j].set_index(-100);
//								}
//								else if (this->Plr[i]->Ps[j].getCh_clr() == 'r')
//								{
//									this->Plr[i]->Ps[j].set_index(-200);
//								}
//								else if (this->Plr[i]->Ps[j].getCh_clr() == 'B')
//								{
//									this->Plr[i]->Ps[j].set_index(-300);
//								}
//								else if (this->Plr[i]->Ps[j].getCh_clr() == 'p')
//								{
//									this->Plr[i]->Ps[j].set_index(-400);
//								}
//								else if (this->Plr[i]->Ps[j].getCh_clr() == 'y')
//								{
//									this->Plr[i]->Ps[j].set_index(-500);
//								}
//								else if (this->Plr[i]->Ps[j].getCh_clr() == 'g')
//								{
//									this->Plr[i]->Ps[j].set_index(-600);
//								}
//								else
//								{
//									cout << "Error occured piece_checker_move: line 311\n";
//										return false;
//								}
//								return true;
//									
//
//							
//
//							}
//						}
//
//					}
//				}
//			}
//
//		}
//		// If the destinaton is a stop || Piece will move without any problem
//		return true;
//	
//
//	//}
//	
//
//}



bool Ludo::piece_checker_move(Player& plr, Piece* P, const int& dst_index)
{            // If the destination is not a stop

	if (!this->B.stop_Checker(P, dst_index))
	{      // If dst id empty
		if (empty_destination(P, dst_index))
		{
			// Piece will move without any problem
			return true;


		}
		else
		{
			// Traversing into the players array
			for (int i = 0; i < NO_player; i++)
			{    // Traversing into the player's pieces array 
				for (int j = 0; j < 4; j++)
				{   // is the piece is in house or has won: no need to check
					if (!(this->Plr[i]->Ps[j].get_Index() < -90 || this->Plr[i]->Ps[j].getWin_bool()))
					{           // Checking the index of all 4 pieces of the Player with the indeexes of all 4 pieces of all other Players (ka turn pa jo player ha wo ksi or player ka piece koye to nhi rha)
						if (P->get_Index() + dst_index == this->Plr[i]->Ps[j].get_Index())
						{     // Agr destination pa piece apna hi ha to baghar beat kia wapis bhj da

							if (this->Plr[i]->Ps[j].getCh_clr() == P->getCh_clr())
							{
								return true;
							}
							
							// reaching here means that there is a piece on the destination of our piece

							this->Plr[turn - 1]->has_killed = true; // player ha killed the enemy player || turn wla player ki gotian ab pug sakti hain


							if (this->Plr[i]->Ps[j].getCh_clr() == 'b')
							{
								this->Plr[i]->Ps[j].set_index(-100);
							}
							else if (this->Plr[i]->Ps[j].getCh_clr() == 'r')
							{
								this->Plr[i]->Ps[j].set_index(-200);
							}
							else if (this->Plr[i]->Ps[j].getCh_clr() == 'B')
							{
								this->Plr[i]->Ps[j].set_index(-300);
							}
							else if (this->Plr[i]->Ps[j].getCh_clr() == 'p')
							{
								this->Plr[i]->Ps[j].set_index(-400);
							}
							else if (this->Plr[i]->Ps[j].getCh_clr() == 'y')
							{
								this->Plr[i]->Ps[j].set_index(-500);
							}
							else if (this->Plr[i]->Ps[j].getCh_clr() == 'g')
							{
								this->Plr[i]->Ps[j].set_index(-600);
							}
							else
							{
								cout << "Error occured piece_checker_move: line 311\n";
								return false;
							}
							return true;




						}
					}

				}
			}
		}

	}
	// If the destinaton is a stop || Piece will move without any problem
	return true;


	//}


}

bool Ludo::Win_checker(string& msg)
{    
	
	//if in friend mode
	if (friend_mode==true)
	{
		int count_T1 = 0, count_T2 = 0;
		for (int i = 0; i < NO_player; i++)
		{       
			for (int j = 0; j < 4; j++)
			{
				if (this->Plr[i]->Ps[j].getWin_bool())
				{   // Team 1
					if (i == 0 || i == 2 || i == 4)
					{
						count_T1++;
					}
					else // others are team 2
					{
						count_T2++;
					}

				}
			}
		}
		if (NO_player == 6)
		{	
			if (count_T1 == 12)
			{
				msg = "Team Blue has won!!!";
				return true;
			}
			else if (count_T2 == 12)
			{
				msg = "Team Red has won!!!";
				return true;
			}
			return false;
		}   
		else if (NO_player == 4) // For 4 player friend mode
		{
			if (count_T1 == 8)
			{
				msg = "Team Blue has won!!!";
				return true;
			}
			else if (count_T2 == 8)
			{
				msg = "Team Red has won!!!";
				return true;
			}
			return false;
		}
	}
	else // For solo and 2 player mode
	{                  // One count for every team
		int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
		for (int i = 0; i < NO_player; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (this->Plr[i]->Ps[j].getWin_bool())
				{   // Team 1
					if (i == 0)
					{
						c1++;
					}
					else if (i == 1) // others are team 2
					{
						c2++;
					}
					else if (i == 2) // others are team 2
					{
						c3++;
					}
					else if (i == 3) // others are team 2
					{
						c4++;
					}
					else if (i == 4) // others are team 2
					{
						c5++;
					}
					else if (i == 5) // others are team 2
					{
						c6++;
					}
				}
			}
		}

		// For 2 players
		if (NO_player == 2)
		{
			if (c1 == 4)
			{
				msg = "Light Blue Player has won!!!";
				return true;
			}
			else if (c2 == 4)
			{
				msg = "Purple PLayer has won!!!";
				return true;
			}
			return false;
			// For 4 players
			if (NO_player == 4)
			{
				if (c1 == 4)
				{
					msg = "Light Blue Player has won!!!";
					return true;
				}
				else if (c2 == 4)
				{
					msg = "Red PLayer has won!!!";
					return true;
				}
				else if (c3 == 4)
				{
					msg = "Purple Player has won!!!";
					return true;
				}
				else if (c4 == 4)
				{
					msg = "Yellow Player has won!!!";
					return true;
				}
				return false;

			}

			// For 6 players
			if (NO_player == 6)
			{
				if (c1 == 4)
				{
					msg = "Light Blue Player has won!!!";
					return true;
				}
				else if (c2 == 4)
				{
					msg = "Red PLayer has won!!!";
					return true;
				}
				else if (c3 == 4)
				{
					msg = "Blue Player has won!!!";
					return true;
				}
				else if (c4 == 4)
				{
					msg = "Purple Player has won!!!";
					return true;
				}
				else if (c5 == 4)
				{
					msg = "Yellow Player has won!!!";
					return true;
				}
				else if (c6 == 4)
				{
					msg = "Green Player has won!!!";
					return true;
				}
				return false;


			}

		}
	}
}

void Ludo::printAll(sf::RenderWindow& window)
{
	float increse_r = 23;
	float increse_c = 12;

	B.drawBoard(window, "6P board_2.png");
	for (int i = 0; i < this->NO_player; i++) {
		for (int j = 0; j < 4; j++) {
			if (!this->Plr[i]->Ps[j].getWin_bool())
			{
				this->Plr[i]->Ps[j].Draw_piece(window);
				
			}
		}
	}


}
void Ludo::printWithVector(sf::RenderWindow& window,vector<int> A)
{
	this->printAll(window);
	drawDialoge(window);

	print_Dice_arr(window, A);
}
   // only checks wheather the piece is inside the house or not
void Ludo::printAll_dice(sf::RenderWindow& window, int value)
{
	this->printAll(window);
	this->D.draw_dice(window, value);//center
	//draw total di
}

Piece* return_valid_player(const Player& p1)
{
	for (int i = 0; i < 4; i++)
	{         // Agr piece ghar ma ha or jita nhi to wo bahir aa sakta ha
		if (p1.Ps[i].get_Index() < -90 && p1.Ps[i].getWin_bool() == false)
		{
			return &p1.Ps[i];
		}
	}
	 // Agr koi bhi piece ghar pa nhi ha too nullptr bhj da
	return nullptr;
}

int Helper_index_giver(int NO_player,Player** P,int x)
{
	for (int i = 0; i < NO_player; i++)
	{
		if (P[i]->home_index == x)
		{
			return i;
		}
	}    // if we are playing 6 player and 4 player
}
  
// this check is for indexes like -100 -200 and do on
//bool Ludo::p_index_checker(const int& p_index)
//{
//	if (p_index == -100)
//	{
//
//	}
//
//}

Piece* Ludo::Piece_picker(RenderWindow& window,const int& turn,const int& val, bool is_out_house)
{    
	int  p_index = 0; // The index which we are gonna pick from board
	Piece* decoy=nullptr	;
	do
	{      // ghar wla pieces ka check bhi lag gia means ka agr plyer ghar sa piece uthana chaha or ghar ma koi piece na ho to ya dobara pocha ga
		p_index = B.index_provider(window);
		cout << p_index<<endl;
		if (p_index <= 76 && p_index >= 0|| (p_index%10>=-4 && p_index % 10<= -1) )
		{
			
			// now we are going to search which piece is it 
			// actually we only need to check the pieces of player at that turn and its friends
			for (int i = 0; i < 4; i++)
			{            // PLayer       its piece 
				if (this->Plr[turn - 1]->Ps[i].get_Index() == p_index)  // turn-1 is lia kionka turn 1 sa start ho rhi ha
				{           // Agr same index ha too ya wla piece return kar do
					return &this->Plr[turn - 1]->Ps[i];
				}


			}
			//_________________________________________Not required now________________________________________
			// for loop sa bahir ana ka matlab us player ma nhi ha 
					// agr friends mode ha to friends ko search karo
			if (this->friend_mode)
			{
				// Traversing in friends char array present in player
				for (int i = 0; i < this->Plr[turn - 1]->No_of_friends; i++)
				{       // searching for friend in the PLr array
					for (int j = 0; j < NO_player; j++)
					{       // comparing the char of friends array of the player in turn with the color chars of all players
						if (this->Plr[turn - 1]->f_players[i] == this->Plr[j]->ch_clr)
						{
							for (int k = 0; k < 4; k++)
							{  // if a friend is found
									// then compare its 4 pieces with the index
								if (this->Plr[j]->Ps[k].get_Index() == p_index)
								{          // Agr same index ha too ya wla piece return kar do
									return &this->Plr[j]->Ps[k];
								}

							}

						}
					}
				}

			}
			//___________________________________________________________________________________
			// jab tak nhi milta dhondta raho or user sa pochta rho
			
		}
		else
		{
			int which_player = 0;

			if (val == 6)
			{
				
					
					if (p_index == -100)
					{
						which_player = 1; // just as decoy its not needed here
						decoy=return_valid_player(*this->Plr[0]); // it is always gonna be blue player
					}
					else if (p_index == -200)
					{       // searching player which has the -200 index
						which_player = Helper_index_giver(NO_player, this->Plr, -200);
						decoy = return_valid_player(*this->Plr[which_player]);
					}
					else if (p_index == -300)
					{
						which_player = Helper_index_giver(NO_player, this->Plr, -300);
						decoy = return_valid_player(*this->Plr[which_player]);
					}
					else if (p_index == -400)
					{
						which_player = Helper_index_giver(NO_player, this->Plr, -400);
						decoy = return_valid_player(*this->Plr[which_player]);
					}
					else if (p_index == -500)
					{
						which_player = Helper_index_giver(NO_player, this->Plr, -500);
						decoy = return_valid_player(*this->Plr[which_player]);
					}
					else if (p_index == -600)
					{
						which_player = Helper_index_giver(NO_player, this->Plr, -600);
						decoy = return_valid_player(*this->Plr[which_player]);
					}
					
					if (decoy != nullptr)
					{
						return decoy;
					}
				
			}
			// if we want to make a piece come out of his house but the value is not 6
			
		}  // nullptr wala masla hi kahtam kar dia
	} while (true);

	/*cout << "Piece_picker has struck nullptr" << endl;
	return nullptr;*/
}


int dice_value_picker(RenderWindow& window,vector<int>& dice_values,int& index)
{
	
	int val = 0;
	int i = 0;
	cout << "Which value you want to pick" << endl;
	cout << "size of array is: " << dice_values.size() << endl;
	cin >>i;
	index = i;
	val = dice_values[index];
	
	return val;

}
      // checks ka piece jo pick hoa ha wo turn or No_of_players ka lahaz sa sahi hoa ha ya nhi
bool Ludo::is_Piece_pick_valid(Piece* P)
{
	if (P==nullptr)
	{
		return false;
	}
	else if(NO_player == 6)
	{        // Agr 1st turn ho or player na light blue piece pick kia ha to ok ha ........
		if (this->turn == 1 && P->getCh_clr() == 'b')
		{
			return true;
		}
		else if (this->turn == 2 && P->getCh_clr() == 'r')
		{
			return true;
		}
		else if (this->turn == 3 && P->getCh_clr() == 'B')
		{
			return true;
		}
		else if (this->turn == 4 && P->getCh_clr() == 'p')
		{
			return true;
		}
		else if (this->turn == 5 && P->getCh_clr() == 'y')
		{
			return true;
		}
		else if (this->turn == 6 && P->getCh_clr() == 'g')
		{
			return true;
		}
		
		
	}  
	// for 4 player match
	else if (NO_player == 4)
	{
		if (this->turn == 1 && P->getCh_clr() == 'b')
		{
			return true;
		}
		else if (this->turn == 2 && P->getCh_clr() == 'r')
		{
			return true;
		}
		else if (this->turn == 3 && P->getCh_clr() == 'p')
		{
			return true;
		}
		else if (this->turn == 4 && P->getCh_clr() == 'y')
		{
			return true;
		}

	}  // 2 player match
	else
	{
		if (this->turn == 1 && P->getCh_clr() == 'b')
		{
			return true;
		}
		else if (this->turn == 2 && P->getCh_clr() == 'p')
		{
			return true;
		}
	
	}
	// agr ghalat ha too return false
	return false;
}
//______________________________

void turn_change(int&turn,const int& NO_players)
{
	turn = (++turn) % (NO_players + 1);
	if (turn == 0)
	{
		turn++;
	}
}
//_______________________________
 // agr pahli move ha or 6 sa chota dice aa jta ha too turn change karka dobara dice shake kara
bool Ludo::redicer_check(Player& P)
{

	
	if (dice_moves[0]!=6)
	{      //  Agr sara ghar pa hi hain or phli move 6 nhi ha
		if(P.All_piece_unavaliable() )//|| P.all_pieces_at_home_check()) 
		{
			turn_change(this->turn, this->NO_player);
			this->dice_moves.erase(dice_moves.begin(), dice_moves.end()); // dice moves wla vector empty kar da
			return true;  // redicing ki zarorat ha
		}
		
	}
	return false; // agr pahli move 6 ha to zarorat nhi check karna ki

}
// Promotion of piece checker
//bool Ludo::inHouse_move_checker(Player& Plr,Piece* P,const int&dice_val,int& decoy)
//{
//
//	//if(P->getCh_clr() == 'b' && (P->get_Index()+ dice_val>=2);
//	
//	int difference = 0;
//	if (Plr.has_killed == true)
//	{      // Agr piece abhi mid row ma nhi gia
//		if (P->in_mid_row == false)
//		{    // 1 For Light blue pieces 
//			if (P->getCh_clr() == 'b' && (P->get_Index()==76 ||(P->get_Index() >= 1 && P->get_Index() <= 5)))
//			{    // AGr piece ha hi door pa to ya chala ga
//				if (P->get_Index() == 5)
//				{    // agr dice ki value 6 sa smaller ha
//					if (dice_val < 6)
//					{
//						P->get_Index() = -4;   // 4
//						P->get_Index() += (dice_val - 1);
//						P->in_mid_row = true;
//						if (P->get_Index() == 0)
//						{
//							P->is_Win = true;
//						}
//						return false;
//					}
//					else
//					{
//						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
//					}
//					
//				}        // door sa pahla ha piece magar apna colour ki domain maha
//				else if(P->get_Index()==76 || (P->get_Index() >= 1 && P->get_Index() < 5))
//				{
//					if (P->get_Index() == 76) { P->get_Index() = 0; } // just for simplicity in calculation
//					if (P->get_Index() + dice_val > 5)
//					{
//						difference = 5 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
//						P->get_Index() = -4; // one value from the dice is used
//						P->get_Index() += (dice_val - (difference+1));
//						P->in_mid_row = true;
//						if (P->get_Index() == 0)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//					 
//				}
//				cout << "Ludo.cpp: Line 833 return true hit\n";
//				return true;  // dobara sa dice_val or piece select karo
//			}   // 2 For Red Piece 
//			else if (P->getCh_clr() == 'r' && (P->get_Index() >= 11 && P->get_Index() <= 16))
//			{
//				// AGr piece ha hi door pa to ya chala ga
//				if (P->get_Index() == 16)
//				{    // agr dice ki value 6 sa smaller ha
//					if (dice_val < 6)
//					{
//						P->get_Index() = -14;   // 4
//						P->get_Index() += (dice_val - 1);
//						P->in_mid_row = true;
//						if (P->get_Index() == -10)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//					else
//					{
//						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
//					}
//
//				}        // door sa pahla ha piece magar apna colour ki domain maha
//				else if ((P->get_Index() >= 11 && P->get_Index() < 16))
//				{
//					
//					if (P->get_Index() + dice_val > 16)
//					{
//						difference = 16 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
//						P->get_Index() = -14; // one value from the dice is used
//						P->get_Index() += (dice_val - (difference + 1));
//						P->in_mid_row = true;
//						if (P->get_Index() == -10)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//
//				}
//				cout << "Ludo.cpp: Line 875 return true hit\n";
//				return true;  // dobara sa dice_val or piece select karo
//			}  // 3 For BLue Piece 
//			else if (P->getCh_clr() == 'B' && (P->get_Index()>=22 && P->get_Index() <= 27))
//			{
//				// AGr piece ha hi door pa to ya chala ga
//				if (P->get_Index() == 27)
//				{    // agr dice ki value 6 sa smaller ha
//					if (dice_val < 6)
//					{
//						P->get_Index() = -24;   // 4
//						P->get_Index() += (dice_val - 1);
//						P->in_mid_row = true;
//						if (P->get_Index() == -20)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//					else
//					{
//						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
//					}
//
//				}        // door sa pahla ha piece magar apna colour ki domain maha
//				else if ((P->get_Index() >= 22 && P->get_Index() < 27))
//				{
//
//					if (P->get_Index() + dice_val > 27)
//					{
//						difference = 27 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
//						P->get_Index() = -24; // one value from the dice is used
//						P->get_Index() += (dice_val - (difference + 1));
//						P->in_mid_row = true;
//						if (P->get_Index() == -20)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//
//				}
//				cout << "Ludo.cpp: Line 917 return true hit\n";
//				return true;  // dobara sa dice_val or piece select karo
//			}  // 4  For purple pieces
//			else if (P->getCh_clr() == 'p' && (P->get_Index() >= 38 && P->get_Index() <= 43))
//			{
//				// AGr piece ha hi door pa to ya chala ga
//				if (P->get_Index() == 43)
//				{    // agr dice ki value 6 sa smaller ha
//					if (dice_val < 6)
//					{
//						P->get_Index() = -34;   // 4
//						P->get_Index() += (dice_val - 1);
//						P->in_mid_row = true;
//						if (P->get_Index() == -30)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//					else
//					{
//						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
//					}
//
//				}        // door sa pahla ha piece magar apna colour ki domain maha
//				else if ((P->get_Index() >= 38 && P->get_Index() < 43))
//				{
//
//					if (P->get_Index() + dice_val > 43)
//					{
//						difference = 43 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
//						P->get_Index() = -34;       // one value from the dice is used
//						P->get_Index() += (dice_val - (difference + 1));
//						P->in_mid_row = true;
//						if (P->get_Index() == -30)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//
//				}
//				cout << "Ludo.cpp: Line 959 return true hit\n";
//				return true;  // dobara sa dice_val or piece select karo
//			}   // 5 For yellow pieces
//			else if (P->getCh_clr() == 'y' && (P->get_Index() >= 49 && P->get_Index() <= 54))
//			{
//				// AGr piece ha hi door pa to ya chala ga
//				if (P->get_Index() == 54)
//				{    // agr dice ki value 6 sa smaller ha
//					if (dice_val < 6)
//					{
//						P->get_Index() = -44;   // 4
//						P->get_Index() += (dice_val - 1);
//						P->in_mid_row = true;
//						if (P->get_Index() == -40)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//					else
//					{
//						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
//					}
//
//				}        // door sa pahla ha piece magar apna colour ki domain maha
//				else if ((P->get_Index() >= 49 && P->get_Index() < 54))
//				{
//
//					if (P->get_Index() + dice_val > 54)
//					{
//						difference = 54 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
//						P->get_Index() = -44; // one value from the dice is used
//						P->get_Index() += (dice_val - (difference + 1));
//						P->in_mid_row = true;
//						if (P->get_Index() == -40)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//
//				}
//				cout << "Ludo.cpp: Line 1001 return true hit\n";
//				return true;  // dobara sa dice_val or piece select karo
//			}       // 6   for green 
//			else if (P->getCh_clr() == 'g' && (P->get_Index() >= 60 && P->get_Index() <= 65))
//			{
//				// AGr piece ha hi door pa to ya chala ga
//				if (P->get_Index() == 65)
//				{    // agr dice ki value 6 sa smaller ha
//					if (dice_val < 6)
//					{
//						P->get_Index() = -54;   // 4
//						P->get_Index() += (dice_val - 1);
//						P->in_mid_row = true;
//						if (P->get_Index() == -50)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//					else
//					{
//						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
//					}
//
//				}        // door sa pahla ha piece magar apna colour ki domain ma ha
//				else if ((P->get_Index() >= 60 && P->get_Index() < 65))
//				{
//
//					if (P->get_Index() + dice_val > 65)
//					{
//						difference = 65 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
//						P->get_Index() = -54; // one value from the dice is used
//						P->get_Index() += (dice_val - (difference + 1));
//						P->in_mid_row = true;
//						if (P->get_Index() == -50)
//						{  // is ka matlab ha ka piece jeet gia ha
//							P->is_Win = true;
//						}
//						return false;
//					}
//
//				}
//				cout << "Ludo.cpp: Line 1043 return true hit\n";
//				return true;  // dobara sa dice_val or piece select karo
//			}
//        }
//		
//		// ya phir 2nd if sa ya pata chala ga ka agr piece already middle row ma ha to bhi ya function deal nhi kara ga
//	} 
//	decoy = 1;
//	return false;  // plyer na kill hi nhi kia too ya wla function isa handle nhi kara ga koi aga wla function handle kara ga
//}    // ya piece apni domain ma nhi ha abhi
bool Ludo::inHouse_move_checker(Player& Plr, Piece* P, const int& dice_val, int& decoy)
{

	//if(P->getCh_clr() == 'b' && (P->get_Index()+ dice_val>=2);

	int difference = 0;
	if (Plr.has_killed == true)
	{      // Agr piece abhi mid row ma nhi gia
		if (P->in_mid_row == false)
		{    // 1 For Light blue pieces 
			if (P->getCh_clr() == 'b' && (P->get_Index() == 76 || (P->get_Index() >= 1 && P->get_Index() <= 5)))
			{    // AGr piece ha hi door pa to ya chala ga
				if (P->get_Index() == 5)
				{    // agr dice ki value 6 sa smaller ha
					if (dice_val < 6)
					{
						P->get_Index() = -4;   // 4
						P->get_Index() += (dice_val - 1);
						P->in_mid_row = true;
						if (P->get_Index() == 0)
						{
							P->is_Win = true;
						}
						return false;
					}
					else
					{
						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice ki value bari ha remaining boxes ka respective
					}

				}        // door sa pahla ha piece magar apna colour ki domain maha
				else if (P->get_Index() == 76 || (P->get_Index() >= 1 && P->get_Index() < 5))
				{
					int decoy_index;
					if (P->get_Index() == 76) { P->get_Index() = 0; } // just for simplicity in calculation
					if (P->get_Index() + dice_val > 5)
					{
						difference = 5 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
						P->get_Index() = -4; // one value from the dice is used
						P->get_Index() += (dice_val - (difference + 1));
						P->in_mid_row = true;
						if (P->get_Index() == 0)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else  // is ka matlab chosen dice value itni bari nhi ha ka piece mid rows ma chala jai to usa normal move karni chia
					{
						decoy = 2;
						return false;
					}

				}
				cout << "Ludo.cpp: Line 857 return true hit\n";
				return true;  // dobara sa dice_val or piece select karo
			}   // 2 For Red Piece 
			else if (P->getCh_clr() == 'r' && (P->get_Index() >= 11 && P->get_Index() <= 16))
			{
				// AGr piece ha hi door pa to ya chala ga
				if (P->get_Index() == 16)
				{    // agr dice ki value 6 sa smaller ha
					if (dice_val < 6)
					{
						P->get_Index() = -14;   // 4
						P->get_Index() += (dice_val - 1);
						P->in_mid_row = true;
						if (P->get_Index() == -10)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else
					{
						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
					}

				}        // door sa pahla ha piece magar apna colour ki domain maha
				else if ((P->get_Index() >= 11 && P->get_Index() < 16))
				{

					if (P->get_Index() + dice_val > 16)
					{
						difference = 16 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
						P->get_Index() = -14; // one value from the dice is used
						P->get_Index() += (dice_val - (difference + 1));
						P->in_mid_row = true;
						if (P->get_Index() == -10)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else  // is ka matlab chosen dice value itni bari nhi ha ka dice mid rows ma chala jai to usa normal move karni chia
					{
						decoy = 2;
						return false;
					}

				}
				cout << "Ludo.cpp: Line 899 return true hit\n";
				return true;  // dobara sa dice_val or piece select karo
			}  // 3 For BLue Piece 
			else if (P->getCh_clr() == 'B' && (P->get_Index() >= 22 && P->get_Index() <= 27))
			{
				// AGr piece ha hi door pa to ya chala ga
				if (P->get_Index() == 27)
				{    // agr dice ki value 6 sa smaller ha
					if (dice_val < 6)
					{
						P->get_Index() = -24;   // 4
						P->get_Index() += (dice_val - 1);
						P->in_mid_row = true;
						if (P->get_Index() == -20)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else
					{
						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
					}

				}        // door sa pahla ha piece magar apna colour ki domain maha
				else if ((P->get_Index() >= 22 && P->get_Index() < 27))
				{

					if (P->get_Index() + dice_val > 27)
					{
						difference = 27 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
						P->get_Index() = -24; // one value from the dice is used
						P->get_Index() += (dice_val - (difference + 1));
						P->in_mid_row = true;
						if (P->get_Index() == -20)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else  // is ka matlab chosen dice value itni bari nhi ha ka dice mid rows ma chala jai to usa normal move karni chia
					{
						decoy = 2;
						return false;
					}

				}
				cout << "Ludo.cpp: Line 917 return true hit\n";
				return true;  // dobara sa dice_val or piece select karo
			}  // 4  For purple pieces
			else if (P->getCh_clr() == 'p' && (P->get_Index() >= 38 && P->get_Index() <= 43))
			{
				// AGr piece ha hi door pa to ya chala ga
				if (P->get_Index() == 43)
				{    // agr dice ki value 6 sa smaller ha
					if (dice_val < 6)
					{
						P->get_Index() = -34;   // 4
						P->get_Index() += (dice_val - 1);
						P->in_mid_row = true;
						if (P->get_Index() == -30)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else
					{
						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
					}

				}        // door sa pahla ha piece magar apna colour ki domain maha
				else if ((P->get_Index() >= 38 && P->get_Index() < 43))
				{

					if (P->get_Index() + dice_val > 43)
					{
						difference = 43 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
						P->get_Index() = -34;       // one value from the dice is used
						P->get_Index() += (dice_val - (difference + 1));
						P->in_mid_row = true;
						if (P->get_Index() == -30)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else  // is ka matlab chosen dice value itni bari nhi ha ka dice mid rows ma chala jai to usa normal move karni chia
					{
						decoy = 2;
						return false;
					}

				}
				cout << "Ludo.cpp: Line 959 return true hit\n";
				return true;  // dobara sa dice_val or piece select karo
			}   // 5 For yellow pieces
			else if (P->getCh_clr() == 'y' && (P->get_Index() >= 49 && P->get_Index() <= 54))
			{
				// AGr piece ha hi door pa to ya chala ga
				if (P->get_Index() == 54)
				{    // agr dice ki value 6 sa smaller ha
					if (dice_val < 6)
					{
						P->get_Index() = -44;   // 4
						P->get_Index() += (dice_val - 1);
						P->in_mid_row = true;
						if (P->get_Index() == -40)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else
					{
						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
					}

				}        // door sa pahla ha piece magar apna colour ki domain maha
				else if ((P->get_Index() >= 49 && P->get_Index() < 54))
				{

					if (P->get_Index() + dice_val > 54)
					{
						difference = 54 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
						P->get_Index() = -44; // one value from the dice is used
						P->get_Index() += (dice_val - (difference + 1));
						P->in_mid_row = true;
						if (P->get_Index() == -40)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else  // is ka matlab chosen dice value itni bari nhi ha ka dice mid rows ma chala jai to usa normal move karni chia
					{
						decoy = 2;
						return false;
					}

				}
				cout << "Ludo.cpp: Line 1001 return true hit\n";
				return true;  // dobara sa dice_val or piece select karo
			}       // 6   for green 
			else if (P->getCh_clr() == 'g' && (P->get_Index() >= 60 && P->get_Index() <= 65))
			{
				// AGr piece ha hi door pa to ya chala ga
				if (P->get_Index() == 65)
				{    // agr dice ki value 6 sa smaller ha
					if (dice_val < 6)
					{
						P->get_Index() = -54;   // 4
						P->get_Index() += (dice_val - 1);
						P->in_mid_row = true;
						if (P->get_Index() == -50)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else
					{
						return true; // is ka matlab ha ka piece door par ha or ghar ja bhi sakta ha mgr dice sahi select nhi kia
					}

				}        // door sa pahla ha piece magar apna colour ki domain ma ha
				else if ((P->get_Index() >= 60 && P->get_Index() < 65))
				{

					if (P->get_Index() + dice_val > 65)
					{
						difference = 65 - P->get_Index(); // ya difference hi wo value ha jo piece ko door tak lana ka lia index ma plus karni ho gi or dice val sa minus karni ho gi
						P->get_Index() = -54; // one value from the dice is used
						P->get_Index() += (dice_val - (difference + 1));
						P->in_mid_row = true;
						if (P->get_Index() == -50)
						{  // is ka matlab ha ka piece jeet gia ha
							P->is_Win = true;
						}
						return false;
					}
					else  // is ka matlab chosen dice value itni bari nhi ha ka dice mid rows ma chala jai to usa normal move karni chia
					{
						decoy = 2;
						return false;
					}

				}
				cout << "Ludo.cpp: Line 1043 return true hit\n";
				return true;  // dobara sa dice_val or piece select karo
			}
		}

		// ya phir 2nd if sa ya pata chala ga ka agr piece already middle row ma ha to bhi ya function deal nhi kara ga
	}

	decoy = 1;

	return false;  // plyer na kill hi nhi kia too ya wla function isa handle nhi kara ga koi aga wla function handle kara ga
}    // ya piece apni domain ma nhi ha abhi
//______________________________


bool Ludo::OnlyOneLeft()
{
	int count = 0;
	for (int i = 0; i < this->NO_player; i++)
	{
		int count99 = 0;
		for (int j = 0; j< 4; j++)
		{
			if (this->Plr[i]->Ps[j].is_Win)
				count99++;
		}
		if (count99 == 4)
			count++;
	}
	if (count == NO_player - 1)
		return 1;
	return false;
}

bool is_inside_check(Piece*P)
{
	if (P->get_Index() < 0 && P->get_Index()>-90)
		return true;
	return false;
}
bool is_dice_value_valid(Piece*P, const int& dice_val)
{
	int diff = 0;
	if (P->getCh_clr() == 'b')
	{
		diff = abs(P->get_Index());  // because the dubtraction from 0 is same as the given value
	}
	else if (P->getCh_clr() == 'r')
	{
		diff = abs(P->get_Index()) - (10);
	}
	else if (P->getCh_clr() == 'B')
	{
		diff = abs(P->get_Index()) - (20);
	}
	else if (P->getCh_clr() == 'p')
	{
		diff = abs(P->get_Index()) - (30);
	}
	else if (P->getCh_clr() == 'y')
	{
		diff = abs(P->get_Index()) - (40);
	}
	else if (P->getCh_clr() == 'g')
	{
		diff = abs(P->get_Index()) - (50);
	}
	//__________
	if (diff<dice_val)
	{
		return false; // dice ka number bara ha or remaining boxes com hain goti ka pugna ka lia
	}
	else
	{
		return true;  // you can proceed with the movement 
	}
}

bool Ludo::jota_piece_checker(Piece* P, const int& dst_index)
{
	int count = 0;
	if (P->get_Index() > 0)
	{          // checking the indexes b/w the piece's current index and its destination index
		int destination = P->get_Index() + dst_index - 1;
		int strt = P->get_Index() + 1;
		if (strt > 76)
		{
			strt -= 76;
		}
		if (destination > 76)
		{
			destination -= 76;
		}
		for (int k = 1; k <= dst_index - 1; k++)  // dice value-1 times chala ga kionka  
		{


			if (strt > 76)
			{
				strt -= 76;
			}
			// Traversing into players array (Plr)
			for (int i = 0; i < NO_player; i++)
			{   // Traversing into pieces array
				for (int j = 0; j < 4; j++)
				{
					cout << this->Plr[i]->Ps[j].get_Index() << endl; // if a piece has the same index as the indexes we are searching in b/w
					if (this->Plr[i]->Ps[j].get_Index() == strt)
					{       // piece usi player ka nahi hona chia
						if (this->Plr[turn - 1]->ch_clr != this->Plr[i]->ch_clr)
						{
							count++;
						}
						if (count > 1)
						{   // agr ak hi index pa 2 sa ziada pieces mila han to is ka matlab wo jota ha 

							//  +++++++++++++++++   (Text: Jota ho gia ha )   ++++++++++++++++++
							return true;
						}
					}
				}
			}
			if (strt == destination)
			{
				break;
			}
			strt++;
			// Agr ak hi index par 2 sa ziada nhi mila to count 0 kar do
					// Because aga ksi index pa bhi koi piece para ho sakta ha mgr wo as a jota count nhi ho ga is lia index change hona par 
			count = 0;
		}
	}
	// koi jota nhi mila || ya phir jo piece select hoa us ka index 0 sa chota ha
	return false;
}
// checking the position if there is a jota then we have to put pieces with precaution
bool Ludo::jota_mover_valid(Piece* P, const int& dst_index)
{
	int count = 0;
	int dest = P->get_Index() + dst_index;
	if (dest > 76)
	{
		dest -= 76;
	}
	if (P->get_Index() > 0)
	{
		// Traversing into players array (Plr)
		for (int i = 0; i < NO_player; i++)
		{   // Traversing into pieces array
			for (int j = 0; j < 4; j++)
			{         // if a piece has the same index as the indexes we are searching in b/w
				if (this->Plr[i]->Ps[j].get_Index() == dest)
				{
					if (this->Plr[turn - 1]->ch_clr != this->Plr[i]->ch_clr)
					{
						count++;
					}
					if (count > 1)
					{   // agr ak hi index pa 2 sa ziada pieces mila han to is ka matlab wo jota ha 
						return true;
					}
				}
			}
		}
		// Agr ak hi index par 2 sa ziada nhi mila to count 0 kar do
				// Because aga ksi index pa bhi koi piece para ho sakta ha mgr wo as a jota count nhi ho ga is lia index change hona par 
		count = 0;

	}
	// koi jota nhi mila || ya phir jo piece select hoa us ka index 0 sa chota ha
	return false;
}

bool Ludo::jota_mover(Piece* P, const int& dst_index, const int& remove_index, vector<int>& dice_moves, int& decoy_num)
{
	int other_count = 0, self_count = 0;

	if (jota_mover_valid(P, dst_index))
	{
		vector<int> Player_index;
		vector<int> Piece_index;
		P->move_piece(dst_index, dice_moves, remove_index);
		decoy_num = 5;
		// 1 stly checking the count of pieces of player[turn -1] at that index
		for (int i = 0; i < NO_player; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << this->Plr[i]->Ps[j].get_Index() << endl;
				if (this->Plr[i]->Ps[j].get_Index() == P->get_Index())
				{
					if (this->Plr[i]->Ps[j].getCh_clr() == P->getCh_clr())
					{
						self_count++;
					}
					else if (this->Plr[i]->Ps[j].getCh_clr() != P->getCh_clr())
					{
						Player_index.push_back(i);
						Piece_index.push_back(j);
						other_count++;
					}
				}

			}
		}
		if (self_count >= other_count)
		{
			this->Plr[turn - 1]->has_killed = true;
			for (int i = 0; i < Piece_index.size(); i++)
			{
				if (this->Plr[Player_index[i]]->Ps[Piece_index[i]].getCh_clr() == 'b')
				{
					this->Plr[Player_index[i]]->Ps[Piece_index[i]].set_index(-100);
				}
				else if (this->Plr[Player_index[i]]->Ps[Piece_index[i]].getCh_clr() == 'r')
				{
					this->Plr[Player_index[i]]->Ps[Piece_index[i]].set_index(-200);
				}
				else if (this->Plr[Player_index[i]]->Ps[Piece_index[i]].getCh_clr() == 'B')
				{
					this->Plr[Player_index[i]]->Ps[Piece_index[i]].set_index(-300);
				}
				else if (this->Plr[Player_index[i]]->Ps[Piece_index[i]].getCh_clr() == 'p')
				{
					this->Plr[Player_index[i]]->Ps[Piece_index[i]].set_index(-400);
				}
				else if (this->Plr[Player_index[i]]->Ps[Piece_index[i]].getCh_clr() == 'y')
				{
					this->Plr[Player_index[i]]->Ps[Piece_index[i]].set_index(-500);
				}
				else if (this->Plr[Player_index[i]]->Ps[Piece_index[i]].getCh_clr() == 'g')
				{
					this->Plr[Player_index[i]]->Ps[Piece_index[i]].set_index(-600);
				}
			}

		}
		return true;
	}
	return false;
}

//void Ludo::play_Ludo(RenderWindow &  window)
//{
//	vector<int>All_vector_dice{ 1,2,3,4,5,6 };//all dice
//	int move_val = 0;// which is going to be implemented as the move value of a piece 
//	bool is_out_house = false;  // check karna ka lia ka piece ghar sa bahir aa gia ha ka nhi
//	int out_index = 0; // if the piece is coming out of house than its destination is
//	//RenderWindow window(VideoMode(1350, 780), "The BOYZ Ludo");
//	Piece* P1 = nullptr;
//	int remove_index = 0; // the value at this index dice_vector which is going to be consumed and then deleted
//	
//	bool first_move_bool = false,move_taken=false;
//	int decoy_num = 0;
//	
//	Music mm,mi;
//	while (!this->OnlyOneLeft()) //Win condition
//	{
//
//		do
//		{
//			{
//				window.clear();
//				this->printAll(window);
//				drawDialoge(window);
//				TurnMsg(window, turn, this->NO_player);
//				CheatP(window);
//				window.display();
//			}
//			 Position O=calculate_mouseP_utility(window);
//			 if (O.cheatPicked()) {
//				 mm.openFromFile("che.ogg");
//				 mm.play();
//				 D.dice_shake_select(window, dice_moves, B, this->Plr, this->NO_player, this->turn);
//			 }
//			 else
//			D.dice_shake_auto(window, dice_moves, B,this->Plr,this->NO_player,this->turn);
//		} while (this->redicer_check(*this->Plr[turn-1]));
//		
//		do
//		{
//			
//			// home condition ka do while yahan laga ga
//			do
//			{
//				window.clear();
//				drawDialoge(window);
//				this->printWithVector(window, dice_moves);
//				TurnMsg(window, turn, this->NO_player);
//				window.display();
//				move_val=select_num_of_Dice_number_utility(window, dice_moves, remove_index); 
//				mi.openFromFile("chi.ogg");
//				mi.play();
//
//				do
//				{
//					P1 = Piece_picker(window, turn, move_val, is_out_house);
//				} while (!is_Piece_pick_valid(P1));
//				
//				Music music; music.openFromFile("move.ogg"); music.play();
//				if (inHouse_move_checker(*this->Plr[turn - 1], P1, move_val, decoy_num))
//				{
//					move_taken = false;	
//				}
//				else if (decoy_num == 1)
//				{
//					move_taken = false;
//				}
//				else
//				{
//					move_taken = true;
//				}
//				Sleep(40);
//
//			} while (move_taken);
//		    // its good to go: piece_1st_move ka lia sari valid checking uperho gai ha
//			if (decoy_num)  // jab move_val = false ho ga too ya wla ifs nhi chalanga
//			{
//				if (is_inside_check(P1))  // ya check awain shugal ka lia alahda banaya ha
//				{
//					if (is_dice_value_valid(P1, move_val))
//					{
//						
//						P1->move_piece(move_val, dice_moves, remove_index);
//					}
//
//				}
//				else if (piece_1st_move(P1, move_val, turn, out_index, first_move_bool))
//				{       // Turn is starting from 1 to the number of players
//					P1->move_piece(out_index, dice_moves, remove_index); //  out_index is the destination
//				}   // agr ghr sa bahir ana wali move nhi thi to phir board pa chala ga piece
//				else
//				{            // agr piece board par valid move chal rha ha too of ha
//					if (piece_checker_move(*this->Plr[turn - 1], P1, move_val))
//					{
//
//						P1->move_piece(move_val, dice_moves, remove_index);
//					}
//
//				}
//
//			}
//			decoy_num = 0;
//			//this->printAll(window);
//			//window.display();
//			
//			
//			
//		} while (!dice_moves.empty());
//		
//		turn_change(this->turn, this->NO_player);
//	}
//
//
//	_getch();
//}
///////////////////////////////////////////////////////new\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void Ludo::play_Ludo(RenderWindow& window)
{
	Music mm, mi;
	int move_val = 0; // which is going to be implemented as the move value of a piece 
	bool is_out_house = false;  // check karna ka lia ka piece ghar sa bahir aa gia ha ka nhi
	int out_index = 0; // if the piece is coming out of house than its destination is
	//RenderWindow window(VideoMode(1350, 780), "The BOYZ Ludo");
	Piece* P1 = nullptr;
	int remove_index = 0; // the value at this index dice_vector which is going to be consumed and then deleted
	this->printAll(window);
	bool first_move_bool = false, move_taken = false;
	int decoy_num = 0;
	window.display();
	bool breaker = false; // for breaking the do while loops while piece is moving inside the mid row 
	bool jota_check1 = false;
	while (true) //Win condition
	{

		do
		{
			//display
			{
				window.clear();
				this->printAll(window);
				drawDialoge(window);
				TurnMsg(window, turn, this->NO_player);
				CheatP(window);
				window.display();
			}
			Position O = calculate_mouseP_utility(window);
			if (O.cheatPicked()) {
				mm.openFromFile("che.ogg");
				mm.play();
				D.dice_shake_select(window, dice_moves, B, this->Plr, this->NO_player, this->turn);
			}
			else
				D.dice_shake_auto(window, dice_moves, B, this->Plr, this->NO_player, this->turn);
		} while (this->redicer_check(*this->Plr[turn - 1]));

		/*do
		{
			D.dice_shake(window, dice_moves, B);

		} while (this->redicer_check(*this->Plr[turn - 1]));*/
		do
		{
			do
			{
				window.clear();
				drawDialoge(window);
				this->printWithVector(window, dice_moves);
				TurnMsg(window, turn, this->NO_player);
				window.display();
				///////////////////////////
				if (move_taken && decoy_num != 3)
				{
					if (decoy_num != 5)
					{
						dice_moves.erase(dice_moves.begin() + remove_index);
					}

					/*this->printAll(window);
					window.display();*/
				}
				move_taken = false;
				if (dice_moves.empty())
				{
					breaker = true;
					break;
				}			
				do
				{
					//  -- Changes here 
					jota_check1 = false;
					move_val = select_num_of_Dice_number_utility(window, dice_moves, remove_index);
					mi.openFromFile("chi.ogg"); mi.play();
					Sleep(60);
					//move_val = dice_value_picker(window, dice_moves, remove_index);
					do
					{
						P1 = Piece_picker(window, turn, move_val, is_out_house);
					} while (!is_Piece_pick_valid(P1));///////////////////////masla
					Music music; music.openFromFile("move.ogg"); music.play();

					if (jota_piece_checker(P1, move_val))   // is function ma print ho ga jhota ka text
					{
						if (dice_moves[0] != 6 && dice_moves.size() == 1)
						{
							dice_moves.erase(dice_moves.begin());
							do
							{
								D.dice_shake(window, dice_moves, B,this->NO_player);

							} while (this->redicer_check(*this->Plr[turn - 1]));
						}
						else
						{
							dice_moves.erase(dice_moves.begin() + remove_index);
						}
						jota_check1 = true;
					}
					
					Sleep(100);
				} while (jota_check1);
				if (jota_mover(P1, move_val, remove_index, dice_moves, decoy_num))  //     
				{
					move_taken = true;
				}
 				else if (inHouse_move_checker(*this->Plr[turn - 1], P1, move_val, decoy_num))
				{
					move_taken = true; // move take nhi hoi magar dobara select karna ha piece or dice
					decoy_num = 3;
				}
				else if (decoy_num == 2)
				{
					break;
				}
				else if (decoy_num == 1)
				{
					move_taken = false;
				}
				else
				{
					move_taken = true;
				}

			} while (move_taken);
			if (breaker)
			{
				breaker = false;
				break;
			}
			// its good to go: piece_1st_move ka lia sari valid checking uperho gai ha
			if (decoy_num)  // jab move_val = false ho ga too ya wla ifs nhi chalanga
			{
				/////////////////////////////////////////////////////////////////////////////

				if (is_inside_check(P1))  // ya check awain shugal ka lia alahda banaya ha
				{
					if (is_dice_value_valid(P1, move_val))
					{
						P1->move_piece(move_val, dice_moves, remove_index);

						//display all
						window.clear();
						drawDialoge(window);
						this->printWithVector(window, dice_moves);
						TurnMsg(window, turn, this->NO_player);
						window.display();
						///////////////
					}
					
					/*else 
					{
						int count__n = 0;
						for (int t= 0; t < 4; t++)
						{
							if (P1->get_Index() != Plr[0]->Ps[t].get_Index())
							{
								if(Plr[0]->Ps[t].get_Index()>-1 && Plr[0]->Ps[t].get_Index()<=76)
								count__n++;
							}
						}
						if (count__n == 3)
							dice_moves.erase(dice_moves.begin(), dice_moves.end());
					}*/
				}
				/////////////////////////////////////////////////////////////////////////////

				else if (piece_1st_move(P1, move_val, turn, out_index, first_move_bool))
				{       // Turn is starting from 1 to the number of players
					P1->move_piece(out_index, dice_moves, remove_index); //  out_index is the destination
				}   // agr ghr sa bahir ana wali move nhi thi to phir board pa chala ga piece
				else if (decoy_num != 5)
				{            // agr piece board par valid move chal rha ha too of ha
					if (piece_checker_move(*this->Plr[turn - 1], P1, move_val))
					{

						P1->move_piece(move_val, dice_moves, remove_index);
					}

				}

			}
			decoy_num = 0;
			this->printAll(window);
			window.display();
		} while (!dice_moves.empty());
		turn_change(this->turn, this->NO_player);
	}


	_getch();
}