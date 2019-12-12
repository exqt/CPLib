template<class T>
struct vec2 {
  T x, y;
  vec2() {}
  vec2(T x, T y) : x(x), y(y) {}
  vec2<T> operator+(const vec2<T> o) { return vec2<T>(x+o.x, y+o.y); }
  vec2<T> operator-(const vec2<T> o) { return vec2<T>(x-o.x, y-o.y); }
  T dot(vec2<T> o) { return x*o.x + y*o.y; }
  T cross(vec2<T> o) { return x*o.y - y*o.x; }
  T length() { return x*x + y*y; } // squared
};

template<class T>
struct vec3 {
  T x, y, z;
  vec3() {}
  vec3(T x, T y, T z) : x(x), y(y), z(z) {}
  vec3<T> operator+(const vec3<T> o) { return vec3<T>(x+o.x, y+o.y, z+o.z); }
  vec3<T> operator-(const vec3<T> o) { return vec3<T>(x-o.x, y-o.y, z-o.z); }
  T dot(vec3<T> o) { return x*o.x + y*o.x + z*o.z; }
  vec3<T> cross(vec3<T> o) {
    return vec3<T>(y*o.z - z*o.y, -(x*o.z - z*o.x), x*o.y - y*o.x);
  }
  T length() { return x*x + y*y; } // squared
};
