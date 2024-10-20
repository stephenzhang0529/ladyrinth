#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
//定义方向，下右上左
int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
//初始化栈
void initialstack(Stack* s)
{
	s->top = -1;//即栈为空
}
//判断栈是否为空 true空false不空
bool judge_empty(Stack* s)
{
	return (s->top == -1);
}
//压栈
void push(Stack* s, Position p)
{
	s->data[++(s->top)] = p;
}
//弹栈
Position pop(Stack* s)
{
	return s->data[(s->top)--];
}
//获取栈顶元素
Position showtop(Stack* s)
{
	return s->data[(s->top)];
}
//打印路径
void printpath(Stack* s)
{
	for (int i = 0; i <= s->top; i++)
	{
		printf("(%d,%d)", s->data[i].x, s->data[i].y);
	}
	printf("\n");
}
//判断是否可以走,不走障碍，不走走过的
bool judgemove(int maze[MAX_M][MAX_N], int visited[MAX_M][MAX_N], int x, int y)
{
	return (x >= 0 && x < MAX_M && y >= 0 && y < MAX_N && maze[x][y] == 0 && !visited[x][y]);
}
void savepath(Stack* path, Stack* shortest_path)
{
	if (shortest_path->top == -1 || path->top < shortest_path->top)
	{
		*shortest_path = *path;
	}
}
void dfs(int maze[MAX_M][MAX_N], int visited[MAX_M][MAX_N], Stack* path, Stack* shortest_path, Position current, Position end)
{
	if (current.x == end.x && current.y == end.y)
	{
		savepath(path, shortest_path);
		printpath(path);
		return;
	}

	//四方向移动
	for (int i = 0; i < 4; i++)
	{
		int new_x = current.x + direction[i][0];
		int new_y = current.y + direction[i][1];
		if (judgemove(maze, visited, new_x, new_y))//可走
		{
			Position next = { new_x, new_y };
			push(path, next);
			visited[new_x][new_y] = 1;//标记为已访问
			dfs(maze, visited, path, shortest_path, next, end);
			//开始回溯
			visited[new_x][new_y] = 0;//重新标记为未访问
			pop(path);
		}
	}
}