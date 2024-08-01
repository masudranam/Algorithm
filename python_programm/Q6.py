import numpy as np
from scipy.stats import shapiro

# Data
data = [
    67, 63, 33, 69, 53, 51, 49, 78, 77, 83, 47, 53, 51, 49, 78, 77, 
    83, 47, 67, 63, 33, 69, 53, 51, 49, 78, 77, 83, 47, 53, 51, 49
]

# Perform Shapiro-Wilk test
stat, p_value = shapiro(data)

# Define the critical value
critical_value = 0.24

# Determine if data fits normal distribution
if p_value > critical_value:
    result = "Data fits normal distribution"
else:
    result = "Data does not fit normal distribution"

# Output the result
print(f"Shapiro-Wilk Test Statistic: {stat}")
print(f"p-value: {p_value}")
print(result)
