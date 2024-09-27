import pandas as pd
import numpy as np

# IAT distribution
df_IAT = pd.DataFrame({
    "IAT": [1, 2, 3, 4],
    "Probability": [0.25, 0.40, 0.20, 0.15]
})

# ST distribution of Anis
df_ST_Anis = pd.DataFrame({
    "ST": [2, 3, 4, 5],
    "Probability": [0.30, 0.28, 0.25, 0.17]
})

# ST distribution of Barik
df_ST_Barik = pd.DataFrame({
    "ST": [3, 4, 5, 6],
    "Probability": [0.35, 0.25, 0.20, 0.20]
})

# Random Digits for Arrival (RDA) time and Random Digit for Service (RDS) time
df_RD = pd.DataFrame({
    "RDA": [None, 30, 89, 50, 10, 20, 70, 45, 90, 95],
    "RDS": [65, 15, 25, 70, 20, 86, 48, 82, 35, 54]
})

# Simulate the system for 10 teachers
num_teachers = 10
arrival_times = []
service_times_anis = []
service_times_barik = []

for i in range(num_teachers):
    # Generate random arrival time using the IAT distribution
    rand = np.random.uniform()
    cumulative_prob = df_IAT['Probability'].cumsum()
    iat = df_IAT.loc[(cumulative_prob >= rand), 'IAT'].iloc[0]

    # Generate random service time for Anis using the ST distribution
    rand = np.random.uniform()
    cumulative_prob = df_ST_Anis['Probability'].cumsum()
    st_anis = df_ST_Anis.loc[(cumulative_prob >= rand), 'ST'].iloc[0]

    # Generate random service time for Barik using the ST distribution
    rand = np.random.uniform()
    cumulative_prob = df_ST_Barik['Probability'].cumsum()
    st_barik = df_ST_Barik.loc[(cumulative_prob >= rand), 'ST'].iloc[0]

    arrival_times.append(iat)
    service_times_anis.append(st_anis)
    service_times_barik.append(st_barik)

# Calculate average arrival time
AAT = np.mean(arrival_times)

# Calculate average service time of Anis (ASTA)
ASTA = np.mean(service_times_anis)

# Calculate average service time of Barik (ASTB)
ASTB = np.mean(service_times_barik)

print("Average Arrival Time (AAT):", AAT)
print("Average Service Time of Anis (ASTA):", ASTA)
print("Average Service Time of Barik (ASTB):", ASTB)
