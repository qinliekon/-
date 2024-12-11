//
// Created by liekon on 2024/11/27.
//

#include <iostream>
#include <vector>
#include <cmath>

// Jacobi方法求解n阶线性方程组 A * x = b
std::vector<double> jacobiMethod(const std::vector<std::vector<double>>& A, const std::vector<double>& b, std::vector<double>& x, double tolerance, int maxIter) {
    int n = A.size();
    std::vector<double> x_new(n, 0.0);  // 新的解向量

    // 迭代过程
    for (int k = 0; k < maxIter; ++k) {
        // 对每个未知数更新
        for (int i = 0; i < n; ++i) {
            double sum = b[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }
            x_new[i] = sum / A[i][i];
        }

        // 检查收敛性
        double norm = 0.0;
        for (int i = 0; i < n; ++i) {
            norm += std::pow(x_new[i] - x[i], 2);
        }

        norm = std::sqrt(norm);  // 计算解的变化的欧几里得范数
        if (norm < tolerance) {
            std::cout << "Converged after " << k + 1 << " iterations." << std::endl;
            return x_new;  // 返回解向量
        }

        // 更新解向量
        x = x_new;
    }

    std::cerr << "Warning: Maximum iterations reached." << std::endl;
    return x_new;  // 如果未收敛，返回最后的近似解
}

int main() {
    // 系数矩阵 A
    std::vector<std::vector<double>> A = {
            {4, -1, 0, 0},
            {-1, 4, -1, 0},
            {0, -1, 4, -1},
            {0, 0, -1, 3}
    };

    // 常数向量 b
    std::vector<double> b = {15, 10, 10, 10};

    // 初始猜测解向量 x (一般初始为0)
    std::vector<double> x = {0.0, 0.0, 0.0, 0.0};

    // 精度要求和最大迭代次数
    double tolerance = 1e-6;
    int maxIter = 100;

    // 使用Jacobi方法求解
    std::vector<double> solution = jacobiMethod(A, b, x, tolerance, maxIter);

    // 输出结果
    std::cout << "The solution is:" << std::endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        std::cout << "x[" << i + 1 << "] = " << solution[i] << std::endl;
    }

    return 0;
}
