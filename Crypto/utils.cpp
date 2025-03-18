#include "utils.h"
#include "alphabet.h"
#include <cctype>  // ��� isalpha, toupper, tolower
#include <vector>


int extendedGCD(int a, int b, int& x, int& y) {
    if (a == 0) {
        // ������� ������: ���� a = 0, �� gcd(b, 0) = b
        // � ���� ������ x = 0, y = 1, ��� ��� b*1 + 0*0 = b
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;  // ��������� ���������� ��� �������������
    int gcd = extendedGCD(b % a, a, x1, y1); // ����������� ����� � (b % a, a)

    // ���������� ������������� x � y �� ������ ����������� ������������ ������
    x = y1 - (b / a) * x1;
    y = x1;

    return gcd; // ���������� ���
}


// ������� ��� ������ �������� ����� � �������� ���
std::vector<int> toBinary(int n) {
    std::vector<int> binary;
    while (n > 0) {
        binary.push_back(n % 2);  // ����� ��������� ��� (������� �� ������� �� 2)
        n /= 2;                   // ������� ������������ ��� (����� ������)
    }
    return binary; // ���������� �������� ������������� (�������� �������)
}

// ������� ���������� � ������� � ����� �������������� �������� �������
long long fastPower(long long base, long long exp, long long mod) {
    std::vector<int> binaryExp = toBinary(exp); // �������� �������� ��� ����������
    long long result = 1;
    long long power = base;  // ������� ���������, ������� ����� ����������� � ������� 2^i

    // ������������ ���� ����� ������� (� �������� �������)
    for (int i = 0; i < binaryExp.size(); i++) {
        if (binaryExp[i] == 1) {  // ���� ��� ����� 1, �������� result �� ������� �������� power
            result = (result * power) % mod;
        }
        power = (power * power) % mod; // �������� ��������� � �������
    }

    return result;
}
