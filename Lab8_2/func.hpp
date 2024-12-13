#pragma once
#include <string>

bool isVowel(char c);

int countConsonants(const std::string& word);

std::string processWord(const std::string& word);

void splitString(const std::string& str, std::string words[], int& wordCount);

void sortWords(std::string words[], int wordCount);
