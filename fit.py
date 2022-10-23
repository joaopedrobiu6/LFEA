from sys import float_repr_style
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

from scipy.optimize import curve_fit


def check_float(potential_float):
    try:
        float(potential_float)
        return True
    except ValueError:
        return False


def read(file_path):

    file = open(file_path, "r")
    leitura = []
    for line in file:
        lido = line.strip().split(";")
        if check_float(lido[0]) == False:
            leitura.append(lido)
        else:
            leitura.append(lido)

    file.close()

    return leitura


data = read("rend.txt")

x = []
y = []
ey = []
for i in range(0, len(data)):
    x.append(float(data[i][0]))
    y.append(float(data[i][1]))
    ey.append(np.sqrt(y[i]))


def func(x, a, b):
    return a*x + b

print(x, y, ey)

popt, pcov = curve_fit(func, x, y, sigma=ey)

plt.errorbar(x, y, yerr=ey, fmt="none")
xfine = np.linspace(0., 2022, 1000)  # define values to plot the function for
#plt.plot(xfine, func(xfine, popt[0], popt[1]), 'r-')

plt.show()
