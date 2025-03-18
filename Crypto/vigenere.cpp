// vigenere.cpp
#include "vigenere.h"
#include "alphabet.h"
#include <cctype>  // ��� isalpha, islower, toupper, tolower

// ��������������� ������� ��� ���������� ������ � �������
char applyShift(char ch, int shift, const std::string& alphabet) {
    if (isalpha(ch)) {  // ������� ������ ��������� �����
        // ������� ������ ������� � ��������
        size_t index = alphabet.find(tolower(ch));
        if (index != std::string::npos) {  // ���� ������ ������ � ��������
            // ��������� ����� ������ � ������ ������
            size_t newIndex = (index + shift + alphabet.size()) % alphabet.size();
            // �������� ����� ������
            char newChar = alphabet[newIndex];
            // ��������� �������
            return (isupper(ch) ? toupper(newChar) : newChar);
        }
    }
    return ch;  // ��������� ��-����� ��� ���������
}

// ���������� ������
std::string vigenereEncrypt(const std::string& text, const std::string& key) {
    std::string result = "";
    size_t keyIndex = 0;

    for (char ch : text) {
        if (isalpha(ch)) {  // ������� ������ ��������� �����
            // �������� ������ ����� (� ������ ��������)
            char keyChar = tolower(key[keyIndex % key.size()]);
            // ������� ������ ������� ����� � ��������
            size_t keyShift = LATIN_ALPHABET.find(keyChar);
            // ��������� �����
            result += applyShift(ch, keyShift, LATIN_ALPHABET);
            keyIndex++;
        }
        else {
            result += ch;  // ��������� ��-����� ��� ���������
        }
    }

    return result;
}

// ������������ ������
std::string vigenereDecrypt(const std::string& text, const std::string& key) {
    std::string result = "";
    size_t keyIndex = 0;

    for (char ch : text) {
        if (isalpha(ch)) {  // ������� ������ ��������� �����
            // �������� ������ ����� (� ������ ��������)
            char keyChar = tolower(key[keyIndex % key.size()]);
            // ������� ������ ������� ����� � ��������
            size_t keyShift = LATIN_ALPHABET.find(keyChar);
            // ��������� �������� �����
            result += applyShift(ch, -static_cast<int>(keyShift), LATIN_ALPHABET);
            keyIndex++;
        }
        else {
            result += ch;  // ��������� ��-����� ��� ���������
        }
    }

    return result;
}