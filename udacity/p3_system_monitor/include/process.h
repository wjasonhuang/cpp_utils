#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid() const;                         // TODO: See src/process.cpp
  std::string User() const;                // TODO: See src/process.cpp
  std::string Command() const;             // TODO: See src/process.cpp
  float CpuUtilization() const;            // TODO: See src/process.cpp
  std::string Ram() const;                 // TODO: See src/process.cpp
  long int UpTime() const;                 // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp
  Process(int pid);
  void SetAttributes();                    // set all the private attributes

  // TODO: Declare any necessary private members
 private:
  float cpu_utilization_;
  int pid_;
  long int up_time_;
  std::string user_, command_, ram_;
};

#endif
