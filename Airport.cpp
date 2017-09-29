# include<stdio.h>
# include"Airport.h"
# include"Stack.h"
# include"Node.h"
# include"Chess.h"
# include"something.h"
# include"Place.h"

Airport::Airport(Color col = red)
{
	color = col;
	int i;
	//printf("[+] Airport %d setting\n", color);
	Port = new Stack<Chess>;
	End = new Stack<Chess>;
	//printf("[+]\t port is ready\n");
	for (i = 0; i < 4; i++)
	{
		Chess *nChess = new Chess(col, i);
		chess[i] = nChess;
		Port->Push(nChess);
		//printf("[+]\t\t plane<%d>.%d ready\n", color, i);
	}
	//printf("[+]\t all plane<%d> ready\n", color);
	Place *p = new Place(color);
	start = new Node<Place>(p);
	//printf("[+]\t road is ready\n");
	//printf("[+] Airport %d ready\n", color);
}

void Airport::toEnd(Chess *che)
{
    End->Push(che);
}

Color Airport::getColor()
{
	return color;
}

Color Airport::getEffect()
{
	return getColor();
}

Chess *Airport::getChess(int index = 0)
{
	return chess[index];
}

void Airport::planeStandBy(int num = 1)
{
	start->Date->cheStack->Push(Port->Pop(num));
	Node<Chess> *p = start->Date->cheStack->Head->next;
	while (p != NULL)
	{
		p->Date->onFlying(this);
		p = p->next;
	}
}
