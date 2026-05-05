import pandas as pd
import matplotlib.pyplot as plt
import os

df = pd.read_csv("results/results.csv")

os.makedirs("results/figures", exist_ok=True)

for sommet in df["sommet"].unique():
    data = df[df["sommet"] == sommet]

    plt.figure()
    plt.plot(data["alpha"], data["google"], marker="o", label="Google")
    plt.plot(data["alpha"], data["backspace"], marker="o", label="Backspace")

    plt.xlabel("alpha")
    plt.ylabel("Score PageRank")
    plt.title(f"Comparaison Google vs Backspace - Sommet {sommet}")
    plt.legend()
    plt.grid(True)

    plt.savefig(f"results/figures/sommet_{sommet}.png")
    plt.close()

print("Graphes generes dans results/figures/")