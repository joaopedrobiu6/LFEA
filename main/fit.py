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

data = read("../rend.txt")
print(data)


def func(x, a, b):
    return a*x + b


popt, pcov = curve_fit(func, x, y, sigma=sqrt(y))
