#include "func.hpp"
#include <cctype>
#include <algorithm>

// Функция для проверки, является ли буква гласной
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Функция для подсчета количества согласных в слове
int countConsonants(const std::string& word) {
    int count = 0;
    for (char c : word) {
        if (isalpha(c) && !isVowel(c)) {
            count++;
        }
    }
    return count;
}

// Функция для удаления гласных и продублирования согласных
std::string processWord(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (isalpha(c) && !isVowel(c)) {
            result += c;
            result += c;
        }
    }
    return result;
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

// Функция для сортировки массива строк
void sortWords(std::string words[], int wordCount) {
    for (int i = 0; i < wordCount - 1; ++i) {
        for (int j = 0; j < wordCount - i - 1; ++j) {
            if (words[j] > words[j + 1]) {
                std::swap(words[j], words[j + 1]);
            }
        }
    }
}
