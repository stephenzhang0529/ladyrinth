#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

int main()//入口（0，0）出口（M,N）
{
	//定义一个5x5的迷宫，0是通路，1是障碍
	int maze[MAX_M][MAX_N] =
	{
		{0, 1, 0, 0, 0},
		{0, 1, 0, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 1, 1, 1, 0},
		{0, 0, 0, 0, 0}
	};

	//访问数组初始化为0
	int visited[MAX_M][MAX_N] = { 0 };

	//定义起点和终点
	Position start = { 0, 0 };  // 左上角
	Position end = { 4, 4 };    // 右下角

	Stack path, shortest_path;
	initialstack(&path);
	initialstack(&shortest_path);
	push(&path, start);
	
	visited[start.x][start.y] = 1;


	printf("所有可能的路径如下:\n");
	dfs(maze, visited, &path, &shortest_path, start, end);
	printf("最佳路径为：\n");
	printpath(&shortest_path);
	return 0;
}