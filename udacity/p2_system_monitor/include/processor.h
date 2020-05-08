#include <vector>

#ifndef PROCESSOR_H
#define PROCESSOR_H

using std::vector;

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  vector<int> info_;

};

#endif
