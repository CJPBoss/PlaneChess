# ifndef _PLACE_H_
# define _PLACE_H_

# include"Node.h"
# include"Stack.h"
# include"Chess.h"
# include"something.h"
# include"string"

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
