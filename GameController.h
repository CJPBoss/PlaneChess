# ifndef _GAMECONTROLLER_H_
# define _GAMECONTROLLER_H_
# include<vector>

class Map;
class Airport;
class Chess;
class Player;

class GameController
{
public :
	GameController();
	//CMD
    int moveCMD(int, int, int); //color, plane index, step,
    int takeOffCMD(int, int);
    int showPlane(int, int);
    std::vector<int> showAllPlane();
    std::vector<int> showWinner();

    Chess *getPlane(int, int);

	void Start();               //start a Game
	Map *PlaneMap;              //point to the game map
	Airport *airport[4];        //point to 4 airport
    int getRandomInt_6();         //get random number (building)
    Player *player[4];
    void setPlayer(Player *);
    int *showFour(int, int *);
    void test();                //just for test
    void Init();
private :
    int first;
    int movable(int, int);
    int moveC();
    int gaming;
    int randStep;
    int isFinish();
    int superMoveC();
    int takeoffC();
    int showOne();
    void showInfo(int , int *);
    std::vector<int> showAll();
    std::vector<int> showWin();
};

# endif // _GAMECONTROLLER_H_
