#ifndef THELIST_H
#define THELIST_H


#include <cstddef>
#include <iterator>
#include<string.h>
class foo{
public :
    foo(int i){
        nbr =i;
    }
    int nbr =0;
};

template<typename T>
class myList
{
    struct Element;
    class iterator;
  public:
  myList();
  ~myList();
  void push_back(T );
  void pop_back();
  T& back();
  std::size_t size() const;
  bool empty() const;
  void push_front(T);
  void pop_front();
  void remove (T);
  iterator begin();
  iterator end() ;
  private:
  struct Element
  {
    T levl;
    Element* next;
    Element* previous;
  };
  Element* start  = nullptr;
  std::size_t m_size = 0;
  class iterator  {
  public:
      iterator(Element* e);
      iterator& operator ++(int);
      iterator& operator --(int);
      T operator *();
      bool operator ==(const iterator& i);
      bool operator !=(const iterator& i);
      T getvalue();
  private:
      Element* current;

  };
};
void error(const std::string&);
#endif // THELIST_H
