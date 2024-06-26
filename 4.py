import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt('exp_dist.txt')

plt.hist(data, bins=100, density=True, label='Generated Data')

alpha = 2.0  
x = np.linspace(0, np.max(data), 1000)
pdf = alpha * np.exp(-alpha * x)
plt.plot(x, pdf, 'r-', lw=2, label='Exact PDF')
plt.xlabel('x')
plt.ylabel('P(x)')
plt.legend()
plt.show()
