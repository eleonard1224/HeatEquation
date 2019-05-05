/*
 * HeatSolver.cpp
 *
 *  Created on: May 4, 2019
 *      Author: eleonard
 */

#include "HeatSolver.h"

HeatSolver::HeatSolver(const Grid &grid) {

	int i;

	x = NULL;
	t = NULL;
	u = NULL;

	x = (double *) calloc(n_pts, sizeof *x);
	double dx = (x_right-x_left)/(((double) n_pts)-1.0);

	for(vector<double>::const_iterator it = grid.x.begin(); it != grid.x.end(); ++it) {
		i = distance(grid.x.begin(),it);
		x[i] = x_left + dx*i;
	}

	t = (double *) calloc(nt_steps, sizeof *t);

	u = (double **) calloc(n_pts, sizeof *u);

	for(i = 0; i < n_pts; i++) {
		u[i] = (double *) calloc(nt_steps, sizeof **u);
	}

	set_time();

	set_initial_condition();

}


HeatSolver::~HeatSolver() {

	int i;

	for(i = 0; i < n_pts; i++) {
		free(u[i] );
	}

	free(x);
	free(u);
	free(t);
}


void HeatSolver::print_solver() {

	int i, j;
	FILE *fptr;
	fptr = fopen( "u", "w" );
	for(i = 0; i < n_pts; i++) {
		for(j = 0; j < nt_steps; j++) {
			if(j != (nt_steps-1)) {
				fprintf( fptr, "%f ", u[i][j] );
			}
			else {
				fprintf( fptr, "%f\n", u[i][j] );
			}
		}
	}
	fclose( fptr );

}

void HeatSolver::print_time() {

	int i;
	FILE *fptr;

	fptr = fopen( "t", "w" );

	for(i = 0; i < nt_steps; i++) {
		fprintf( fptr, "%f\n", t[i] );
	}

	fclose( fptr );

}

void HeatSolver::set_time() {

	int i;
	double nt_steps_double, dt;

	nt_steps_double = (double) nt_steps;
	dt = (tend-t0)/(nt_steps_double-1.0);

	for(i = 0; i < nt_steps; i++) {
		t[i] = t0 + dt*i;
	}

}

void HeatSolver::set_initial_condition() {

	sine_initial_condition();
}

/*void HeatSolver::solve_heat_equation() {

	finite_difference_solution();

}*/

// Defining the private functions

void HeatSolver::sine_initial_condition() {

	int i;
	const double pi = 4.0*atan(1.0);

	for(i = 0; i < n_pts; i++) {
		u[i][0] = sin(pi*x[i]);
	}
}

void HeatSolver::finite_difference_solution() {

	int i, j, p, r;
	int n = n_pts - 2;
	double lambda, dt, dx;
	double **I = NULL; // I is the identity matrix
	double **M = NULL; // M is the finite difference matrix
	double **IM = NULL; // IM contains I - lambda*M
	double *temp_u1 = NULL;
	double *temp_u2 = NULL;


	// Allocating the matrices
	I = (double **) calloc(n, sizeof(*I));
	M = (double **) calloc(n, sizeof(*M));
	IM = (double **) calloc(n, sizeof(*IM));
	for(i = 0; i < n; i++) {
		I[i] = (double *) calloc(n, sizeof(**I));
		M[i] = (double *) calloc(n, sizeof(**M));
		IM[i] = (double *) calloc(n, sizeof(**IM));
		temp_u1 = (double *) calloc(n, sizeof(*temp_u1));
		temp_u2 = (double *) calloc(n, sizeof(*temp_u2));
	}


	// Filling up the matrices and getting the relevant variables
	identity_matrix(I, n);
	finite_difference_matrix(M, n);
	dx = get_dx();
	dt = get_dt();
	lambda = (alpha*dt)/(dx*dx);
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			IM[i][j] = I[i][j] - lambda*M[i][j];
		}
	}

	// Solving for u
	for(j = 1; j < nt_steps; j++) {
		for(i = 0; i < n; i++) {
			temp_u1[i] = u[i+1][j-1];
		}

		gaussian_elimination(n, IM, temp_u2, temp_u1);

		for(p = 0; p < n; p++) {
			for(r = 0; r < n; r++) {
				IM[p][r] = I[p][r] - lambda*M[p][r];
			}
		}

		for(i = 0; i < n; i++) {
			u[i+1][j] = temp_u2[i];
		}
	}


	// Freeing the matrices
	for(i = 0; i < n; i++) {
		free(I[i]);
		free(M[i]);
		free(IM[i]);
	}
	free(I);
	free(M);
	free(IM);
	free(temp_u1);
	free(temp_u2);

}


double HeatSolver::get_dx() {

	double dx;
	double n_pts_double;

	n_pts_double = (double) n_pts;
	dx = (x_right - x_left)/(n_pts_double - 1.0);

	return dx;
}

double HeatSolver::get_dt() {

	double dt;
	double nt_steps_double;

	nt_steps_double = (double) nt_steps;
	dt = (tend - t0)/(nt_steps_double - 1.0);

	return dt;
}

void HeatSolver::identity_matrix(double **I, int n) {

	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(i == j) {
				I[i][j] = 1.0;
			}
			else {
				I[i][j] = 0.0;
			}
		}
	}
}


void HeatSolver::finite_difference_matrix(double **M, int n) {

	int i, j;

	// Filling up the top and bottom rows
	for(i = 0; i < n; i++) {
		M[0][i] = 0.0;
		M[n-1][i] = 0.0;
	}
	M[0][0] = -2.0;
	M[0][1] = 1.0;
	M[n-1][n-2] = 1.0;
	M[n-1][n-1] = -2.0;

	// Filling up the rows in between
	for(i = 1; i < n-1; i++) {
		M[i][i-1] = 1.0;
		M[i][i] = -2.0;
		M[i][i+1] = 1.0;
	}
}


/* Gaussian elimination with partial pivoting */
void HeatSolver::gaussian_elimination(int n, double **A, double *x, double *b) {

	int i, j, k;
	double multiplier;
	double max_value;
	int max_index;

	for (i = 0; i < n; i++) {
		max_value = A[i][i];
		max_index = i;

		/* Getting the row index of the largest pivot */
		for (j = (i+1); j < n; j++) {
			if (A[j][i] > max_value) {
				max_value = A[j][i];
				max_index = j;
			}
		}

		/* Row exchanges in A and b */
		matrix_row_exchange(n, A, i, max_index);
		vector_row_exchange(n, b, i, max_index);

		/* Using the pivot to clear out the entries beneath it */
		for (j = (i+1); j < n; j++) {
			multiplier = A[j][i]/A[i][i];
			for (k = i; k < n; k++) {
				A[j][k] = A[j][k] - multiplier*A[i][k];
			}
			b[j] = b[j] - multiplier*b[i];
		}

	}

	/* Now have A in row echelon form, next do back substitution */
	x[n-1] = b[n-1]/A[n-1][n-1];
	for (i = (n-2); i >= 0; i--) {
		for (j = (n-1); j >= (i+1); j--) {
			b[i] = b[i] - A[i][j]*x[j];
			x[i] = b[i]/A[i][i];
		}
	}
}


/* matrix_row_exchange exchanges rows i and j of an n x n matrix */
void HeatSolver::matrix_row_exchange(int n, double **A, int i, int j) {

	int k;
	double *row_i = NULL;
	double *row_j = NULL;

	row_i = (double *) calloc(n, sizeof(*row_i));
	row_j = (double *) calloc(n, sizeof(*row_j));

	for (k = 0; k < n; k++) {
		row_i[k] = A[i][k];
		row_j[k] = A[j][k];
	}

	for (k = 0; k < n; k++) {
		A[i][k] = row_j[k];
		A[j][k] = row_i[k];
	}
}

/* vector_row_exchange exchanges entries i and j of an n x 1 vector */
void HeatSolver::vector_row_exchange(int n, double *b, int i, int j) {

	double entry_i;
	double entry_j;

	entry_i = b[i];
	entry_j = b[j];

	b[i] = entry_j;
	b[j] = entry_i;
}







