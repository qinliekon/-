//
// Created by liekon on 2024/11/26.
//

#include<iostream>
#define MAX 100
using namespace std;

//拉格朗日插值
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
    cout << "输入插值节点数 n ：" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "：";
        cin >> x[i] >> y[i];
    }
    cout << "输入要计算的 x0 ：";
    cin >> x0;
    cout << "函数f(x)在点x0的近似值为：" << Lagrange(x, y, n, x0) << endl;
    return 0;
}