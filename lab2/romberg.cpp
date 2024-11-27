//
// Created by liekon on 2024/11/27.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

using namespace std;

// Romberg���ַ�
double romberg(function<double(double)> f, double a, double b, double tol = 1e-6, int max_iter = 10) {
    // ����һ����ά����R���洢�����ֵ
    vector<vector<double>> R(max_iter, vector<double>(max_iter, 0.0));

    // �������η���ĳ�ֵ
    R[0][0] = 0.5 * (b - a) * (f(a) + f(b));

    // ��������Romberg����
    for (int k = 1; k < max_iter; ++k) {
        double h = (b - a) / pow(2, k);  // ��������
        double sum_f = 0.0;

        // �������η����ֵ T_k
        for (int i = 1; i < pow(2, k-1); i += 2) {
            sum_f += f(a + i * h);  // �������������
        }

        // �����k�����η������ֵ
        R[k][0] = 0.5 * R[k-1][0] + h * sum_f;

        // ���Ƽ���Romberg����
        for (int j = 1; j <= k; ++j) {
            R[k][j] = (pow(4, j) * R[k][j-1] - R[k-1][j-1]) / (pow(4, j) - 1);
        }

        // ���������
        if (abs(R[k][k] - R[k-1][k-1]) < tol) {
            return R[k][k];
        }
    }

    // ������������������������������ֵ
    return R[max_iter-1][max_iter-1];
}

// ���Ժ�����x^2
double f(double x) {
    return 2 * x;
}

int main() {
    // ����������� [0, 1]
    double a = 0.0;
    double b = 1.0;

    // �������
    double result = romberg(f, a, b);

    // ������
    cout << "Romberg���ֽ��: " << result << endl;
    return 0;
}
