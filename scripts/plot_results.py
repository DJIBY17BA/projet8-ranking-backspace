import os
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("results/results.csv")

os.makedirs("results/figures", exist_ok=True)

# 1) Top 10 des différences pour alpha = 0.50
df["diff"] = (df["backspace"] - df["google"]).abs()
df_alpha = df[df["alpha"] == 0.50]

top10 = df_alpha.sort_values(by="diff", ascending=False).head(10)
top10.to_csv("results/top10_diff.csv", index=False)

plt.figure(figsize=(10, 6))
plt.bar(top10["sommet"].astype(str), top10["diff"])
plt.xlabel("Sommet")
plt.ylabel("Différence absolue")
plt.title("Top 10 des différences entre PageRank Google et Backspace")
plt.xticks(rotation=45)
plt.tight_layout()
plt.savefig("results/figures/top10_diff.png")
plt.close()

# 2) Evolution alpha pour le sommet 9467
target_node = 9467
df_node = df[df["sommet"] == target_node]

plt.figure()
plt.plot(df_node["alpha"], df_node["google"], marker="o", label="Google")
plt.plot(df_node["alpha"], df_node["backspace"], marker="o", label="Backspace")
plt.xlabel("alpha")
plt.ylabel("Score PageRank")
plt.title(f"Evolution du PageRank pour le sommet {target_node}")
plt.legend()
plt.tight_layout()
plt.savefig("results/figures/evolution_alpha.png")
plt.close()

# 3) Courbes pour sommets 0, 1 et 2
for node in [0, 1, 2]:
    df_node = df[df["sommet"] == node]

    plt.figure()
    plt.plot(df_node["alpha"], df_node["google"], marker="o", label="Google")
    plt.plot(df_node["alpha"], df_node["backspace"], marker="o", label="Backspace")
    plt.xlabel("alpha")
    plt.ylabel("Score PageRank")
    plt.title(f"Comparaison Google vs Backspace - Sommet {node}")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(f"results/figures/sommet_{node}.png")
    plt.close()

print("Figures générées dans results/figures/")
print("CSV généré : results/top10_diff.csv")