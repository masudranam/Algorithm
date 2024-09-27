import random

total_roll = 100000
cnt_double_six = 0 

for i in range(total_roll):
    double_six = False
    for i in range(24):
        die1, die2 = random.randint(1,6),random.randint(1,6)
        if die1 == 6 and die2 == 6:
            double_six = True
            break 
    if double_six:
        cnt_double_six += 1

probability = cnt_double_six / total_roll
print("Probability of getting a double six after rolling 24 times:", probability)


