/*
 * Grid.h
 *
 *  Created on: May 4, 2019
 *      Author: eleonard
 */

#ifndef GRID_H_
#define GRID_H_

#include <iostream>

#include "Inputs.h"
#include <vector>

using namespace std;

class Grid : virtual public Inputs {

public:

	// Public Functions

	Grid();

	virtual ~Grid() {};

	void print_grid();

	void print_grid_points();  // For printing grid points to console

private:

	// Private Methods

	void set_grid();

	// Private Variables

	vector<double> x;

	friend class HeatSolver;

};

#endif /* GRID_H_ */
