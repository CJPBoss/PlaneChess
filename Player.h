# ifndef _PLAYER_H_
# define _PLAYER_H_

class Map;
class GameController;

class Player
{
public :
    Map *planeMap;
    GameController *gc;
    char AIaddress[4096];
    char AIname[256];
    Player();
    Player(int hFlag, int id);
    void setAI();
    void setPlayer(int );
    int human;
    int index;
    int getCMD(int randStep, int *, int);
    int sendCMD(char *);
    int getHumanCMD(int randStep);
    int getAICMD(int , int *, int);
};

# endif // _PLAYER_H_
