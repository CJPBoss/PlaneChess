# include"Node.h"
# include"Chess.h"
# include"Airport.h"
# include"something.h"
# include"Stack.h"
# include"Place.h"
# include"Map.h"

Chess::Chess(Color col, int num):color(col), index(num)
{
	position = NULL;
	direction = 1;
	flying = 0;
}

int Chess::moveTo(int step)
{
	Node<Place> *now = getPosition();
	now->Date->cheStack->Pop(this);
	while (step--)
	{
		now = now->next;
	}
	position = now;
	position->Date->cheStack->Push(this);
	return 0;
}

void Chess::onFlying(Airport *airport)
{
	position = airport->start;
	flying = 1;
}

int Chess::moveTo(Node<Place> *pos)
{
	Node<Place> *now = getPosition();
	now->Date->cheStack->Pop(this);
	position = pos;
	pos->Date->cheStack->Push(this);
	return 0;
}

Color Chess::getColor()
{
	return color;
}

Color Chess::getEffect()
{
    return getColor();
}

int Chess::isFlying()
{
    return flying;
}

void Chess::setIndex(int idx)
{
    index = idx;
}

int Chess::getDirection()
{
	return direction;
}

void Chess::isKilled()
{
    flying = 0;
    position->Date->cheStack->earse();
    position = NULL;
    direction = 1;
}

Node<Place> *Chess::getPosition()
{
    return position;
}

void Chess::setPosition(Node<Place> *pls)
{
    position = pls;
}

void Chess::turnDirection()
{
	direction = 1 - direction;
}

