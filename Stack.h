#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_M 5
#define MAX_N 5

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
void initialstack(Stack* s);
//判断栈是否为空 true空false不空
bool judge_empty(Stack* s);
//压栈
void push(Stack* s, Position p);
//弹栈
Position pop(Stack* s);
//获取栈顶元素
Position showtop(Stack* s);
//打印路径
void printpath(Stack* s);
//判断是否可以走,不走障碍，不走走过的
bool judgemove(int maze[MAX_M][MAX_N], int visited[MAX_M][MAX_N], int x, int y);
//判断最小距离
void savepath(Stack* path, Stack* shortest_path);
//dfs搜索
void dfs(int maze[MAX_M][MAX_N], int visited[MAX_M][MAX_N], Stack* path, Stack* shortest_path, Position current, Position end);