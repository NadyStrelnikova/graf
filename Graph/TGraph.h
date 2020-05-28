#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TGraph {
public:
	vector<vector<int>> AdjacencyMatrix; //������� ���������
	vector<int> NTable; //������� ������� ������
	vector<vector<int>> ChTable; //������� ��������
	vector<int> LowTable; //������� ����������� ������� ������� ������ � ������ � ������� �� ������ �� ����, ���������� ����� ������
	TGraph(int n) { //�����������
		for (int i = 0; i < n; i++) {
			AdjacencyMatrix.push_back(vector<int>());
			//AdjTable.push_back(vector<int>());
			//NTable.push_back(-1);
			ChTable.push_back(vector<int>());
			//LowTable.push_back(-1);

			for (int j = 0; j < n; j++) {
				AdjacencyMatrix[i].push_back(0);//��������� ������

			}
		}

	}

	void InitAdjMatrix(int num); //����������� ����
	void HingesSearch(int curr, vector<int>& nodes); //����� � �������
	void HingesSearchStart(); //����� ����������� ����� � �������
	bool IsZeroInVector(vector<int> vec, int& notConnectNode);
	bool IsChild(int currNode, int parrentNode);
	int MinAdjV(int node); //���� ������� ������� � ����������� ������� 
	void MinNumChild(int node, int& min);
	int Low(int node);
	void SetLowTable();
	bool IsConnectedGraph(int& notConnectNode);
	void InputMatrix(int node, int prob);
	void PrintMatrix(); //����� �������
	void PrintTable(); //����� ������
	void PrintHinges(); //����� ��������

};