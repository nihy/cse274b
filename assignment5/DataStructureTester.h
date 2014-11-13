/*
 * DataStructureTester.h
 *
 *  Created on: Nov 11, 2014
 *      Author: Henry
 */

#ifndef DATASTRUCTURETESTER_H_
#define DATASTRUCTURETESTER_H_

namespace ods {

template<class T>
class DataStructureTester {
protected:
  int start_time, end_time, run_time;
public:
  DataStructureTester();
  virtual ~DataStructureTester();
  int DoSequencialAdd(int start, int end, int step);
  int DoRandomAdd(int n);
  int DoSequencialRemove(int start, int end, int step);
  int DoRandomRemove(int n);
  int DoSequencialFind(int start, int end, int step);
  int DoRandomFind(int n);

};
}

#endif /* DATASTRUCTURETESTER_H_ */
