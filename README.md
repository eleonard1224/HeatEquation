# HeatEquation
C++ code to solve the 1D heat equation

This repository contains C++ code to solve the 1D heat equation du/dt = d^2 u/ dx^2  in the domain 0 <= x <= 1, 0 <= t < infinity subject to the boundary conditions u(x=0,t) = u(x=1,t) = 0 and the initial condition u(x,t=0) = sin(pi * x).  The class structure is outlined in HeatEquationClassStructure.pdf and the main method for the C++ code is in main.cpp.  A plot of the solution to the pde at three different time steps is available in HeatEquation.pdf.
