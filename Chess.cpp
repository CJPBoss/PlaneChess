# include"Node.h"
# include"Chess.h"
# include"Airport.h"
# include"something.h"
# include"Stack.h"
# include"Place.h"
# include"Map.h"

Chess::Chess() : color(RED), index(0), win(0)
{

}

Chess::Chess(Color col, int num) : color(col), index(num)
{
    win = 0;
	position = NULL;
	direction = 1;
	flying = 0;
}

void Chess::outInfo()
{
    printf("\tPlane[");
    outColor(color);
    printf(", %d]: ", index);
    (*planeMap)->outInfo(position);
}

void Chess::onFlying(Airport *airport)
{
	position = airport->start;
	airport->start->Value->cheStack->Push(this);
	flying = 1;
}

int Chess::moveTo(int step)
{
    int ww = step;
    if (isWin())
    {
        return 1;
    }
    if (!isFlying())
    {
        //can't not fly
        outInfo();
        printf("\t[Didn't take off\]\n");
        return 1;
    }
    int i = 0;
	direction = 1;				        //direction turn to positive
	//Node<Place> *now = position;
	position->Value->cheStack->Pop(this);		//pop this plane from plane's position

	outInfo();
    printf("\n");

    if (!step)
    {
        outInfo();
        printf("\t[Didn't move]\n");
        return 1;
    }
	while (step--)
	{
		//now = now->getNext(this);       //useful
        position = position->getNext(this);
        outInfo();
        printf("\n");
        if (position->Value->cheStack->length() > 1&& ww == 6)
        {
            position->Value->cheStack->Push(this);
            return -1;
        }
	}
	//position = now;
	Stack<Chess> *temp = position->Value->cheStack;
	if (temp->length() != 0)
    {
        if (temp->Head->next->Value->color != color)
        {
            temp->earse();
        }
    }
	position->Value->cheStack->Push(this);
    if (isWin())
    {
        return 0;
    }
	if ((*planeMap)->isEndLine(position))
    {
        printf("in end line\n");
        return 0;
    }
	else if (!superFly())
    {
        jump();
    }
    else if (!jump())
    {
        superFly();
    }
	return 0;
}

int Chess::isWin()
{
    if (win == 1)
    {/*
        if ()
        {
            outInfo();
            printf(" [\"has already get to the end!!\"]\n");
        }*/
        return 1;
    }
    if ((*planeMap)->isEnd(position))
    {
        position->Value->cheStack->Pop(this);
        position = NULL;
        airport->End->Push(this);
        flying = 0;
        win = 1;
        outInfo();
        printf(" [\"REACH TO THE END!!!\"]\n");
        return 1;
    }
    return 0;
}

int Chess::jump()
{
    if (position->Value->color != color)
    {
        return 1;
    }
    if ((*planeMap)->isEndStartPoint(position))
    {
        return 2;
    }
    int id = (*planeMap)->findIndex(position);
    if (id / 100 != 0|| id == -1)
    {
        return 3;
    }
    position->Value->cheStack->Pop(this);
    for (int i = 0; i < 4; i++)
    {
        position = position->next;
    }
    Stack<Chess> *temp = position->Value->cheStack;
	if (temp->length() != 0)
    {
        if (temp->Head->next->Value->color != color)
        {
            temp->earse();
        }
    }
	position->Value->cheStack->Push(this);
	printf("Jump !!\n");
	outInfo();
	printf("\n");
	return 0;
}

int Chess::getStatus()
{
    if ((*planeMap)->iStart(position))
    {
        return -1;
    }
    else if (isWin())
    {
        return -3;
    }
    else if (airport->Port->has(this))
    {
        return -2;
    }
    int id = (*planeMap)->findIndex(position);
    return id;
}

int Chess::superFly()
{
    Node<Place> *sps = (*planeMap)->SuperFly[color][0];
    Node<Place> *spe = (*planeMap)->SuperFly[color][1];
    if (position != sps)
    {
        return 1;
    }
    printf("Super Fly!!\n");
    (*planeMap)->DangerEnd[right_4(color + 2)]->Value->cheStack->earse();
    moveTo(spe);
    return 0;
}

int Chess::moveTo(Node<Place> *pos)
{
    if (isWin())
    {
        outInfo();
        printf(" [\"has already get to the end!!\"]\n");
        return 1;
    }
	Node<Place> *now = getPosition();
	now->Value->cheStack->Pop(this);
	position = pos;
	Stack<Chess> *temp = position->Value->cheStack;
	if (temp->length() != 0)
    {
        if (temp->Head->next->Value->color != color)
        {
            temp->earse();
        }
    }
	pos->Value->cheStack->Push(this);
	outInfo();
	printf("\n");
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

int Chess::takeOff()
{
    if (isFlying())
    {
        printf("Plane<%d,%d> is not in port\n", color, index);
        return 1;
    }
    flying = 1;
    airport->Port->Pop(this);
    airport->start->Value->cheStack->Push(this);
    position = airport->start;
    printf("plane<%d,%d> take off\n", color, index);
    return 0;
}

int Chess::beKilled()
{
    flying = 0;
    position->Value->cheStack->Pop(this);
    airport->Port->Push(this);
    position = NULL;
    direction = 1;
    return 0;
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

