import numpy as np
import scipy as sp
import matplotlib.pyplot as plt


def WeightedMean(X, Y):
    mean = 0
    sumY = 0
    for i in range(0, len(X)):
        mean = mean + X[i] * Y[i]
        sumY = sumY + Y[i]
    return mean / sumY


def error_propagarion(X, Y):
    mean = WeightedMean(X, Y)
    sum = 0
    sumY = 0
    for i in range(0, len(Y)):
        sumY += Y[i]
    for i in range(0, len(X)):
        sum += (X[i] - mean) * (X[i] - mean) * Y[i]
    return np.sqrt(sum) / sumY


# PERTO 1

pico1a_X = [1.71, 1.78, 1.855, 1.925, 1.995, 2.07, 2.14, 2.21, 2.285]
pico1a_Y = [0.635, 0.96, 1.345, 1.54, 1.345, 1.025, 0.79, 0.685, 0.665]

erro1 = error_propagarion(pico1a_X, pico1a_Y)
print(f"Erro Pico 1a: {erro1}")

pico1b_X = [2.355,2.425,2.5,2.57,2.645,2.715,2.785,2.86,2.93,3.005,3.075,3.145]
pico1b_Y = [0.7,0.785,0.935,1.2,1.615,2.17,2.645,2.62,2.08,1.46,0.985,0.71]

erro1b = error_propagarion(pico1b_X, pico1b_Y)
print(f"Erro Pico 1b: {erro1b}")

pico2a_X = [5.225,5.3,5.37,5.44,5.515,5.585,5.655,5.73,5.8]
pico2a_Y = [0.58,0.815,1.105,1.295,1.2,0.935,0.74,0.665,0.67]

erro2a = error_propagarion(pico2a_X, pico2a_Y)
print(f"Erro Pico 2a: {erro2a}")

pico2b_X = [5.87,5.94,6.015,6.085,6.155,6.23,6.3,6.37,6.445,6.515,6.585]
pico2b_Y = [0.73,0.88,1.17,1.735,2.305,2.78,2.705,2.04,1.365,0.885,0.615]

erro2b = error_propagarion(pico2b_X, pico2b_Y)
print(f"Erro Pico 2b: {erro2b}")

pico3a_X = [8.515,8.59,8.66,8.73,8.805,8.875,8.945,9.015]
pico3a_Y = [0.615,0.855,1.095,1.155,0.98,0.775,0.67,0.645]

erro3a = error_propagarion(pico3a_X, pico3a_Y)
print(f"Erro Pico 3a: {erro3a}")

pico3b_X = [9.09,9.16,9.23,9.305,9.375,9.445,9.515,9.59,9.66,9.73,9.805,9.865]
pico3b_Y = [0.685,0.795,1.045,1.52,2.255,2.945,2.94,2.21,1.445,0.955,0.665,0.51]

erro3b = error_propagarion(pico3b_X, pico3b_Y)
print(f"Erro Pico 3b: {erro3b}")