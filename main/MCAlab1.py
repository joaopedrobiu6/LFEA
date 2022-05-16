import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dataframe2 = pd.read_csv("../MCA1.csv", index_col=False, header=None, squeeze=True, sep=",")
plt.plot(dataframe2.iloc[0:, 0], dataframe2.iloc[0:, 1])
plt.savefig("../aula1/MCA1_hist.pdf")

df = pd.read_csv("../MCA2.csv", index_col=False, header=None, squeeze=True, sep=",")
plt.plot(df.iloc[0:, 0], df.iloc[0:, 1])
plt.savefig("../aula1/MCA2_hist.pdf")