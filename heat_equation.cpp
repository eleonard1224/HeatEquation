#include "heat_equation.h"
#include "heat_solver.h"
#include "grid.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

// Going to test committing changes to local repository and pushing to remote repository

int main() 
{

	// Inputs
	int nt_steps = 50;
	double t0 = 0.0;
	double tend = 0.1;
	double alpha = 1.0;
	int n_pts = 100;
	double x_left = 0.0;
	double x_right = 1.0;

	solver_inputs *solverInputs = NULL;
	solverInputs = (solver_inputs *) calloc(1, sizeof *solverInputs);

	fill_solver_inputs(solverInputs, nt_steps, t0, tend, alpha, n_pts, x_left, x_right);

	grid *gr = new grid(solverInputs);

	gr->set_grid(solverInputs);

	gr->print_grid();

	heat_solver *hs = new heat_solver(*gr, solverInputs);

	hs->set_time();

	hs->print_time();

	hs->set_initial_condition();

	hs->solve_heat_equation();

	hs->print_solver();

	free(solverInputs);
		
    return 0;
}

