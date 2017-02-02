#ifndef TRACKINGDEQUE_H
#define TRACKINGDEQUE_H
#include <deque>
#include <iostream>
using namespace std;

template<typename T>
class TrackingDeque:public std::deque<T>
{
  public:
    TrackingDeque();
    void push_front(const T&);
    void push_back(const T&);
    ~TrackingDeque();
  private:
    int maximum_size;
};

template<typename T>
TrackingDeque<T>::TrackingDeque():maximum_size(0), std::deque<T>(0)
{}

template<typename T>
void TrackingDeque<T>::push_front(const T& val)
{
  deque<T>::push_front(val);
	int size=deque<T>::size();
  if(size>maximum_size)
  {
    maximum_size=size;
  }
}

template<typename T>
void TrackingDeque<T>::push_back(const T& val)
{
  deque<T>::push_back(val);
  int size=deque<T>::size();
  if(size>maximum_size)
  {
    maximum_size=size;
  }
}

template<typename T>
TrackingDeque<T>::~TrackingDeque()
{
  std::cout<<"--> "<<deque<T>::size()<<" <--"<<endl;
}

#endif
