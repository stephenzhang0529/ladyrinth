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
	Position data[MAX_M * MAX_N];//Position�������飬�ռ�ΪMAX_M * MAX_N
	int top;//�洢�������data���±�
}Stack;
//��ʼ��ջ
void initialstack(Stack* s);
//�ж�ջ�Ƿ�Ϊ�� true��false����
bool judge_empty(Stack* s);
//ѹջ
void push(Stack* s, Position p);
//��ջ
Position pop(Stack* s);
//��ȡջ��Ԫ��
Position showtop(Stack* s);
//��ӡ·��
void printpath(Stack* s);
//�ж��Ƿ������,�����ϰ��������߹���
bool judgemove(int maze[MAX_M][MAX_N], int visited[MAX_M][MAX_N], int x, int y);
//�ж���С����
void savepath(Stack* path, Stack* shortest_path);
//dfs����
void dfs(int maze[MAX_M][MAX_N], int visited[MAX_M][MAX_N], Stack* path, Stack* shortest_path, Position current, Position end);