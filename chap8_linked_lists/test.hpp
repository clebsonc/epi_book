#ifndef test_hpp
#define test_hpp


template <typename T>
class test{
  public:
    T sum(T, T) const;

    int sub(int a, int b) const;
};



template <typename T>
T test<T>::sum(T a, T b) const{
  return a+b;
}



#endif
