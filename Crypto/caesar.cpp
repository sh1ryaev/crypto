// caesar.cpp
#include "caesar.h"
#include "alphabet.h"
#include <cctype>  // Для isalpha, islower, toupper, tolower

// Функция для шифрования и дешифрования текста

std::string caesarCipher(const std::string& text, int shift) {
    std::string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {  // Шифруем только латинские буквы
            // Находим индекс символа в алфавите
            size_t index = LATIN_ALPHABET.find(tolower(ch));
            if (index != std::string::npos) {  // Если символ найден в алфавите
                // Вычисляем новый индекс с учетом сдвига
                size_t newIndex = (index + shift + LATIN_ALPHABET.size()) % LATIN_ALPHABET.size();
                // Получаем новый символ
                char newChar = LATIN_ALPHABET[newIndex];
                // Сохраняем регистр
                result += (isupper(ch) ? toupper(newChar) : newChar);
            }
        }
        else {
            result += ch;  // Оставляем не-буквы без изменений
        }
    }

    return result;
}
