#include "theList.h"
#include <stdexcept>
#include <iostream>
#include"Level.h"
template<typename T>
myList<T>::myList()
{

}

template<typename T>
myList<T>::~myList()
{
}
template<typename T>
 void myList<T>::push_back(T level)
{
     std::cout<<"oush uo o o o o"<<std::endl;
    Element* tmp = new Element{level, nullptr,nullptr};
    if (empty())
      {
        start = tmp;
        m_size++;
        start->next=nullptr;
        return;
      }
    Element* current1 = nullptr;
    Element* current = nullptr;
    current = start;
    current1=start;

      while (current->next != nullptr)
      {
          current = current->next;
          current->previous=current1;
          current1=current;
      }
            current->next = tmp;
            tmp->previous=current;
            m_size++;
}
 template<typename T>
void myList<T>::push_front(T level)
{
    Element* tmp = new Element{level, nullptr,nullptr};
    if (start== nullptr)
    {
        start=tmp;
        m_size++;
        return;
    }
    tmp->next=start;
    start->previous=tmp;
    start=tmp;

    m_size++;
}

template<typename T>
void myList<T>::pop_back()
{
    if (start == nullptr)
      { std::cout<<"kein PopBack mehr !!!"<<std::endl;
        return;
      }
    if (start->next == nullptr)
     {
       delete start;
       start = nullptr;
       return;
     }
    Element* current = start;
      while (current->next->next != nullptr)
      {
        current = current->next;
      }
      delete current->next;
      current->next = nullptr;
      m_size--;
}
template<typename T>
std::size_t myList<T>::size() const
{
    return m_size;
}
template<typename T>

bool myList<T>::empty() const
{
    return m_size == 0;
}

template<typename T>

void myList<T>::pop_front()
{
    if(m_size<2){
        pop_back();
        return;
    }
    try {
        Element* current=start;
        start=current->next;
        start->previous=nullptr;
        delete current ;
        m_size--;
    } catch (const std::exception& e)
    {
        std::cerr<<"cant pop list ist empty !!! "<< std::endl;
    }

}
template<typename T>
void myList<T>::remove( T levl)
{
    Element * ptr =start;
    bool isFound = false;
    while(ptr!= nullptr){
        if(ptr->levl==levl){
            isFound=true;
        }
        ptr=ptr->next;
    }
    if(!isFound) {
        std::cout<<"this Level is not Found !!! "<<std::endl;
        return;}
    ptr=start;
    while(ptr!= nullptr){
      if(ptr->levl==levl){
        if(ptr==start){
        pop_front();
        continue;
        }

        if(ptr->next==nullptr){
            pop_back();
            return;
        }
        ptr->previous->next=ptr->next;
        ptr->next->previous=ptr->previous;
        m_size--;
      }
     ptr=ptr->next;
    }
}
template<typename T>

typename myList<T>::iterator myList<T>::begin()
{
    if(m_size==0) error("no begin h=the list is leer");
    return iterator(start);
}
template<typename T>
typename myList<T>::iterator myList<T>::end()
{
   Element* tmp=start;
   if(m_size<2) return begin();
   while (tmp->next!=nullptr)
   {
       tmp=tmp->next;
   }
   return iterator(tmp->next);

}
template<typename T>
myList<T>::iterator::iterator(Element *e)
{
    current=e;
}
template<typename T>
typename myList<T>::iterator &myList<T>::iterator::operator++(int)
{
    if(!current) error("from ++ ");
    current=current->next;
    return *this;
}
template<typename T>
typename myList<T>::iterator &myList<T>::iterator::operator--(int)
{
    if(!current) error("hey it is null ");
     current =current->previous;
    if (current==nullptr)
    {
        std::cout<<"opertaion nicht möglich weil sie im ersten Element sind !! "<<std::endl;
    }
    return *this;
}
template<typename T>
T myList<T>::iterator::operator *()
{
    if(!current) {
        error("nullptr is from *()");
        std::cout<<std::endl<<"cannot dereference null"<<std::endl;
    error("poineer is null");
        return current->levl ;}
    return current->levl;
}
template<typename T>
bool myList<T>::iterator::operator==(const iterator & i)
{
    bool test = i.current == this->current;
    return test;
}
template<typename T>
bool myList<T>::iterator::operator!=(const iterator &i)
{

    bool test = i.current != this->current;
    return test;
}
template class myList<int>;
template class myList<int*>;
template class myList<Level*>;
void error(const std::string& e){
    throw std::runtime_error(e);
}

template<typename T>
T myList<T>::iterator::getvalue()
{
   return current->levl;
}
