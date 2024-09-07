import sys
input = sys.stdin.read
output = sys.stdout.write

def read_input():
    data = input().split()
    index = 0
    num_testcases = int(data[index])
    index += 1
    test_cases = []
    
    for _ in range(num_testcases):
        n = int(data[index])
        index += 1
        array_values = [int(data[index + i]) for i in range(n)]
        index += n
        test_cases.append((n, array_values))
    
    return test_cases

def is_true(index):
    output(f"READ {index}\n")
    sys.stdout.flush()
    response = input().strip()
    return response == "true"

def find_transition(n, array_values):
    low, high = 0, n - 1

    while low < high:
        mid = (low + high) // 2
        if is_true(mid):
            if not is_true(mid + 1):
                return mid
            low = mid + 1
        else:
            high = mid - 1

    return -1  # If no transition point found (should not occur as per problem statement)

if __name__ == "__main__":
    test_cases = read_input()
    results = []

    for n, array_values in test_cases:
        transition_index = find_transition(n, array_values)
        if transition_index != -1:
            results.append(f"OUTPUT {transition_index}")

    output("\n".join(results) + "\n")
