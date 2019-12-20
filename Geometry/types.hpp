#ifndef _GEO_TYPES_
#define _GEO_TYPES_
template<class T>
struct vec2 {
  T x, y;
  vec2() {}
  vec2(T x, T y) : x(x), y(y) {}
  vec2<T> operator+(const vec2<T> o) const { return vec2<T>(x+o.x, y+o.y); }
  vec2<T> operator-(const vec2<T> o) const { return vec2<T>(x-o.x, y-o.y); }
  bool operator==(const vec2<T> o) const { return x == o.x && y == o.y; }
  T dot(const vec2<T> o) const { return x*o.x + y*o.y; }
  T cross(const vec2<T> o) const { return x*o.y - y*o.x; }
  T length() { return x*x + y*y; } // squared
};

template<class T>
struct vec3 {
  T x, y, z;
  vec3() {}
  vec3(T x, T y, T z) : x(x), y(y), z(z) {}
  vec3<T> operator+(const vec3<T> o) const { return vec3<T>(x+o.x, y+o.y, z+o.z); }
  vec3<T> operator-(const vec3<T> o) const { return vec3<T>(x-o.x, y-o.y, z-o.z); }
  bool operator==(const vec3<T> o) const { return x == o.x && y == o.y && z == o.z; }
  T dot(const vec3<T> o) const { return x*o.x + y*o.y + z*o.z; }
  vec3<T> cross(const vec3<T> o) const { return vec3<T>(y*o.z - z*o.y, -(x*o.z - z*o.x), x*o.y - y*o.x); }
  T length() { return x*x + y*y + z*z; } // squared
};
#else
#endif
