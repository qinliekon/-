//
// Created by liekon on 2024/11/26.
//

#include<iostream>
#define MAX 100
using namespace std;

//差商
double dividedDifference(double x[], double y[], int i, int j) {
    if (j == 0) {
        return y[i];
    } else {
        return (dividedDifference(x, y, i + 1, j - 1) - dividedDifference(x, y, i, j - 1)) / (x[i + j] - x[i]);
    }
}

//计算Newton插值多项式的值
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

// 计算Newton插值多项式在x0处的值
double newton(double x[], double y[], int n, double x0) {
    return newtonPolynomial(x, y, n, x0, n - 1);
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
    cout << "函数f(x)在点x0的近似值为：" << newton(x, y, n, x0) << endl;
    return 0;
}