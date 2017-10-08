# include<iostream>
# include"something.h"
# include"Place.h"
# include"Chess.h"
# include"Node.h"
# include"Stack.h"

Place::Place()
{
    color = RED;
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
        case RED:       std::cout << "   Red ";   break;
        case GREEN:     std::cout << " Green "; break;
        case BLUE:      std::cout << "  Blue ";  break;
        case YELLOW:    std::cout << "Yellow "; break;
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
