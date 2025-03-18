// vigenere.cpp
#include "vigenere.h"
#include "alphabet.h"
#include <cctype>  // Для isalpha, islower, toupper, tolower

// Вспомогательная функция для применения сдвига к символу
char applyShift(char ch, int shift, const std::string& alphabet) {
    if (isalpha(ch)) {  // Шифруем только латинские буквы
        // Находим индекс символа в алфавите
        size_t index = alphabet.find(tolower(ch));
        if (index != std::string::npos) {  // Если символ найден в алфавите
            // Вычисляем новый индекс с учетом сдвига
            size_t newIndex = (index + shift + alphabet.size()) % alphabet.size();
            // Получаем новый символ
            char newChar = alphabet[newIndex];
            // Сохраняем регистр
            return (isupper(ch) ? toupper(newChar) : newChar);
        }
    }
    return ch;  // Оставляем не-буквы без изменений
}

// Шифрование текста
std::string vigenereEncrypt(const std::string& text, const std::string& key) {
    std::string result = "";
    size_t keyIndex = 0;

    for (char ch : text) {
        if (isalpha(ch)) {  // Шифруем только латинские буквы
            // Получаем символ ключа (в нижнем регистре)
            char keyChar = tolower(key[keyIndex % key.size()]);
            // Находим индекс символа ключа в алфавите
            size_t keyShift = LATIN_ALPHABET.find(keyChar);
            // Применяем сдвиг
            result += applyShift(ch, keyShift, LATIN_ALPHABET);
            keyIndex++;
        }
        else {
            result += ch;  // Оставляем не-буквы без изменений
        }
    }

    return result;
}

// Дешифрование текста
std::string vigenereDecrypt(const std::string& text, const std::string& key) {
    std::string result = "";
    size_t keyIndex = 0;

    for (char ch : text) {
        if (isalpha(ch)) {  // Шифруем только латинские буквы
            // Получаем символ ключа (в нижнем регистре)
            char keyChar = tolower(key[keyIndex % key.size()]);
            // Находим индекс символа ключа в алфавите
            size_t keyShift = LATIN_ALPHABET.find(keyChar);
            // Применяем обратный сдвиг
            result += applyShift(ch, -static_cast<int>(keyShift), LATIN_ALPHABET);
            keyIndex++;
        }
        else {
            result += ch;  // Оставляем не-буквы без изменений
        }
    }

    return result;
}