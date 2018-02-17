#ifndef TIME_CHRONO_H
#define TIME_CHRONO_H
#include <time.h>
#include <chrono>
#include <ctime>
struct timespec tstart = {0, 0};
struct timespec tend ={0,0};
//time of execution
void start_chrono(){
    clock_gettime(CLOCK_MONOTONIC, &tstart);
}
double elapsed(){
    static double res = 0.0;
    clock_gettime(CLOCK_MONOTONIC,&tend);
    res =((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec);
    return res;
}
class Timer
{
public:
void start()
    {
        m_StartTime = std::chrono::system_clock::now();
        m_bRunning = true;
    }
void stop()
    {
        m_EndTime = std::chrono::system_clock::now();
        m_bRunning = false;
    }
double elapsedMilliseconds()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        if(m_bRunning)
        {
            endTime = std::chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    }
double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }
private:
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    bool                                               m_bRunning = false;
};
/*
 * Timer timer;
    timer.start();
    timer.stop();
std::cout << "Seconds: " << timer.elapsedSeconds() << std::endl;
    std::cout << "Milliseconds: " << timer.elapsedMilliseconds() << std::endl;
 */

#endif // TIME_CHRONO_H
