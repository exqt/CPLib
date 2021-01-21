template <typename T>
struct LabelEncoder {
  std::vector<T> l;
  LabelEncoder() {}
  void add(T x) {
    l.push_back(x);
  }
  void add(std::vector<T> &v) {
    for(auto x : v) add(x);
  }
  void process() {
    sort(l.begin(), l.end());
    l.resize(unique(l.begin(), l.end()) - l.begin());
  }
  int get(T v) {
    return lower_bound(l.begin(), l.end(), v) - l.begin();
  }
  std::vector<int> get(std::vector<T> &v) {
    std::vector<int> r;
    for(auto x : v) r.push_back(get(x));
    return r;
  }
};
