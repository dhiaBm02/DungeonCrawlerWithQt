#ifndef MYLIST_H
#define MYLIST_H


#include <cstddef>

#include <Level.h>

class myList
{
    struct Element;
    class iterator;
  public:
  myList();
  ~myList();
  void push_back(int );
  void pop_back();
  int& back();
  std::size_t size() const;
  bool empty() const;
  void push_front(int);
  void pop_front();
  void remove (int);
  iterator begin();
  iterator end() ;
  private:
  struct Element
  {
    int levl;
    Element* next;
    Element* previous;
  };
  Element* start  = nullptr;
  std::size_t m_size = 0;


  class iterator :public std::iterator< std::forward_iterator_tag, Level*> {
  public:
      iterator(Element* e);
      iterator& operator ++();
      iterator& operator --();
      int operator *();
      bool operator ==(const iterator& i);
      bool operator !=(const iterator& i);

  private:
      Element* current;

  };
};

#endif // MYLIST_H
