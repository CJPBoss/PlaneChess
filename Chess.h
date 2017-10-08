# ifndef _CHESS_H_
# define _CHESS_H_

typedef int Color;
class Airport;
class Place;
class Chess;
class Map;

template <typename T>
class Node;

class Chess
{
public :
	Chess();
	Chess(Color col, int num);
	Color getColor();
	int getDirection();                 //1 is positive, 0 is negative
	void turnDirection();
	Color getEffect();
	Node<Place> *getPosition();
	void setPosition(Node<Place> *);
	void setIndex(int);
	int takeOff();
	int beKilled();                    //plane being killed
	int isFlying();                     //is the plane flying?
	void onFlying(Airport *);           //get ready
	int moveTo(int );                   //move by count
	int moveTo(Node<Place> *);          //move by pointer
	int superFly();
	int isWin();
	int jump();
	void outInfo();
	int getStatus();
//private :
    int win;
    int flying;                         //stand for flying or not
    Map **planeMap;                      //point to map
    Airport *airport;                   //point to airport
	Node<Place> *position;              //pointer to the map
	int index;                          //index of plane in airport
	int direction;
	Color color;
};
# endif
