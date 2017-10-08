# ifndef _STACK_H_
# define _STACK_H_
# include"Node.h"

template<typename T>
class Stack
{
public :
    Node<T> *Head;
    Stack()
    {
        T *n = new T;
        Head = new Node<T>(n);
    }

    Node<T> *Pop(T *);

    Node<T> *Pop(int cnt = 1);

    int length();

    void earse()
    {
        Node<T> *p = Head;
        Node<T> *q = p->next;
        while (q != NULL)
        {
            q->Value->beKilled();
            q = q->next;
        }
        //p->Value->beKilled();
        Head->next = NULL;
    }

    Node<T> *getTop()
    {
        return Head->next;
    }

    int isEmpty()
    {
        if (Head->next == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void Push(Node<T> p)
    {
        if (Head->next != NULL)
        {
            Head->next->prev = &p;
        }
        p.next = Head->next;
        Head->next = &p;
        p.prev = NULL;
    }

    void Push(T *p)
    {
        Node<T> *nNode = new Node<T>(p);
        Push(nNode);
    }

    void Push(T p)
    {
        Node<T> *nNode = new Node<T>(p);
        Push(nNode);
    }

    void Push(Node<T> *p)//can push in a list, but p is the top
    {
        Node<T> *q = p;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = Head->next;
        if (isEmpty() != 1)
        {
            Head->next->prev = q;
        }
        Head->next = p;
        p->prev = NULL;
    }
//
    int has(Node<T> *p)
    {
        return has(p->Value);
    }

    int has(T &p)
    {
        return has(&p);
    }

    int has(T *p)
    {
        Node<T> *q = Head->next;
        while (q != NULL)
        {
            if (q->Value == p)
            {
                return 1;
            }
            q = q->next;
        }
        return 0;
    }
};

template<typename T>
Node<T> *Stack<T>::Pop(T *t)
{
    Node<T> *p = Head->next;
    Node<T> *q = Head;
    while (p != NULL)
    {
        if (p->Value == t)
        {
            q->next = p->next;
            if (p->next != NULL)
            {
                p->next->prev = q;
            }
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

template<typename T>
Node<T> *Stack<T>::Pop(int cnt)
{
    Node<T> *c = Head->next;//return these from c to cnt
    Node<T> *q = Head->next;
    Node<T> *p = Head;
    Head->next = Head->next->next;
    while (cnt != 0&& q != NULL)
    {
        p = q;
        q = q->next;
        cnt--;
    }
    p->next = NULL;//list end -> next is NULL
    if (q != NULL)// stack -> prev is NULL
    {
        q->prev = NULL;
    }
    Head->next = q;// stack's Head -> next is q
    return c;
}

template<typename T>
int Stack<T>::length()
{
    int len = 0;
    Node<T> *p = Head->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
# endif // _STACK_H_
