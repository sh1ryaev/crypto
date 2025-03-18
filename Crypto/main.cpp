#include "caesar.h"
#include "vigenere.h"
#include "atbash.h"
#include "utils.h"
#include <iostream>

void runCaesarTests() {
    // Тест 1: Шифрование с положительным сдвигом
    std::string text1 = "Hello, World!";
    int shift1 = 3;
    std::string encrypted1 = caesarCipher(text1, shift1);
    std::string decrypted1 = caesarCipher(encrypted1, -shift1);
    std::cout << "Test 1:\n";
    std::cout << "Original: " << text1 << "\n";
    std::cout << "Encrypted: " << encrypted1 << "\n";
    std::cout << "Decrypted: " << decrypted1 << "\n\n";

    // Тест 2: Шифрование с отрицательным сдвигом
    std::string text2 = "Hello, World!";
    int shift2 = -5;
    std::string encrypted2 = caesarCipher(text2, shift2);
    std::string decrypted2 = caesarCipher(encrypted2, -shift2);
    std::cout << "Test 2:\n";
    std::cout << "Original: " << text2 << "\n";
    std::cout << "Encrypted: " << encrypted2 << "\n";
    std::cout << "Decrypted: " << decrypted2 << "\n\n";

    // Тест 3: Шифрование с большим сдвигом
    std::string text3 = "Hello, World!";
    int shift3 = 30;  // Сдвиг больше размера алфавита
    std::string encrypted3 = caesarCipher(text3, shift3);
    std::string decrypted3 = caesarCipher(encrypted3, -shift3);
    std::cout << "Test 3:\n";
    std::cout << "Original: " << text3 << "\n";
    std::cout << "Encrypted: " << encrypted3 << "\n";
    std::cout << "Decrypted: " << decrypted3 << "\n\n";
}

void runVigenereTests() {
    std::string text = "Hello, World!";
    std::string key = "key";
    std::string vigenereEncrypted = vigenereEncrypt(text, key);
    std::cout << "Encrypted text: " << vigenereEncrypted << "\n";
    std::string vigenereDecrypted = vigenereDecrypt(vigenereEncrypted, key);
    std::cout << "Decrypted text: " << vigenereDecrypted << "\n";
}

void runAtbashTests() {
    // Тест 1: Обычный текст
    std::string text1 = "Hello, World!";
    std::string encrypted1 = atbashCipher(text1);
    std::string decrypted1 = atbashCipher(encrypted1);
    std::cout << "Test 1:\n";
    std::cout << "Original: " << text1 << "\n";
    std::cout << "Encrypted: " << encrypted1 << "\n";
    std::cout << "Decrypted: " << decrypted1 << "\n\n";

    // Тест 2: Текст с цифрами и символами
    std::string text2 = "Atbash123!";
    std::string encrypted2 = atbashCipher(text2);
    std::string decrypted2 = atbashCipher(encrypted2);
    std::cout << "Test 2:\n";
    std::cout << "Original: " << text2 << "\n";
    std::cout << "Encrypted: " << encrypted2 << "\n";
    std::cout << "Decrypted: " << decrypted2 << "\n\n";

    // Тест 3: Только буквы в нижнем регистре
    std::string text3 = "abcdefg";
    std::string encrypted3 = atbashCipher(text3);
    std::string decrypted3 = atbashCipher(encrypted3);
    std::cout << "Test 3:\n";
    std::cout << "Original: " << text3 << "\n";
    std::cout << "Encrypted: " << encrypted3 << "\n";
    std::cout << "Decrypted: " << decrypted3 << "\n\n";
}
// Функция для тестирования fastPower
void testFastPower() {
    std::cout << "Testing fastPower:\n";

    std::cout << "2^10 % 1000 = " << fastPower(2, 10, 1000) << " (Expected: 24)\n";
    std::cout << "3^5 % 13 = " << fastPower(3, 5, 13) << " (Expected: 9)\n";
    std::cout << "10^0 % 7 = " << fastPower(10, 0, 7) << " (Expected: 1)\n";
    std::cout << "5^3 % 7 = " << fastPower(5, 3, 7) << " (Expected: 6)\n";
    std::cout << "7^2 % 5 = " << fastPower(7, 2, 5) << " (Expected: 4)\n";
    std::cout << "123^456 % 789 = " << fastPower(123, 456, 789) << " (Expected: " << (123 % 789) << ")\n";

    std::cout << "fastPower tests completed.\n\n";
}

// Функция для тестирования extendedGCD
void testExtendedGCD() {
    std::cout << "Testing extendedGCD:\n";

    int x, y, gcd;

    gcd = extendedGCD(35, 15, x, y);
    std::cout << "GCD(35, 15) = " << gcd << ", x = " << x << ", y = " << y << " (Expected GCD: 5)\n";
    std::cout << "Check: 35 * " << x << " + 15 * " << y << " = " << (35 * x + 15 * y) << "\n\n";

    gcd = extendedGCD(101, 103, x, y);
    std::cout << "GCD(101, 103) = " << gcd << ", x = " << x << ", y = " << y << " (Expected GCD: 1)\n";
    std::cout << "Check: 101 * " << x << " + 103 * " << y << " = " << (101 * x + 103 * y) << "\n\n";

    gcd = extendedGCD(252, 105, x, y);
    std::cout << "GCD(252, 105) = " << gcd << ", x = " << x << ", y = " << y << " (Expected GCD: 21)\n";
    std::cout << "Check: 252 * " << x << " + 105 * " << y << " = " << (252 * x + 105 * y) << "\n\n";

    gcd = extendedGCD(0, 9, x, y);
    std::cout << "GCD(0, 9) = " << gcd << ", x = " << x << ", y = " << y << " (Expected GCD: 9)\n";
    std::cout << "Check: 0 * " << x << " + 9 * " << y << " = " << (0 * x + 9 * y) << "\n\n";

    gcd = extendedGCD(9, 0, x, y);
    std::cout << "GCD(9, 0) = " << gcd << ", x = " << x << ", y = " << y << " (Expected GCD: 9)\n";
    std::cout << "Check: 9 * " << x << " + 0 * " << y << " = " << (9 * x + 0 * y) << "\n\n";

    std::cout << "extendedGCD tests completed.\n";
}


int main()
{
    //runCaesarTests();

    //runVigenereTests();

    //runAtbashTests();

    testExtendedGCD();

    testFastPower();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
