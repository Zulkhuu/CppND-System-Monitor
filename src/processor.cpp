#include <vector>
#include <iostream>
#include "processor.h"
#include "linux_parser.h"

using std::vector;
using std::string;
using std::stoi;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    vector<string> stats = LinuxParser::CpuUtilization();
    int user = stoi(stats[0]);
    int nice = stoi(stats[1]);
    int system = stoi(stats[2]);
    int idle = stoi(stats[3]);
    int iowait = stoi(stats[4]);
    int irq = stoi(stats[5]);
    int softirq = stoi(stats[6]);
    int steal = stoi(stats[7]);
    int guest = stoi(stats[8]);
    int guest_nice = stoi(stats[9]);

    user -= guest;
    nice -= guest_nice;

    int total_nonidle = user + nice + system + irq + softirq + steal;
    int total_idle = idle + iowait;
    int total = total_idle + total_nonidle;

    int total_diff = total - prev_total;
    int idle_diff = total_idle - prev_idle;

    float cpu_utilization = (float)(total_diff - idle_diff)/total_diff;
    //float cpu_utilization = (float)total_nonidle/total;

    prev_nonidle = total_nonidle;
    prev_idle = total_idle;
    prev_total = total_idle + total_nonidle;

    return cpu_utilization; 
}