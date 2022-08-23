import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

c = 299792458 # viteza luminii in vid
v = c # viteza relativa a lui S', in raport cu S.


gamma = 1/np.sqrt(1-v**2/c**2) #factorul de contractie Lorentz


def get_cube():   

    phi = np.arange(1,10,2)*np.pi/4
    Phi, Theta = np.meshgrid(phi, phi)

    x = np.cos(Phi)*np.sin(Theta)
    y = np.sin(Phi)*np.sin(Theta)
    z = 2*np.cos(Theta)/np.sqrt(2)

    return x,y,z

fig = plt.figure("Contractia Lorentz a unui obiect: vazuta de un observator static")

ax = fig.add_subplot(121, projection='3d')

a = 4
b = 1
c = 1
x,y,z = get_cube()

ax.plot_surface(x*a, y*b, z*c)

ax.set_xlim(-5,5)
ax.set_ylim(-5,5)
ax.set_zlim(-5,5)

#denumirea axelor:
plt.title('Obiectul in sistemul de referinta S("static")', fontweight ='bold')

ax.set_xlabel('$X$', fontsize=15, rotation=150, color="C3", fontweight ='bold')
ax.set_ylabel('$Y$', fontsize=15, color="C1", fontweight ='bold')
ax.set_zlabel('$Z$', fontsize=15, rotation=60, color="C2", fontweight ='bold')
ax.grid(False)


#partea 2
ax1 = fig.add_subplot(122, projection='3d')

a1 = 4/gamma
b1 = 1
c1 = 1
x,y,z = get_cube()

ax1.plot_surface(x*a1, y*b1, z*c1)

ax1.set_xlim(-5,5)
ax1.set_ylim(-5,5)
ax1.set_zlim(-5,5)

#denumirea axelor:
plt.title('Obiectul in sistemul de referinta S1(in stare de miscare relativa)', fontweight ='bold')

ax1.set_xlabel('$X1$', fontsize=15, rotation=150, color="C3", fontweight ='bold')
ax1.set_ylabel('$Y1$', fontsize=15, color="C1", fontweight ='bold')
ax1.set_zlabel('$Z1$', fontsize=15, rotation=60, color="C2", fontweight ='bold')

ax1.quiver(2, 0, 0, 2.5, 0, 0, color="C3")
ax1.text(2.5, 0.1, 0.4, "v = c", color='black', fontweight ='bold', fontsize=14)

ax1.grid(False)


plt.show()