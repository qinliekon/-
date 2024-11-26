//
// Created by liekon on 2024/11/26.
//

#include <iostream>
#include <vector>

const int MAX = 100; // 最大节点数

// 线性拟合函数，返回拟合的a和b
void linearFit(const double x[], const double y[], int n, double& a, double& b) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    // 计算所需的各项和
    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // 使用正规方程解线性回归
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;
}

int main() {
    double x[MAX], y[MAX];
    int n;
    double a, b; // 用来存储线性拟合的系数

    std::cout << "输入插值节点数 n ：" << std::endl;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "请输入第 " << i + 1 << " 个节点 (x, y): ";
        std::cin >> x[i] >> y[i];
    }

    // 调用线性拟合函数，计算a和b
    linearFit(x, y, n, a, b);

    // 输出拟合结果
    std::cout << "拟合的直线方程是: p(x) = " << a << " + " << b << "x" << std::endl;

    return 0;
}
