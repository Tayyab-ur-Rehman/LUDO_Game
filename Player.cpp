#include "Player.h"


/*
Position Chess::MouseClick() {
    Position raw{ -1, -1 };
    sf::Event event;
    while (raw.x == -1 && raw.y == -1) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                exit(0);
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    raw.y = event.mouseButton.y;
                    raw.x = event.mouseButton.x;
                    return raw;
                }
                break;
            default:
                break;
            }
        }
    }
    return raw;
}
*/
Player::Player(int col, vector<char> f_players,int turn)
{  // We will later convert 'int col' into char 
    char x;
    switch (col)
    {
    case lBlue:
        x = 'b';
        this->home_index = -100;
        break;
    case blue:
        x = 'B';
        this->home_index = -300;
        break;
    case red:
        x = 'r';
        this->home_index = -200;
        break;
    case yellow:
        x = 'y';
        this->home_index = -500;
        break;
    case lGreen:
        x = 'g';
        this->home_index = -600;
        break;
    case purple:
        x = 'p';
        this->home_index = -400;
        break;
    default:
        break;
    }
    
    this->ch_clr= x;

    if (!f_players.empty())
    {
        this->No_of_friends = f_players.size();
        this->f_players = new char[No_of_friends];
          
        for (int i = 0; i < No_of_friends; i++)
        {
            this->f_players[i] = f_players[i];
        }
    }
    else
    {
        this->f_players = nullptr;
        this->No_of_friends = 0;
        
    }
    this->Ps = new Piece[4]{ {col,1},{col,2} ,{col,3} ,{col,4} };
    this -> turn = turn;
    //this->first_move = true; // agr player ki sari pieces ghar ma han to ya true ho ga otherwise false
    // Constructor complete
}
bool Player::all_pieces_at_home_check()
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (this->Ps[i].get_Index() < -90)
        {
            count++;
        }
    }
    if (count == 4)
    {
        return  true;  // sari ghar ma hi hain
    }
    else
    {
        return false; // nhi hain sari ghar ma
    }
}
bool Player::All_piece_unavaliable()
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (this->Ps[i].get_Index() < -90 || this->Ps[i].getWin_bool())//|| (this->Ps[i].get_Index()%10< -4 && this->Ps[i].get_Index() % 10) > -1)
        {
            count++;
        }
    }
    if (count == 4)
    {
        return  true;  // sari ghar ma hi hain
    }
    else
    {
        return false; // nhi hain sari ghar ma
    }
}
bool Player:: is_friend(const int& x)
{   // This colour character of colour is the
    if (this->f_players != nullptr)
    {
        char c=0;
        if (x == 4)
            c = 'r';
        else if (x == 10)
            c = 'g';
        else if (x == 1)
            c = 'B';
        else if (x == 9)
            c = 'b';
        else if (x == 13)
            c = 'p';
        else if (x == 12)
            c = 'y';
        for (int i = 0; i < this->No_of_friends; i++)
        {
            if (c == this->f_players[i])
            {
                return true;
            }
        }
    }
    return false;

}
void Player::set_friend(vector<char> f_players)
{
    this->No_of_friends = f_players.size();
    this->f_players = new char[No_of_friends];
    for (int i = 0; i < No_of_friends; i++)
    {
        this->f_players[i] = f_players[i];
    }


}
//Piece* get_Pieces()
//{
//
//}

