import pandas as pd
import matplotlib.pyplot as plt
import os

df = pd.read_csv("results/results_small.csv")

os.makedirs("results/figures", exist_ok=True)

for node in [0, 1, 2]:
    df_node = df[df["sommet"] == node]

    plt.figure()
    plt.plot(df_node["alpha"], df_node["google"], marker="o", label="Google")
    plt.plot(df_node["alpha"], df_node["backspace"], marker="o", label="Backspace")

    plt.xlabel("alpha")
    plt.ylabel("Score PageRank")
    plt.title(f"Petit graphe - Sommet {node}")

    plt.legend()
    plt.grid(True)

    plt.savefig(f"results/figures/sommet_{node}.png")
    plt.close()

print("Courbes du petit graphe générées.")