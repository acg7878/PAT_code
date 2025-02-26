#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>
struct Person {
    int id;
    std::vector<int> i_score;
    int sum_score;
    Person() : sum_score(0) {};
    Person(int m_id, int K) : id(m_id), sum_score(0) {
        i_score.assign(K + 1, std::numeric_limits<int>::min());
    };
    int rank;
};
int N, K, M;
std::vector<int> problem_score;
std::vector<Person> persons;

int main() {
    std::cin >> N >> K >> M;
    problem_score.resize(K + 1);
    persons.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        persons[i] = Person(i, K);
    }
    for (int i = 1; i <= K; i++)
        std::cin >> problem_score[i];

    // 计算单题分数
    for (int i = 0; i < M; i++) {
        int user_id, problem_id, partial_score_obtained;
        std::cin >> user_id >> problem_id >> partial_score_obtained;
        if (partial_score_obtained > problem_score[problem_id])
            continue;  // 跳过无效分数
        persons[user_id].i_score[problem_id] = std::max(
            persons[user_id].i_score[problem_id], partial_score_obtained);
    }

    //计算总分
    for (auto& person : persons) {
        for (const auto& score : person.i_score) {
            if (score != std::numeric_limits<int>::min())
                person.sum_score += score;
        }
    }
    
    std::sort(persons.begin(), persons.end(),
              [](const Person& a, const Person& b) {
                  return a.sum_score > b.sum_score;
              });
    persons[1].rank=1;
    for(int i=1;i<=N-1;i++) {
        if(persons[i+1].sum_score == persons[i].sum_score) persons[i+1].rank=persons[i].rank;
        else persons[i+1].rank = i+1;
    }

    for(const auto& person:persons) {
        std::cout << person.rank << " ";
        std::cout << std::setw(5) << std::setfill('0') << person.id << " ";
        std::cout << person.sum_score;
        for(int i=1;i<person.i_score.size();i++){
            if(i>1) std::cout << " ";
            if (person.i_score[i] != std::numeric_limits<int>::min()) 
                std::cout << person.i_score[i];
            else std::cout << '-';     
        }
        std::cout << std::endl;
    }
}