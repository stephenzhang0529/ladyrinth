#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_M 5
#define MAX_N 5
//定义方向，上下左右
int direction[4][2]= { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
typedef struct Position
{
	int x, y;
}Position;
typedef struct Stack
{
	Position data[MAX_M * MAX_N];//Position类型数组，空间为MAX_M * MAX_N
	int top;//存储最上面的data的下标
}Stack;

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
	for (int i = 0; i < s->top; i++)
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
void dfs(int maze[MAX_M][MAX_N], int visited[MAX_M][MAX_N], Position start, Position end)
{
	Stack path;
	initialstack(&path);

	push(&path, start);
	visited[start.x][start.y] = 1;

	while (!judge_empty(&path))//路径不空时
	{
		Position current = showtop(&path);
		if (current.x == end.x && current.y == end.y)
		{
			printpath(&path);
			Position now= pop(&path);
			visited[now.x][now.y] = 1;//将现在的位置标为不可走
			pop(&path);//弹两次栈
			continue;
		}
		//四方向移动
		bool moved = false;
		for (int i = 0; i < 4; i++)
		{
			int new_x = current.x + direction[i][0];
			int new_y = current.y + direction[i][1];
			if (judgemove(maze, visited, new_x, new_y))
			{
				Position next = { new_x, new_y };
				push(&path, next);
				visited[new_x][new_y] = 1;
				moved = true;
				break;
			}
		}
		if (!moved)//无路可走，回溯
		{
			visited[current.x][current.y] = 1;//将现在的位置标为不可走
			pop(&path);
		}
	}
}
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

	printf("所有可能的路径如下:\n");
	dfs(maze, visited, start, end);

	return 0;
}