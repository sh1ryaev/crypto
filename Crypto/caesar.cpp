// caesar.cpp
#include "caesar.h"
#include "alphabet.h"
#include <cctype>  // ��� isalpha, islower, toupper, tolower

// ������� ��� ���������� � ������������ ������

std::string caesarCipher(const std::string& text, int shift) {
    std::string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {  // ������� ������ ��������� �����
            // ������� ������ ������� � ��������
            size_t index = LATIN_ALPHABET.find(tolower(ch));
            if (index != std::string::npos) {  // ���� ������ ������ � ��������
                // ��������� ����� ������ � ������ ������
                size_t newIndex = (index + shift + LATIN_ALPHABET.size()) % LATIN_ALPHABET.size();
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
