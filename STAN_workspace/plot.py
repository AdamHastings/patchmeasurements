import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sys

########################################################
# Expected data
########################################################

df = pd.read_csv("data.csv")
df['offer'] = df['offer'].str.replace('$', '')
df['offer'] = df['offer'].astype(float)
df['accept'] = df['accept'].astype(int)

plt.plot(df.offer.values, df.accept.values, 'ro')


alpha = -1.42
alpha_2p5 = -3.01
alpha_97p5 = -0.05

beta = 0.41
beta_2p5 = 0.13
beta_97p5 = 0.71

x = np.arange(-5.0, 15.0, 0.1)
y = 1 / (1 + np.exp(-1 * (alpha + beta * x)))

y_2p5 = 1 / (1 + np.exp(-1 * (alpha_2p5 + beta * x)))
y_97p5 = 1 / (1 + np.exp(-1 * (alpha_97p5 + beta * x)))

plt.plot(x, y, 'b')

#plt.plot(x, y_2p5, 'g')
#plt.plot(x, y_97p5, 'g')


plt.show()

########################################################
# Doubled data
########################################################

df = pd.read_csv("doubled_data.csv")
df['offer'] = df['offer'].str.replace('$', '')
df['offer'] = df['offer'].astype(float)
df['accept'] = df['accept'].astype(int)

plt.plot(df.offer.values, df.accept.values, 'ro')


alpha = -1.38
alpha_2p5 = -2.45
alpha_97p5 = -0.41

beta = 0.39
beta_2p5 = 0.21
beta_97p5 = 0.61

x = np.arange(-5.0, 15.0, 0.1)
y = 1 / (1 + np.exp(-1 * (alpha + beta * x)))

plt.plot(x, y, 'b')


plt.show()

########################################################
# Good data
########################################################

df = pd.read_csv("good_data.csv")
df['offer'] = df['offer'].str.replace('$', '')
df['offer'] = df['offer'].astype(float)
df['accept'] = df['accept'].astype(int)

plt.plot(df.offer.values, df.accept.values, 'ro')


alpha = -2.33
alpha_2p5 = -4.03
alpha_97p5 = -0.81

beta = 0.55
beta_2p5 = 0.16
beta_97p5 = 0.89

x = np.arange(-5.0, 15.0, 0.1)
y = 1 / (1 + np.exp(-1 * (alpha + beta * x)))

plt.plot(x, y, 'b')


plt.show()

########################################################
# Ideal data
########################################################

df = pd.read_csv("ideal_data.csv")
df['offer'] = df['offer'].str.replace('$', '')
df['offer'] = df['offer'].astype(float)
df['accept'] = df['accept'].astype(int)

plt.plot(df.offer.values, df.accept.values, 'ro')


alpha = -7.2e7
alpha_2p5 = -2.1e8
alpha_97p5 = -1.6e6

beta = 1.6e7
beta_2p5 = 3.7e5
beta_97p5 = 4.8e7

x = np.arange(-5.0, 15.0, 0.1)
y = 1 / (1 + np.exp(-1 * (alpha + beta * x)))

plt.plot(x, y, 'b')


plt.show()





