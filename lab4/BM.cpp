#include <iostream>
#include <cmath>
#include <functional>

// 定义方程 f(x) = 0，这里使用 f(x) = x^2 - 4 作为示例
double f(double x) {
    return x * x - 4;  // 例如 x^2 - 4 = 0
}

// 二分法求解 f(x) = 0
double bisectionMethod(double (*f)(double), double a, double b, double tol, int maxIter) {
    if (f(a) * f(b) >= 0) {
        std::cerr << "The function must have opposite signs at the endpoints a and b." << std::endl;
        return NAN;  // 返回无效值表示错误
    }

    double c = a;  // 用于存储中点
    int iter = 0;

    while ((b - a) / 2.0 > tol && iter < maxIter) {
        // 计算中点
        c = (a + b) / 2.0;

        // 输出当前区间和中点的值
        std::cout << "Iteration " << iter + 1 << ": a = " << a << ", b = " << b << ", c = " << c << ", f(c) = " << f(c) << std::endl;

        // 判断中点是否为根，或根在哪一侧
        if (f(c) == 0.0) {
            break;  // 找到精确根
        } else if (f(c) * f(a) < 0) {
            b = c;  // 根在左半区间
        } else {
            a = c;  // 根在右半区间
        }

        iter++;
    }

    // 返回中点作为根的近似值
    return c;
}

int main() {
    double a = 0.0;      // 区间的左端点
    double b = 3.0;      // 区间的右端点
    double tolerance = 1e-6; // 精度要求
    int maxIter = 100;    // 最大迭代次数

    // 使用二分法求解方程
    double root = bisectionMethod(f, a, b, tolerance, maxIter);

    // 输出结果
    if (!std::isnan(root)) {
        std::cout << "The root is approximately: " << root << std::endl;
    }

    return 0;
}
