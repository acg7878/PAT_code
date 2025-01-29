#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

struct Book {
    std::string id;
    std::string title;
    std::string author;
    std::string key_word;
    std::string publisher_name;
    std::string publisher_year;
};

std::map<std::string, std::set<std::string>> title_map;
std::map<std::string, std::set<std::string>> author_map;
std::map<std::string, std::set<std::string>> keyword_map;
std::map<std::string, std::set<std::string>> publisher_map;
std::map<std::string, std::set<std::string>> year_map;

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // 忽略换行符，以便后续的 getline 能正确读取
    std::vector<Book> books(n);
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, books[i].id);
        std::getline(std::cin, books[i].title);
        std::getline(std::cin, books[i].author);
        std::getline(std::cin, books[i].key_word);
        std::getline(std::cin, books[i].publisher_name);
        std::getline(std::cin, books[i].publisher_year);

        // 将书籍信息存储到对应的 map 中
        title_map[books[i].title].insert(books[i].id);
        author_map[books[i].author].insert(books[i].id);
        std::istringstream iss(books[i].key_word);
        std::string keyword;
        while (iss >> keyword) {
            keyword_map[keyword].insert(books[i].id);
        }
        publisher_map[books[i].publisher_name].insert(books[i].id);
        year_map[books[i].publisher_year].insert(books[i].id);
    }

    int m;
    std::cin >> m;
    std::cin.ignore();
    for (int i = 0; i < m; i++) {
        std::string query;
        std::getline(std::cin, query);
        std::cout << query << std::endl;
        char type = query[0];
        std::string content = query.substr(3);

        std::set<std::string> result;
        if (type == '1') {
            result = title_map[content];
        } else if (type == '2') {
            result = author_map[content];
        } else if (type == '3') {
            result = keyword_map[content];
        } else if (type == '4') {
            result = publisher_map[content];
        } else if (type == '5') {
            result = year_map[content];
        }

        if (result.empty()) {
            std::cout << "Not Found" << std::endl;
        } else {
            for (const auto& id : result) {
                std::cout << id << std::endl;
            }
        }
    }

    return 0;
} 