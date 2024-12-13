#include "func.hpp"
#include <algorithm>
#include <cctype>
// Функция для проверки, является ли буква гласной
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Функция для проверки, упорядочены ли согласные буквы в слове по алфавиту
bool areConsonantsOrdered(const std::string& word) {
    std::string consonants;
    for (char c : word) {
        if (isalpha(c) && !isVowel(c)) {
            consonants += c;
        }
    }
    return std::is_sorted(consonants.begin(), consonants.end());
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
        }
    }
    if (!word.empty()) {
        words[wordCount++] = word;
    }
}

// Функция для сортировки массива строк по невозрастанию длины
void sortWords(std::string words[], int wordCount) {
    for (int i = 0; i < wordCount - 1; ++i) {
        for (int j = 0; j < wordCount - i - 1; ++j) {
            if (words[j].length() < words[j + 1].length()) {
                std::swap(words[j], words[j + 1]);
            }
        }
    }
}

// Функция для удаления дубликатов из массива строк
int removeDuplicates(std::string words[], int wordCount) {
    int uniqueCount = 0;
    for (int i = 0; i < wordCount; ++i) {
        bool isUnique = true;
        for (int j = 0; j < uniqueCount; ++j) {
            if (words[i] == words[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            words[uniqueCount++] = words[i];
        }
    }
    return uniqueCount;
}