#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
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
  std::ifstream filestream(kProcDirectory + kVersionFilename);
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
  float MemTotal = 0, MemFree = 0;
  string line, key, value;
  std::ifstream filestream(kProcDirectory + kMeminfoFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      if (linestream >> key >> value) {
        if (key == "MemTotal:") MemTotal = std::stof(value);
        else if (key == "MemFree:") MemFree = std::stof(value);
      }
      if (MemTotal > 0.1 && MemFree > 0.1) return 1 - MemFree / MemTotal;
    }
  }
  return 0;
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() {
  float t;
  string line;
  std::ifstream filestream(kProcDirectory + kUptimeFilename);
  if (filestream.is_open() && std::getline(filestream, line)) {
    std::istringstream linestream(line);
    linestream >> t;
    return (long) t;
  }
  return 0;
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
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open() && std::getline(filestream, line)) {
    std::istringstream linestream(line);
    while (linestream >> value) info.push_back(value);
  }
  return info;
}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  string line, key;
  int value;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> key;
      if (key == "processes") {
        linestream >> value;
        return value;
      }
    }
  }
  return 0;
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() {
  string line, key;
  int value;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> key;
      if (key == "procs_running") {
        linestream >> value;
        return value;
      }
    }
  }
  return 0;
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) {
  string line;
  std::ifstream filestream(kProcDirectory + to_string(pid) + kCmdlineFilename);
  if (filestream.is_open()) std::getline(filestream, line);
  return line;
}

float LinuxParser::CpuUtilization(int pid) {
  int seconds = LinuxParser::UpTime(pid);
  if (seconds == 0) return 0;
  int utime, stime, cutime, cstime, total_time;
  string line, value;
  std::ifstream filestream(kProcDirectory + to_string(pid) + kStatFilename);
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
  string line, key, value;
  std::ifstream filestream(kProcDirectory + to_string(pid) + kStatusFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      if (linestream >> key >> value && key == "VmSize:") return to_string(std::stoi(value) / 1000);
    }
  }
  return string();
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) {
  string line, key, value;
  std::ifstream filestream(kProcDirectory + to_string(pid) + kStatusFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key == "Uid:") return value;
    }
  }
  return string();
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) {
  string uid = LinuxParser::Uid(pid);
  string line, key, x, value;
  std::ifstream filestream(kPasswordPath);
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
  std::ifstream filestream(kProcDirectory + to_string(pid) + kStatFilename);
  if (filestream.is_open() && std::getline(filestream, line)) {
    std::istringstream linestream(line);
    for (int i = 1; i <= 21; i++) linestream >> value;
    linestream >> starttime;
    return LinuxParser::UpTime() - starttime / sysconf(_SC_CLK_TCK);
  }
  return 0;
}
