#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
想建立一个链表，链表形式为head-->5-->1-->2-->3-->4-->NULL
然后遍历这个链表，将每个链表的data值打印出来
*/
struct  list_node
{
	int data ; 
	struct list_node *next ;
};
typedef struct list_node list_single ; 	//给list_node结构体定义别名list_single
list_single *creatLinkBlock(int data){
    list_single *node = NULL ;          //1、首先，当然是定义一个头指针node
	node = (list_single *)malloc(sizeof(list_single)); //2、然后分配内存空间
	if(node == NULL){
		printf("malloc fair!\n");
	}
	memset(node,0,sizeof(list_single)); //3、清一下
	node->data = data ;		    		//4、给链表节点的数据赋值 此出node->data   等同于（*node）.data
	node->next = NULL ;                 //5、将链表的指针域指向空
	// free(node);
    return node;

}
int lookAllBlock(list_single* p){
    list_single* a=p;
    while (a->next!=NULL)
    {
        printf("%d\n",a->data);
        a=a->next;
    }   
    printf("%d\n",a->data);
return 0;
}

int main(){
list_single *node=creatLinkBlock(5);
list_single*head=node;
for(int i=1;i<5;i++){
list_single *newNode=creatLinkBlock(i);
node->next=newNode;
node=newNode;
}
lookAllBlock(head);
return 0;
}