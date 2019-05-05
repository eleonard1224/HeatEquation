/*
 * HeatEquation.cpp
 *
 *  Created on: May 4, 2019
 *      Author: eleonard
 */

#include <iostream>
#include <stdlib.h>

#include "HeatEquation.h"
using namespace std;



int main() {

	Grid grid;
	grid.print_grid();
	HeatEquation heatequation(grid);
	heatequation.solve_heat_equation();
	heatequation.print_time();
	heatequation.print_solver();


	return 0;
}
