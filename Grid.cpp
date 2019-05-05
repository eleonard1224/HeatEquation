/*
 * Grid.cpp
 *
 *  Created on: May 4, 2019
 *      Author: eleonard
 */

#include "Grid.h"

// Defining the public functions

Grid::Grid() {

	x.assign(n_pts,0.0);
	set_grid();

}

// For printing the grid points to the console
void Grid::print_grid_points() {

	int index;
	vector<double>::iterator it;

	for(it = x.begin(); it != x.end(); ++it) {
		index = distance(x.begin(),it);
		cout << "x[" << index << "] = " << *it << endl;
	}
}

void Grid::print_grid() {

	int i;
	FILE *fptr;

	fptr = fopen( "x", "w" );

	for(i = 0; i < n_pts; i++) {
		fprintf( fptr, "%f\n", x[i] );
	}

	fclose( fptr );

}


// Defining the private functions

void Grid::set_grid() {

	int index;
	double n_pts_double, dx;
	vector<double>::iterator it;


	n_pts_double = (double) n_pts;
	dx = (x_right-x_left)/(n_pts_double-1.0);

	for(it = x.begin(); it != x.end(); ++it) {
		index = distance(x.begin(),it);
		*it = x_left + dx*index;
	}


}







