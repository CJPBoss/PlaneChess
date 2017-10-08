# include<iostream>
# include<vector>
# include<stdio.h>
# include<conio.h>
# include<ctime>
# include<windows.h>
# include"GameController.h"
# include"Map.h"
# include"Node.h"
# include"Stack.h"
# include"something.h"
# include"Chess.h"
# include"Airport.h"
# include"Place.h"
# include"Player.h"

using namespace std;

GameController::GameController()
{
    srand((unsigned)time(NULL));
    gaming = 0;
    first = 0;
}

void GameController::Init()
{
    randStep = 0;
	PlaneMap = new Map;
    printf("Game is init -ing\n");
   // printf("airport set \n");
	int i;
	for (i = 0; i < 4; i++)
	{
        printf("Player %d is Human?(0-no, other-yes)");
        int fHuman;
        cin >> fHuman;
        if (fHuman)
        {
            player[i] = new Player(1, i);
        }
        else
        {
            player[i] = new Player(0, i);
        }
	    player[i]->planeMap = PlaneMap;
	    player[i]->gc = this;
	    airport[i] = new Airport(i);
	    //printf("airport[%d] is ready\n", i);
		airport[i]->start = PlaneMap->Start[i];
		airport[i]->planeMap = PlaneMap;
        PlaneMap->airport[i] = airport[i];
	}
    printf("Game ready\n");
    gaming = 1;
}

int *GameController::showFour(int id, int *a)
{
    for (int i = 0; i < 4; i++)
    {
        a[i] = showPlane(id, i);
    }
    return a;
}

int GameController::isFinish()
{
    vector<int> t = showWinner();
    int s = 0;
    for (int i = 0; i < 4; i++)
    {
        s += t[i];
    }
    if (s >= 3)
    {
        return 1;
    }
    return 0;
}

void GameController::showInfo(int nowPlayer, int allplaneinfo[16])
{
    vector<int> temp = showAllPlane();
    for (int i = 0; i < 16; i++)
    {
        allplaneinfo[i] = temp[i];
    }
    if (!player[nowPlayer]->human)
    {
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == nowPlayer)
            {
                printf("< %d > ", temp[i * 4 + j]);
            }
            else
            {
                printf("[ %d ] ", temp[i * 4 + j]);
            }
        }
        printf("\n");
    }
}

void GameController::Start()
{
    if (gaming == 0)
    {
        Init();
    }
    int winnerlist[4];
    for (int i = 0; i < 4; i++)
    {
        winnerlist[i] = -1;
    }
    int wl = 1;
    printf("start!!!\n");
    int nowPlayer = first;
    int allplaneinfo[16];
    int st = 0;
    printf("===============================================\n");
    while (!isFinish())
    {
        //int tFlag = -1;
        printf("\tNow ");
        outColor(nowPlayer);
        printf(" : \n");
        randStep = 0;
        randStep = getRandomInt_6();
        printf("get %d\n", randStep);
        //getch();

        if (!movable(nowPlayer, randStep))
        {
            nowPlayer = right_4(nowPlayer + 1);
            continue;
        }
        int wFlag = 1;
        while (wFlag)
        {
            showInfo(nowPlayer, allplaneinfo);
            int cmd = player[nowPlayer]->getCMD(randStep, allplaneinfo, st++);
            printf("rCMD : %d\n", cmd);
            int n = cmd;
            int planeID = n % 10;
            //int planeID = tFlag < 0 ? n % 10 : tFlag;
            //tFlag = -1;
            n /= 10;
            //int portID = n % 10;
            //n /= 10;
            int CMD = n;

            if (n == 0)
            {
                wFlag = 0;
            }
            else if (n == 1)
            {
                cout << "MOVING!!" << endl;
                wFlag = moveCMD(nowPlayer, planeID, randStep);
            }
            else if (n == 2)
            {
                cout << "TAKING OFF!!" << endl;
                wFlag = takeOffCMD(nowPlayer, planeID);
            }
            /*
            if (wFlag < 0)
            {
                wFlag = 0;
                tFlag = planeID;
            }
            */
        }

        if (airport[nowPlayer]->isWin())
        {
            winnerlist[nowPlayer] = wl;
            printf(">>>>>>>>>> winner %d <%d>\n", wl++, nowPlayer);
            //getch();
        }

        if (randStep != 6)
        {
            nowPlayer = right_4(nowPlayer + 1);
            printf("==============================================================================================\n");
        }

    }

    printf("Winner list is :\n");
    for (int i = 1; i < 4; i++)
    {
        printf("<%d> : ", i);
        for (int j = 0; j < 4; j++)
        {
            if (winnerlist[j] == i)
            {
                outColor(j);
                if (player[j]->human)
                {
                    printf(" player : Human %d", j);
                }
                else
                {
                    printf(" player : %s", player[j]->AIname);
                }
            }
        }
        printf("\n");
    }
    printf("<4> : ");
    for (int i = 0; i < 4; i++)
    {
        if (winnerlist[i] == -1)
        {
            outColor(i);
            if (player[i]->human)
            {
                printf(" player : Human %d", i);
            }
            else
            {
                printf(" player : %s", player[i]->AIname);
            }
        }

    }
    printf("\n");
    gaming = 0;
}

int GameController::movable(int index, int num)
{
    int flag = 0;
    int temp[4];
    showFour(index, temp);
    for (int i = 0; i < 4; i++)
    {
        //printf("(%d) -", temp[i]);
        if (temp[i] >= -1)
        {
            return 1;
        }
        if (temp[i] == -2)
        {
            flag = 1;
        }
    }
    if (num == 6&& flag == 1)
    {
        return 1;
    }
    return 0;
}

int GameController::showPlane(int portID, int planeID)
{
    portID = right_4(portID);
    planeID = right_4(planeID);
    Airport *ap = airport[portID];
	Chess *plane = getPlane(portID, planeID);
	int id = plane->getStatus();
	return id;
}

vector<int> GameController::showAllPlane()
{
	vector<int> planeInfo;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			planeInfo.push_back(showPlane(i, j));
		}
	}
	return planeInfo;
}

int GameController::getRandomInt_6()
{
    return randStep == 0 ? (rand() % 6) + 1 : randStep;
}

int showPlane();

Chess *GameController::getPlane(int portID, int planeID)
{
    portID = right_4(portID);
    planeID = right_4(planeID);
    return airport[portID]->chess[planeID];
}

int GameController::moveCMD(int portID, int planeID, int step)
{
	Chess *plane = getPlane(portID, planeID);
	int result = -1;
	while (result == -1)
    {
        result = plane->moveTo(step);
        step = (rand() % 6) + 1;
        if (result == -1)
        {
            printf("another step : %d\n", step);
        }
    }
    randStep = step;

	return result;
}

int GameController::takeOffCMD(int portID, int planeID)
{
    if (randStep != 6)
    {
        printf("[+]\tCan not take off when not 6 \n");
        return 1;
    }
    Chess *plane = getPlane(portID, planeID);
    return plane->takeOff();
}

vector<int> GameController::showWinner()
{
    vector<int> winner;
    for (int i = 0; i < 4; i++)
    {
        winner.push_back(airport[i]->isWin());
    }
    return winner;
}

void MENU()
{
    cout << "< 0>:\tget random number from 1 to 6" << endl;
    cout << "< 1>:\tmove the plane (require use the <0> first everytime)" << endl;
    cout << "< 2>:\take off" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
}

void GameController::test()
{
    for (int i = 0; i < 4; i++)
    {
        airport[i]->planeStandBy(4);
    }
/*
    for (int i = 0; i < 4; i++)
    {
        if (PlaneMap->Start[i] == airport[i]->start)
        {
            printf("yes\n");
        }
        printf("???%d\n", PlaneMap->findIndex(airport[i]->start->next));
    }
*/
    int cmdID;
    cout << ">>> ";
    cin >> cmdID;
    while (cmdID != -1)
    {
        switch (cmdID)
        {
            case 0 :    randStep = getRandomInt_6();
                        printf("[+]\tRandom Step : %d\n", randStep);
                        break;
            case 1 :    moveC();       break;
            case 2 :    takeoffC();    break;
            case 3 :    showOne();     break;
            case 4 :    showAll();     break;
            case 5 :    showWin();     break;
            case -100 : superMoveC();  break;
            //default :
        }
        cout << ">>> ";
        cin >> cmdID;
    }

	printf("Done");
}

//private

int GameController::moveC()
{
    if (randStep == 0)
    {
        printf("[-]\tDidn't get the random step !\n");
        return 1;
    }
    cout << "<?> input portID, planeID\n>>>";
    int portID, planeID, s;
    s = randStep;
    randStep = 0;
    cin >> portID >> planeID;
    return moveCMD(portID, planeID, s);
}

int GameController::superMoveC()
{
    cout << "<?> input portID, planeID, step\n>>>";
    int portID, planeID, step;
    cin >> portID >> planeID >> step;
    return moveCMD(portID, planeID, step);
}

int GameController::takeoffC()
{
    int portID, planeID;
    cout << "<?> input portID, planeID\n>>>";
    cin >> portID >> planeID;
    return takeOffCMD(portID, planeID);
}

int GameController::showOne()
{
    int portID, planeID;
    cout << "<?> input portID, planeID\n>>>";
    cin >> portID >> planeID;
    int a = showPlane(portID, planeID);
    printf("[+]\tPlane<%d,%d>-location[%d]\n", portID, planeID, a);
    return a;
}

vector<int> GameController::showAll()
{
    vector<int> temp = showAllPlane();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("[+]\tPlane<%d,%d>-location[%d]\n", i, j, temp[i * 4 + j]);
        }
    }
    return temp;
}

vector<int> GameController::showWin()
{
    vector<int> winner = showWinner();
    for (int i = 0; i < 4; i++)
    {
        outColor(i);
        cout << " : " <<winner[i] << endl;
    }
    return winner;
}
