#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using namespace std;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

/*vector<int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int leftp=l;
  int rightp=r;
  int i=l;
  while(i<=rightp)
  {
      if(a[i]<x)
      {
          swap(a[i],a[leftp]);
          leftp++;
          i++;     
      }
      else if(a[i]>x)
      {
          swap(a[i],a[rightp]);
          rightp--;
      }
      else
      {
          i++;
      }
  }
  vector<int>p;
  p.push_back(rightp);
  p.push_back(leftp);
  return p;
}*/

vector<int> partition3(vector<int> &a, int l, int r) {
    int x=a[l];
    int p1;
    int j=l;
    for(int i=l+1;i<=r;i++)
    {
        if(a[i]<=x)
        {
            j++;
            swap(a[i],a[j]);
        }
    }
    swap(a[l],a[j]);
    p1=j-1;
    for(int i=l;i<j && p1>=l && p1>i;)
    {
        if(a[j]==a[i])
            swap(a[i],a[p1--]);
        else
            i++;
    }
    p1++;
    vector<int>p;
    p.push_back(p1);
    p.push_back(j);
    return p;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  //int k = l + rand() % (r - l + 1);
  //swap(a[l], a[k]);
  //int m = partition2(a, l, r);

  //randomized_quick_sort(a, l, m - 1);
  //randomized_quick_sort(a, m + 1, r);
  vector<int>m;
  m=partition3(a,l,r);
  int pivot1=m[0];
  int pivot2=m[1];
  randomized_quick_sort(a,l,pivot1-1);
  randomized_quick_sort(a,pivot2+1,r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
