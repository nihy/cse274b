/*
 * DataStructureTester.h
 *
 *  Created on: Nov 11, 2014
 *      Author: Henry
 */

#ifndef DATASTRUCTURETESTER_H_
#define DATASTRUCTURETESTER_H_

#include <ctime>
#include <cstdlib>

using namespace std;
namespace ods {

template<class T>
class DataStructureTester {
protected:
  T list;
  clock_t runtime;
public:
  DataStructureTester();
  //virtual ~DataStructureTester();
  int DoSequentialAdd(int start, int end, int step);
  int DoRandomAdd(int n);
  int DoSequentialRemove(int start, int end, int step);
  int DoRandomRemove(int n);
  int DoSequentialFind(int start, int end, int step);
  int DoRandomFind(int n);

};

template<class T>
DataStructureTester<T>::DataStructureTester() {
  srand(time(0));
  runtime = 0;
}

template<class T>
int DataStructureTester<T>::DoSequentialAdd(int start, int end, int step) {
  runtime = clock();
  for (int i = start; i < end; i += step)
    list.add(i);

  runtime = clock() - runtime;
  return (((float)(runtime))/CLOCKS_PER_SEC)*1000;
}

template<class T>
int DataStructureTester<T>::DoRandomAdd(int n) {
  runtime = clock();
  for (int i = 0; i < n; i++) {
    int x = rand() % 100000;
    list.add(x);
  }
  runtime = clock() - runtime;
  return (((float)(runtime))/CLOCKS_PER_SEC)*1000;
}

template<class T>
int DataStructureTester<T>::DoSequentialRemove(int start, int end, int step) {
  runtime = clock();
  for (int i = start; i < end; i += step)
    list.remove(i);

  runtime = clock() - runtime;
  return (((float)(runtime))/CLOCKS_PER_SEC)*1000;
}

template<class T>
int DataStructureTester<T>::DoRandomRemove(int n) {
  runtime = clock();
  int x = rand() % 100000;
  for (int i = 0; i < n; i++)
    list.remove(x);

  runtime = clock() - runtime;
  return (((float)(runtime))/CLOCKS_PER_SEC)*1000;
}

template<class T>
int DataStructureTester<T>::DoSequentialFind(int start, int end, int step) {
  runtime = clock();
  for (int i = start; i < end; i += step)
    list.find(i);

  runtime = clock() - runtime;
  return (((float)(runtime))/CLOCKS_PER_SEC)*1000;
}

template<class T>
int DataStructureTester<T>::DoRandomFind(int n) {
  runtime = clock();
  int x = rand() % 100000;
  for (int i = 0; i < n; i++)
    list.find(x);

  runtime = clock() - runtime;
  return (((float)(runtime))/CLOCKS_PER_SEC)*1000;
}

}

#endif /* DATASTRUCTURETESTER_H_ */
