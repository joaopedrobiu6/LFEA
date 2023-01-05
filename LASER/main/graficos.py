import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import os


def ReadFile(filename):
    File_data = np.loadtxt(filename, dtype=float)
    X = File_data[0:, 0]
    Y = File_data[0:, 1]
    return X, Y


path = "/home/joaobiu/LFEA/LASER/"
os.chdir(path)

X1, Y1 = ReadFile("perto1.txt")

plt.plot(X1, Y1, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('2mW, L = 6.1 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("teste6.png", dpi=300)
plt.clf()

X1, Y1 = ReadFile("perto2.txt")

plt.plot(X1, Y1, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('2mW, L = 6.1 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("teste6.png", dpi=300)
plt.clf()

X1, Y1 = ReadFile("perto3.txt")

plt.plot(X1, Y1, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('2mW, L = 6.1 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("teste6.png", dpi=300)
plt.clf()

X1, Y1 = ReadFile("perto4.txt")

plt.plot(X1, Y1, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('2mW, L = 6.1 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("teste6.png", dpi=300)
plt.clf()

X1, Y1 = ReadFile("teste6.txt")

plt.plot(X1, Y1, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('2mW, L = 7.3 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("teste6.png", dpi=300)
plt.clf()

X2, Y2 = ReadFile("teste3.txt")

plt.plot(X2, Y2, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('2mW, L = 7.3 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("teste3.png", dpi=300)
plt.clf()

X3, Y3 = ReadFile("10mW_1.txt")

plt.plot(X3, Y3, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('10mW, L = 3.4 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("10mW_1.png", dpi=300)
plt.clf()

X4, Y4 = ReadFile("10mW_2.txt")

plt.plot(X4, Y4, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('10mW, L = 6.0 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("10mW_2.png", dpi=300)
plt.clf()

X4, Y4 = ReadFile("minilaser5.txt")

plt.plot(X4, Y4, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('<1mW, L = 7.3 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("ml5.png", dpi=300)
plt.clf()

X4, Y4 = ReadFile("minilaser6.txt")

plt.plot(X4, Y4, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('<1mW, L = 7.3 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("ml6.png", dpi=300)
plt.clf()

X4, Y4 = ReadFile("minilaser7.txt")

plt.plot(X4, Y4, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('<1mW, L = 7.3 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("ml7.png", dpi=300)
plt.clf()

X4, Y4 = ReadFile("minilaser8.txt")

plt.plot(X4, Y4, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('<1mW, L = 7.3 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("ml8.png", dpi=300)
plt.clf()

X4, Y4 = ReadFile("minilaser2_d.txt")

plt.plot(X4, Y4, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('<1mW, L = 7.3 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("ml2d.png", dpi=300)
plt.clf()

X4, Y4 = ReadFile("minilaser3_d.txt")

plt.plot(X4, Y4, '-o', markersize=3, markerfacecolor='blue', c='red')
plt.title('<1mW, L = 3.4 $\pm$ 0.1 [cm]')
plt.xlabel('$U_{a}$ [V]')
plt.ylabel('$U_{b}$ [V]')
plt.savefig("ml3d.png", dpi=300)
plt.clf()

