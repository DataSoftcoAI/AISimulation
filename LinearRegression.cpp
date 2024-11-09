#include <iostream>
#include <vector>

class LinearRegression {
private:
    double weight;
    double bias;
    double learningRate;

public:
    LinearRegression(double lr = 0.01) : weight(0), bias(0), learningRate(lr) {}

    // دالة التوقع
    double predict(double x) {
        return weight * x + bias;
    }

    // دالة التدريب
    void train(const std::vector<double>& X, const std::vector<double>& y, int epochs) {
        for (int i = 0; i < epochs; ++i) {
            double totalErrorW = 0;
            double totalErrorB = 0;

            for (size_t j = 0; j < X.size(); ++j) {
                double prediction = predict(X[j]);
                double error = prediction - y[j];
                totalErrorW += error * X[j];
                totalErrorB += error;
            }

            // تحديث المعاملات
            weight -= learningRate * (totalErrorW / X.size());
            bias -= learningRate * (totalErrorB / X.size());

            // طباعة الخطأ في كل حقبة تدريبية
            if (i % 100 == 0) {
                std::cout << "Epoch " << i << " - Error: " << totalErrorW << std::endl;
            }
        }
    }
};

int main() {
    // بيانات تدريب بسيطة (يمكن أن تكون هذه البيانات من عالم حقيقي)
    std::vector<double> X = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 6, 8, 10};  // y = 2 * x

    // إعداد النموذج
    LinearRegression model(0.01);
    model.train(X, y, 1000);

    // اختبار النموذج
    double testValue = 6.0;
    std::cout << "Prediction for " << testValue << ": " << model.predict(testValue) << std::endl;

    return 0;
}
