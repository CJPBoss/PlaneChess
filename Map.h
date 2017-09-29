# ifndef _MAP_H_
# define _MAP_H_

# include"Node.h"
/*
# include"Place.h"
# include"Chess.h"
*/
//R->G->B->Y
class Map
{
public :
    Node<Place> *Port[4];
    Node<Place> *Head;
    Node<Place> *operator[](int );
    int length();
    int findIndex(Node<Place> *);
    Map();
    void Init();
    void outInfo(Node<Place> *);
    int iStart(Node<Place> *);
    int isDanger(Node<Place> *);
    int isEndLine(Node<Place> *);
private :
    void createEnd(Node<Place> *);
    Node<Place> *DangerEnd[4];
    Node<Place> *EndLine[4];
};


# endif // _MAP_H_
