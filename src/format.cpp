#include <iomanip>
#include <sstream>
#include <string>

#include "format.h"

#define SECS_IN_HOUR 3600
#define SECS_IN_MIN 60

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  int hour = seconds / SECS_IN_HOUR;
  int minute = (seconds % SECS_IN_HOUR) / SECS_IN_MIN;
  int second = seconds % SECS_IN_MIN;
  std::stringstream ss;
  ss << std::setw(2) << std::setfill('0') << hour << ":" << minute << ":"
     << second;
  return ss.str();
}