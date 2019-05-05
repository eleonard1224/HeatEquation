# Plots u(x,t) at three specified time steps
# The files 'x', 't', and 'u' have to be saved as 
# Excel files with each data entry in each of the files
# belonging to its own cell in the Excel file

# Specify time steps to plot
ts1 = 0
ts2 = 25
ts3 = 45 


# Importing libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Reading in the data
df_x = pd.read_excel('x.xlsx', 'x', header=None)
df_t = pd.read_excel('t.xlsx', 't', header=None) 
df_u = pd.read_excel('u.xlsx', 'u', header=None) 
   
# Creating matrcies for x, t, and u
x = df_x.values 
t = df_t.values 
u = df_u.values
   
# Getting t and u data for the three specified time steps
t1 = t[ts1]; u1 = u[:,ts1] 
t2 = t[ts2]; u2 = u[:,ts2] 
t3 = t[ts3]; u3 = u[:,ts3] 
   
# Printing the time at which the time steps occur
print("t1 = " + str(t1))
print("t2 = " + str(t2))
print("t3 = " + str(t3))
   
# Plotting u(x,t1), u(x,t2), u(x,t3) 
f1 = plt.figure(1)
plt.plot(x, u1, color = 'b') 
plt.plot(x, u2, color = 'g') 
plt.plot(x, u3, color = 'r')
plt.xlabel('x')
plt.ylabel('u')
# f1.savefig("heat_equation.pdf", bbox_inches='tight')
plt.show()