import matplotlib.pyplot as plt
import scipy.optimize as opt
import numpy as np


def func(x, c):
    return c * x * np.log(x)


def model(x):
    return 2.8 * x * np.log(x)


data = np.transpose(np.loadtxt('../Rand1.txt'))
N = data[0]
theoretical = data[1]
insert = data[2]
delete = data[3]
search = data[4]
data2 = np.transpose(np.loadtxt('../Rand2.txt'))
theoretical2 = data2[0]
insert2 = data2[1]
delete2 = data2[2]
search2 = data2[3]

plt.plot(N, 2.8 * theoretical, 'r-', label='theory')
plt.plot(N, insert, 'y-D', label='insert', )
plt.plot(N, delete, 'b.-', label='delete')
plt.plot(N, search, 'g-x', label='search')

plt.xlabel('N')
plt.ylabel('iteration`')
plt.grid()
plt.legend()
plt.show()

plt.plot(N, theoretical2, 'r-', label='theoretical2', )
plt.plot(N, insert2, 'y-D', label='insert2', )
plt.plot(N, delete2, 'b.-', label='delete2')
plt.plot(N, search2, 'g-x', label='search2')

plt.xlabel('N')
plt.ylabel('iteration`')
plt.grid()
plt.legend()
plt.show()
