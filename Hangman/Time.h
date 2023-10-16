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
	Time();
	void Record();
	void CountTime() const;
	void Print() const;
};

Time::Time()
{
	Record();
}

void Time::Record()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	hours = newtime.tm_hour;
	minutes = newtime.tm_min;
	seconds = newtime.tm_sec;
}
void Time::CountTime() const
{
	Time temp;

	temp.hours -= hours;
	temp.minutes -= minutes;
	temp.seconds -= seconds;

	if (temp.minutes < 0)
	{
		temp.hours--;
		temp.minutes += 60;
	}
	if (temp.seconds < 0)
	{
		temp.minutes--;
		temp.seconds += 60;
	}

	temp.Print();
}
void Time::Print() const
{
	cout << hours << ":" << minutes << ":" << seconds;
}