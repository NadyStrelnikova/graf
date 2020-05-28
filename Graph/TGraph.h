#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TGraph {
public:
	vector<vector<int>> AdjacencyMatrix; //матрица смежности
	vector<int> NTable; //таблица номеров вершин
	vector<vector<int>> ChTable; //таблица потомков
	vector<int> LowTable; //таблица минимальных номеров смежных вершин и вершин в которые мы пришли по пути, проходящим через вершин
	TGraph(int n) { //конструктор
		for (int i = 0; i < n; i++) {
			AdjacencyMatrix.push_back(vector<int>());
			//AdjTable.push_back(vector<int>());
			//NTable.push_back(-1);
			ChTable.push_back(vector<int>());
			//LowTable.push_back(-1);

			for (int j = 0; j < n; j++) {
				AdjacencyMatrix[i].push_back(0);//заполнили нулями

			}
		}

	}

	void InitAdjMatrix(int num); //стандартный граф
	void HingesSearch(int curr, vector<int>& nodes); //поиск в глубину
	void HingesSearchStart(); //метод запускающий поиск в глубину
	bool IsZeroInVector(vector<int> vec, int& notConnectNode);
	bool IsChild(int currNode, int parrentNode);
	int MinAdjV(int node); //ищем смежную вершину с минимальным номером 
	void MinNumChild(int node, int& min);
	int Low(int node);
	void SetLowTable();
	bool IsConnectedGraph(int& notConnectNode);
	void InputMatrix(int node, int prob);
	void PrintMatrix(); //вывод матрицы
	void PrintTable(); //вывод таблиц
	void PrintHinges(); //вывод шарниров

};