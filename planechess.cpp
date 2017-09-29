# include<iostream>
# include<string>
# include"something.h"
# include"GameController.h"
# include"Node.h"
# include"Stack.h"
# include"Map.h"
# include"Chess.h"
# include"Place.h"
# include"Airport.h"
using namespace std;

int main(void)
{
	GameController *gc = new GameController;
	gc->test();
    return 0;
}
/*Test for stack
    Stack<int> st;
    int num[10];
    for (int i = 0; i < 10; i++)
    {
        num[i] = i;
        st.Push(&num[i]);
    }
    Node<int> *p;
    p = st.Head->next;
    while (p != NULL)
    {
        cout << "!! " << *p->Date << endl;
        p = p->next;
    }
    cout << endl;

    Node<int> *q = st.Pop(3);
    p = st.Head->next;
    while (p != NULL)
    {
        cout << "!! " << *p->Date << endl;
        p = p->next;
    }
    cout << endl;

    Node<int> *r = st.Pop(4);
    p = st.Head->next;
    while (p != NULL)
    {
        cout << "!! " << *p->Date << endl;
        p = p->next;
    }
    cout << endl;

    st.Push(q);
    p = st.Head->next;
    while (p != NULL)
    {
        cout << "!! " << *p->Date << endl;
        p = p->next;
    }
    cout << endl;

    st.Push(r);
    p = st.Head->next;
    while (p != NULL)
    {
        cout << "!! " << *p->Date << endl;
        p = p->next;
    }
    cout << endl;

    q = st.Pop(5);
    p = st.Head->next;
    while (p != NULL)
    {
        cout << "!! " << *p->Date << endl;
        p = p->next;
    }
    cout << endl;

    r = st.Pop(3);
    p = st.Head->next;
    while (p != NULL)
    {
        cout << "!! " << *p->Date << endl;
        p = p->next;
    }
    cout << endl;

    st.Push(q);
    p = st.Head->next;
    while (p != NULL)
    {
        cout << "!! " << *p->Date << endl;
        p = p->next;
    }
    cout << endl;

    st.Push(r);
    p = st.Head->next;
    while (p != NULL)
    {
        cout << "!! " << *p->Date << endl;
        p = p->next;
    }
    cout << endl;
*/

    /*Test for map
    Map *m = new Map;
    m->Init();
    Node<Place> *p = m->Head->next;
    int i = 0;
    cout << "[+] <" << ++i << "> ";
    p->Date->outInfo();
    cout << " : " << m->iStart(p) << endl;
    p = p->next;
    while (p != m->Head->next)
    {
        cout << "[+] <" << ++i << "> ";
        p->Date->outInfo();
        cout << " : " << m->iStart(p) << endl;
        if (p->brch != NULL)
        {
            Node<Place> *q = p->brch;
            while (q != NULL)
            {
                cout << "\t";
                q->Date->outInfo();
                if (m->isDanger(q))
                {
                    cout << " !!!Danger!!!" ;
                }
                cout << endl;
                q = q->next;
            }
        }
        p = p->next;
    }
    */
    /*
    Place*pla = new Place(yellow);
    Node<Place> node(pla);
    Chess *chs = new Chess(blue, 1);
    chs->setPosition(&node);
    cout << chs->getPosition()->Date->getColor() << endl;
    */
