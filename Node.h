# ifndef _NODE_H_
# define _NODE_H_
# include"stdio.h"
# include"something.h"
//# include"Chess.h"
//# include"Place.h"

/*
class Node can store any type or class
by using the template
And it has 3 pointer, which can act 'T' Link
	1.next pointer links to the next node on the main line
	2.prev pointer links to the previous node ont the main line
	3.brch pointer links to the branch
+----------------------------+
|previous <- position -> next|
|		        |	         |
|		        V	         |
|		        branch	     |
+----------------------------+
*/
template<typename T>
class Node
{
public :
	T *Date;
	Node<T> *next;	//common next Node, on line
	Node<T> *prev;	//common prev Node, on line
	Node<T> *brch;	//To the branch of flight(if T is Place)

	Node<T>()
	{
	    next = NULL;
	    prev = NULL;
	    Date = NULL;
	    brch = NULL;
    }
	Node<T>(T *date)
	{
	    next = NULL;
	    prev = NULL;
	    Date = date;
	    brch = NULL;
    }
	Node<T>(T date)
	{
	    next = NULL;
	    prev = NULL;
	    Date = &date;
	    brch = NULL;
    }
	Node<T>(T &date)
	{
	    next = NULL;
	    prev = NULL;
	    Date = &date;
	    brch = NULL;
    }

	Node<T> *getNext()
	{
		return next;
	}

    template<typename S>
    Node<T> *getNext(S *effect)
    {
        if (next == NULL&& brch == NULL)
        {
            effect->direction = 0;
        }
        if (effect->getDirection() == 0)
        {
            return prev;
        }
        else if (brch != NULL&& effect->getEffect() == Date->getEffect())
        {
            return brch;
        }
        else
        {
            return next;
        }
    }

	Node<T> *getPrev()
	{
		return prev;
	}
};

class Chess;
class Place;
template class Node<Chess>;
template class Node<Place>;

# endif
