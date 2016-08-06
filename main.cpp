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

int main()
{
////	RungeKutta/Euler example
////	std::vector <double> yInitial = {0.8, 2.0};

////	double a = 0.0;
////	double b = 1.0;

////	double h = 0.000001;

////	int    nSteps = int((b - a) / h);

////	System system;
////	State  state(1, 2, nSteps);

////	RungeKuttaSolver rungeKuttaSolver(system, state, a, b, h, yInitial);
////	//EulerSolver eulerSolver(system, state, a, b, h, yInitial);
////	for (int i = 0; i < nSteps; i++) {
////	 rungeKuttaSolver.solve();
////	  //eulerSolver.solve();
////	}

////	for (int i = 0; i < nSteps; i++) {
////	  std::cout << (a + i * h) << "  y1 = " << state(0, 0, i)
////				<< "  y2 = " << state(0, 1, i) << std::endl;
////	}
//// Godunov's example

	const double zero = 0.0;

	double courantNumber;
//	std::cout << "Courant number = ";
//	std::cin >> courantNumber;

	int nPeriods;
//	std::cout << "number of periods = ";
//	std::cin >> nPeriods;

//	standart input
	courantNumber = 1.0;
	nPeriods = 1.0;
	double a = 0.0;
	double b = 20.0;
	double time = 0.05;

	double rho = 1.225;
	double c = 10.0;
	double K   = c * c * rho;

	double h = 0.001;

	double tau = (courantNumber * h) / c;

//	std::cout << "tau = " << tau << std::endl;
//	std::cout << "continue?" << std::endl;

//	char answer;
//	std::cin >> answer;
//	if (answer == 'n')
//		return 0;

	// floor or sell
	int nSteps = int((b - a) / h);
	int timeSteps = int (time/tau);

	System system;
	for (int i = 0; i < nSteps; i++)
	{
			system.rho.push_back(rho);
			system.K.push_back(K);
			system.c.push_back(c);

//			auto func = [system](double d) {
//				return d * d * system.rho.back();
//			};
//			std::cout << func(1) << std::endl;
	}


//	State initialState (nSteps, 2, 1);
//	for (int i = 0; i < initialState.iSize(); i++)
//	{
//		// ? to make vector form
//		initialState(i, 0, 0) = sin (((i * h) / (b - a)) * 2.0 * M_PI * nPeriods) * system.c[i];
//		initialState(i, 1, 0) = sin (((i * h) / (b - a)) * 2.0 * M_PI * nPeriods) / system.rho[i];
//	}



//	std::vector <State> state(timeSteps, initialState);
////	state.push_back(initialState);

//	std::system("rm /home/bobo/data/*.vtr");
//	std::system("rm /home/bobo/data/*.pvtr");

//	std::string name = "part0_";
//	std::string pName = "part0_";
//	double testF, testD;

//	GodunovSolver godunovSolver (system, state, a, b, h, tau);
//		for (int t = 0; t < timeSteps - 1; t++)
//		{
//			testF = state[t](10,0,0);
//			testD = state[t+1](10,0,0);


//		 godunovSolver.solve();

//		 testF = state[t](10,0,0);
//		 testD = state[t+1](10,0,0);

//		 name = "part0_";
//		 name += std::to_string(t + 1);
//		 name += ".vtr";
////		 std::cout << name << std::endl;

//		 pName = "file";
//		 pName += std::to_string(t + 1);
//		 pName += ".pvtr";
////		 std::cout << pName << std::endl;
//	// multiplatforming through system calls
//		 std::ofstream foutP("/home/bobo/data/" + pName);
////		 std::setiosflags(std::ios_base::scientific);
//		 foutP  << "<?xml version=\"1.0\"?>\n" <<
//				 "<VTKFile type=\"PRectilinearGrid\" version=\"0.1\" byte_order=\"LittleEndian\">\n" <<
//				 "<PRectilinearGrid WholeExtent=\"0 20 0 8 0 8\" GhostLevel=\"0\">\n" <<
//				 "<PPointData></PPointData>\n" <<
//				 "<PCellData>\n" <<
//					 "\t<PDataArray Name=\"p\" NumberOfComponents=\"3\" type=\"Float32\"/> \n" <<
//				 "</PCellData>\n" <<
//				 "<PCoordinates>\n" <<
//					 "\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
//					 "\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
//					 "\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
//				 "</PCoordinates>\n" <<
//				 "<Piece Extent=\"0 20 0 8 0 8\" Source=\"" << name << "\" />\n" <<
//				 "</PRectilinearGrid>\n" <<
//				 "</VTKFile>";
//		 foutP.close();
//		 std::ofstream foutN("/home/bobo/data/" + name);
//		 foutN.precision(2);
//		 foutN  << "<?xml version=\"1.0\"?>\n" <<
//				 "<VTKFile type=\"RectilinearGrid\" version=\"0.1\" byte_order=\"LittleEndian\">\n" <<
//				 "<RectilinearGrid WholeExtent=\"0 20 0 8 0 8\">\n" <<
//				 "<Piece Extent=\"0 20 0 8 0 8\">\n" <<
//				 "<PointData>\n" <<
//				  "</PointData>\n" <<
//				 "<CellData>\n" <<
//				 "\t<DataArray Name=\"p\" NumberOfComponents=\"3\" type=\"Float32\">\n"
//				  << "\t\t";
//				 for (int i = 0; i < initialState.iSize(); i++)
//				 {

//				  foutN << std::scientific << state[t](i, 0, 0) << " " << zero << " " << zero << " ";
//				 }
//				 foutN << "\n";
//				 foutN << "</DataArray>\n" << "</CellData>\n"<<
//				 "<Coordinates>\n" <<
//				 "\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">\n" <<
//				 "\t\t0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20\n" <<
//				 "</DataArray>\n"
//				 "\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">\n" <<
//				 "\t\t0 1 2 3 4 5 6 7 8 \n" <<
//				 "</DataArray>\n" <<
//				 "\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">0 1 2 3 4 5 6 7 8</DataArray>\n" <<
//				 "</Coordinates>\n" <<
//				 "</Piece>\n" <<
//				 "</RectilinearGrid>\n" <<
//				 "</VTKFile>\n";
//				 foutN.close();
//		}

//		name = "part0_0.vtr";
//		pName = "file0.pvtr";
//		std::ofstream foutP("/home/bobo/data/" + pName);
//		foutP  << "<?xml version=\"1.0\"?>\n" <<
//				"<VTKFile type=\"PRectilinearGrid\" version=\"0.1\" byte_order=\"LittleEndian\">\n" <<
//				"<PRectilinearGrid WholeExtent=\"0 20 0 8 0 8\" GhostLevel=\"0\">\n" <<
//				"<PPointData></PPointData>\n" <<
//				"<PCellData>\n" <<
//					"\t<PDataArray Name=\"p\" NumberOfComponents=\"3\" type=\"Float32\"/> \n" <<
//				"</PCellData>\n" <<
//				"<PCoordinates>\n" <<
//					"\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
//					"\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
//					"\t<PDataArray NumberOfComponents=\"1\" type=\"Float32\"/>\n" <<
//				"</PCoordinates>\n" <<
//				"<Piece Extent=\"0 20 0 8 0 8\" Source=\"" << name << "\" />\n" <<
//				"</PRectilinearGrid>\n" <<
//				"</VTKFile>";
//		foutP.close();

//		std::ofstream foutN("/home/bobo/data/" + name);
//		foutN.precision(2);
//		foutN  << "<?xml version=\"1.0\"?>\n" <<
//				"<VTKFile type=\"RectilinearGrid\" version=\"0.1\" byte_order=\"LittleEndian\">\n" <<
//				"<RectilinearGrid WholeExtent=\"0 20 0 8 0 8\">\n" <<
//				"<Piece Extent=\"0 20 0 8 0 8\">\n" <<
//				"<PointData>\n" <<
//				 "</PointData>\n" <<
//				"<CellData>\n" <<
//				"\t<DataArray Name=\"p\" NumberOfComponents=\"3\" type=\"Float32\">\n"
//				 << "\t\t";
//				for (int i = 0; i < initialState.iSize(); i++)
//				{

//				 foutN << std::scientific << state[0](i, 0, 0) << " " << zero << " " << zero << " ";
//				}
//				foutN << "\n";
//				foutN << "</DataArray>\n" << "</CellData>\n"<<
//				"<Coordinates>\n" <<
//				"\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">\n" <<
//				"\t\t0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20\n" <<
//				"</DataArray>\n"
//				"\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">\n" <<
//				"\t\t0 1 2 3 4 5 6 7 8\n" <<
//				"</DataArray>\n" <<
//				"\t<DataArray NumberOfComponents=\"1\" type=\"Float32\">0 1 2 3 4 5 6 7 8</DataArray>\n" <<
//				"</Coordinates>\n" <<
//				"</Piece>\n" <<
//				"</RectilinearGrid>\n" <<
//				"</VTKFile>\n";
//				foutN.close();
State state(1,1,1);
state(0,0,0) = 1;
State state1(state);
State state2(0,0,0);
state2 = state;
std::cout << state1(0,0,0) << " " << state2(0,0,0);
	return 0;
}
