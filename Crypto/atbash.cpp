#include "atbash.h"
#include "alphabet.h"
#include <cctype>  // ��� isalpha, toupper, tolower

std::string atbashCipher(const std::string& text) {
    std::string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {  // ������� ������ �����
            // �������� ������ � ������� �������� ��� ������ � ��������
            char lowerCh = tolower(ch);
            // ������� ������ ������� � ��������
            size_t index = LATIN_ALPHABET.find(lowerCh);
            if (index != std::string::npos) {  // ���� ������ ������ � ��������
                // ��������� ������������ ������
                size_t newIndex = LATIN_ALPHABET.size() - 1 - index;
                // �������� ����� ������
                char newChar = LATIN_ALPHABET[newIndex];
                // ��������� �������
                result += (isupper(ch) ? toupper(newChar) : newChar);
            }
        }
        else {
            result += ch;  // ��������� ��-����� ��� ���������
        }
    }

    return result;
}