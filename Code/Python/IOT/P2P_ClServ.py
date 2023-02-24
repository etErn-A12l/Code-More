import matplotlib.pyplot as plt


P2P_X = []
P2P_Y = []

CS_X = []
CS_Y = []

NIC = 500
WIRE = 200

for i in range(0, 52, 2):
    P2P_X.append(i)
    CS_X.append(i)
    CS_Y.append(i * (NIC + WIRE))
    P2P_Y.append((i * NIC) + ((i * (i - 1) / 2) * WIRE))



plt.plot(P2P_X, P2P_Y, label = "Peer to Peer")
plt.plot(CS_X, CS_Y, label = "Client Server")

plt.xlabel('Units of Hosts')
plt.ylabel('Cost per unit Host')

plt.legend()
  
plt.show()