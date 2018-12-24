#ifndef _GRID__H
#define _GRID__H

#include "heat_equation.h"

class grid {

public:

	// Functions

	grid(solver_inputs *solverInputs);

	~grid();

	void print_grid();

	void set_grid(solver_inputs *solverInputs);

protected:

	// Methods

	// Variables

	int nt_steps;
	double t0;
	double tend;
	double alpha;
	int n_pts;
	double x_left;
	double x_right;
	double *x;

private:

	// Methods

	void grid_points(solver_inputs *solverInputs);

};

#endif