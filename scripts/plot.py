import pandas as pd
import matplotlib.pyplot as plt

def smoothen(Y, N):
    """
    Smooths the data by averaging over N points.
    """
    smoothened = []
    Y = list(Y)
    for i in range(len(Y)):
        if i < N:
            smoothened.append(Y[i])
        else:
            smoothened.append(sum(Y[i-N:i])/N)
    return smoothened

#EXPERIMENT 1

df = pd.read_csv("./output/experiment1.csv")
fig,ax = plt.subplots()
EX1 = ["BS", "HS", "CS", "ShS"]
for alg in EX1:
    ax.plot(df[df.algorithm==alg].n, smoothen(df[df.algorithm==alg].time, 15), label=alg)

ax.set_xlabel("number of elements")
ax.set_ylabel("time to sort")
ax.legend(loc='best')
plt.savefig("./output/sorting_experiment1.png", dpi=300)


#EXPERIMENT 2

df = pd.read_csv("./output/experiment2.csv")
EX2 = ["QS", "HS", "MS"]
TYPES = ['r', 'c', 'i', 'd', 'A', 'V']

for types in zip(TYPES[1::2], TYPES[::2]):
    fig,ax = plt.subplots()
    for t in types:
        for alg in EX2:
            ax.plot(df[(df.algorithm==alg) & (df.type==t)].n, smoothen(df[(df.algorithm==alg) & (df.type==t)].time, 15), label=f'{alg}_{t}')
    ax.set_xlabel("number of elements")
    ax.set_ylabel("time to sort")
    ax.set_ylim([0, 0.15])
    ax.legend(loc='best')
    plt.savefig(f'./output/sorting_experiment2-{types}.png', dpi=300)
