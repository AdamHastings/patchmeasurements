import numpy as np
import matplotlib.pyplot as plt

x = np.array([0.01,0.05,0.25,1,5])
y20 = np.array([2,1,4,6,22])/30
y40 = np.array([0,0,1,2,6])/30
y10 = np.array([3,4,7,15,26])/30
y5 = np.array([6,6,8,20,28])/30
y1 = np.array([15,18,30,30,30])/30



plt.scatter(x,y1, color="b")
plt.plot(np.unique(x), np.poly1d(np.polyfit(x, y1, 1))(np.unique(x)), color="b", label="1% slowdown")
#coef = np.polyfit(x,y1,5)
#poly1d_fn = np.poly1d(coef)
#plt.plot(x, poly1d_fn(x), 'b')

plt.scatter(x,y5, color="r")
plt.plot(np.unique(x), np.poly1d(np.polyfit(x, y5, 1))(np.unique(x)), color="r", label="5% slowdown")
plt.scatter(x,y10, color="g")
plt.plot(np.unique(x), np.poly1d(np.polyfit(x, y10, 1))(np.unique(x)), color="g", label="10% slowdown")
plt.scatter(x,y20, color="c")
plt.plot(np.unique(x), np.poly1d(np.polyfit(x, y20, 1))(np.unique(x)), color="c", label="20% slowdown")
plt.scatter(x,y40, color="k")
plt.plot(np.unique(x), np.poly1d(np.polyfit(x, y40, 1))(np.unique(x)), color="k", label="40% slowdown")



plt.legend(loc='lower right')


#plt.plot(x,y)
plt.xlabel("Daily WTA ($)")
plt.ylabel("Proportion of paricipants who accepted \nfull 30 days of slowdowns")
plt.title("Proportion of participants who accepted full 30 days of slowdowns\n across multiple price points")
plt.show()
