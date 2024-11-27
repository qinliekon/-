//
// Created by liekon on 2024/11/27.
//

#include <iostream>
#include <cmath>
#include <functional>

// 定义方程 f(x) = 0，这里使用 f(x) = x^2 - 4 作为示例
double f(double x) {
    return x * x - 4;  // 例如 x^2 - 4 = 0
}

// 定义方程 f(x) 的导数 f'(x)，对于 f(x) = x^2 - 4, 导数是 f'(x) = 2x
double df(double x) {
    return 2 * x;  // 导数 f'(x) = 2x
}

// 牛顿迭代法求解 f(x) = 0
double newtonMethod(double (*f)(double), double (*df)(double), double x0, double tol, int maxIter) {
    double x = x0;
    int iter = 0;

    while (iter < maxIter) {
        // 计算 f(x) 和 f'(x)
        double fx = f(x);
        double dfx = df(x);

        // 如果导数为零，避免除以零的错误
        if (dfx == 0) {
            std::cerr << "Error: Derivative is zero." << std::endl;
            return NAN;
        }

        // 计算下一个近似解
        double x_next = x - fx / dfx;

        // 输出当前迭代的结果
        std::cout << "Iteration " << iter + 1 << ": x = " << x << ", f(x) = " << fx << ", x_next = " << x_next << std::endl;

        // 判断收敛
        if (std::abs(x_next - x) < tol) {
            return x_next;  // 收敛，返回近似根
        }

        // 更新当前解
        x = x_next;
        iter++;
    }

    std::cerr << "Warning: Maximum iterations reached." << std::endl;
    return x;  // 返回最后的近似解
}

int main() {
    // 初始猜测
    double x0 = 100.0;  // 初始猜测 x0 = 3
    double tolerance = 1e-6;  // 精度要求
    int maxIter = 100;  // 最大迭代次数

    // 使用牛顿法求解方程
    double root = newtonMethod(f, df, x0, tolerance, maxIter);

    // 输出结果
    if (!std::isnan(root)) {
        std::cout << "The root is approximately: " << root << std::endl;
    }

    return 0;
}