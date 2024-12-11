//
// Created by liekon on 2024/11/27.
//

#include <iostream>
#include <cmath>

using namespace std;

// 被积函数 f(x) = x^2
double f(double x) {
    return x * x; // 被积函数
}

// 复化梯形法计算定积分
double composite_trapezoidal(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n; // 步长
    double sum = 0.0;

    // 计算内部点的加权和
    for (int i = 1; i < n; ++i) {
        sum += func(a + i * h);
    }

    // 计算梯形法结果
    return (h / 2) * (func(a) + 2 * sum + func(b));
}

// 变步长递推的自适应积分方法
double adaptive_integration(double (*func)(double), double a, double b, double tol, int n_initial = 2) {
    int n = n_initial;  // 初始分割数
    double I1 = composite_trapezoidal(func, a, b, n);
    n *= 2;  // 增加分割数
    double I2 = composite_trapezoidal(func, a, b, n);

    // 误差估计
    if (fabs(I2 - I1) < tol) {
        return I2;
    } else {
        // 如果误差大于容忍度，继续细化区间
        return adaptive_integration(func, a, b, tol, n);
    }
}

int main() {
    // 设置积分区间、容忍度
    double a = 0.0;
    double b = 1.0; // 积分区间 [0, 1]
    double tol = 1e-6; // 容忍度

    // 调用自适应积分函数
    double result = adaptive_integration(f, a, b, tol);

    // 输出结果
    cout << "积分结果: " << result << endl;

    return 0;
}
