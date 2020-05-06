#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::ifstream;
using std::string;
using std::to_string;
using std::vector;

// Helper function to find value associated with target_key in filename
template <typename T>
T FindValueByKey(string const &target_key, string const &filename) {
  string line, key;
  T value;
  ifstream filestream(filename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value)
        if (key == target_key) return value;
    }
  }
  filestream.close();
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return string();
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  ifstream filestream(kProcDirectory + kVersionFilename);
  if (filestream.is_open() && std::getline(filestream, line)) {
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  float MemTotal = FindValueByKey<float>("MemTotal:", kProcDirectory + kMeminfoFilename);
  float MemFree = FindValueByKey<float>("MemFree:", kProcDirectory + kMeminfoFilename);
  return MemTotal > 0 ? 1 - MemFree / MemTotal : 0;
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() {
  float t;
  string line;
  ifstream filestream(kProcDirectory + kUptimeFilename);
  if (filestream.is_open() && std::getline(filestream, line)) {
    std::istringstream linestream(line);
    linestream >> t;
  }
  return (long) t;
}

// TODO: Read and return the number of jiffies for the system
// long LinuxParser::Jiffies() { return 0; }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
// long LinuxParser::ActiveJiffies(int pid[[maybe_unused]]) { return 0; }

// TODO: Read and return the number of active jiffies for the system
// long LinuxParser::ActiveJiffies() { return 0; }

// TODO: Read and return the number of idle jiffies for the system
// long LinuxParser::IdleJiffies() { return 0; }

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() {
  string line, value;
  vector<string> info;
  ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open() && std::getline(filestream, line)) {
    std::istringstream linestream(line);
    while (linestream >> value) info.push_back(value);
  }
  filestream.close();
  return info;
}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  return FindValueByKey<int>("processes", kProcDirectory + kStatFilename);
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() {
  return FindValueByKey<int>("procs_running", kProcDirectory + kStatFilename);
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) {
  string line;
  ifstream filestream(kProcDirectory + to_string(pid) + kCmdlineFilename);
  if (filestream.is_open()) std::getline(filestream, line);
  return line;
}

float LinuxParser::CpuUtilization(int pid) {
  int seconds = LinuxParser::UpTime(pid);
  if (seconds == 0) return 0;
  int utime, stime, cutime, cstime, total_time;
  string line, value;
  ifstream filestream(kProcDirectory + to_string(pid) + kStatFilename);
  if (filestream.is_open() && std::getline(filestream, line)) {
    std::istringstream linestream(line);
    for (int i = 1; i <= 13; i++) linestream >> value;
    linestream >> utime >> stime >> cutime >> cstime;
    total_time = utime + stime + cutime + cstime;
    return (total_time + 0.0) / sysconf(_SC_CLK_TCK) / seconds;
  }
  return 0;
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) {
  int value = FindValueByKey<int>("VmSize:", kProcDirectory + to_string(pid) + kStatusFilename);
  return to_string(value / 1000);
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) {
  return FindValueByKey<string>("Uid:", kProcDirectory + to_string(pid) + kStatusFilename);
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) {
  string uid = LinuxParser::Uid(pid);
  string line, key, x, value;
  ifstream filestream(kPasswordPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      linestream >> key >> x >> value;
      if (value == uid) return key;
    }
  }
  return string();
}

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long int LinuxParser::UpTime(int pid) {
  string line, value;
  long starttime;
  ifstream filestream(kProcDirectory + to_string(pid) + kStatFilename);
  if (filestream.is_open() && std::getline(filestream, line)) {
    std::istringstream linestream(line);
    for (int i = 1; i <= 21; i++) linestream >> value;
    linestream >> starttime;
    return LinuxParser::UpTime() - starttime / sysconf(_SC_CLK_TCK);
  }
  return 0;
}
