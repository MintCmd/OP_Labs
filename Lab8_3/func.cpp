#include "func.hpp"
#include <cctype>

// Функция для проверки, содержит ли слово две одинаковые буквы подряд
bool hasDoubleLetters(const std::string& word, char& doubleLetter) {
    for (size_t i = 0; i < word.length() - 1; ++i) {
        if (word[i] == word[i + 1]) {
            doubleLetter = word[i];
            return true;
        }
    }
    return false;
}

// Функция для обработки слова
std::string processWord(const std::string& word) {
    char doubleLetter;
    if (hasDoubleLetters(word, doubleLetter)) {
        std::string upperWord = word;
        for (char& c : upperWord) {
            c = toupper(c);
        }
        return upperWord + "(" + doubleLetter + doubleLetter + ")";
    }
    return word;
}

// Функция для разделения строки на слова
void splitString(const std::string& str, std::string words[], int& wordCount) {
    std::string word = "";
    wordCount = 0;
    for (char c : str) {
        if (isalpha(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                words[wordCount++] = word;
                word = "";
            }
            if (!isspace(c)) {
                words[wordCount++] = std::string(1, c);
            }
        }
    }
    if (!word.empty()) {
        words[wordCount++] = word;
    }
}
