/*单链表就地逆置问题*/
#include <stdio.h>
#include <stdlib.h>
typedef struct block
{
    int data;
    struct block *next;
} Block;

Block *creatBlock(int data)
{
    Block *p = (Block *)malloc(sizeof(Block));
    p->data = data;
    p->next = NULL;
    return p;
}
Block *creatLink(int a[])
{
    int length = sizeof(a) / sizeof(int);
    // printf("传递后值%d\n",sizeof(a));   //打印为8
    // printf("传递后值%d\n",sizeof(int));  //打印为4
    // printf("%d\n",length);
    Block *h = creatBlock(0);
    h->data = NULL;
    Block *Head = h;
    for (int i = 0; i < 3; i++)
    {
        Block *p = creatBlock(a[i]);
        h->next = p;
        h = p;
    }
    return Head;
}
void lookAll(Block *a)
{
    Block *b = a;
    while (b != NULL)
    {
        printf("%d\n", b->data);
        b = b->next;
    }
}
int punchList(Block *p)
{ //倒置链表，传入参数为头指针
    Block *c = p->next->next;
    Block *Block1 = p->next;
    while (c != NULL)
    {
        Block *temp = c->next;
        c->next = p->next;
        p->next = c;
        Block1->next = temp;
        c = temp;
    }

    return 0;
}
int main()
{
    int a[3] = {45, 78, 5};
    Block *list = creatLink(a);
    lookAll(list);
    punchList(list);

    printf("%s", "变化过后为：");
    lookAll(list);
    // printf("传递前值%d\n",sizeof(a));//  打印为12
    // printf("传递前值%d\n",sizeof(int));//打印为4
}
