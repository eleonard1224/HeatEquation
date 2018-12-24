#ifndef _HEAT_SOLVER__H
#define _HEAT_SOLVER__H

#include "heat_equation.h"
#include "grid.h"

#include <stdio.h>

class heat_solver : public grid {

public:

	// Functions

	heat_solver(grid& Grid, solver_inputs *solverInputs);

	~heat_solver();

	void print_solver();

	void print_time();

	void set_time();

	void set_initial_condition();

	void solve_heat_equation();

	// Variables

private:

	// Functions

	void sine_initial_condition();

	void finite_difference_solution();

	double get_dx();

	double get_dt();

	void identity_matrix(double **I, int n);

	void finite_difference_matrix(double **M, int n);

	void gaussian_elimination(int n, double **A, double *x, double *b);

	void matrix_row_exchange(int n, double **A, int i, int j);

	void vector_row_exchange(int n, double *b, int i, int j);

	// Variables

	double *t;

	double **u;

};

#endif