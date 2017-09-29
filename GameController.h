# ifndef _GAMECONTROLLER_H_
# define _GAMECONTROLLER_H_

class Map;
class Airport;

class GameController
{
public :
	GameController();
    int moveCMD(int, int, int);//color, plane index, step

	//void init();
	void start();
	Map *PlaneMap;
	Airport *airport[4];
    int getRandomInt();
    void mm(int, int, int);
    //Player *player[4];
    //void setPlayer(Player *);
    void test();
};

# endif // _GAMECONTROLLER_H_
