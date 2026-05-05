import pandas as pd
import matplotlib.pyplot as plt
import os

df = pd.read_csv("results/top10_diff.csv")

os.makedirs("results/figures", exist_ok=True)

plt.figure(figsize=(10, 6))
plt.bar(df["sommet"].astype(str), df["diff"])

plt.xlabel("Sommet")
plt.ylabel("Différence absolue")
plt.title("Top 10 des différences entre PageRank Google et Backspace")
plt.xticks(rotation=45)
plt.tight_layout()

plt.savefig("results/figures/top10_diff.png")
plt.close()

print("Figure generee : results/figures/top10_diff.png")