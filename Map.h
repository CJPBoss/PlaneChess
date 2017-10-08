# ifndef _MAP_H_
# define _MAP_H_



template<typename T>
class Node;

class Airport;
class Place;
//R->G->B->Y
class Map
{
public :
    Node<Place> *Start[4];               //point to 4 node which different type of plane start to
    Airport *airport[4];
    Node<Place> *Head;                  //point to the whole map's start(Head->next)
    Node<Place> *SuperFly[4][2];        //point to the super fly, 0 is start, 1 is end
    Node<Place> *DangerEnd[4];          //for isDanger
    Map();
    void Init();
    Node<Place> *operator[](int );      //get index from head->next
    int length();                       //map's length
    int findIndex(Node<Place> *);       //find the Index p
    void outInfo(Node<Place> *);        //out put the p's info
    int iStart(Node<Place> *);          //is p one of the plane start place?
    int isDanger(Node<Place> *);        //is p one of the danger place in EndStartPoint?
    int isEndStartPoint(Node<Place> *);       //is p one of the EndStartPoint's start node?
    int isEndLine(Node<Place> *);
    int isEnd(Node<Place> *);
private :
    void createEnd(Node<Place> *);      //like the name
    Node<Place> *End[4];
    Node<Place> *EndStartPoint[4];            //for isEndStartPoint
};


# endif // _MAP_H_
