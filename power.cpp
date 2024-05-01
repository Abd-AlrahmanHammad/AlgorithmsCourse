#include <iostream>
#include <ctime>
using namespace std;

long long power_iterative(int x, int y) {
 
  if (y < 0) {
    return 0; // Handle negative exponents (implementation specific)
  } else if (y == 0) {
    return 1; // Base case: x^0 is 1
  } else {
    long long result = 1;
    for (int i = 0; i < y; ++i) {
      result *= x;
    }
    return result;
  }
}

long long power_recursive(int x, int y) {
 
  if (y < 0) {
    return 0; // Handle negative exponents (implementation specific)
  } else if (y == 0) {
    return 1; // Base case: x^0 is 1
  } else {
    return x * power_recursive(x, y - 1);
  }
}

int main() {
  // Table to store execution times
  double execution_times[4][2];

  // Test with different values of x and y
  for (int i = 0; i < 4; ++i) {
    int x = 2; // Base number
    int y = 5 * (i + 1); // Exponent, starting with 5 and increasing by 5

    // Iterative function execution time measurement
    clock_t start_time = clock();
    long long result = power_iterative(x, y);
    clock_t end_time = clock();
    double iterative_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    execution_times[i][0] = iterative_time;

    // Recursive function execution time measurement
    start_time = clock();
    result = power_recursive(x, y);
    end_time = clock();
    double recursive_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    execution_times[i][1] = recursive_time;

    // Print results for each test case
    cout << "Input (x, y): (" << x << ", " << y << ")" << endl;
    cout << "  Iterative Time: " << iterative_time << " seconds" << endl;

    // Check for stack overflow in recursive function
    if (recursive_time < 0) {
      cout << "  Recursive Time: Stack Overflow Error" << endl;
    } else {
      cout << "  Recursive Time: " << recursive_time << " seconds" << endl;
    }
  }

  // Print the table of execution times
  cout << "\n**Execution Time Results**\n";
  cout << "| Input (x, y) | Iterative Time (s) | Recursive Time (s) |\n";
  cout << "|---|---|---|";
  for (int i = 0; i < 4; ++i) {
    cout << endl << "| (" << 2 << ", " << 5 * (i + 1) << ") | "
              << execution_times[i][0] << " | ";
    if (execution_times[i][1] < 0) {
      cout << "Stack Overflow Error |";
    } else {
      cout << execution_times[i][1] << " |";
    }
  }
  cout << endl;

  return 0;
}
