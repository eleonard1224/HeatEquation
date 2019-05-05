/*
 * HeatEquation.h
 *
 *  Created on: May 4, 2019
 *      Author: eleonard
 */

#ifndef HEATEQUATION_H_
#define HEATEQUATION_H_


#include "Inputs.h"
#include "Grid.h"
#include "HeatSolver.h"

class HeatEquation: public HeatSolver, public Grid {

public:

/*	HeatEquation(const Grid& grid, int nt_steps_h = 50, double t0_h = 0.0,
			double tend_h = 0.1, double alpha_h = 1.0,
			int n_pts_h = 100, double x_left_h = 0.0, double x_right_h = 1.0)
: HeatSolver(grid), Inputs(nt_steps_h,t0_h,tend_h,alpha_h,n_pts_h,x_left_h,x_right_h) {};*/

	HeatEquation(const Grid& grid) : HeatSolver(grid) {};
	// ~HeatEquation() {};

	void solve_heat_equation(){finite_difference_solution();};



};

#endif /* HEATEQUATION_H_ */
