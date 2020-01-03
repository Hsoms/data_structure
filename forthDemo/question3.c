/* 二进制数的加法 */

#include <stdio.h>
#include <stdlib.h>

typedef struct code
{
    int data;
    struct code *next;
} Code;

void addOne();
Code *block(int data);
Code *create(int a[], int length);
int lookAll(Code *Head);

int main()
{
    int a[] = {1, 1, 0, 1, 1, 1, 1};
    int length = 7;
    Code *Head = create(a, length);
    printf("%s", "before: ");
    lookAll(Head);
    printf("\n");
    printf("%s", "now: ");
    addOne(Head);
    lookAll(Head);
}

void addOne(Code *Head)
{
    Code *HeadSave = Head;
    Code *temp = NULL;
    while (Head != NULL)
    {
        if (Head->data == 0)
        {
            temp = Head;
        }
        Head = Head->next;
    }
    if (temp == NULL)
    {
        Code *a1 = block(1);
        Code *a = Head->next;
        Head->next = a1;
        a1->next = a;
        while (a != NULL)
        {
            a->data = 0;
            a = a->next;
        }
    }
    else
    {
        temp->data = 1;
        Code *a = temp->next;
        while (a != NULL)
        {
            a->data = 0;
            a = a->next;
        }
    }
}
Code *block(int data)
{
    Code *a = (Code *)malloc(sizeof(Code));
    a->data = data;
    a->next = NULL;
    return a;
}

Code *create(int a[], int length)
{
    Code *q = (Code *)malloc(sizeof(Code));
    q->data = NULL;
    Code *Head = q;
    for (int i = 0; i < length; i++)
    {
        Code *p = (Code *)malloc(sizeof(Code));
        q->next = p;
        p->data = a[i];
        p->next = NULL;
        q = p;
    }
    return Head;
}
int lookAll(Code *Head)
{
    Head = Head->next;
    while (Head != NULL)
    {
        int i = 0;
        printf("%d\0", Head->data);
        Head = Head->next;
        i++;
    }
    return 0;
}
