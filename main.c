#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_M 5
#define MAX_N 5
//���巽����������
int direction[4][2]= { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
typedef struct Position
{
	int x, y;
}Position;
typedef struct Stack
{
	Position data[MAX_M * MAX_N];//Position�������飬�ռ�ΪMAX_M * MAX_N
	int top;//�洢�������data���±�
}Stack;

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
	for (int i = 0; i < s->top; i++)
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
void dfs(int maze[MAX_M][MAX_N], int visited[MAX_M][MAX_N], Position start, Position end)
{
	Stack path;
	initialstack(&path);

	push(&path, start);
	visited[start.x][start.y] = 1;

	while (!judge_empty(&path))//·������ʱ
	{
		Position current = showtop(&path);
		if (current.x == end.x && current.y == end.y)
		{
			printpath(&path);
			Position now= pop(&path);
			visited[now.x][now.y] = 1;//�����ڵ�λ�ñ�Ϊ������
			pop(&path);//������ջ
			continue;
		}
		//�ķ����ƶ�
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
		if (!moved)//��·���ߣ�����
		{
			visited[current.x][current.y] = 1;//�����ڵ�λ�ñ�Ϊ������
			pop(&path);
		}
	}
}
int main()//��ڣ�0��0�����ڣ�M,N��
{
	//����һ��5x5���Թ���0��ͨ·��1���ϰ�
	int maze[MAX_M][MAX_N] = 
	{
		{0, 1, 0, 0, 0},
		{0, 1, 0, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 1, 1, 1, 0},
		{0, 0, 0, 0, 0}
	};

	//���������ʼ��Ϊ0
	int visited[MAX_M][MAX_N] = { 0 };

	//���������յ�
	Position start = { 0, 0 };  // ���Ͻ�
	Position end = { 4, 4 };    // ���½�

	printf("���п��ܵ�·������:\n");
	dfs(maze, visited, start, end);

	return 0;
}