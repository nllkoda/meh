#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Time
{
public:
	Time();
	Time(int d, int hr, int min, int sec)
	{
		this->day = d;
		this->hour = hr;
		this->minute = min;
		this->second = sec;

	}

	~Time();
	void print()
	{
		string dayStr;
		string hourStr;
		string minStr;
		string secStr;

			dayStr += to_string(day);

		if (minute < 10)
		{
			minStr = "0";
			minStr += to_string(minute);
		}
		else
		{
			minStr += to_string(minute);
		}
		if (second < 10)
		{
			secStr = "0";
			secStr += to_string(second);
		}
		else
		{
			secStr += to_string(second);
		}
		if (hour < 10)
		{
			hourStr = "0";
			hourStr += to_string(hour);
		}
		else
		{
			hourStr += to_string(hour);
		}
		printf("%s.%s.%s.%s\n", dayStr.c_str(), hourStr.c_str(), minStr.c_str(), secStr.c_str());
	}

	Time compare(Time t2)
	{
		Time t1(this->day, this->hour, this->minute, this->second);
		int count_secFirst = 0;
		int count_secSecond = 0;

		count_secFirst += (this->day * 24) * 3600;
		count_secFirst += this->hour * 3600;
		count_secFirst += this->minute* 60;
		count_secFirst += this->second;

		count_secSecond += (t2.day * 24) * 3600;
		count_secSecond += t2.hour * 3600;
		count_secSecond += t2.minute * 60;
		count_secSecond += t2.second;

		if (count_secFirst > count_secSecond)
		{
			return t1;
		}
		else
		{
			return t2;
		}
	}
	void substuctTime(Time t2)
	{
		int nDay = this->day - t2.day;
		int nHour, nMinute, nSecund = 0;
		if (this->hour - t2.hour > 0)
		{
			nHour = this->hour - t2.hour;
		}
		else
		{
			nHour = this->hour - t2.hour;
			nHour += 24;
			nDay--;
		}

		if (this->minute - t2.minute > 0)
		{
			nMinute = this->minute - t2.minute;
		}
		else
		{
			nMinute = this->minute - t2.minute;
			nMinute += 59;
			if (nHour - 1 > 0)
			{
				nHour = nHour - 1;
			}
			else
			{
				nHour = nHour - 1;
				nHour += 24;
				nDay--;
			}
		}
		if (this->second - t2.second > 0)
		{
			nSecund = this->second - t2.second;
		}
		else
		{
			nSecund = this->second - t2.second;
			nSecund += 59;
			if (nMinute - 1 > 0)
			{
				nMinute = nMinute - 1;
			}
			else
			{
				nMinute = nMinute - 1;
				nMinute += 59;
				if (nHour - 1 > 0)
				{
					nHour = nHour - 1;
				}
				else
				{
					nHour = nHour - 1;
					nHour += 24;
					nDay--;
				}
			}
		}
		Time res(nDay, nHour, nMinute, nSecund);
		res.print();
	}

	void addTime(Time t2) //добавляем время т1 + т2
	{
		int nDay = this->day + t2.day;
		int nHour,nMinute, nSecund = 0;
		if (this->hour + t2.hour < 24)
		{
			nHour = this->hour + t2.hour;
		}
		else
		{
			nHour = this->hour + t2.hour;
			nHour -= 24;
			nDay++;
		}

		if (this->minute + t2.minute <= 59)
		{
			nMinute = this->minute + t2.minute;
		}
		else
		{
			nMinute = this->minute + t2.minute;
			nMinute -= 59;
			if (nHour + 1 < 24)
			{
				nHour = nHour + 1;
			}
			else
			{
				nHour = nHour + 1;
				nHour -= 24;
				nDay++;
			}

		}
		if (this->second+ t2.second<= 59)
		{
			nSecund = this->second + t2.second;
		}
		else
		{
			nSecund = this->second + t2.second;
			nSecund -= 59;
			if (nMinute + 1 <= 59)
			{
				nMinute = nMinute + 1;
			}
			else
			{
				nMinute = nMinute + 1;
				nMinute -= 59;
				if (nHour + 1 < 24)
				{
					nHour = nHour + 1;
				}
				else
				{
					nHour = nHour + 1;
					nHour -= 24;
					nDay++;
				}
			}
		}
		Time res(nDay, nHour, nMinute, nSecund);
		res.print();
	}

private:
	int day;
	int hour;
	int minute;
	int second;
};

Time::Time()
{
}

Time::~Time()
{
}
Time getTime()
{
	Time t1;
	int day = 0;
	cout << "Enter day:" << endl;
	cin >> day;
	if (day < 0)
	{
		cout << "Error" << endl;
		return t1;
	}
	int hour = 0;
	cout << "Hour: " << endl;
	cin >> hour;
	if (hour < 0 || hour > 24)
	{
		cout << "Error" << endl;
		return t1;
	}
	int min = 0;
	cout << "Minutes:" << endl;
	cin >> min;
	if (min > 59 || min < 0)
	{
		cout << "Error" << endl;
		return t1;
	}

	int sec = 0;
	cout << "Secunds:" << endl;
	cin >> sec;
	if (sec < 0 || sec > 59)
	{
		cout << "Error" << endl;
		return t1;
	}

	Time t_cure(day, hour, min, sec);
	return t_cure;
}


int main()
{
    Time t1;
	t1 = getTime();
	t1.print();

	cout << "Fill t2" << endl;
	Time t2;
	t2 = getTime();
	t2.print();

	cout << "Compare" << endl;
	t1.compare(t2).print();

	cout << "t1 + t2" << endl;
	t1.addTime(t2);
	cout << "t1 - t2" << endl;
	t1.substuctTime(t2);
}
