#pragma once
#include <string>

bool hasDoubleLetters(const std::string& word, char& doubleLetter);

std::string processWord(const std::string& word);

void splitString(const std::string& str, std::string words[], int& wordCount);
