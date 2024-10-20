#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
//���巽����������
int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
//��ʼ��ջ
void initialstack(Stack* s)
{
	s->top = -1;//��ջΪ��
}
//�ж�ջ�Ƿ�Ϊ�� true��false����
bool judge_empty(Stack* s)
{
	return (s->top == -1);
}
//ѹջ
void push(Stack* s, Position p)
{
	s->data[++(s->top)] = p;
}
//��ջ
Position pop(Stack* s)
{
	return s->data[(s->top)--];
}
//��ȡջ��Ԫ��
Position showtop(Stack* s)
{
	return s->data[(s->top)];
}
//��ӡ·��
void printpath(Stack* s)
{
	for (int i = 0; i <= s->top; i++)
	{
		printf("(%d,%d)", s->data[i].x, s->data[i].y);
	}
	printf("\n");
}
//�ж��Ƿ������,�����ϰ��������߹���
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

	//�ķ����ƶ�
	for (int i = 0; i < 4; i++)
	{
		int new_x = current.x + direction[i][0];
		int new_y = current.y + direction[i][1];
		if (judgemove(maze, visited, new_x, new_y))//����
		{
			Position next = { new_x, new_y };
			push(path, next);
			visited[new_x][new_y] = 1;//���Ϊ�ѷ���
			dfs(maze, visited, path, shortest_path, next, end);
			//��ʼ����
			visited[new_x][new_y] = 0;//���±��Ϊδ����
			pop(path);
		}
	}
}