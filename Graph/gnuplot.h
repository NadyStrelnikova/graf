#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <iostream>
#include <stdio.h>
#include <string>


class gnuplot
{
public:
	gnuplot()
	{
		gnuplotpipe = _popen("C:\\Users\\Nadya\\source\\repos\\Graph\\gnuplot\\bin\\gnuplot.exe -persist", "w");
		if (!gnuplotpipe)
			std::cerr << "gnuplot not found";

	}
	~gnuplot()
	{
		fprintf(gnuplotpipe, "exit\n");
		_pclose(gnuplotpipe);
	}

	void operator () (const std::string& command)
	{
		fprintf(gnuplotpipe, "%s\n", command.c_str());
		fflush(gnuplotpipe);
	}

protected:
	FILE* gnuplotpipe;//поле

};



















#endif // !GNUPLOT_H

#pragma once
