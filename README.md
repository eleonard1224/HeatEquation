# HeatEquation
C++ code to solve the 1D heat equation

This repository contains C++ code to solve the 1D heat equation du/dt = d^2 u/ dx^2  in the domain 0 <= x <= 1, 0 <= t < infinity subject to the boundary conditions u(x=0,t) = u(x=1,t) = 0 and the initial condition u(x,t=0) = sin(pi * x).  The main method for the C++ code is in heat_equation.cpp and the Python code heat_equation_output.py plots the solution of the pde for three specified time steps.  In order to run heat_equation_output.py the files outputted from the C++ code, 'x', 't', and 'u', have to be saved as Excel files with each data entry in each of the files belonging to its own cell.  A plot of the solution is available in heat_equation.pdf.
