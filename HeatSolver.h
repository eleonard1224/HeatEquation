/*
 * HeatSolver.h
 *
 *  Created on: May 4, 2019
 *      Author: eleonard
 */

#ifndef HEATSOLVER_H_
#define HEATSOLVER_H_

#include <stdlib.h>
#include <math.h>

#include "Inputs.h"
#include "Grid.h"


class HeatSolver : virtual public Inputs {

public:

	HeatSolver(const Grid &grid);
	virtual ~HeatSolver();

	void print_solver();

	void print_time();

	void set_time();

	void set_initial_condition();

//	void solve_heat_equation();

protected:

	void finite_difference_solution();


private:

	// Private Functions

	void sine_initial_condition();

//	void finite_difference_solution();

	double get_dx();

	double get_dt();

	void identity_matrix(double **I, int n);

	void finite_difference_matrix(double **M, int n);

	void gaussian_elimination(int n, double **A, double *x, double *b);

	void matrix_row_exchange(int n, double **A, int i, int j);

	void vector_row_exchange(int n, double *b, int i, int j);

	// Private Variables

//	Grid grid;

	double *x; // separate copy of the grid points

	double *t;

	double **u;


};



#endif /* HEATSOLVER_H_ */
