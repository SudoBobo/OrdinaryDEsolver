#ifndef WRITER_H
#define WRITER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include "State.h"

class Writer
{
public:
	Writer (State & source, std::string generalFileName,
			std::string generalHeaderName, std::string path,
		   int precision, std::vector <int> & gridSize);
	void changePrecision (int newPrecision);
	void write (int stepNumber);
	void clean();

protected:
	State &           m_source;
	const std::string m_generalFileName;
	const std::string m_generalHeaderName;
	const std::string m_path;
	int               m_precision;
	const std::vector <int> & m_gridSize;
};

#endif // WRITER_H
