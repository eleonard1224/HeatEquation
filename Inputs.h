/*
 * Inputs.h
 *
 *  Created on: May 4, 2019
 *      Author: eleonard
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <iostream>

using namespace std;

class Inputs {

public:
	Inputs(int nt_steps = 50, double t0 = 0.0, double tend = 0.1, double alpha = 1.0,
			int n_pts = 100, double x_left = 0.0, double x_right = 1.0);


//	Inputs(int nt_steps, double t0, double tend, double alpha,
//			int n_pts, double x_left, double x_right);

	virtual ~Inputs() {};

	void print_nt_steps() {cout << "nt_steps = " << nt_steps << endl;};

protected:

	int nt_steps;
	double t0;
	double tend;
	double alpha;
	int n_pts;
	double x_left;
	double x_right;

};


#endif /* INPUTS_H_ */
