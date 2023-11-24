#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>

int main() {
    std::string input;
    std::string word = {};
    std::unordered_map<std::string, int> wordCounts;

    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    for (char ch : input) {
        if (isalnum(ch)) {
            word.push_back(ch);
        } else if (!word.empty()) {
            wordCounts[word]++;
            word.clear();
        }
    }
    if (!word.empty()) {
        wordCounts[word]++;
    }

    // Copia as chaves para um std::set para ordenação alfabética
    std::set<std::string> sortedWords;
    for (const auto& pair : wordCounts) {
        sortedWords.insert(pair.first);
    }

    // Imprime as palavras e suas contagens em ordem alfabética
    for (const auto& word : sortedWords) {
        std::cout << word << ' ' << wordCounts[word] << std::endl;
    }

    return 0;
}
