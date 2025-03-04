#include <iomanip>
#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

double sale = 0.0;
std::unordered_map<int, int> retailers;  // index, num_sale
std::vector<std::vector<int>> network;
int N;
double P, r;

void dfs(int start_index, double price) {
    if (network[start_index].empty()) {
        sale += price * retailers[start_index];
        return;
    }
    for (const auto& child : network[start_index]) {
        dfs(child, price * (1.0 + r / 100));
    }
}

int main() {
    std::cin >> N >> P >> r;
    network.resize(N);
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        if (num == 0) {
            int num_sale;
            std::cin >> num_sale;
            retailers.emplace(i, num_sale);
        } else {
            network[i].resize(num);
            for (int j = 0; j < num; j++) {
                std::cin >> network[i][j];
            }
        }
    }
    dfs(0, P);
    std::cout << std::fixed << std::setprecision(1) << sale << std::endl;
}