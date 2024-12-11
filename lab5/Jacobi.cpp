//
// Created by liekon on 2024/11/27.
//

#include <iostream>
#include <vector>
#include <cmath>

// Jacobi�������n�����Է����� A * x = b
std::vector<double> jacobiMethod(const std::vector<std::vector<double>>& A, const std::vector<double>& b, std::vector<double>& x, double tolerance, int maxIter) {
    int n = A.size();
    std::vector<double> x_new(n, 0.0);  // �µĽ�����

    // ��������
    for (int k = 0; k < maxIter; ++k) {
        // ��ÿ��δ֪������
        for (int i = 0; i < n; ++i) {
            double sum = b[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }
            x_new[i] = sum / A[i][i];
        }

        // ���������
        double norm = 0.0;
        for (int i = 0; i < n; ++i) {
            norm += std::pow(x_new[i] - x[i], 2);
        }

        norm = std::sqrt(norm);  // �����ı仯��ŷ����÷���
        if (norm < tolerance) {
            std::cout << "Converged after " << k + 1 << " iterations." << std::endl;
            return x_new;  // ���ؽ�����
        }

        // ���½�����
        x = x_new;
    }

    std::cerr << "Warning: Maximum iterations reached." << std::endl;
    return x_new;  // ���δ�������������Ľ��ƽ�
}

int main() {
    // ϵ������ A
    std::vector<std::vector<double>> A = {
            {4, -1, 0, 0},
            {-1, 4, -1, 0},
            {0, -1, 4, -1},
            {0, 0, -1, 3}
    };

    // �������� b
    std::vector<double> b = {15, 10, 10, 10};

    // ��ʼ�²������ x (һ���ʼΪ0)
    std::vector<double> x = {0.0, 0.0, 0.0, 0.0};

    // ����Ҫ�������������
    double tolerance = 1e-6;
    int maxIter = 100;

    // ʹ��Jacobi�������
    std::vector<double> solution = jacobiMethod(A, b, x, tolerance, maxIter);

    // ������
    std::cout << "The solution is:" << std::endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        std::cout << "x[" << i + 1 << "] = " << solution[i] << std::endl;
    }

    return 0;
}
