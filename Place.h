# ifndef _PLACE_H_
# define _PLACE_H_

typedef int Color;

class Chess;

template<typename T>
class Stack;
template<typename T>
class Node;


class Chess;
class Place
{
public :
	Place(Color col);
	Place();
	Color getColor();
	void earse(Chess *);
    Color getEffect();
    void outInfo();
    Node<Chess> *takeChess(int );
    void earse();
//private :
	Color color;
	Stack<Chess> *cheStack;
};


# endif // _PLACE_H_
