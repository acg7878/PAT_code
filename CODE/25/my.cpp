#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
struct Testee {
  std::string id;
  int score;
  int final_rank;
  int local_rank;
  int location_number;
};

bool cmp(const Testee &a, const Testee &b) {
  if (a.score != b.score) {
    return a.score > b.score; // 分数高的排前面
  } else {
    return a.id < b.id; // 分数相同，ID 小的排前面
  }
}

void sortLocalRank(std::vector<Testee> &vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    vec[i].local_rank = i + 1;
  }
  for (size_t i = 1; i < vec.size(); i++) {
    if (vec[i].score == vec[i - 1].score) {
      vec[i].local_rank = vec[i - 1].local_rank;
    }
  }
}

void sortFinalRank(std::vector<Testee> &vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    vec[i].final_rank = i + 1;
  }
  for (size_t i = 1; i < vec.size(); i++) {
    if (vec[i].score == vec[i - 1].score) {
      vec[i].final_rank = vec[i - 1].final_rank;
    }
  }
}

int main() {
  int n, k, total_k = 0;
  std::vector<std::vector<Testee>> testee_vec;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> k;
    total_k += k;
    std::vector<Testee> testees;
    for (int j = 1; j <= k; j++) {
      Testee testee;
      testee.location_number = i;
      std::cin >> testee.id;
      std::cin >> testee.score;
      testees.push_back(testee);
    }
    std::sort(testees.begin(), testees.end(), cmp);
    sortLocalRank(testees);
    testee_vec.push_back(testees);
  }

  std::vector<Testee> all_testees;
  for (const auto &local_testees : testee_vec) {
    all_testees.insert(all_testees.end(), local_testees.begin(),
                       local_testees.end());
  }
  std::sort(all_testees.begin(), all_testees.end(), cmp);
  sortFinalRank(all_testees);

  std::cout << total_k << std::endl;
  for (Testee testee : all_testees) {
    std::cout << testee.id << " " << testee.final_rank << " "
              << testee.location_number << " " << testee.local_rank << std::endl;
  }
}