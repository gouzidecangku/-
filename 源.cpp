#include"single.h"
#include <iostream>
using namespace std;
#define max 10000
typedef struct
{
	int vexs, arcs;
	char vex[100];
	int arc[100][100];
}Graph;
int locatevex(Graph& G, char vex)//寻找对应的顶点位置
{
	for (int i = 0;i < G.vexs;i++)
	{
		if (G.vex[i] == vex)
		{
			return i;
		}
	}
	return -1;
}
void creatgraph(Graph& G)
{
	char vex1, vex2;
	int weight;
	cout << "pls input vex num and arc num: " << endl;
	cin >> G.vexs >> G.arcs;
	for (int i = 0;i < G.vexs;i++)
	{
		cout << "pls input " << (i + 1) << " vex num" << endl;
		cin >> G.vex[i];
	}
	for (int i = 0;i < G.vexs;i++)
	{
		for (int j = 0;j < G.vexs;j++)
		{
			G.arc[i][j] = max;
		}
	}
	int m, n;
	for (int i = 0;i < G.arcs;i++)
	{
		cout << "pls input vex about arc and weight" << endl;
		cin >> vex1 >> vex2 >> weight;
		m = locatevex(G, vex1);
		n = locatevex(G, vex2);
		G.arc[m][n] = weight;//根据无向图原理，是一个n*n的矩形
		G.arc[n][m] = weight;
		if (n == -1 || m == -1)
		{
			cout << "error" << endl;
		}
	}
}
void showgraph(Graph& G)//输出，检查！
{
	for (int i = 0;i < G.vexs;i++)
	{
		for (int j = 0;j < G.vexs;j++)
		{
			if (G.arc[i][j] != max)
			{
				cout << G.arc[i][j] << " ";
			}
			else
			{
				cout << "#" << " ";
			}

		}
		cout << endl;

	}
}
int main()
{
	Graph G;
	creatgraph(G);
	showgraph(G);
	return 0;
}