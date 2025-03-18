// vigenere.h
#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

// Функция для шифрования текста
std::string vigenereEncrypt(const std::string& text, const std::string& key);

// Функция для дешифрования текста
std::string vigenereDecrypt(const std::string& text, const std::string& key);

#endif // VIGENERE_H