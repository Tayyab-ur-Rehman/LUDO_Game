#include <iostream>
#include <conio.h>


#include <SFML/Graphics.hpp>
#include"Board.h"
#include"Ludo.h"
#include"Piece.h"

using namespace std;
using namespace sf;

//Position MouseClick(RenderWindow& window) {
//    Position raw{ -1, -1 };
//    sf::Event event;
//    while (raw.x == -1 && raw.y == -1) {
//        while (window.pollEvent(event)) {
//            switch (event.type) {
//            case sf::Event::Closed:
//                window.close();
//                exit(0);
//                break;
//            case sf::Event::MouseButtonReleased:
//                if (event.mouseButton.button == sf::Mouse::Left) {
//                    raw.y = event.mouseButton.y;
//                    raw.x = event.mouseButton.x;
//                    return raw;
//                }
//                break;
//            default:
//                break;
//            }
//        }
//    }
//    return raw;
//}


int main()
{
	srand(time(0));
  RenderWindow window(VideoMode(1350, 780), "									               The BOYZ Ludo                                   ");
  Vector2i A; A.x = 0; A.y = 0;
  window.setPosition(A);
   Ludo ludo(window);
   ludo.play_Ludo(window);
}


//___________________________
Position mouse_positin_2(sf::RenderWindow& window)
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
Position calculate_mouseP_2(sf::RenderWindow& window)
{
	Position A = mouse_positin_2(window);
	A.x;//= 49.1;
	A.y;//= 50.2;
	cout << "Row " << A.x << " Col " << A.y << endl;
	return A;
}










































































//__________________________-
//
//void dr(RenderWindow &window,const string& image_n,int col,int row)
//{
//	sf::Texture temp;
//	if (!temp.loadFromFile(image_n))  //  img ==> file name for image
//	{
//		throw("Unable to load img");
//	}
//	// scale of board are 0.31
//	sf::Sprite s(temp);
//	s.setScale(.19, .19); //  (width and heigth of image to be printed)
//	//s.setOrigin(col, row);
//	s.setPosition(col, row); // position of image
//	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
//
//
//	
//}
//int main()
//{
//	
//	Board B;
//	RenderWindow window(VideoMode(1350, 780), "The BOYZ Ludo");
//	B.drawBoard(window, "6P board_2.png");
//	
//	
//	dr(window,"dice 1.png",490,293);
//	window.display();
//	_getch();
//	// mid dice 490,293   indexes : Row=6 col=10
//	// array starting 1185,70
//}
//
//int main()
//{
//	Board B;
//	RenderWindow window(VideoMode(1350, 780), "The BOYZ Ludo");
//	B.drawBoard(window, "6P board_2.png");
//	Piece A(red,1); A.get_Index();
//	Position P = A.index_to_xyBoard();
//	A.getCh_clr() = 'p';
//	float increse_r = 23;
//	float increse_c = 12;//, P.x * (49.1)+ increse_r, P.y * (50.2)+ increse_c
//	A.Draw_piece(window); window.display();
//	while (1)
//	{
//		
//
//		A.get_Index() = B.index_provider(window); cout << A.get_Index() << endl;
//		Position P = A.index_to_xyBoard();
//		cout << "COl: " << P.x << " Rom: " << P.y << endl;
//		//
//		calculate_mouseP_2(window);
//		//cout << "R =" << A.x << " C = " << A.y << endl; 
//		/*Position A = B.calculate_mouseP(window);
//		cout << "R =" << A.x << " C = " << A.y << endl;*/
//	}
//}
//
//int main()
//{
//	Board B;
//	RenderWindow window(VideoMode(1300,750), "The BOYZ Ludo");
//	B.drawBoard(window,"6P board_2.png");
//	window.display();
//	_getch();
//}
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}
//______________________________
//void print_shp(RenderWindow& window)
//{
//	float increse_r = 23;
//	float increse_c = 12;
//	CircleShape shape(9.f);
//	shape.setFillColor(Color::Magenta);
//	
//	
//	shape.setPosition(9 * (49.1) + increse_r, 11 * (50.2) + increse_c);  // 1,17 is not working
//	window.draw(shape);
//}
//
//int main()
//{
//	Board B;
//	RenderWindow window(VideoMode(1350, 780), "The BOYZ Ludo");
//	B.drawBoard(window, "6P board_2.png");
//	print_shp(window);
//	window.display();
//}
