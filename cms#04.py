import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad

# NOTE : BELOW |
#              |
#              V
#(MAAM THE CODE TAKES SOME TIME WHILE RUNNING BUT IT GIVES THE VALUES AT THE END AND EXECUTES PERFECTLY AND ALSO DISPLAYS GRAPH)
# ALSO USE (pip install matplotib) and (pip install scipy) before to run this code


# Define functions for each of the given questions

def f1(x):
    return np.sqrt(np.sin(2*x) + 1)  # Function for question 1

def f2(x):
    return x**3  # Function for question 2

def f3(x):
    return np.cos(x**2)  # Function for question 3

# Part a: Plotting function f for each question

def plot_function(f, x_min, x_max, label):
    x_values = np.linspace(x_min, x_max, 400)
    plt.plot(x_values, f(x_values), label=label)
    plt.fill_between(x_values, f(x_values), alpha=0.3)
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title(f'Plot of {label}')
    plt.grid(True)
    plt.legend()

# Plot function f1 for question 1
plot_function(f1, 0, 2, 'f(x) = sqrt(sin(2x) + 1)')

# Plot function f2 for question 2
plt.figure()
plot_function(f2, 2, 3, 'f(x) = x^3')

# Plot function f3 for question 3
plt.figure()
plot_function(f3, 2, 3, 'f(x) = cos(x^2)')

plt.show()

# Part b: Monte Carlo area estimation function for each question
def monte_carlo_area_estimate(f, x_min, x_max, num_darts):
    count_under_curve = 0
    
    for _ in range(num_darts):
        x = (x_max - x_min) * np.random.random() + x_min  # Generate a random x in the specified range
        y = np.random.random()  # Generate a random y between 0 and 1
        
        if y <= f(x):
            count_under_curve += 1
    
    area_ratio = count_under_curve / num_darts
    total_area = area_ratio * (x_max - x_min)  # Total area under curve in the specified range
    
    return total_area

# Part c: Function to calculate mean and standard deviation of Monte Carlo estimates

def monte_carlo_mean_and_std(f, x_min, x_max, num_samples, num_darts):
    results = [monte_carlo_area_estimate(f, x_min, x_max, num_darts) for _ in range(num_samples)]
    mean = np.mean(results)
    std_dev = np.std(results)
    return mean, std_dev

# Part d: Integration calculation for each question

def integration_estimate(f, x_min, x_max):
    return quad(f, x_min, x_max)[0]

# Part e: Calculate percentage error between integration and Monte Carlo estimate

def calculate_percentage_error(integration_value, monte_carlo_mean):
    return abs((integration_value - monte_carlo_mean) / integration_value) * 100

# Perform computations and print results for each question

# Question 1
print("\nQuestion 1:")
exact_area_1 = integration_estimate(f1, 0, 2)
mean_estimate_1, _ = monte_carlo_mean_and_std(f1, 0, 2, 1000, 10000)
error_1 = calculate_percentage_error(exact_area_1, mean_estimate_1)
print(f"Exact Area (Integration): {exact_area_1:.6f}")
print(f"Mean Estimate (Monte Carlo): {mean_estimate_1:.6f}")
print(f"Percentage Error: {error_1:.4f}%")

# Question 2
print("\nQuestion 2:")
exact_area_2 = integration_estimate(f2, 2, 3)
mean_estimate_2, _ = monte_carlo_mean_and_std(f2, 2, 3, 1000, 10000)
error_2 = calculate_percentage_error(exact_area_2, mean_estimate_2)
print(f"Exact Area (Integration): {exact_area_2:.6f}")
print(f"Mean Estimate (Monte Carlo): {mean_estimate_2:.6f}")
print(f"Percentage Error: {error_2:.4f}%")

# Question 3
print("\nQuestion 3:")
exact_area_3 = integration_estimate(f3, 2, 3)
mean_estimate_3, _ = monte_carlo_mean_and_std(f3, 2, 3, 1000, 10000)
error_3 = calculate_percentage_error(exact_area_3, mean_estimate_3)
print(f"Exact Area (Integration): {exact_area_3:.6f}")
print(f"Mean Estimate (Monte Carlo): {mean_estimate_3:.6f}")
print(f"Percentage Error: {error_3:.4f}%")