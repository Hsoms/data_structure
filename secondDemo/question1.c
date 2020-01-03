/*利用顺序表调整其为左右两部分，左边的为奇数，右边的为偶数*/
#define MAXSIZE 100
typedef struct    //定义了数组类型结构，实现顺序存储
{
 int elem[MAXSIZE];
 int last;  //就是数组的最大下标
}SeqList;

AdjustSqlist(SeqList *L)/*利用顺序表调整其为左右两部分，左边的为奇数，右边的为偶数*/
{
 int i=0,j=L->last;
 int t;
 while(i<j) 
 {
  while(L->elem[i]%2!=0)
   i++;
  while(L->elem[j]%2==0)
   j--;
  if(i<j)
  {
   t=L->elem[i];
   L->elem[i]=L->elem[j];
   L->elem[j]=t;
  }
 }
}


void main()//主函数
{
    SeqList l;
 int p,q,r,i,j;
 printf("请输入线性表的长度：");
 scanf("%d",&p);
 l.last=p-1;
 printf("/n请输入线性表中各元素的值：");
 for(i=0;i<=l.last;i++)
 scanf("%d",&l.elem[i]);

 AdjustSqlist(&l);//参数为指向结构体l的指针

 printf("/n调整后的顺序表为");
 for(i=0;i<=l.last;i++)
 //scanf("%d",&l.elem[i]);
 printf("%d ",l.elem[i]);

}

