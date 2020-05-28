#include "TGraph.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void TGraph::InitAdjMatrix(int num) {//заполнит структуру готовым графом из Википедии
	switch (num) {
	case 1:
		AdjacencyMatrix[0][1] = 1;
		AdjacencyMatrix[1][0] = 1;

		AdjacencyMatrix[1][3] = 1;
		AdjacencyMatrix[3][1] = 1;

		AdjacencyMatrix[1][4] = 1;
		AdjacencyMatrix[4][1] = 1;

		AdjacencyMatrix[2][0] = 1;
		AdjacencyMatrix[0][2] = 1;

		AdjacencyMatrix[2][5] = 1;
		AdjacencyMatrix[5][2] = 1;

		AdjacencyMatrix[2][6] = 1;
		AdjacencyMatrix[6][2] = 1;
		break;

	case 2:
		AdjacencyMatrix[0][1] = 1;
		AdjacencyMatrix[1][0] = 1;

		AdjacencyMatrix[1][2] = 1;
		AdjacencyMatrix[2][1] = 1;

		AdjacencyMatrix[1][3] = 1;
		AdjacencyMatrix[3][1] = 1;

		AdjacencyMatrix[1][4] = 1;
		AdjacencyMatrix[4][1] = 1;

		AdjacencyMatrix[2][3] = 1;
		AdjacencyMatrix[3][2] = 1;

		AdjacencyMatrix[3][4] = 1;
		AdjacencyMatrix[4][3] = 1;

		AdjacencyMatrix[4][5] = 1;
		AdjacencyMatrix[5][4] = 1;
		break;

	case 3:

		AdjacencyMatrix[0][1] = 1;
		AdjacencyMatrix[1][0] = 1;

		AdjacencyMatrix[1][2] = 1;
		AdjacencyMatrix[2][1] = 1;

		AdjacencyMatrix[2][3] = 1;
		AdjacencyMatrix[3][2] = 1;

		AdjacencyMatrix[0][3] = 1;
		AdjacencyMatrix[3][0] = 1;

		AdjacencyMatrix[2][4] = 1;
		AdjacencyMatrix[4][2] = 1;
		break;

	case 4:

		AdjacencyMatrix[0][1] = 1;
		AdjacencyMatrix[1][0] = 1;

		AdjacencyMatrix[1][2] = 1;
		AdjacencyMatrix[2][1] = 1;

		AdjacencyMatrix[2][0] = 1;
		AdjacencyMatrix[0][2] = 1;

		AdjacencyMatrix[2][5] = 1;
		AdjacencyMatrix[5][2] = 1;

		AdjacencyMatrix[5][4] = 1;
		AdjacencyMatrix[4][5] = 1;

		AdjacencyMatrix[5][6] = 1;
		AdjacencyMatrix[6][5] = 1;

		AdjacencyMatrix[4][6] = 1;
		AdjacencyMatrix[6][4] = 1;

		AdjacencyMatrix[4][3] = 1;
		AdjacencyMatrix[3][4] = 1;
		break;

	case 5:

		AdjacencyMatrix[0][1] = 1;
		AdjacencyMatrix[1][0] = 1;

		AdjacencyMatrix[1][2] = 1;
		AdjacencyMatrix[2][1] = 1;

		AdjacencyMatrix[2][3] = 1;
		AdjacencyMatrix[3][2] = 1;

		AdjacencyMatrix[2][4] = 1;
		AdjacencyMatrix[4][2] = 1;

		AdjacencyMatrix[5][4] = 1;
		AdjacencyMatrix[4][5] = 1;

		AdjacencyMatrix[3][4] = 1;
		AdjacencyMatrix[4][3] = 1;

		AdjacencyMatrix[1][6] = 1;
		AdjacencyMatrix[6][1] = 1;

		AdjacencyMatrix[6][8] = 1;
		AdjacencyMatrix[8][6] = 1;

		AdjacencyMatrix[6][7] = 1;
		AdjacencyMatrix[7][6] = 1;

		AdjacencyMatrix[8][7] = 1;
		AdjacencyMatrix[7][8] = 1;

		AdjacencyMatrix[9][7] = 1;
		AdjacencyMatrix[7][9] = 1;

		AdjacencyMatrix[10][7] = 1;
		AdjacencyMatrix[7][10] = 1;

		AdjacencyMatrix[9][10] = 1;
		AdjacencyMatrix[10][9] = 1;

		break;


	}

}






void TGraph::HingesSearch(int curr, vector<int>& nodes) //ПОИСК в глубину
{

	int r;

	//cout << curr + 1 << " ";//очередность вершин в которые заходили
	NTable.push_back(curr); //очередность вершин в которые заходили
	nodes[curr] = 1;
	for (r = 0; r < AdjacencyMatrix.size(); r++)
		if ((AdjacencyMatrix[curr][r] != 0) && (nodes[r] == 0)) {
			ChTable[curr].push_back(r); // запись в таблицу потомка 
			HingesSearch(r, nodes);
		}
}


void TGraph::HingesSearchStart() //метод запускающий поиск в глубину
{
	vector<int> nodes;
	for (int i = 0; i < AdjacencyMatrix.size(); i++)
		nodes.push_back(0);
	HingesSearch(0, nodes);

	vector<int> tmp;
	for (int i = 0; i < AdjacencyMatrix.size(); i++)
		tmp.push_back(-1);
	for (int i = 0; i < AdjacencyMatrix.size(); i++)
		tmp[NTable[i]] = i;
	NTable = tmp;

}

bool TGraph::IsZeroInVector(vector<int> vec, int& notConnectNode)
{
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] == 0)
		{
			notConnectNode = i;
			return true;
		}
	return false;
}

bool TGraph::IsChild(int currNode, int parrentNode)
{
	for (int i = 0; i < ChTable[parrentNode].size(); i++)
	{
		if (ChTable[parrentNode][i] == currNode)
			return true;
	}
	return false;
}


int TGraph::MinAdjV(int node) //ищем смежную вершину с минимальным номером 
{
	for (int j = 0; j < AdjacencyMatrix.size(); j++)
	{
		if (!IsChild(j, node))
			if (AdjacencyMatrix[node][j] == 1)
				return NTable[j];
	}

	return -1;
}

void TGraph::MinNumChild(int node, int& min)
{

	for (int j = 0; j < ChTable[node].size(); j++)
	{
		if (ChTable[node][j] < min)//обращение к номеру вершины текущего ребенка
			min = ChTable[node][j];
		MinNumChild(ChTable[node][j], min);
	}
}


int TGraph::Low(int node)
{
	int minCh = INT_MAX;
	for (int j = 0; j < ChTable[node].size(); j++)
	{
		int minCurr = Low(ChTable[node][j]);
		if (minCurr < minCh)
			minCh = minCurr;
	}
	return min(minCh, MinAdjV(node));
}


void TGraph::SetLowTable()
{
	for (int i = 0; i < AdjacencyMatrix.size(); i++)
	{
		/*int _min = INT_MAX;
		MinNumChild(i, _min);
		LowTable.push_back(min(MinAdjV(i), _min));*/
		LowTable.push_back(Low(i));
	}
}

bool TGraph::IsConnectedGraph(int& notConnectNode)
{
	vector<int> nodes;
	for (int i = 0; i < AdjacencyMatrix.size(); i++)
		nodes.push_back(0);
	HingesSearch(0, nodes);

	return !IsZeroInVector(nodes, notConnectNode);
}

void TGraph::InputMatrix(int node, int prob) //prob - вероятность
{
	int k = 0;
	if (node > 5) {
		for (int i = 0; i < node; i++) {
			for (int j = i; j < node; j++) {
				if (i == j) AdjacencyMatrix[i][j] = 0;
				else {
					k = rand() % 100;
					if (k < prob) AdjacencyMatrix[i][j] = 0;
					else AdjacencyMatrix[i][j] = 1;
				}
			}
		}
		for (int j = 0; j < node; j++) {
			for (int i = j; i < node; i++) {
				AdjacencyMatrix[i][j] = AdjacencyMatrix[j][i];
			}
		}
	}
	else {
		cout << "enter elements" << endl;
		for (int i = 0; i < node; i++)
			for (int j = 0; j < node; j++)
				cin >> AdjacencyMatrix[i][j];
	}
	int notConnectNode = -1;
	while (!IsConnectedGraph(notConnectNode))
	{
		if (notConnectNode != 0)
		{
			AdjacencyMatrix[notConnectNode][0] = 1;
			AdjacencyMatrix[0][notConnectNode] = 1;
		}
		else
		{
			AdjacencyMatrix[notConnectNode][1] = 1;
			AdjacencyMatrix[1][notConnectNode] = 1;
		}
	}
	NTable.clear();
	LowTable.clear();
	for (int i = 0; i < ChTable.size(); i++)
		ChTable[i].clear();

}


void TGraph::PrintMatrix()
{
	for (int i = 0; i < AdjacencyMatrix.size(); i++)
	{
		for (int j = 0; j < AdjacencyMatrix.size(); j++)
		{
			cout << AdjacencyMatrix[i][j] << " ";

		}
		cout << endl;
	}

}

void TGraph::PrintTable()
{
	cout << endl;
	cout << "CHILDTABLE ";
	cout << endl;

	for (int i = 0; i < ChTable.size(); i++)
	{
		for (int j = 0; j < ChTable[i].size(); j++)
		{
			cout << ChTable[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "NTABLE ";
	for (int i = 0; i < NTable.size(); i++)
	{
		cout << NTable[i] << " ";
	}
	cout << endl;
	cout << "LOWTABLE ";

	for (int i = 0; i < LowTable.size(); i++)
	{
		cout << LowTable[i] << " ";
	}
	cout << endl;

}

void TGraph::PrintHinges()
{
	//cout << endl;
	cout << "Hinges : ";
	if (ChTable[0].size() > 1)
		cout << 0 << " ";
	for (int i = 1; i < AdjacencyMatrix.size(); i++)
	{
		for (int j = 0; j < ChTable[i].size(); j++)
		{
			if (LowTable[ChTable[i][j]] == NTable[i]) {
				cout << i << " ";
				break;
			}
		}
	}
	//cout << endl;
}





