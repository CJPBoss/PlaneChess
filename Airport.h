# ifndef _AIRPORT_H_
# define _AIRPORT_H_

typedef int Color;
class Chess;
class Place;
class Airport;
class Map;

template<typename T>
class Node;

template<typename T>
class Stack;

class Airport
{
public :
	Airport(Color );
	Color getColor();           //
	Chess *getChess(int );      //get chess by index 0 to 3
	Color getEffect();          //get effect when (getColor) of node's get next
	void planeStandBy(int );    //make i planes from port to start
    void toEnd(Chess *);        //make plane to the stack which is win
    int isWin();

    Map *planeMap;
    Stack<Chess> *End;          //stack of the win plane
	Node<Place> *start;         //start node, which next should point to the start of map
	Color color;
	Chess *chess[4];
	Stack<Chess> *Port;
};

# endif // _AIRPORT_H_
