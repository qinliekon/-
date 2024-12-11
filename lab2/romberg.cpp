//
// Created by liekon on 2024/11/27.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // 控制小数点输出精度
using namespace std;

// 被积函数
double f(double x) {
    return x * x; // 示例函数
}

// 快速幂
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

// 复合梯形公式
double compositeTrapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double Tn = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        Tn += 2 * f(a + i * h);
    }
    return (Tn * h) / 2;
}

// Romberg 积分
double rombergIntegration(double a, double b, double epsilon) {
    vector<vector<double>> table; // 动态二维表节省空间
    table.push_back(vector<double>(1, compositeTrapezoidal(a, b, 1))); // 初始值 T(2^0)

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

    // 输入区间范围和误差限
    cout << "请输入区间范围 [a, b]: ";
    cin >> a >> b;
    cout << "请输入误差限: ";
    cin >> epsilon;

    // 检查输入有效性
    if (a >= b || epsilon <= 0) {
        cerr << "输入无效，请检查区间范围和误差限。" << endl;
        return 1;
    }

    // 计算积分
    double result = rombergIntegration(a, b, epsilon);

    // 输出结果
    cout << fixed << setprecision(6); // 设置输出格式为小数点后6位
    cout << "积分结果为: " << result << endl;

    return 0;
}

