#pragma once
#include <string>

bool isVowel(char c);

bool areConsonantsOrdered(const std::string& word);

void splitString(const std::string& str, std::string words[], int& wordCount);

void sortWords(std::string words[], int wordCount);

int removeDuplicates(std::string words[], int wordCount);
