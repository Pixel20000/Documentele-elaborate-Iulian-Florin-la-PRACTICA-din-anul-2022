import matplotlib.pyplot as plt
import numpy as np

ax = plt.axes()



plt.title('GRAFICUL varstei lui A, functie de varsta lui B', fontsize=18)
plt.xlabel('Varsta lui B', fontsize=14)
plt.ylabel('Varsta lui A.', fontsize=14)


plt.xlim([0,8])
plt.ylim([0,16])


plt.plot(0,0, marker="o", color="black")

eq = r"Plecare."
ax.text(0, 0.4, eq, {'color': 'C3', 'fontsize': 14})

eq = r"Calatorie1."
ax.text(2, 2, eq, {'color': 'C3', 'fontsize': 14})
plt.plot(4,2, marker="<", color="black")


eq = r"Destinatie."
ax.text(4, 8, eq, {'color': 'C1', 'fontsize': 14})
plt.plot(4,8, marker=">", color="black")


eq = r"Calatorie2."
ax.text(6, 14, eq, {'color': 'C3', 'fontsize': 14})
plt.plot(4, 14, marker=">", color="black")

eq = r"P2."
ax.text(4.1, 14.2, eq, {'color': 'C8', 'fontsize': 14})

eq = r"P1."
ax.text(4.1, 2, eq, {'color': 'C8', 'fontsize': 14})


eq = r"Sosire."
ax.text(8, 16, eq, {'color': 'C3', 'fontsize': 14})
plt.plot(8, 16, marker="o", color="black")

x = [0,4,4,4,8]
y = [0,2,8,14,16]

plt.scatter(x, y)
plt.plot(x,y)





plt.grid(b=None, which='major', axis='both')

plt.show()