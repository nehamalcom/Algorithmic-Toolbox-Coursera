#include <iostream>
#include <vector>

using namespace std;

int get_change(int money) {
    
  int minNumCoins[money+1];
  int coins[]={1,3,4};
  
  minNumCoins[0]=0;
  int numcoins=0;
  for(int m=1;m<=money;m++)
  {
      minNumCoins[m]=9999999;
      for(int i=0;i<3;i++)
      {
          if(m>=coins[i])
          {
              numcoins=minNumCoins[m-coins[i]]+1;
            if(numcoins<minNumCoins[m])
            {
                minNumCoins[m]=numcoins;
            }
          }
      }
  }
    
  return minNumCoins[money];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
