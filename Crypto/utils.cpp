#include "utils.h"
#include "alphabet.h"
#include <cctype>  // Для isalpha, toupper, tolower
#include <vector>


int extendedGCD(int a, int b, int& x, int& y) {
    if (a == 0) {
        // Базовый случай: если a = 0, то gcd(b, 0) = b
        // В этом случае x = 0, y = 1, так как b*1 + 0*0 = b
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;  // Временные переменные для коэффициентов
    int gcd = extendedGCD(b % a, a, x1, y1); // Рекурсивный вызов с (b % a, a)

    // Вычисление коэффициентов x и y на основе результатов рекурсивного вызова
    x = y1 - (b / a) * x1;
    y = x1;

    return gcd; // Возвращаем НОД
}


// Функция для явного перевода числа в двоичный код
std::vector<int> toBinary(int n) {
    std::vector<int> binary;
    while (n > 0) {
        binary.push_back(n % 2);  // Берем последний бит (остаток от деления на 2)
        n /= 2;                   // Убираем обработанный бит (сдвиг вправо)
    }
    return binary; // Возвращаем двоичное представление (обратный порядок)
}

// Быстрое возведение в степень с явным использованием двоичной системы
long long fastPower(long long base, long long exp, long long mod) {
    std::vector<int> binaryExp = toBinary(exp); // Получаем двоичный код экспоненты
    long long result = 1;
    long long power = base;  // Текущее основание, которое будет возводиться в степени 2^i

    // Обрабатываем биты слева направо (с младшего разряда)
    for (int i = 0; i < binaryExp.size(); i++) {
        if (binaryExp[i] == 1) {  // Если бит равен 1, умножаем result на текущее значение power
            result = (result * power) % mod;
        }
        power = (power * power) % mod; // Возводим основание в квадрат
    }

    return result;
}
