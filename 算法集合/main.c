//
//  main.c
//  算法集合
//
//  Created by 宗丽娜 on 17/5/3.
//  Copyright © 2017年 宗丽娜. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//简单桶排序
void sigleSequence();

//邻居好说话-- 冒泡排序 -- 基本思想每次比较两个相邻的元素，如果它们的顺序错误就把他们交换过来
void bubbleSequence();
void  structStudent();

//快速排序 --  基本思想就是每一轮将基准数归位
void quicksort();
void quick();

//队列排序  先进先出
void queueSort();
//栈  后劲先出
void penSort();


//链表
void chainSqilt();

void newDfs();
void dfs(int step,int n);
int main(int argc, const char * argv[]) {
 

//    structStudent();
    
//    quick();
//    queueSort();
//    penSort();
//    chainSqilt();
    newDfs();
    return 0;
}


//最快最简单的排序-- 桶排序   时间复杂度O(m + m) 空间复杂度特别大
void sigleSequence(){
    int number;
    printf("请输入你要排序的数字个数:");
    scanf("%d",&number);
    
    int newN = number + 1;
    int a[newN],i,j,t;
    for (i = 0; i <= newN; i++) {
        a[i] = 0;
    }
  
    //循环读入5个数
    for (i = 0; i< number; i++) {
          printf("请输入第%d个数",i);
          scanf("%d",&t);
          a[t]++;
    }
    
    //依次判断a[0] ~ a[10]
    for (i = 0; i<=number; i++) {
       
        for (j = 1; j <= a[i]; j++) {
            
            printf("___%d",i);
        }
    }
  
}


// 时间复杂度 o(N^2)
void bubbleSequence(){

    int n;
    printf("请输入你要排序的数字个数");
    scanf("%d",&n);
    int  a[n],i,j,t;
    for (i = 1; i<=n; i++) {
        printf("请输入第%d个数",i);
        scanf("%d",&a[i]);
    }

    for (i = 1; i<= n-1; i++) {
        for (j=1; j <= n-i; j++) {
            if (a[j] > a[j+1]) {
                t = a[j]; a[j]= a[j+1]; a[j+1] = t;
            }
        }
    }
    
    for (i = 1; i<=n; i++) {
        printf("%d\n",a[i]);
    }

}

struct student{
    char name[21];
    int  score;
    
};
void structStudent(){

   
    
    int i,j,n;
     printf("请输入你要排序的学生个数");
    scanf("%d",&n);
    struct student a[n] ,t ;
    for (i = 1; i<=n; i++) {
             printf("请输入学生姓名和成绩");
        scanf("%s%d",a[i].name,&a[i].score);
    }
 
    for (i = 0; i<= n-1; i++) {
        for (j=0; j<= n-1; j++) {
            if (a[j].score < a[j+1].score) {
                t= a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
        }
    }
    
    
    for (i=1; i<= n; i++) {
        printf("%s%d\n",a[i].name,a[i].score);
    }
    
}


//快速排序 平均时间复杂度为o(NlogN)

int a[101],n;
void quicksort(int left,int right){

    int i ,j ,t ,temp;
    if (left > right) {
        return;
    }
    
    temp = a[left];
    i = left;
    j= right;
    while (i!= j) {
        while (a[j]>=temp && i<j) {
            j--;
        }
        
        while (a[i]<=temp && i<j) {
            i++;
        }
        
        //交换两个数的数组中的位置
        if (i<j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        
    }
    
    a[left] = a[i];
    a[i] = temp;
    quicksort(left,i-1);//继续处理左边的,这里是一个递归的过程
    quicksort(i+1,right);
    
}


void quick(){

    int i,n;
    printf("请输入你要排序的数字个数");
    scanf("%d",&n);
   
    for (i = 1; i<=n; i++) {
        printf("请输入第%d个数",i);
        scanf("%d",&a[i]);
    }
    printf("_______");
    quicksort(1, n);
    for (i= 1; i<=n; i++) {
        printf("%d\n",a[i]);
    }

}

struct queue{
    int  data[100];
    int  head;
    int tail;

};

void queueSort(){
//    int q[102] = {0,6,3,1,7,5,8,9,2,4},head,tail;
//   
//    head = 1;
//    tail = 10;
//    while (head < tail) {
//        printf("%d",q[head]);
//        head++;
//        
//        q[tail] = q[head];
//        tail++;
//        head++;
//    }
 
    struct queue q;
    int i ;
    
    q.head = 1;
    q.tail = 1;
    for (i=1; i<=9; i++) {
        printf("请依次输入9个数");
        scanf("%d",&q.data[q.tail]);
        q.tail++;
    }
    
    while (q.head < q.tail) {
        printf("%d",q.data[q.head]);
        q.head++;
        
        q.data[q.tail] = q.data[q.head];
        q.tail++;
        q.head++;
    }
    
    
}

//判断是否是回文字符串
void penSort(){

    char a[101],s[101];
    int i,len,mid,next,top;
    
    printf("请输入你要判断的字符串");
    
    gets(a);
    len = strlen(a);
    mid = len/2 - 1;

    top = 0;
    
    for (i = 0; i<=mid; i++) {
        s[++top] = a[i];
      
        
    }
    
    if (len %2 ==0) {
        
        next = mid + 1;
        
    }else{
    
        next = mid + 2;
    
    }
    
    for (i= next; i<=len -1; i++) {
        
        if (a[i] != s[top]) {
            
            break;
            
            top--;
        }
        
    }
    
    if (top == 0) {
        
        printf("YES");
    }else{
        
        printf("NO");
    }


}



//链表
struct node {

    int data;
    struct node *next;

};

void chainSqilt(){

    struct node * head, *p, *t;
    struct node * q;
    int i , n,a ;
    
    printf("请输入你要排序的个数");
    scanf("%d",&n);
    head = NULL;
    
    for (i = 0; i<=n; i++) {
        printf("请输入第%d个数",i);
        scanf("%d",&a);
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a;
        p->next = NULL;
        
        if (head == NULL) {
            head = p;
        }else{
        
//
            q->next = p;
            q = p;
            
        }
        
        t = head;
        while (t != NULL) {
            printf("%d",t->data);
            t = t->next;
        }
        
    }

}


void newDfs(){
    int n;
    printf("请输入个数");
    scanf("%d",&n);
    dfs(1, n);
    

}

void dfs(int step,int n){
    int  a[10] = {0,0,0,0,0,0,0,0,0,0,0},book[10] ={0,0,0,0,0,0,0,0,0,0};
    if (step == n) {
        
        for (int i=0; i<=n;i++) {
            printf("%d",a[i]);
            
            printf("\n");
            
            return;
        }
    }
    
    for (int j =  0; j<=n; j++) {
        
        if (book[j] == 0) {
            
            a[step] = j;
            printf("数字%d%d",step,a[step]);
            book[j] = 1;
            
            dfs(step+1, n);
            book[j] = 0;
        }
        
        return;
    }
    
    
}











