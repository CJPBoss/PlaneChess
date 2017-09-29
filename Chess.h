# ifndef _CHESS_H_
# define _CHESS_H_

# include"Node.h"
# include"Place.h"
# include"something.h"
class Airport;
class Place;

class Chess
{
public :
	Chess(){color = red; index = 0;}
	Chess(Color col, int num);
	Color getColor();
	int getDirection();
	void turnDirection();
	Color getEffect();
	Node<Place> *getPosition();
	void setPosition(Node<Place> *);
	void setIndex(int);
	void isKilled();
	int isFlying();
	int moveTo(int );
	void onFlying(Airport *);
	int moveTo(Node<Place> *);
//private :
    int flying;
	Node<Place> *position;
	int index;
	int direction;
	Color color;
};
# endif
