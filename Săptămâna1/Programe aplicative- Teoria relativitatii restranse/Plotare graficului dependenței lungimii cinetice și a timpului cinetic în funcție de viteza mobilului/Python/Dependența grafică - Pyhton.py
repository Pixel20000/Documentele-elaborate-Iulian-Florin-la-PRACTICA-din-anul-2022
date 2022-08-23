import matplotlib.pyplot as plt
import numpy as np
#from matplotlib.pyplot import figure

#dim. canvas
#figure(figsize=(10, 10), dpi=80)

#variabile
#linearly spaced numbers
c=299792458
v = np.linspace(0,c-1,500)

t0 = float(input("Timpul de repaus(static, in s)- masurat in SR al navei: "))
l0 = float(input("Lungimea de repaus(statica, in m)- masurat in SR al navei: "))

v1 = float(input("Viteza relativa a navei in MRU(m/s): "))


#graficul1

plt.figure(1)
#plt.subplot(1, 2, 1)

# the function
y = t0/np.sqrt(1-v**2/c**2)

# setting the axes at the centre
fig = plt.figure()
#ax = fig.add_subplot(1, 1, 1)

#ax limits
plt.xlim(0, 1.1*c)
plt.ylim(0, 5*t0)


#denumiri de axe+ titlu
plt.title('Timpul cinetic functie de viteza: t = f(v)', fontsize=18)
plt.xlabel('v[m/s]', fontsize=15)
plt.ylabel('t_cinetic[s]', fontsize=15)
plt.grid()

# plot the function and the legend
plt.plot(v,y, 'g', label='tc=f(v)')
plt.legend(loc='upper left')

#point in a particular situatuion
plt.plot(v1, t0/np.sqrt(1-v1**2/c**2), marker="o", markersize=8, markeredgecolor="red", markerfacecolor="red")


#graficul 2

plt.figure(1) # plotare separata
#plt.subplot(1, 2, 2) # plotare reunita

y1 = l0*np.sqrt(1-v**2/c**2)

# setting the axes at the centre
#ax = fig.add_subplot(1, 1, 1)

#ax limits
plt.xlim(0, 1.1*c)
plt.ylim(0, 2*l0)

#denumiri de axe+ titlu
plt.title('Lungimea cinetica ca functie de viteza: l = f(v)', fontsize=18)
plt.xlabel('v[m/s]', fontsize=15)
plt.ylabel('l[m]', fontsize=15)
plt.grid()

# plot the function and the legend
plt.plot(v,y1, 'b', label='l_c=f(v)')
plt.legend(loc='upper left')

#point in a particular situatuion
plt.plot(v1, l0*np.sqrt(1-v1**2/c**2), marker="o", markersize=8, markeredgecolor="red", markerfacecolor="red")

plt.tight_layout()

# show the plots
plt.show()

###################################################################
fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(5, 3))
axes[0].plot(v, y)
axes[1].plot(v, y1)

fig.tight_layout()
