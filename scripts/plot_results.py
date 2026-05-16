import pandas as pd
import matplotlib.pyplot as plt
import os

df = pd.read_csv("results/results.csv")

# Choisir un sommet important (ex: celui avec grosse diff)
target_node = 9467

df_node = df[df["sommet"] == target_node]

os.makedirs("results/figures", exist_ok=True)

plt.figure()
plt.plot(df_node["alpha"], df_node["google"], marker='o', label="Google")
plt.plot(df_node["alpha"], df_node["backspace"], marker='o', label="Backspace")

plt.xlabel("alpha")
plt.ylabel("Score PageRank")
plt.title(f"Evolution du PageRank pour le sommet {target_node}")
plt.legend()

plt.savefig("results/figures/evolution_alpha.png")
plt.close()

print("Courbe générée : evolution_alpha.png")