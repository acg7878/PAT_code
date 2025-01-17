#include <iomanip>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
struct People {
  int come_time, process_time;
};

bool cmp(const People &a, const People &b) { return a.come_time < b.come_time; }

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<People> peoples;
  std::cin.ignore();
  while (n--) {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int hour, minute, second;
    People people;
    char colon;
    ss >> hour >> colon >> minute >> colon >> second >> 
        people.process_time;
    people.come_time = hour * 3600 + minute * 60 + second;
    if (people.come_time > 61200)
      continue;
    people.process_time *= 60;
    peoples.push_back(people);
  }
  std::sort(peoples.begin(), peoples.end(), cmp);

  std::priority_queue<int, std::vector<int>, std::greater<>> q;
  for (int i = 0; i < k; i++) {
    q.push(28800);
  }
  int total = 0, cnt = peoples.size();
  for (int i = 0; i < cnt; i++) {
    if (q.top() <= peoples[i].come_time) {
      q.push(peoples[i].come_time + peoples[i].process_time);
      q.pop();
    } else {
      total += q.top() - peoples[i].come_time;
      q.push(q.top() + peoples[i].process_time);
      q.pop();
    }
  }
  if (total == 0) {
    std::cout << "0.0" << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(1)
              << ((double)total / 60.0) / (double)cnt << std::endl;
  }
}