#include <iostream>
#include <vector>

using std::vector;
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int W = 0;
  
  int num_of_items=weights.size();
  vector<double> value_per_weight(num_of_items);
  
  for(int i=0;i<num_of_items;i++)
  {
      value_per_weight[i]=(values[i]/(double)weights[i]);
  }
  for(int i=0;i<num_of_items;i++)
  {
      for(int j=i+1;j<num_of_items;j++)
      {
          if(value_per_weight[i]<value_per_weight[j])
          {
              double temp2=value_per_weight[i];
              value_per_weight[i]=value_per_weight[j];
              value_per_weight[j]=temp2;
              
              int temp=values[i];
              values[i]=values[j];
              values[j]=temp;
              
              temp=weights[i];
              weights[i]=weights[j];
              weights[j]=temp;
          }
      }
  }
  /*cout<<endl<< "Weights: ";
  for(int i=0;i<num_of_items;i++)
  {
      cout<<weights[i]<< "  ";
  }
  cout<<endl<< "Values: ";
  for(int i=0;i<num_of_items;i++)
  {
      cout<<values[i]<< "  ";
  }
  cout<<endl<< "Values per weight: ";
  for(int i=0;i<num_of_items;i++)
  {
      cout<<value_per_weight[i]<< "  ";
  }
  cout<<endl<<endl;*/
  
  int i=0;
  while(i<num_of_items)
  {
      if(W==capacity)
          return value;
      while((weights[i]!=0)&&(W<capacity))
      {
          W+=1;
          weights[i]-=1;
          value+= value_per_weight[i];
      }
      i++;
  }
  
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
