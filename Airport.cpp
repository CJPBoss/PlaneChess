# include<stdio.h>
# include"Airport.h"
# include"Stack.h"
# include"Node.h"
# include"something.h"
# include"Chess.h"
# include"Place.h"

Airport::Airport(Color col = RED)
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
		nChess->airport = this;
		nChess->position = NULL;
		nChess->planeMap = &(this->planeMap);
		Port->Push(nChess);
		//printf("[+]\t\t plane<%d>.%d ready\n", color, i);
	}
	//printf("[+]\t all plane<%d> ready\n", color);
	//Place *p = new Place(color);
	//start = new Node<Place>(p);
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

int Airport::isWin()
{
    if (End->length() >= 4)
    {
        return 1;
    }
    return 0;
}

Chess *Airport::getChess(int index = 0)
{
	return chess[index];
}

void Airport::planeStandBy(int num = 1)
{
	Node<Chess> *p = Port->Head->next;
	while (p != NULL&& num--)
	{
	    printf("[+]\t");
		p->Value->takeOff();
		p = p->next;
	}
}
