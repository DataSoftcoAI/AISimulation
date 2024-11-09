#include <iostream>
#include <string>
#include <vector>
#include <map>

class AI{
    public:
    int runApp(AI* app){
        return 0;
    };
};

class HumanBehaviorSimulatorAI {
public:
    virtual void learn() = 0;           // التعلم من التجارب
    virtual void makeDecision() = 0;     // اتخاذ القرارات بناءً على المعلومات
    virtual void interact() = 0;         // التفاعل مع البيئة أو الكائنات الأخرى
    virtual ~HumanBehaviorSimulatorAI() {}  // الدالة الافتراضية للمُدمر
};
class EcosystemSimulator {
public:
    virtual void simulateEnvironment() = 0;  // محاكاة البيئة المحيطة
    virtual void trackSpecies() = 0;         // تتبع الكائنات في النظام البيئي
    virtual void applyForces() = 0;          // تطبيق القوى الطبيعية (مثل الطقس، التغيرات المناخية)
    virtual ~EcosystemSimulator() {}
};

class AutonomousDrivingSimulator {
public:
    virtual void senseEnvironment() = 0;   // استشعار البيئة (كاميرات، حساسات)
    virtual void planPath() = 0;            // تخطيط المسار
    virtual void controlVehicle() = 0;      // التحكم في المركبة
    virtual ~AutonomousDrivingSimulator() {}
};

class DeepLearningSimulator {
public:
    virtual void trainModel() = 0;          // تدريب النموذج باستخدام البيانات
    virtual void testModel() = 0;           // اختبار النموذج
    virtual void updateModel() = 0;         // تحديث النموذج بناءً على الأداء
    virtual ~DeepLearningSimulator() {}
};

class DecisionMakingSimulator {
public:
    virtual void analyzeData() = 0;         // تحليل البيانات المدخلة
    virtual void evaluateOptions() = 0;     // تقييم الخيارات المتاحة
    virtual void makeChoice() = 0;          // اتخاذ القرار
    virtual ~DecisionMakingSimulator() {}
};


class HumanBehaviorSimulator:AI {
public:
    // التعلم من التجارب
    virtual void learn(const std::string& experience) = 0;
    
    // اتخاذ القرارات بناءً على المعلومات المتاحة
    virtual void makeDecision(const std::string& situation) = 0;
    
    // الاستجابة العاطفية للمواقف المختلفة
    virtual void expressEmotion(const std::string& emotionType) = 0;
    
    // التفاعل مع الآخرين أو مع البيئة
    virtual void interact(const std::string& interactionType) = 0;
    
    // تكيف الإنسان مع التغيرات
    virtual void adaptToChange(const std::string& change) = 0;
    
    // إظهار السلوكيات الاجتماعية
    virtual void socialize(const std::string& socialContext) = 0;
    
    virtual ~HumanBehaviorSimulator() {} // دالة الافتراضية للمُدمر
};
