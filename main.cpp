#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>


#include "Solver.h"
#include "GodunovSolver.h"

//#include "EulerSolver.h"
//#include "RungeKuttaSolver.h"


const std::string rangeString(int range);

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

	double a    = 0.0;
	double b    = 20.0;
	double time = 1000.0;

	int xGridSize = 8;
	int yGridSize = 8;
	int zGridSize = 8;

	double rho = 1.225;
	double c   = 10.0;
	double K   = c * c * rho;

	double courantNumber = 1;

	int nPeriods = 1;

	double h   = 0.01;
	double tau = (courantNumber * h) / c ;

	double zero = 0.0;

	int nSteps    = int((b - a) / h);
	int timeSteps = int (time/tau);

	System system;

	for (int i = 0; i < nSteps; i++)
	{
	 system.rho.push_back(rho);
	 system.K.  push_back(K);
	 system.c.  push_back(c);
	}


	State initialState (nSteps, 2, 1);
	for (int i = 0; i < initialState.iSize(); i++)
	{
		initialState(i, 0, 0) = 1000.0 * sin (((i * h) / (b - a)) * 2.0 * M_PI * nPeriods) * system.c[i];
		initialState(i, 1, 0) = 1000.0 * sin (((i * h) / (b - a)) * 2.0 * M_PI * nPeriods) / system.rho[i];
//		if ((i+1) % 2)
//		{
//			initialState(i, 0, 0) = 1000;
//			initialState(i, 1, 0) = 1000;
//		}
//		else
//		{
//			initialState(i, 0, 0) = 0;
//			initialState(i, 1, 0) = 0;
//		}
	}

	std::vector <State> state (timeSteps, initialState);
	GodunovSolver godunovSolver (system, state, a, b, h, tau);

	std::string name  = "part0_";
	std::string pName = "part0_";

	std::system("rm /home/bobo/data/*.vtr");
	std::system("rm /home/bobo/data/*.pvtr");

	for (int t = 0; t < timeSteps - 1; t++)
	{
	 godunovSolver.solve();

	 name = "part0_";
	 name += std::to_string(t);
	 name += ".vtr";

	 pName = "file";
	 pName += std::to_string(t);
	 pName += ".pvtr";

	 std::ofstream foutP("/home/bobo/data/" + pName);
	 foutP  << "<?xml version=\"1.0\"?>\n" <<
	 "<VTKFile type=\"PRectilinearGrid\" version=\"0.1\" byte_order=\"LittleEndian\">\n" <<
	 "<PRectilinearGrid WholeExtent=\"0 " << xGridSize <<" 0 " << yGridSize <<  " 0 " << zGridSize << "\" GhostLevel=\"0\">\n" <<
	 "<PPointData></PPointData>\n" <<
	 "<PCellData>\n" <<
		 "\t<PDataArray Name=\"p\" NumberOfComponents=\"3\" type=\"Float32\"/> \n" <<
	 "</PCellData>\n" <<
	 "<PCoordinates>\n" <<
		 "\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
		 "\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
		 "\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
	 "</PCoordinates>\n" <<
	 "<Piece Extent=\"0 " << xGridSize << " 0 " << yGridSize << " 0 " << zGridSize << "\" Source=\"" << name << "\" />\n" <<
	 "</PRectilinearGrid>\n" <<
	 "</VTKFile>";
	 foutP.close();

	 std::ofstream foutN("/home/bobo/data/" + name);
	 foutN.precision(2);
	 foutN  << "<?xml version=\"1.0\"?>\n" <<
			 "<VTKFile type=\"RectilinearGrid\" version=\"0.1\" byte_order=\"LittleEndian\">\n" <<
			 "<RectilinearGrid WholeExtent=\" 0 " << xGridSize << " 0 " << yGridSize << " 0 " << zGridSize << "\">\n" <<
			 "<Piece Extent=\"0 " << xGridSize << " 0 " << yGridSize << " 0 " << zGridSize << "\">\n" <<
			 "<PointData>\n" <<
			  "</PointData>\n" <<
			 "<CellData>\n" <<
			 "\t<DataArray Name=\"p\" NumberOfComponents=\"3\" type=\"Float32\">\n"
			  << "\t\t";
			 for (int i = 0; i < initialState.iSize(); i++)
			 {

			  foutN << std::scientific << state[t](i, 0, 0) << " " << zero << " " << zero << " ";
			 }
			 foutN << "\n";
			 foutN << "</DataArray>\n" << "</CellData>\n"<<
			 "<Coordinates>\n" <<
			 "\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">\n" <<
			 "\t\t" << rangeString(xGridSize) << "\n" <<
			 "</DataArray>\n"
			 "\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">\n" <<
			 "\t\t" << rangeString(yGridSize) << "\n" <<
			 "</DataArray>\n" <<
			 "\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">" << rangeString(zGridSize) << "</DataArray>\n" <<
			 "</Coordinates>\n" <<
			 "</Piece>\n" <<
			 "</RectilinearGrid>\n" <<
			 "</VTKFile>\n";
			 foutN.close();
	}

	return 0;
}

const std::string rangeString(int range)
{
	std::string rangeString;
	for (int i = 0; i <= range; i++)
	{
	 rangeString += std::to_string(i);
	 rangeString += " ";
	}
	return rangeString;
}
