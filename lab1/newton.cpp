//
// Created by liekon on 2024/11/26.
//

#include<iostream>
#define MAX 100
using namespace std;

//����
double dividedDifference(double x[], double y[], int i, int j) {
    if (j == 0) {
        return y[i];
    } else {
        return (dividedDifference(x, y, i + 1, j - 1) - dividedDifference(x, y, i, j - 1)) / (x[i + j] - x[i]);
    }
}

//����Newton��ֵ����ʽ��ֵ
double newtonPolynomial(double x[], double y[], int n, double x0, int degree = 0) {
    if (degree == 0) {
        return y[0];
    } else {
        double term = dividedDifference(x, y, 0, degree) * 1;
        for (int i = 1; i <= degree; ++i) {
            term *= (x0 - x[i - 1]);
        }
        return term + newtonPolynomial(x, y, n, x0, degree - 1);
    }
}

// ����Newton��ֵ����ʽ��x0����ֵ
double newton(double x[], double y[], int n, double x0) {
    return newtonPolynomial(x, y, n, x0, n - 1);
}


int main() {
    double x[MAX], y[MAX];
    int n;
    double x0;
    cout << "�����ֵ�ڵ��� n ��" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "��";
        cin >> x[i] >> y[i];
    }
    cout << "����Ҫ����� x0 ��";
    cin >> x0;
    cout << "����f(x)�ڵ�x0�Ľ���ֵΪ��" << newton(x, y, n, x0) << endl;
    return 0;
}