#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

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

	Stack path, shortest_path;
	initialstack(&path);
	initialstack(&shortest_path);
	push(&path, start);
	
	visited[start.x][start.y] = 1;


	printf("���п��ܵ�·������:\n");
	dfs(maze, visited, &path, &shortest_path, start, end);
	printf("���·��Ϊ��\n");
	printpath(&shortest_path);
	return 0;
}