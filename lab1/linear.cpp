//
// Created by liekon on 2024/11/26.
//

#include <iostream>
#include <vector>

const int MAX = 100; // ���ڵ���

// ������Ϻ�����������ϵ�a��b
void linearFit(const double x[], const double y[], int n, double& a, double& b) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    // ��������ĸ����
    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // ʹ�����淽�̽����Իع�
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;
}

int main() {
    double x[MAX], y[MAX];
    int n;
    double a, b; // �����洢������ϵ�ϵ��

    std::cout << "�����ֵ�ڵ��� n ��" << std::endl;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "������� " << i + 1 << " ���ڵ� (x, y): ";
        std::cin >> x[i] >> y[i];
    }

    // ����������Ϻ���������a��b
    linearFit(x, y, n, a, b);

    // �����Ͻ��
    std::cout << "��ϵ�ֱ�߷�����: p(x) = " << a << " + " << b << "x" << std::endl;

    return 0;
}
