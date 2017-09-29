# include<iostream>
# include<stdio.h>
# include<conio.h>
# include"GameController.h"
# include"Map.h"
# include"Node.h"
# include"Chess.h"
# include"Airport.h"

GameController::GameController()
{
	airport[0] = new Airport(red);
	airport[1] = new Airport(green);
	airport[2] = new Airport(blue);
	airport[3] = new Airport(yellow);
    printf("Game is init -ing\n");
   // printf("airport set \n");
	PlaneMap = new Map;
	int i;
	for (i = 0; i < 4; i++)
	{
	    //printf("airport[%d] is ready\n", i);
		airport[i]->start->next = PlaneMap->Port[i];
	}
    printf("Game ready\n");
}

int GameController::moveCMD(int portID, int planeID, int step)
{
	Chess *plane = airport[portID]->chess[planeID];
	plane->direction = 1;
	//int planeIndex = Map->findIndex(plane->getPosition());
	Node<Place> *position = plane->getPosition();
	position->Date->cheStack->Pop(plane);
    printf("From ");
    PlaneMap->outInfo(position);
    printf("\n");
	while (step--)
	{
		position = position->getNext(plane);
		PlaneMap->outInfo(position);
		printf("\n");
	}

	plane->position = position;
	position->Date->cheStack->Push(plane);
	return 0;
}

void GameController::mm(int a, int b, int c)
{
    printf("\n[+] Plane<%d, %d> step{%d} ", a, b, c);
    moveCMD(a,b,c);
    airport[a]->chess[b]->getPosition()->Date->outInfo();
    int id = PlaneMap->findIndex(airport[a]->chess[b]->getPosition());
    printf(" Plane<%d, %d> now pos [%d]", a, b, id % 100);
    if (id / 100 > 0)
    {
        printf(".[%d]", id / 100);
    }
    printf("\n");
}

void GameController::test()
{
    for (int i = 0; i < 4; i++)
    {
        airport[i]->planeStandBy(4);
    }
    int po = 2;
    int idpl = 3;
    int step = 1;
    std::cout << "Input the <Airport's ID, Plane's ID, step> without ',' \n";
    std::cin >> po >> idpl >> step;
    while (po != -1 && idpl != -1&& step != -1)
    {
        mm(po, idpl, step);
        std::cout << "Input the <Airport's ID, Plane's ID, step> without ',' \n";
        std::cin >> po >> idpl >> step;
    }
    /*
	for (int i = 1; i <= 6; i++)
	{
        printf(">>> <%d>", i);
		mm(po, idpl, i);
		//getch();
	}
    mm(po, idpl, 31);
    mm(po, idpl, 2);
    mm(po, idpl, 2);
    mm(po, idpl, 2);
    mm(po, idpl, 2);
    mm(po, idpl, 4);
    mm(po, idpl, 10);
    mm(po, idpl, 10);
    */
    /*
    mm(0, 0, 31);
    mm(0, 0, 2);
    mm(0, 0, 2);
    mm(0, 0, 2);
    mm(0, 0, 4);
    mm(0, 0, 10);
    mm(0, 0, 10);*/
	printf("Done");
}

