#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

struct Record {
  bool isOnline;
  int month, day, hour, minute, time;
  std::string name;
};

bool cmp(Record a, Record b) {
  return a.name == b.name ? a.time < b.time : a.name < b.name;
}

std::string formatTime(int day, int hour, int minute) {
  std::ostringstream oss;
  oss << std::setw(2) << std::setfill('0') << day << ":" << std::setw(2)
      << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0')
      << minute;
  return oss.str();
}

double billFromZero(Record record, int *rate) {
  double total = record.minute * rate[record.hour] + rate[24] * record.day * 60;
  for (int i = 0; i < record.hour; i++) {
    total += rate[i] * 60;
  }
  return total / 100.0;
}

int main() {
  int rate[25]={0};
  for (int i = 0; i < 24; i++) {
    std::cin >> rate[i];
    rate[24] += rate[i];
  }
  int n;
  std::cin >> n;
  std::vector<Record> Records(n);
  std::cin.ignore(); 
  for (int i = 0; i < n; i++) {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    char colon;
    std::string status_str;
    ss >> Records[i].name;
    ss >> Records[i].month >> colon >> Records[i].day >> colon >>
        Records[i].hour >> colon >> Records[i].minute >> status_str;
    Records[i].isOnline = (status_str == "on-line");
    Records[i].time =
        Records[i].day * 24 * 60 + Records[i].hour * 60 + Records[i].minute;
  }

  std::sort(Records.begin(), Records.end(), cmp);

  std::map<std::string, std::vector<Record>> custom; // 名字和一条记录建立map
  for (int i = 1; i < n; i++) {
    if (Records[i].name == Records[i - 1].name && !Records[i].isOnline &&
        Records[i - 1].isOnline) {
      custom[Records[i-1].name].push_back(Records[i-1]);
      custom[Records[i].name].push_back(Records[i]);
    }
  }

  for (auto it : custom) {
    std::vector<Record> records = it.second;
    std::cout << it.first << " " << std::setw(2) << std::setfill('0') << records[0].month << std::endl; 
    double total = 0.0;
    for (size_t i = 1; i < records.size(); i += 2) {
      double t =
          billFromZero(records[i], rate) - billFromZero(records[i - 1], rate);
      std::cout << formatTime(records[i - 1].day, records[i - 1].hour,
                              records[i - 1].minute)
                << " "
                << formatTime(records[i].day, records[i].hour,
                              records[i].minute)
                << " " << records[i].time - records[i - 1].time << " $"
                << std::fixed << std::setprecision(2) << t << std::endl;
      total += t;
    }
    std::cout << "Total amount: $" << std::fixed << std::setprecision(2)
              << total << std::endl;
  }
  return 0;
}