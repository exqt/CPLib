#include <vector>

namespace array2D {

template<class T>
using array2D = std::vector<std::vector<T>>;

template<class T>
std::vector<std::vector<T>> input(int n, int m) {
  std::vector<std::vector<T>> a(n, std::vector<T>(m));
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> a[i][j];
    }
  }
  return a;
}

template<class T>
void print(std::vector<std::vector<T>> &a) {
  int n = a.size();
  int m = a[0].size();
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}

template<class T>
std::vector<std::vector<T>> rotate(std::vector<std::vector<T>> &a, bool CW=false) {
  int n = a.size();
  int m = a[0].size();
  std::vector<std::vector<T>> b(m, std::vector<T>(n));
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(!CW) b[m-1-j][i] = a[i][j];
      else b[j][n-1-i] = a[i][j];
    }
  }
  
  return b;
}

}
