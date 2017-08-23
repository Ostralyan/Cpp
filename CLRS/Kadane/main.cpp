#include <iostream>
#include <vector>
#include <algorithm>

int kadane(std::vector<int>);

// TODO: Why does this not work?
int main() {
    std::vector<int> test_vector{-2, -3, 4, -1, -2, 1, 5, -3};

    std::cout << kadane(test_vector) << std::endl;

    return 0;
}

int kadane(std::vector<int> A) {
    int max_current = A[0];
    int max_global = A[0];

    for (int i: A) {
        max_current = std::max(A[i], max_current + A[i]);
        max_global = std::max(max_global, max_current);
    }
    return max_global;
}
