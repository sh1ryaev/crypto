#include "atbash.h"
#include "alphabet.h"
#include <cctype>  // Для isalpha, toupper, tolower

std::string atbashCipher(const std::string& text) {
    std::string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {  // Шифруем только буквы
            // Приводим символ к нижнему регистру для поиска в алфавите
            char lowerCh = tolower(ch);
            // Находим индекс символа в алфавите
            size_t index = LATIN_ALPHABET.find(lowerCh);
            if (index != std::string::npos) {  // Если символ найден в алфавите
                // Вычисляем симметричный индекс
                size_t newIndex = LATIN_ALPHABET.size() - 1 - index;
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