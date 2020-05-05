#include <string>
#include <vector>

#include "processor.h"
#include "linux_parser.h"

using std::string;
using std::vector;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  vector<string> info = LinuxParser::CpuUtilization();
  vector<int> new_info_;
  float CPU_percentage;
  for (int i = 1; i < info.size(); i++) new_info_.push_back(std::stoi(info[i]));
  if (info_.size() == 10 && new_info_.size() == 10) {
    int prev_idle, prev_non_idle, prev_total;
    int idle, non_idle, total;
    int totald, idled;
    prev_idle = info_[3] + info_[4];
    idle = new_info_[3] + new_info_[4];
    prev_non_idle = info_[0] + info_[1] + info_[2] + info_[5] + info_[6] + info_[7];
    non_idle =  new_info_[0] + new_info_[1] + new_info_[2] + new_info_[5] + new_info_[6] + new_info_[7];
    prev_total = prev_idle + prev_non_idle;
    total = idle + non_idle;
    totald = total - prev_total;
    idled = idle - prev_idle;
    CPU_percentage = (totald - idled + 0.0) / totald;
  }
  info_ = new_info_;
  return CPU_percentage;
}
