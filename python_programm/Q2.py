import random

def Monte_carlo(n):
    inside_circle = 0
    inside_square = 0

    for i in range(n):
        x = random.uniform(-1, 1)  
        y = random.uniform(-1, 1)  

        d = x**2 + y**2  
        #comparing with 1 instate of sqrt(1) because 1 == sqrt(1)
        #that's why here distance is not sqrt
        if d <= 1:  
            inside_circle += 1
        inside_square += 1

    estimate_pi = 4 * (inside_circle / inside_square)  
    return estimate_pi


n = 1000000

estimated_pi = Monte_carlo(n)
print("Pi using Monte Carlo method is = ", estimated_pi)
