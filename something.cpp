# include"something.h"
# include<iostream>
# include<string>
# include<cstring>

using namespace std;

string &i2str(int num)
{
    switch (num % 4)
    {
        case 0: return *new string("red");
        case 1: return *new string("green");
        case 2: return *new string("blue");
        case 3: return *new string("yellow");
    }
}

void outColor(int num)
{
    switch (num % 4)
    {
        case 0:     std::cout << "< Red  >";   break;
        case 1:     std::cout << "< Green>"; break;
        case 2:     std::cout << "< Blue >";  break;
        case 3:     std::cout << "<Yellow>"; break;
        default :   std::cout << "<  None>";
    }
}

int right_4(int num)
{
    num = num >= 0 ? num : -num;
    num = num % 4;
    return num;
}

char *int2str(int num, char *str)
{
    sprintf(str, "%d", num);
    return str;
    /*
    int flag = 0;
    if (num < 0)
    {
        flag = 1;
        num = -num;
    }
    char sign[256];
    sign[0] = '-';
    sign[1] = '\0';
    cout << num << endl;
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return str;
	}
	int n = num;
	int len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	cout << "length " << len << endl;
	str[len] = '\0';
	n = num;
	for (int i = len - 1; i >= 0; i--)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	if (flag)
    {
        strcat(sign, str);
        strcpy(str, sign);
    }
	return str;
	*/
}
