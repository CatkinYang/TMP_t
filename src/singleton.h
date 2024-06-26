#pragma once
#include <memory>

namespace TMP {

template <class T, class X = void, int N = 0> class singleton {
  public:
    static T *GetInstance() {
        static T v;
        return &v;
    }
};

template <class T, class X = void, int N = 0> class singletonPtr {
  public:
    static std::shared_ptr<T> GetInstance() {
        static std::shared_ptr<T> v(new T);
        return v;
    }
};
} // namespace TMP
