#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Solver.h"
#include "GodunovSolver.h"
//#include "EulerSolver.h"
//#include "RungeKuttaSolver.h"

int main()
{
//	RungeKutta/Euler example
//	std::vector <double> yInitial = {0.8, 2.0};

//	double a = 0.0;
//	double b = 1.0;

//	double h = 0.000001;

//	int    nSteps = int((b - a) / h);

//	System system;
//	State  state(1, 2, nSteps);

//	RungeKuttaSolver rungeKuttaSolver(system, state, a, b, h, yInitial);
//	//EulerSolver eulerSolver(system, state, a, b, h, yInitial);
//	for (int i = 0; i < nSteps; i++) {
//	 rungeKuttaSolver.solve();
//	  //eulerSolver.solve();
//	}

//	for (int i = 0; i < nSteps; i++) {
//	  std::cout << (a + i * h) << "  y1 = " << state(0, 0, i)
//				<< "  y2 = " << state(0, 1, i) << std::endl;
//	}
// Godunov's example

	double a = 0.0;
	double b = 10.0;
	double time = 3.0;

	double h = 0.01;
	double tau = 1;

	int nSteps = int((b - a) / h);
	int timeSteps = int (time/tau);
	System system;

	std::cout << "1" << std::endl;

	for (int i = 0; i < nSteps; i++)
	{
			system.rho.push_back(1000);
			system.K.push_back(1000);
			system.c.push_back(sqrt(1000/1000));

//			auto func = [system](double d) {
//				return d * d * system.rho.back();
//			};
//			std::cout << func(1) << std::endl;
	}


	State initialState (nSteps, 2, 1);
	for (int i = 0; i < initialState.iSize(); i++)
	{
//		if (i < 50)
//		{
//			initialState(i, 0, 0) = 100.0;
//			initialState(i, 1, 0) = 100.0;
//		}

//		else
//		{
//			initialState(i, 0, 0) = 50.0;
//			initialState(i, 1, 0) = 50.0;
//		}

		// ?
		initialState(i, 0, 0) = sin(3.14 / 4.0 * i) * system.c[i];
		initialState(i, 1, 0) = sin(3.14 / 4.0 * i) / system.rho[i];
	}

		std::cout << "3" << std::endl;

	std::vector <State> state (timeSteps, initialState);

	std::string name = "part0_";
	std::string pName = "part0_";
	GodunovSolver godunovSolver (system, state, a, b, h, tau);
		for (int t = 0; t < timeSteps - 1; t++)
		{
		 godunovSolver.solve();

		 name = "part0_";
		 name += std::to_string(t);
		 name += ".vtr";
		 std::cout << name << std::endl;

		 pName = "part0_";
		 pName += std::to_string(t);
		 pName += ".pvtr";
		 std::cout << pName << std::endl;

		 std::ofstream foutP(pName);
		 foutP << "<?xml version=\"1.0\"?>\n" <<
				 "<VTKFile type=\"PRectilinearGrid\" version=\"0.1\" byte_order=\"LittleEndian\">\n" <<
				 "<PRectilinearGrid WholeExtent=\"0 160 0 120 0 8\" GhostLevel=\"0\">\n" <<
				 "<PPointData></PPointData>\n" <<
				 "<PCellData>\n" <<
					 "\t<PDataArray Name=\"v\" NumberOfComponents=\"3\" type=\"Float32\"/> \n" <<
				 "</PCellData>\n" <<
				 "<PCoordinates>\n" <<
					 "\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
					 "\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
					 "\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
				 "</PCoordinates>\n" <<
				 "<Piece Extent=\"0 160 0 120 0 8\" Source=\"" << name << "\" />\n" <<
				 "</PRectilinearGrid>\n" <<
				 "</VTKFile>";
		 foutP.close();

		 std::ofstream foutN(name);
		 foutN << "<?xml version=\"1.0\"?>\n" <<
				 "<VTKFile type=\"RectilinearGrid\" version=\"0.1\" byte_order=\"LittleEndian\">\n" <<
				 "<RectilinearGrid WholeExtent=\"0 160 0 120 0 8\">\n" <<
				 "<Piece Extent=\"0 160 0 120 0 8\">\n" <<
				 "<PointData>\n" <<
				  "</PointData>\n" <<
				 "<CellData>\n" <<
				 "\t<DataArray Name=\"v\" NumberOfComponents=\"3\" type=\"Float32\">\n"
				  << "\t\t";
				 for (int i = 0; i < initialState.iSize(); i++)
				 {
				  foutN << state[t+1](i, 0, 0) << " ";
				 }
				 foutN << "\n";
				 foutN << "</DataArray>\n" << "</CellData>\n"<<
				 "<Coordinates>\n" <<
				 "\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">\n" <<
				 "\t\t0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 153 154 155 156 157 158 159 160\n" <<
				 "</DataArray>\n"
				 "\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">\n" <<
				 "\t\t0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120\n" <<
				 "</DataArray>\n" <<
				 "\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">0 1 2 3 4 5 6 7 8</DataArray>\n" <<
				 "</Coordinates>\n" <<
				 "</Piece>\n" <<
				 "</RectilinearGrid>\n" <<
				 "</VTKFile>\n";
				 foutN.close();
		}


	//


	std::cout << "0" << std::endl;
	return 0;
}
