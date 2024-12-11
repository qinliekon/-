//
// Created by liekon on 2024/11/27.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // ����С�����������
using namespace std;

// ��������
double f(double x) {
    return x * x; // ʾ������
}

// ������
int quick_power(int base, int power) {
    int result = 1;
    while (power > 0) {
        if (power & 1) {
            result *= base;
        }
        base *= base;
        power >>= 1;
    }
    return result;
}

// �������ι�ʽ
double compositeTrapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double Tn = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        Tn += 2 * f(a + i * h);
    }
    return (Tn * h) / 2;
}

// Romberg ����
double rombergIntegration(double a, double b, double epsilon) {
    vector<vector<double>> table; // ��̬��ά���ʡ�ռ�
    table.push_back(vector<double>(1, compositeTrapezoidal(a, b, 1))); // ��ʼֵ T(2^0)

    int i = 1;
    while (true) {
        table.push_back(vector<double>(1, compositeTrapezoidal(a, b, quick_power(2, i))));
        for (int j = 1; j <= i; j++) {
            double temp = (quick_power(4, j) * table[i][j - 1] - table[i - 1][j - 1]) / (quick_power(4, j) - 1);
            table[i].push_back(temp);
        }
        if (abs(table[i][i] - table[i - 1][i - 1]) <= epsilon) {
            return table[i][i];
        }
        i++;
    }

}

int main() {
    double a, b, epsilon;

    // �������䷶Χ�������
    cout << "���������䷶Χ [a, b]: ";
    cin >> a >> b;
    cout << "�����������: ";
    cin >> epsilon;

    // ���������Ч��
    if (a >= b || epsilon <= 0) {
        cerr << "������Ч���������䷶Χ������ޡ�" << endl;
        return 1;
    }

    // �������
    double result = rombergIntegration(a, b, epsilon);

    // ������
    cout << fixed << setprecision(6); // ���������ʽΪС�����6λ
    cout << "���ֽ��Ϊ: " << result << endl;

    return 0;
}

