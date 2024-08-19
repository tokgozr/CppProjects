#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

int main()
{
    char input;
    bool running = false;
    steady_clock::time_point startTime, endTime;
    duration<double> elapsedTime;

    cout << "Simple Stopwatch\n";
    cout << "Press 's' to start, 'e' to stop, and 'q' to quit.\n";

    while(true)
    {
        cin >> input;
        if(input == 's' && !running)
        {
            running = true;
            startTime = steady_clock::now();
            cout << "stopwatch started...\n";
        }
        else if (input == 'e' && running)
        {
            endTime = steady_clock::now();
            elapsedTime = duration_cast<duration<double>>(endTime - startTime);
            running = false;
            cout << "Stopwatch stopped elapsed time: " << elapsedTime.count() << "seconds\n";
        }
        else if (input == 'q')
            break;
        else
            cout << "Invalid input.\n";
    }
    return 0;
}
