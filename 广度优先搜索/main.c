//
//  main.c
//  广度优先搜索
//
//  Created by 宗丽娜 on 17/5/19.
//  Copyright © 2017年 宗丽娜. All rights reserved.
//

#include <stdio.h>

struct note {
    
    int x; //横坐标
    int y; //纵坐标
    int s; //步数
    int f; //父亲在队列中的编号
};

int main(int argc, const char * argv[]) {
    
    //解救小哈   迷宫由 n行m列的单元格组成 每个单元格不是空地就是障碍物  任务找到一条从迷宫的起点通往小哈所在位置的最短路径。
    struct note que[2501];
    int  head, tail;
    int  a[51][51] = {0};//用来存储地图
    int  book[51][51] = {0}; //数组book的用作是记录那些点已经在队列中了，防止一个点被重复扩散，并全部初始化为0；
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//向右走  向下走 向左走 向上走
    
 
    int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
    printf("请输入行数和列数");
    scanf("%d %d",&n,&m);
    for (i = 1; i <= n; i++) {
        for (j=1; j<=m; j++) {
            printf("请给数组填值");
            scanf("%d",&a[i][j]);
           
        }
    }
    
    printf("请输入起点和所找人的位置");
    scanf("%d %d %d %d",&startx,&starty,&p,&q);
    head = 1;
    tail = 1;
    que[tail].x = startx;
    que[tail].y  = starty;
    que[tail].s = 0;
    que[tail].f = 0;
    tail++;
    book[startx][starty] = 1;
    flag = 0; //用来标试是否达到目标点
    while (head < tail) {
        for (k = 0; k<=3; k++) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            
            if (tx < 1 || tx > n || ty < 1 || ty > m) {
                continue;
            }
            
            if (a[tx][ty] ==0 && book[tx][ty] == 0) {
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head;
                que[tail].s = que[head].s + 1;
                tail++;
            }
            
            if (tx == p && ty == q) {
                flag = 1;
                break;
            }
        }
        
        if (flag ==1) {
            break;
            
        }
        head++;
        
    }
  
    printf("%d",que[tail - 1].s);
    

    return 0;
}







