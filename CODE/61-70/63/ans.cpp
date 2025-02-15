#include <iomanip>  // 用于控制输出精度
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// 计算两个集合的相似度
double calculate_similarity(const set<int>& set1, const set<int>& set2) {
    // 计算交集
    set<int> intersection;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                     inserter(intersection, intersection.begin()));

    // 计算并集
    set<int> union_set;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
              inserter(union_set, union_set.begin()));

    // 相似度公式: (交集大小 / 并集大小) * 100
    double Nc = intersection.size();
    double Nt = union_set.size();

    if (Nt == 0)
        return 0.0;  // 防止除以0的情况
    return (Nc / Nt) * 100;
}

int main() {
    int N;  // 集合数量
    cin >> N;

    vector<set<int>> sets(N);

    // 读取所有集合
    for (int i = 0; i < N; ++i) {
        int M;  // 当前集合的大小
        cin >> M;
        for (int j = 0; j < M; ++j) {
            int x;
            cin >> x;
            sets[i].insert(x);  // 插入元素到集合中
        }
    }

    int K;  // 查询数量
    cin >> K;

    // 处理每个查询
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        // 集合编号从1开始，数组索引从0开始
        double similarity = calculate_similarity(sets[a - 1], sets[b - 1]);
        cout << fixed << setprecision(1) << similarity << "%" << endl;
    }

    return 0;
}
