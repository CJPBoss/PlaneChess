# ifndef _AIRPORT_H_
# define _AIRPORT_H_
# include"Stack.h"
class Airport
{
public :
	Airport(Color );
	Color getColor();
	Chess *getChess(int );
	Color getEffect();
	void planeStandBy(int );
    void toEnd(Chess *);
    Stack<Chess> *End;
	Node<Place> *start;
	Color color;
	Chess *chess[4];
	Stack<Chess> *Port;
};

# endif // _AIRPORT_H_
