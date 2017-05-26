//
//  main.c
//  求一个图中独立子图的个数，这种算法就是鼎鼎大名的Floodfill漫水填充法（也称种子填充法),广泛的运用在计算机图形学中，比如图像分割、物体识别等等,画图软件的油漆桶工具就是基于这个算法的。当你需要给某个密闭区域涂色或者更改某个密闭局域的颜色时，程序自动选中与种子点周边颜色相同的区域，接着将该区域替换成指定的颜色。ps的魔术棒选择工具也可以基于这个算法实现。具体的算法是：茶盅种子周边的点，将于种子点颜色相近的点（可以设置一个阈值）入队作为新种子，并对新种子入队的种子也进行同样的扩展操作，这样就选取了和最初种子相近的区域。
//
//  Created by 宗丽娜 on 17/5/26.
//  Copyright © 2017年 宗丽娜. All rights reserved.
//

#include <stdio.h>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x, int y,int color){

//定义一个方向数组
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int k, tx, ty;
    a[x][y] = color; //对a[x][y]这个格子进行染色
    for (k = 0; k <= 3; k++) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        if (tx < 1 || tx > n || ty < 1 || ty>m) {
            continue;
        }
        
        //判断是否是陆地
        if (a[tx][ty] > 0 && book[tx][ty] == 0) {
            sum++;
            book[tx][ty] = 1; //标记这个点已走过
            dfs(tx, ty, color);
        }
    }
    
    return;
}
int main(int argc, const char * argv[]) {
    int i,j,num = 0;
    printf("请输入行数和列数");
    scanf("%d %d",&n,&m);
    printf("开始赋值\n");
    
    for (i = 1 ; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d",&a[i][j]);
        }
        
        printf("\n");
    }
    
    
    
    //对每一个大于0的点尝试进行dfs颜色
    for (i = 1; i <=n; i++) {
        for (j = 1; j <= m; j++) {
            if (a[i][j] > 0) {
                num--; //小岛需要染的颜色编号
                //每次发现一个小岛应染以不同的颜色，因为每次要-1
                book[i][j] = 1;
                dfs(i, j, num);
            }
        }
    }
    
    
    printf("染色后的图像\n");
    //输出已经染色后的地图
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            printf("%3d",a[i][j]);
        }
        
        printf("\n");
    }
    
    printf("有%d个小岛\n",-num);
    
    
    return 0;
}
