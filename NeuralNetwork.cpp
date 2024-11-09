#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

class NeuralNetwork {
private:
    std::vector<double> weights;
    double bias;
    double learningRate;

public:
    NeuralNetwork(int inputSize, double lr = 0.01) : bias(0), learningRate(lr) {
        // تهيئة الأوزان عشوائيًا
        weights.resize(inputSize);
        for (auto &weight : weights)
            weight = static_cast<double>(rand()) / RAND_MAX;
    }

    double sigmoid(double x) {
        return 1 / (1 + exp(-x));
    }

    double sigmoidDerivative(double x) {
        return x * (1 - x);
    }

    // دالة التوقع للشبكة العصبية
    double predict(const std::vector<double>& inputs) {
        double sum = bias;
        for (size_t i = 0; i < weights.size(); ++i)
            sum += weights[i] * inputs[i];
        return sigmoid(sum);
    }

    // تدريب باستخدام Mini-batch Gradient Descent
    void train(const std::vector<std::vector<double>>& X, const std::vector<double>& y, int epochs, int batchSize) {
        for (int i = 0; i < epochs; ++i) {
            double totalError = 0;
            for (size_t j = 0; j < X.size(); j += batchSize) {
                double errorSum = 0;
                for (size_t k = j; k < j + batchSize && k < X.size(); ++k) {
                    double prediction = predict(X[k]);
                    double error = y[k] - prediction;
                    errorSum += error;

                    // تحديث الأوزان والبياص
                    for (size_t l = 0; l < weights.size(); ++l)
                        weights[l] += learningRate * error * sigmoidDerivative(prediction) * X[k][l];
                    bias += learningRate * error * sigmoidDerivative(prediction);
                }
                totalError += errorSum;
            }
            // عرض الخطأ بعد كل حقبة
            if (i % 100 == 0) {
                std::cout << "Epoch " << i << " - Total Error: " << totalError << std::endl;
            }
        }
    }
};

int main() {
    // بيانات تدريبية بسيطة
    std::vector<std::vector<double>> X = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    std::vector<double> y = {0, 1, 1, 0}; // XOR

    // إنشاء نموذج الشبكة العصبية
    NeuralNetwork nn(2, 0.1);
    nn.train(X, y, 1000, 2);

    // اختبار النموذج
    std::vector<double> testInput = {1, 0};
    std::cout << "Prediction for [1, 0]: " << nn.predict(testInput) << std::endl;

    return 0;
}
