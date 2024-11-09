#include <iostream>
#include <AI/ai> // install AI framework 

class AI{};
class MachineLearning:AI{};
class DeepLearning:AI{};
class IO{};


int main()
{
AI app;
// Run AI Simualtion Application:
MachineLearnin ml;
  ml.load("Model-007");
  ml.learn();
  if (ml.hasNext())
  {
    ml.next();
  }
  
  ml.predict('Q');
  ml.test();
  ml.save();
  
  app.RunAPP(ml);

return 0;
}
