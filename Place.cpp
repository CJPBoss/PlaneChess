# include<iostream>
# include"something.h"
# include"Place.h"
# include"Chess.h"
# include"Node.h"

Place::Place()
{
    color = red;
    cheStack = new Stack<Chess>;
}

Place::Place(Color col)
{
	color = col;
	cheStack = new Stack<Chess>;
}

Color Place::getColor()
{
	return color;
}

void Place::earse()
{
    cheStack->earse();
}

void Place::outInfo()
{
    switch (color)
    {
        case red:       std::cout << "   Red ";   break;
        case green:     std::cout << " Green "; break;
        case blue:      std::cout << "  Blue ";  break;
        case yellow:    std::cout << "Yellow "; break;
        default :       std::cout << "None ";
    }
}

Node<Chess> *Place::takeChess(int cnt = 1)
{
    return cheStack->Pop(cnt);
}

Color Place::getEffect()
{
    return getColor();
}
