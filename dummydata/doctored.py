import matplotlib.pyplot as plt
import numpy as np

wtas= [ 
        38,
        45,
        23,
        34,
        56,
        45,
        75,
        34,
        33,
        25,
        24,
        26,
        23,
        38,
        57,
        78,
        34,
        36,
        57,
        68,
        57,
        34,
        45,
        51,
        10,
        14,
        64,
        17,
        36,
        45
]

plt.hist(wtas, bins=10, normed=False, alpha=0.6)
plt.axvline(np.median(wtas), color='k', linestyle='dashed', linewidth=1)
plt.title('Willingness to accept a slowdown of 20% (Example data only)\n Median is shown via dashed line')
plt.xlabel('Willingness to accept ($)')
plt.ylabel('Count')
print(np.median(wtas))

plt.show()

