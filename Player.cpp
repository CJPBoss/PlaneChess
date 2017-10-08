# include<cstdio>
# include<iostream>
# include"Map.h"
# include<windows.h>
# include<cstring>
# include"something.h"
# include"Player.h"
# include"GameController.h"

using namespace std;

Player::Player()
{
	planeMap = NULL;
	gc = NULL;
	human = 1;
}

Player::Player(int flagHuman, int id)
{
	planeMap = NULL;
	gc = NULL;
	human = flagHuman;
	index = id;
	if (!human)
	{
		setAI();
	}
}

void Player::setPlayer(int flag)
{
    human = flag;
    if (human == 0)
    {
        if (AIname[0] == '\0')
        {
            setAI();
        }
    }
}

void Player::setAI()
{
    human = 0;
	cout << "Please input the address of the AI" << endl;
	cin >> AIaddress;
	//strcpy(AIaddress, "F:\\Program\\codeblock\\PlaneChess\\AI\\ai_1.exe");
	int len = strlen(AIaddress);
	int sta, i;
	for (i = len - 1; i >= 0; i--)
	{
		if (AIaddress[i] == '/'|| AIaddress[i] == '\\')
		{
			break;
		}
	}
	sta = i + 1;
	cout << "\\" << sta << endl;
	for (i = 0; i < AIaddress[i] != '\0'; i++)
	{
		AIname[i] = AIaddress[i + sta];
	}
	AIname[i] = '\0';
	printf("[+]\tAI %s ready\n", AIname);
}

int Player::getCMD(int randStep, int *apCMD, int st)
{
    if (human)
    {
        return getHumanCMD(randStep);
    }
    else
    {
        return getAICMD(randStep, apCMD, st);
    }
}

int Player::getHumanCMD(int randStep)
{
    int a[4];
    printf("Human!!\n");
    gc->showFour(index, a);
    for (int i = 0; i < 4; i++)
    {
        cout << i << ":" << a[i] << endl;
    }
    cout << "<!>\tYou got a " << randStep << endl;
    cout << "<!>\tPlease input your next CMD:activity, planeID" << endl;
    cout << "\t1 - move\n\t2 - take off" << endl;
    int cmd, pl;
    cin >> cmd  >> pl;
    return cmd * 10 + pl;

}

int Player::getAICMD(int randStep, int *apCMD, int st)
{
    FILE *file;
    char *infoaddress = "MAPINFO.txt";
    file = fopen(infoaddress, "w");
    printf("AI!!\n");
	char CMDstring[4096];
	char nu[100];
	CMDstring[0] = '\0';
	strcpy(CMDstring, AIaddress);
	strcat(CMDstring, " ");
	strcat(CMDstring, infoaddress);
	strcat(CMDstring, " ");
	sprintf(CMDstring, "%s%d", CMDstring, st);
	printf("%s|\n", CMDstring);

	for (int i = 0; i < 16; i++)
    {
        fprintf(file, "%d ", apCMD[i]);
        printf("%d ", apCMD[i]);
    }
    printf("\n");
    fprintf(file, "%d ", index);
    fprintf(file, "%d", randStep);
    fclose(file);
    /*
	strcat(CMDstring, int2str(index, nu));
	strcat(CMDstring, " ");
	strcat(CMDstring, int2str(randStep, nu));
    */
    cout << "CMD: ";
    cout << CMDstring << endl;
	return system(CMDstring);
}

int Player::sendCMD(char *cmdstr)
{
    char str[4096];
    strcpy(str, AIaddress);
    strcat(str, " ");
    strcat(str, cmdstr);
    cout << "CMD:" << endl;
    cout << cmdstr << endl;
    return system(str);
}

