#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

long long max_dot_product(vector<int> a, vector<int> b) {
  for(int i=0;i<a.size();i++)
  {
      for(int j=i;j<(a.size());j++)
      {
          if(a[i]>a[j])
          {
              int temp=a[i];
              a[i]=a[j];
              a[j]=temp;
          }
      }
  }
  
  cout<<endl<<endl;
  for(int i=0;i<b.size();i++)
  {
      for(int j=i;j<(b.size());j++)
      {
          if(b[i]>b[j])
          {
              int temp=b[i];
              b[i]=b[j];
              b[j]=temp;
          }
      }
  }

  long long result = 0;
  for (int i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
