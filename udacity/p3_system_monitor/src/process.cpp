#include <string>

#include "linux_parser.h"
#include "process.h"

using std::string;

// TODO: Return this process's ID
int Process::Pid() const { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const { return cpu_utilization_; }

// TODO: Return the command that generated this process
string Process::Command() const { return command_; }

// TODO: Return this process's memory utilization
string Process::Ram() const { return ram_; }

// TODO: Return the user (name) that generated this process
string Process::User() const { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() const { return up_time_; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { return this->CpuUtilization() > a.CpuUtilization(); }

Process::Process(int pid): pid_(pid) {}

void Process::SetAttributes() {
  command_ = LinuxParser::Command(pid_);
  cpu_utilization_ = LinuxParser::CpuUtilization(pid_);
  up_time_ = LinuxParser::UpTime(pid_);
  user_ = LinuxParser::User(pid_);
  ram_ = LinuxParser::Ram(pid_);
}
