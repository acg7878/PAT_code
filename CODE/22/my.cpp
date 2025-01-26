#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

struct Book {
  std::string id;
  std::string title;
  std::string author;
  std::string key_words;
  std::string publisher_name;
  std::string publisher_year;
};

std::map<std::string, std::set<std::string>> title_map, author_map, key_map,
    publisher_map, year_map;

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();
  while (n--) {
    Book book;
    std::getline(std::cin, book.id);
    std::getline(std::cin, book.title);
    std::getline(std::cin, book.author);
    std::getline(std::cin, book.key_words);
    std::getline(std::cin, book.publisher_name);
    std::getline(std::cin, book.publisher_year);

    title_map[book.title].insert(book.id);
    author_map[book.author].insert(book.id);
    std::stringstream ss(book.key_words);
    std::string key_word;
    while (ss >> key_word) {
      key_map[key_word].insert(book.id);
    }
    publisher_map[book.publisher_name].insert(book.id);
    year_map[book.publisher_year].insert(book.id);
  }
  int m;
  std::cin >> m;
  std::cin.ignore();
  while (m--) {
    std::string search;
    std::getline(std::cin, search);
    std::cout << search << std::endl;
    char search_index = search[0];
    std::string search_content = search.substr(3);

    std::set<std::string> result;
    if (search_index == '1')
      result = title_map[search_content];
    else if (search_index == '2')
      result = author_map[search_content];
    else if (search_index == '3')
      result = key_map[search_content];
    else if (search_index == '4')
      result = publisher_map[search_content];
    else if (search_index == '5')
      result = year_map[search_content];

    if (result.empty())
      std::cout << "Not Found" << std::endl;
    else {
      for (const std::string& str : result) {
        std::cout << str << std::endl;
      }
    }
  }
  return 0;
}