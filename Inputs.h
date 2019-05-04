// For the Inputs class

#ifndef _INPUTS__H
#define _INPUTS__H_

class Inputs {

public:
	Inputs(int nt_steps = 50, double t0 = 0.0, double tend = 0.1, double alpha = 1.0,
			int n_pts = 100, double x_left = 0.0, double x_right = 1.0);

// private:

	int nt_steps;
	double t0;
	double tend;
	double alpha;
	int n_pts;
	double x_left;
	double x_right;

};



#endif /* INPUTS_H_ */
