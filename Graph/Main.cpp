#include "TGraph.h"
#include <iostream>
#include <time.h>
#include <ctime>
#include <fstream>
#include "gnuplot.h"
using namespace std;

void Test1(int start, int end, int step)
{
	int n = 0;
	int prob = 99; // Шанс выпадения 0 в матрице
	fstream fout("C:\\Users\\Nadya\\source\\repos\\Graph\\Results.txt"); // Поток для записи

	/*if (fout.is_open())
	{
		cout << "Open!";
	}*/

	srand(time(NULL));
	for (n = start; n <= end; n += step)
	{
		cout << endl;
		cout << "N : " << n << endl;
		fout << n << "	";
		TGraph A(n);
		A.InputMatrix(n, prob);
		unsigned int start_time = clock();
		A.HingesSearchStart();
		cout << endl;
		A.SetLowTable();
		unsigned int end_time = clock();
		unsigned int search_time = end_time - start_time;
		A.PrintHinges();
		cout << endl;
		cout << endl << "Time : " << (double)(search_time) / 1000 << endl;
		fout << (double)(search_time) / 1000 << endl;
		cout << endl;
	}
	fout.close();
}


void Test2(int start, int end, int step)
{
	double sumtime = 0;
	int count = 0;
	int n = 0;
	int prob = 99; // Шанс выпадения 0 в матрице
	fstream fout("C:\\Users\\Nadya\\source\\repos\\Graph\\Results.txt");
	
	srand(time(NULL));

	for (n = start; n <= end; n += step)
	{
		fout << n << "	";
		while (count < n)
		{
			TGraph A(n);
			A.InputMatrix(n, prob);
			unsigned int start_time = clock();
			A.HingesSearchStart();
			A.SetLowTable();
			unsigned int end_time = clock();
			unsigned int search_time = end_time - start_time;
			sumtime = sumtime + (double)(search_time) / 1000;
			//fout << (double)(search_time) / 1000 << endl;
			count++;
		}
		cout << "Average time for " << n << " ver : " << sumtime / n << endl;
		fout << sumtime / n << endl;
		count = 0;
		sumtime = 0;
	}

	fout.close();
}

void main()
{
	int k;
	cout << "1.Test1;\n";
	cout << "2.Test2;\n";
	/*cout << "\n";
	cout << "1.Matrix;\n";
	cout << "2.List;\n";*/
	cout << "Enter:";
	cin >> k;
	switch (k)
	{
	case 1:
	{
		int start = 0;
		int end = 0;
		int step = 0;
		cout << "Enter start, end, step :" << " ";
		cout << endl;
		cin >> start;
		//cout << "Enter end :" << " ";
		cin >> end;
		//cout << "Enter step :" << " ";
		cin >> step;


		

		Test1(start, end, step);

		gnuplot g;

		g("set title \"The search of hinges\"");
		g("set title  font \",20\" norotate"); //размер шрифта

		g("set ylabel \"Time (sec)\"");//название оси y
		g("set ylabel  font \",15\"");//шрифт размер

		g("set xlabel \"Number of nodes\"");//название оси x
		g("set xlabel  font \",15\"");//шрифт  
		//C:\\Users\\Nadya\\source\\repos\\Graph
		g("plot \"C:/Users/Nadya/source/repos/Graph/Results.txt\" with lines, \"C:/Users/Nadya/source/repos/Graph/Results.txt\" with points, \"C:/Users/Nadya/source/repos/Graph/Results.txt\" with impulses");//вывод графика
		break;
	}
	case 2:
	{
		int start = 0;
		int end = 0;
		int step = 0;
		//cout << "Enter vertex, edges:" << " ";
		cout << "Enter start, end, step :" << " ";
		cout << endl;
		cin >> start;
		cin >> end;
		cin >> step;
		cout << endl;
		Test2(start, end, step);
		gnuplot g;

		g("set title \"The search of hinges\"");
		g("set title  font \",20\" norotate"); //размер шрифта

		g("set ylabel \"Time (sec)\"");//название оси y
		g("set ylabel  font \",15\"");//шрифт размер

		g("set xlabel \"Number of nodes\"");//название оси x
		g("set xlabel  font \",15\"");//шрифт

		//g("plot \"D:/StrelnikovaGraph/Results.txt\" with lines, \"D:/StrelnikovaGraph/Results.txt\" with points, \"D:/StrelnikovaGraph/Results.txt\" with impulses");//вывод графика
		g("plot \"C:/Users/Nadya/source/repos/Graph/Results.txt\" with lines, \"C:/Users/Nadya/source/repos/Graph/Results.txt\" with points, \"C:/Users/Nadya/source/repos/Graph/Results.txt\" with impulses");//вывод графика
	
		break;
	}
	}
	return;
}


