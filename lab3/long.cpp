//
// Created by liekon on 2024/11/27.
//

#include <iostream>
#include <cmath>

// 定义常微分方程的右侧 f(t, y)，例如 y'(t) = -2y(t)
double f(double t, double y) {
    return -2 * y;  // 例如 y'(t) = -2y
}

// 使用四阶龙格-库塔方法（RK4）求解常微分方程
void rungeKutta4(double (*f)(double, double), double y0, double t0, double t_end, double h) {
    double y = y0;
    double t = t0;

    // 输出初始值
    std::cout << "t = " << t << ", y = " << y << std::endl;

    // 迭代计算直到达到终点 t_end
    while (t < t_end) {
        // 计算四个斜率 k1, k2, k3, k4
        double k1 = h * f(t, y);
        double k2 = h * f(t + h / 2, y + k1 / 2);
        double k3 = h * f(t + h / 2, y + k2 / 2);
        double k4 = h * f(t + h, y + k3);

        // 使用加权平均公式计算新的 y 值
        y = y + (1.0 / 6) * (k1 + 2 * k2 + 2 * k3 + k4);

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

    // 使用四阶龙格-库塔方法求解
    rungeKutta4(f, y0, t0, t_end, h);

    return 0;
}

