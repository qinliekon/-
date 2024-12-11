//
// Created by liekon on 2024/11/27.
//

#include <iostream>
#include <cmath>

// 定义常微分方程的右侧 f(t, y)，以 y'(t) = -2y(t) 为例
double f(double t, double y) {
    return -2 * y;  // 比如 y'(t) = -2y
}

// 使用改进的欧拉方法（Heun 方法）求解常微分方程
void improvedEuler(double (*f)(double, double), double y0, double t0, double t_end, double h) {
    double y = y0;
    double t = t0;

    // 输出初始值
    std::cout << "t = " << t << ", y = " << y << std::endl;

    // 迭代计算直到达到终点 t_end
    while (t < t_end) {
        // 预测步骤：使用欧拉方法计算预测值
        double y_star = y + h * f(t, y);

        // 校正步骤：利用预测值来更新 y 的值
        y = y + (h / 2) * (f(t, y) + f(t + h, y_star));

        // 更新时间
        t += h;

        // 输出当前的 t 和 y 值
        std::cout << "t = " << t << ", y = " << y << std::endl;
    }
}

int main() {
    // 定义初始条件
    double y0 = 1.0;    // 初始值 y(0) = 1
    double t0 = 0.0;    // 起始时间 t0 = 0
    double t_end = 2.0; // 结束时间 t_end = 2
    double h = 0.1;     // 步长 h = 0.1

    // 使用改进欧拉方法求解
    improvedEuler(f, y0, t0, t_end, h);

    return 0;
}
