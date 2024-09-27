import math

def poisson_probability(avg, estimate):
    log_prob = -avg + (estimate * math.log(avg)) - math.lgamma(estimate + 1)
    probability = math.exp(log_prob)
    return round(probability, 6)

def main():
    cases = [(250, 275), (300, 350), (100, 150)]
    for i, (average, estimated) in enumerate(cases, start=1):
        probability = poisson_probability(average, estimated)
        print(f"Case {i}: {average}, {estimated} {probability}")
if __name__ == "__main__":
    main()
