import matplotlib.pyplot as plt
import numpy as np
ax = plt.axes()

#date/parametrii
c = 299792458 #vit. de propagare a luminii in vid.
v = 39999999 #viteza cu care sist S' se misca relativ la S.

gamma = 1/np.sqrt(1 - v**2/c**2) #factorul Lorentz. 

#vectorul cvadridimensional E = (ct,x)

#in sistemul S, avem coordonatele

#coordonata spatiala:
x = 2 #[m]
#coordonata temporala X c:
ct = 4 #[t*3e8]
#se va tine cont ca x/t<=c 

#in sistemul S'

#coordonata spatiala':
x1 = (x - v*ct/c)*gamma
#coordonata temporala':
ct1 = (ct - x*v/c)*gamma


X=10 #LUNGIMEA AXELOR(VALOARE REGLABILA).
#configuarea axelor:

theta=np.sin(np.arctan(v/c))  
 
#pentru sistemul S:
ax.arrow(0, 0, X, 0, head_width = 0.5, head_length=0.5, fc='r', ec='r')
ax.arrow(0, 0, 0, X, head_width = 0.5, head_length=0.5, fc='b', ec='b')
    
#pentru sistemul S':
ax.arrow(0, 0, X*np.cos(np.arctan(v/c)), X*np.sin(np.arctan(v/c)), head_width = 0.5, head_length=0.5, fc='k', ec='k')
ax.arrow(0, 0, X*np.sin(np.arctan(v/c)), X*np.cos(np.arctan(v/c)), head_width = 0.5, head_length=0.5, fc='g', ec='g')

ax.arrow(0, 0, X, X, head_width = 0, head_length=0, fc='y', ec='y')

#denumim axele sist S, solidar.
eq = r"x"
ax.text(X+0.5, -0.6, eq, {'color': 'C5', 'fontsize': 13})

eq1 = r"c*t"
ax.text(-0.7, X+0.4, eq1, {'color': 'C5', 'fontsize': 13})

#denumim axele sist S', cinematic.
eq = r"x'"
ax.text(X*np.cos(np.arctan(v/c))+0.5, X*np.sin(np.arctan(v/c))-0.6, eq, {'color': 'C4', 'fontsize': 13})

eq1 = r"c*t'"
ax.text(X*np.sin(np.arctan(v/c))-0.7, X*np.cos(np.arctan(v/c))+0.4, eq1, {'color': 'C4', 'fontsize': 13})


eq2 = r"v=c"
ax.text(X, X, eq2, {'color': 'C5', 'fontsize': 13})

plt.title('Diagrama Spatio-temporala', fontsize=18)
plt.xlabel('Axa x- spatiala', fontsize=14)
plt.ylabel('Axa c*t- temporala.', fontsize=14)

#evenimentul spatio-temporal in sist S

#ptr prima linie punctata din S
x_points = [0, x]
y_points = [ct, ct]
plt.plot(x_points, y_points, linestyle='dashed')

#ptr a doua linie punctata din S
x_points1 = [x, x]
y_points1 = [0, ct]

plt.plot(x_points1, y_points1, linestyle='dashed')

#plotare punct E (in sistemul referential S)
plt.plot(x,ct, marker="o", color="black")
eq2 = r"E"
ax.text(x+0.1, ct-0.2, eq2, {'color': 'C4', 'fontsize': 14})

#evenimentul spatio-temporal proiectat in sist S'

#ptr prima linie punctata din S'
x_p = [x1*np.cos(np.arctan(v/c)), x]
y_p = [x1*np.sin(np.arctan(v/c)), ct]
plt.plot(x_p, y_p, linestyle='dashed')

#ptr a doua linie punctata din S'
x_p1 = [ct1*np.sin(np.arctan(v/c)), x]
y_p1 = [ct1*np.cos(np.arctan(v/c)), ct]
plt.plot(x_p1, y_p1, linestyle='dashed')

#Originea
eq4 = r"O"
ax.text(-0.5, -0.5, eq4, {'color': 'C6', 'fontsize': 10})

# plt.grid(b=None, which='major', axis='both')

plt.show()