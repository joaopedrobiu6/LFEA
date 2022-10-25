from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
from math import pi
import numpy as np
import pandas as pd
from scipy.signal import square
from scipy.integrate import quad
from math import *

import csv

from scipy.optimize import curve_fit


def read(filename):
# opening the file in read mode
    my_file = open(filename, "r")
  
# reading the file
    data = my_file.read()
  
# replacing end of line('/n') with ' ' and
# splitting the text it further when '.' is seen.
    data_into_list = data.replace('\n', '').split(";")
  
# printing the data
    print(data_into_list)
    my_file.close()
    return data_into_list


data = read("/home/joaobiu/LFEA/rend.txt")

print(data)


def func(x, a, b):
    return a*x + b



#plt.plot(x, y, '-o', label='data')

#popt, pcov = curve_fit(func, x, y)

#y1 = func(x, *popt)

#plt.plot(x1, y1)

plt.show()
