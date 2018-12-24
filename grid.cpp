#include "grid.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

// Defining the public functions

grid::grid(solver_inputs *solverInputs) {

	nt_steps = solverInputs->nt_steps;
	t0 = solverInputs->t0;
	tend = solverInputs->tend;
	alpha = solverInputs->alpha;
	n_pts = solverInputs->n_pts;
	x_left = solverInputs->x_left;
	x_right = solverInputs->x_right;

	x = NULL;
	x = (double *) calloc(solverInputs->n_pts, sizeof *x);

}

grid::~grid() {

	free(x);

}

void grid::print_grid() {

	int i;
	FILE *fptr;

	fptr = fopen( "x", "w" );

	for(i = 0; i < n_pts; i++) {
		fprintf( fptr, "%f\n", x[i] ); 
	}

	fclose( fptr );

}


void grid::set_grid(solver_inputs *solverInputs) {

	grid_points(solverInputs);
}


// Defining the private functions

void grid::grid_points(solver_inputs *solverInputs) {

	int i;
	double n_pts_double, dx;

	n_pts_double = (double) n_pts;
	dx = (x_right-x_left)/(n_pts_double-1.0);

	for(i = 0; i < n_pts; i++) {
		x[i] = x_left + dx*i;
	}
}