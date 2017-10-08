# include<stdio.h>
# include<iostream>
# include<cstring>
# include<stdlib.h>

using namespace std;

const int diff[4] = {0, 39, 26, 13};
const int startpoint[4] = {0, 13, 26, 39};
int index;
int randStep;
int position[16];
int posi[16];
const int round = 52;

int atMainRoad(int id);
int atEndRoad(int id);
int atStart(int id);
int atRoad(int id);
int movable(int id);
int atPort(int id);
int isWin(int id);

void setToStart()
{
	for (int i = 0; i < 16; i++)
	{
		if (atRoad(i))
		{
			position[i] = (position[i] + diff[index]) % round;
		}
	}
	/*	*/
	int temp[4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", position[i * 4 + j]);
			temp[j] = position[j * 4 + i];
		}
		for (int j = 0; j < 4; j++)
		{
			position[j * 4 + i] = temp[(index + j) % 4];
		}
		printf("\n");
		/*
		int tt = position[index * 4 + i];
		for (int j = 0; j < 4; j++)
		{
			position[((index + j) % 4) * 4 + i] = position[((index + j + 1) % 4) * 4 + i];
		} 
		position[(index + 12) % 4 * 4 + i] = tt;
		*/
	}
}

void predo(char **argv)
{
	FILE *f;
	f = fopen(argv[1], "r");
	
	for (int i = 0; i < 16; i++)
	{
		fscanf(f, "%d", &position[i]);
		posi[i] = position[i];
		//position[i - 1] = atoi(argv[i]);
	}
	fscanf(f, "%d", &index);
	fscanf(f, "%d", &randStep);
	fclose(f);
	setToStart();
}


int value(int k)
{
	switch (k)
	{
		case 1 : return 1;
		case 2 : return 2;
		case 3 : return 3;
	}
} 

int Sum(int a[16])
{
	int s = 0;
	for (int i = 0; i < 16; i++)
	{
		s += a[i];
	}
	return s;
}

int allNotTakeOff()
{
	int flag = 0;
	for (int i = 0; i < 4; i++)
	{
		if (movable(i))
		{
			return 0;
		}
	}
	return 1;
}

int *getDistance(int planeID, int other[12], int flag)
{
	for (int i = 0; i < 12; i++)
	{
		int pos = position[i + 4];
		int plane = position[planeID];
		
		if (flag)//flag为 走了randstep后 
		{
			plane += randStep;
			if (plane > 49)
			{
				plane = 49 + plane % 49;
			}
		}
		if (atStart(planeID))
		{
			other[i] = -1;
			continue;
		}
		if (atEndRoad(i))//目标棋子已到支路 
		{
			other[i] = -1;
			continue;
		}
		
		if (isWin(i))//目标棋子已经到达终点 
		{
			other[i] = -1;
			continue;
		}
		else if (!atRoad(i))//目标棋子还未在地图点上 
		{
			pos = startpoint[i / 4 + 1];
		}
		if (plane < pos)//目标棋子与当前棋子之间隔着起点 
		{
			plane += 52;
		}
		other[i] = plane - pos;

		if (atPort(i))//目标棋子尚未起飞 
		{
			other[i] += 6;
		}
		else if (atStart(i))//目标棋子在起飞点 
		{
			other[i] += 1;
		}
	}
	return other;
}

int getMin(int a[12])// find a smallest, positive number
{
	int min;
	for (int i = 0; i < 12; i++)
	{
		if (a[i] >= 0)
		{
			min = a[i];
			break;
		}
	} 
	for (int i = 0; i < 12; i++)
	{
		if (a[i] < min&& a[i] >= 0)
		{
			min = a[i];
		}
	}
	return min;
}

void getValue(int val[4])
{
	int distance[2][4][12];
	for (int i = 0; i < 3; i++)
	{
		if (movable(i))
		{
			getDistance(i, distance[0][i], 0);
			getDistance(i, distance[1][i], 1);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (movable(i))
		{
			int min1 = getMin(distance[0][i]);
			int min2 = getMin(distance[1][i]);
			if (min2 == 0)
			{
				min2 = 52;
			} 
			val[i] = min2 - min1;
		}
	}
}

int getBestMove(int val[4])
{
	int imax;
	int max;
	for (int i = 0; i < 4; i++)
	{
		if (movable(i))
		{
			max = val[i];
			imax = i;
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (movable(i)&& val[i] >= max)
		{
			if (val[i] == max)
			{
				if (i > imax)
				{
					imax = i;
				}
			}
			else
			{
				max = val[i];
				imax = i;
			}
		}
	}
	return imax;
}

int oneNotTOID()
{
	for (int i = 0; i < 4; i++)
	{
		if (atPort(i))
		{
			return i;
		}
	}
	return -1;
}

int notAllTO()
{
	for (int i = 0; i < 4; i++)
	{
		if (atPort(i))
		{
			return 1;
		}
	}
	return 0;
}

int AI()
{
	if (allNotTakeOff()&& randStep == 6)//直接起飞一架 
	{
		int id = oneNotTOID();
		if (id != -1)
		{
			return oneNotTOID() + 20;
		}
	}
	//flight at fist
	int flag = 0;
	for (int i = 0; i < 4; i++)
	{
		if (position[i] > -2)
		{
			flag++;
		}
	}
	if (flag == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (position[i] > -2)
			{
				return 10 + i;
			}
		}
	}
	
	int val[4];
	getValue(val);
	int id = getBestMove(val);
	
	if (randStep == 6&& notAllTO())
	{
		if (val[id] > 6)
		{
			int idd = oneNotTOID();
			if (idd != -1)
			{
				return idd + 20;
			}
		}
	}
	return 10 + id;
}



int main(int argc, char *argv[])
{
	FILE *f;
	f = fopen("AIlist.txt", "a+");
	if (argc == 1)
	{
		cout << "No commend" << endl;
		fprintf(f, "No command\n");
		fclose(f);
		return 0;
	}
	fprintf(f, "<%04d> CMD: ", atoi(argv[2]));
	for (int i = 0; i < argc; i++)
	{
		fprintf(f, "%s ", argv[i]);
	} 
	fprintf(f, "\n");
	predo(argv);
	for (int i = 0; i < 16; i++)
	{
		fprintf(f, "%d ", posi[i]);
	}
	fprintf(f, "\nindex : %d\nrandStep : %d\n", index, randStep);
	int cmd = AI();
	fprintf(f, "cmd : %d\n", cmd);
	if (cmd / 10 == 1)
	{
		fprintf(f, "<+> Move %d\n\n", cmd % 10);
	}
	else if (cmd /10 == 2)
	{
		fprintf(f, "<+> Take Off %d\n\n", cmd % 10);
	}
	fclose(f);
	return cmd;
}

/*
for (int i = 0; i < 16; i++)
	{
		position[i] = i;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%02d ", position[i * 4 + j]);
		}
		printf("\n");
	}
	printf("\n");
	index = 3;
	setToStart();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%02d ", position[i * 4 + j]);
		}
		printf("\n");
	}

*/

int isWin(int id)//did the id's plane winned?
{
	if (position[id] == -3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int atPort(int id)//did the id's plane at the port, didint take off?
{
	if (position[id] == -2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int movable(int id)//is the id's plane movable?
{
	if (position[id] > -2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int atRoad(int id)
{
	if (position[id] >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int atStart(int id)
{
	if (position[id] == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int atEndRoad(int id)
{
	if (position[id] >= 100)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int atMainRoad(int id)
{
	if (position[id] >= 0&& position[id] < 100)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

