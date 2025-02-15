#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

double query(const std::set<int>& set1, const std::set<int>& set2) {
    std::set<int> intersaction;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                          std::inserter(intersaction, intersaction.begin()));
    std::set<int> uni_set;
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   std::inserter(uni_set, uni_set.begin()));
    double Nc = intersaction.size();
    double Nt = uni_set.size();
    if (Nt == 0)
        return 0.0;  // 防止除以0的情况
    return (Nc / Nt) * 100;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::set<int>> sets(n);
    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;
        std::set<int> m_set;
        for (int j = 0; j < m; j++) {
            int temp_int;
            std::cin >> temp_int;
            m_set.insert(temp_int);
        }
        sets[i] = m_set;
    }
    int k;
    std::cin >> k;
    while (k--) {
        int index1, index2;
        std::cin >> index1 >> index2;
        double similarity = query(sets[index1 - 1], sets[index2 - 1]);
        std::cout << std::fixed << std::setprecision(1) << similarity << "%"
                  << std::endl;
    }
    return 0;
}