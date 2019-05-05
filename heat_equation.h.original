#ifndef _HEAT_EQUATION__H
#define _HEAT_EQUATION__H

typedef struct solver_inputs {

	int nt_steps;
	double t0;
	double tend;
	double alpha;
	int n_pts;
	double x_left;
	double x_right;

} solver_inputs; 

inline void fill_solver_inputs(solver_inputs *solverInputs, int nt_steps, double t0,
						double tend, double alpha, int n_pts,
						double x_left, double x_right) {

	solverInputs->nt_steps = nt_steps;
	solverInputs->t0 = t0;
	solverInputs->tend = tend;
	solverInputs->alpha = alpha;
	solverInputs->n_pts = n_pts;
	solverInputs->x_left = x_left;
	solverInputs->x_right = x_right;

}

#endif