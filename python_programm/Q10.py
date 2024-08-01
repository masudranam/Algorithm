import numpy as np
import matplotlib.pyplot as plt

ages = [1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5]

# Count the frequency of each age
unique_ages, counts = np.unique(ages, return_counts=True)

# Construct the frequency distribution table
print("Age   Frequency")
print("----  ---------")
for age, count in zip(unique_ages, counts):
    print(f"{age:3}      {count:3}")

# Plot the histogram
plt.bar(unique_ages, counts, color='skyblue')
plt.xlabel('Age in days')
plt.ylabel('Frequency')
plt.title('Frequency Distribution of Ages')
plt.xticks(unique_ages)
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.show()
