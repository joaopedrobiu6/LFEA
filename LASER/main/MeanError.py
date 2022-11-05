import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import os


def WeightedMean(X, Y):
    mean = 0
    sumY = 0
    for i in range(0, len(X)):
        mean = mean + X[i] * Y[i]
        sumY = sumY + Y[i]
    return mean / sumY

def error_propagarion(filename):
    X, Y = ReadFile(filename)
    mean = WeightedMean(X, Y)
    sum = 0
    sumY = 0
    for i in range(0, len(Y)):
        sumY += Y[i]
    for i in range(0, len(X)):
        sum += (X[i] - mean) * (X[i] - mean) * Y[i]
    return np.sqrt(sum) / sumY

def ReadFile(filename):
    File_data = np.loadtxt(filename, dtype=float)
    X = File_data[0:, 0]
    Y = File_data[0:, 1]
    return X, Y

path = "/home/joaobiu/LFEA/LASER/mean_error/teste6"
os.chdir(path)

print(error_propagarion("1a"))
print(error_propagarion("1b"))
print(error_propagarion("1c"))
print(error_propagarion("2a"))
print(error_propagarion("2b"))
print(error_propagarion("2c"))
print(error_propagarion("3a"))
print(error_propagarion("3b"))
print(error_propagarion("3c"))
