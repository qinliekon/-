//
// Created by liekon on 2024/11/26.
//

#include<iostream>
#define MAX 100
using namespace std;

//�������ղ�ֵ
double Lagrange(double x[], double y[], int n, double x0) {
    double y0 = 0;
    for (int k = 0; k < n; k++) {
        double temp = y[k];
        for (int i = 0; i < n; i++) {
            if (i != k) {
                temp = temp * (x0 - x[i]);
                temp = temp / (x[k] - x[i]);
            }
        }
        y0 += temp;
    }
    return y0;
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
    cout << "����f(x)�ڵ�x0�Ľ���ֵΪ��" << Lagrange(x, y, n, x0) << endl;
    return 0;
}