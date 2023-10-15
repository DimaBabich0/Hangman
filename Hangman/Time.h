#pragma once
#include <iostream>
using namespace std;
class Time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time()
	{
		Record();
	}
	void Record();
	void Print() const;
	void CountTime() const;
};

void Time::Record()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	hours = newtime.tm_hour;
	minutes = newtime.tm_min;
	seconds = newtime.tm_sec;
}
void Time::Print() const
{
	cout << hours << ":" << minutes << ":" << seconds;
}
void Time::CountTime() const
{
	Time temp;

	temp.hours -= hours;
	temp.minutes -= minutes;
	temp.seconds -= seconds;

	temp.Print();
}