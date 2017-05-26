//
//  main.c
//  万能搜索
//
//  Created by 宗丽娜 on 17/5/18.
//  Copyright © 2017年 宗丽娜. All rights reserved.
//

#include <stdio.h>
//深度搜索
int n,m,p,q, min = 99999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step);
int main(int argc, const char * argv[]) {
  
    int i,j,startx,starty;
    printf("请输入行列");
    scanf("%d %d",&n,&m);
    for (i = 1; i<=n; i++) {
        for (j = 1; j<=m; j++) {
            printf("请输入");
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("请输入起点和终点");
    scanf("%d %d %d %d",&startx,&starty,&p,&q);
    book[startx][starty] = 1;
    dfs(startx, starty, 0);
    printf("%d",min);
    
   
    
    
        return 0;
}
void dfs(int x,int y,int step){
    
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int tx,ty,k;
    if (x==p && y==q) {
        if (step < min) {
            min = step;
            return ;
        }
    }
//
//    //枚举4中走法
    for (k = 0; k<= 3; k++) {
        tx = x+ next[k][0];
        ty = y+ next[k][1];
        
        //判断是否越界
        if (tx<1 || tx>n ||ty<1 || ty>m) {
            continue;
        }
        //判断该点是否为障碍物或者已经在路径中
        
        if(a[tx][ty] ==0 &&book[tx][ty] ==0){
           book[tx][ty] = 1;
//
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
            
        }
    }
    
//    return;
    
}
