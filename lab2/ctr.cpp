//
// Created by liekon on 2024/11/27.
//

#include <iostream>
#include <cmath>

using namespace std;

// �������� f(x) = x^2
double f(double x) {
    return x * x; // ��������
}

// �������η����㶨����
double composite_trapezoidal(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n; // ����
    double sum = 0.0;

    // �����ڲ���ļ�Ȩ��
    for (int i = 1; i < n; ++i) {
        sum += func(a + i * h);
    }

    // �������η����
    return (h / 2) * (func(a) + 2 * sum + func(b));
}

// �䲽�����Ƶ�����Ӧ���ַ���
double adaptive_integration(double (*func)(double), double a, double b, double tol, int n_initial = 2) {
    int n = n_initial;  // ��ʼ�ָ���
    double I1 = composite_trapezoidal(func, a, b, n);
    n *= 2;  // ���ӷָ���
    double I2 = composite_trapezoidal(func, a, b, n);

    // ������
    if (fabs(I2 - I1) < tol) {
        return I2;
    } else {
        // ������������̶ȣ�����ϸ������
        return adaptive_integration(func, a, b, tol, n);
    }
}

int main() {
    // ���û������䡢���̶�
    double a = 0.0;
    double b = 1.0; // �������� [0, 1]
    double tol = 1e-6; // ���̶�

    // ��������Ӧ���ֺ���
    double result = adaptive_integration(f, a, b, tol);

    // ������
    cout << "���ֽ��: " << result << endl;

    return 0;
}
