#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    string h, m, s;
    h = std::to_string(seconds / 3600);
    if (h.size() == 1) h = "0" + h;
    m = std::to_string((seconds % 3600) / 60);
    if (m.size() == 1) m = "0" + m;
    s = std::to_string(seconds % 60);
    if (s.size() == 1) s = "0" + s;
    return h + ":" + m + ":" + s;
}
