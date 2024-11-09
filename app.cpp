#include <iostream>
#include <vector>
#include <algorithm>

#include "AI.hpp" // AI framework 

//class AI{};
class MachineLearning:public AI{
  std::vector<int> data;
  public:
  void load(std::string fileName){};
  void learn(){};
  void predict(std::string Q){};
  void test(){};
  void save(){};
  bool hasNext (){
    if (!data.empty()) {
        return true;
      }
    return false;
    };

  std::vector<int> next(){
       std::vector<int> data;
       // fetch data
       return data;
     };


};
class DeepLearning:public AI{};
class IO{};


int main()
{
AI app;
// Run AI Simualtion Application:
MachineLearning ml;
  ml.load("Model-007");
  ml.learn();
  if (ml.hasNext())
  {
    ml.next();
  }
  
  ml.predict("Q");
  ml.test();
  ml.save();
  
  app.runApp(&ml);

return 0;
}
