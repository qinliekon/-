//
// Created by liekon on 2024/11/27.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

using namespace std;

// Romberg积分法
double romberg(function<double(double)> f, double a, double b, double tol = 1e-6, int max_iter = 10) {
    // 创建一个二维数组R来存储计算的值
    vector<vector<double>> R(max_iter, vector<double>(max_iter, 0.0));

    // 计算梯形法则的初值
    R[0][0] = 0.5 * (b - a) * (f(a) + f(b));

    // 迭代计算Romberg积分
    for (int k = 1; k < max_iter; ++k) {
        double h = (b - a) / pow(2, k);  // 步长减半
        double sum_f = 0.0;

        // 计算梯形法则的值 T_k
        for (int i = 1; i < pow(2, k-1); i += 2) {
            sum_f += f(a + i * h);  // 仅对奇数点求和
        }

        // 计算第k次梯形法则近似值
        R[k][0] = 0.5 * R[k-1][0] + h * sum_f;

        // 递推计算Romberg积分
        for (int j = 1; j <= k; ++j) {
            R[k][j] = (pow(4, j) * R[k][j-1] - R[k-1][j-1]) / (pow(4, j) - 1);
        }

        // 检查收敛性
        if (abs(R[k][k] - R[k-1][k-1]) < tol) {
            return R[k][k];
        }
    }

    // 如果超过最大迭代次数，返回最后计算的值
    return R[max_iter-1][max_iter-1];
}

// 测试函数：x^2
double f(double x) {
    return 2 * x;
}

int main() {
    // 定义积分区间 [0, 1]
    double a = 0.0;
    double b = 1.0;

    // 计算积分
    double result = romberg(f, a, b);

    // 输出结果
    cout << "Romberg积分结果: " << result << endl;
    return 0;
}
