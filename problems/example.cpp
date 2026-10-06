#include <iostream>
#include <vector>

int sum(const std::vector<int>& values) {
    int total = 0;
    for (const int value : values) {
        total += value;
    }
    return total;
}

int main() {
    const std::vector<int> values{1, 2, 3, 4, 5};
    std::cout << "ECE250 workspace ready!\n";
    std::cout << "Sample sum: " << sum(values) << '\n';
    return 0;
}

