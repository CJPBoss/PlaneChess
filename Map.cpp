# include<iostream>
# include<stdio.h>
# include"Map.h"
# include"Node.h"
# include"Place.h"
# include"Chess.h"
# include"something.h"

Node<Place> *Map::operator[](int position)
{
	int len = length();
	int pos = position % len;
	Node<Place> *p = Head->next;
	while (len != 0)
	{
		p = p->next;
	}
	return p;
}

void Map::outInfo(Node<Place> *p)
{
    if (p == NULL)
    {
        return ;
    }
    int id = findIndex(p);
    printf(" [Place_(");
    p->Value->outInfo();
    printf(")-<%2d|%d>]", id%100, id/100);
}

int Map::findIndex(Node<Place> *p)
{
    int index = 0;
    Node<Place> *q = Head->next;
    if (q == p)
    {
        return index;
    }
    else
    {
        index++;
        q = q->next;
    }
    while (q != Head->next)
    {
        if (q == p)
        {
            return index;
        }
        if (isEndStartPoint(q) == 1)
        {
            int a = 1;
            Node<Place> *r = q->brch;
            while (r != NULL)
            {
                if (p == r)
                {
                    return a * 100 + index;
                }
                r = r->next;
                a++;
            }
        }
        index++;
        q = q->next;
    }
    return -1;
}

int Map::length()
{
	int len = 0;
	Node<Place> *p = Head->next;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void i2s(int num)
{
    switch (num % 4)
    {
        case 0:       std::cout << "   Red start ";   break;
        case 1:     std::cout << " Green start "; break;
        case 2:      std::cout << "  Blue start ";  break;
        case 3:    std::cout << "Yellow start "; break;
        default :       std::cout << "None ";
    }
}

Map::Map()
{
	Color w = RED;
	printf("[+] plane map is setting\n");
	for (int i = 0; i < 4; i++)
	{
		Place *p = new Place(i);
		Start[i] = new Node<Place>(p);
	}
	Head = NULL;
	Init();
	printf("[+] plane map is ready\n");
}

int Map::isEnd(Node<Place> *p)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (p == End[i])
        {
            return 1;
        }
    }
    return 0;
}

int Map::isDanger(Node<Place> *p)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (p == DangerEnd[i])
        {
            return 1;
        }
    }
    return 0;
}

void Map::createEnd(Node<Place> *sta)
{
    Node<Place> *p = sta;
    Color col = sta->Value->getColor();

    Place *nPlace = new Place(col);
    Node<Place> *nNode = new Node<Place>(nPlace);
    p->brch = nNode;
    nNode->prev = p;
    p = nNode;

    int i;
    for (i = 1; i < 6; i++)
    {
        nPlace = new Place(col);
        nNode = new Node<Place>(nPlace);
        p->next = nNode;
        nNode->prev = p;
        p = nNode;
        if (i == 2)
        {
            DangerEnd[col] = nNode;
        }
    }
    End[col] = p;
}

int Map::isEndStartPoint(Node<Place> *p)
{
    for (int i = 0; i < 4; i++)
    {
        if (p == EndStartPoint[i])
        {
            return 1;
        }
    }
    return 0;
}

int Map::isEndLine(Node<Place> *p)
{
    int id = findIndex(p);
    if (id / 100 > 0)
    {
        return 1;
    }
    return 0;
}

//Red -> Green -> Blue -> Yellow
void Map::Init()
{
	Head = new Node<Place>;
	Node<Place> *p = Head;
	int staColor = RED;
	int i, j, k = 3;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 13; j++)
		{
			Place *nPlace = new Place(right_4(staColor + k));
			k++;
			Node<Place> *nNode = new Node<Place>(nPlace);
			if (j == 0)
			{
				Start[i]->next = nNode;
			}
            if (j == 3)                                         //i is color, end of super fly of color + 2
            {
                SuperFly[right_4(i + 2)][1] = nNode;
            }
			if (j == 4)                                         //i is color, start of super fly of color + 3
            {
                SuperFly[right_4(i + 3)][0] = nNode;
            }
			p->next = nNode;
			nNode->prev = p;
			p = nNode;
			if (j == 10)
            {
                createEnd(p);
                EndStartPoint[i] = p;
            }
		}
	}
	Head->next->prev = p;
	p->next = Head->next;
}

int Map::iStart(Node<Place> *p)
{
	for (int i = 0; i < 4; i++)
	{
		if (Start[i] == p)
		{
			return 1;
		}
	}
	return 0;
}
