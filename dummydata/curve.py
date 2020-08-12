import numpy as np
import  matplotlib.pyplot as plt

#x = np.array(
#    [1, 7],
#    [5, 16],
#    [10, 28],
#    [20, 37],
#    [40, 89],
#)

x = np.array([1,5,10,20,40])
y = np.array([7,16,28,37,89])

plt.scatter(x, y)
plt.plot(np.unique(x), np.poly1d(np.polyfit(x, y, 1))(np.unique(x)))
plt.xlabel('% slowdown')
plt.ylabel('Minimum WTA ($)')
plt.title('Example supply curve')
plt.show()
