import pandas as pd

# Given data
data = [3, 4, 5, 6, 7, 8, 8, 8, 8, 8, 9, 9, 7, 6, 6, 5, 4, 4, 3, 2]

mean_data = sum(data) / len(data)
std_dev_data = (sum((x - mean_data) ** 2 for x in data) / len(data)) ** 0.5

z_scores = [(x - mean_data) / std_dev_data for x in data]

# Create the DataFrame with original data and z-scores
df_z_score = pd.DataFrame({
    "Data": data,
    "Z-score": z_scores
})

print(df_z_score)
