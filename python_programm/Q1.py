def LCG(seed, mult, inc, mod, n):
    #LCG(Linear congruential generator)
    sequence = [seed]
    
    for i in range(n - 1):
        nxt_val = (mult * sequence[-1] + inc) % mod
        sequence.append(nxt_val)

    return sequence

#Initialization all the parameter
seed, mult, inc, mod, n = 27 , 17, 43, 100, 10

random_sequence = LCG(seed, mult, inc, mod, n)
# Show the sequence
print(random_sequence)
