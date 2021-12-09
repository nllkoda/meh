#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int f(int x, bool upperYear) // проверка на колво дней в мес€це
	{if (x == 2 && upperYear)
	{
		return 29;
	}
	int f = floor(x / 8);
	return 28 + (x + f) % 2 + 2 % x + 2 * floor(1 / x);   // формула из инета https://habr.com/ru/post/261773/
}

bool u(int year)  //проверка на високосный год
{
	if (year % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int codeOfMonth(int m)
{
	int codeMonth = 0;   //это дл€ определени€ дн€ недели (красота) https://lifehacker.ru/kakoj-den-nedeli/
	//1 Ч €нварь, окт€брь;
	//2 Ч май;
	//3 Ч август;
	//4 Ч февраль, март, но€брь;
	//5 Ч июнь;
	//6 Ч декабрь, сент€брь;
	//0 Ч апрель, июль
	if (m == 1 || m == 10)
		codeMonth = 1;
	if (m == 5)
		codeMonth = 2;
	if (m == 8)
		codeMonth = 3;
	if (m == 2 || m == 3 || m == 11)
		codeMonth == 4;
	if (m == 6)
		codeMonth = 5;
	if (m == 12 || m == 9)
		codeMonth = 6;
	if (m == 4 || m == 7)
		codeMonth = 0;

	return codeMonth;
}
int codeOfYear(int year) //тоже дл€ определени€ дн€ недели
{
	string year_Str = to_string(year);
	int twice = stoi(year_Str.substr(year_Str.size() - 2, year_Str.size()));
	//код года = (6 + последние две цифры года + последние две цифры года / 4) % 7;
	int twdel = floor(twice / 4);
	int code = (6 + twice + twdel) % 7;
	return code;
}

class Date
{
public:
	Date();
	Date(int yr, int mn, int dt)
	{
		this->year = yr;
		this->mounth = mn;
		this->date = dt;
	}

	~Date();
	int getYear() { return year; }
	int getMounth() { return  mounth; }
	int getDate() { return date; }
	void print()
	{
		string monthStr;
		string DayStr;
        if (mounth < 10)
		{
			monthStr = "0";
			monthStr += std::to_string(mounth);
		}
		else
		{
			monthStr = std::to_string(mounth);
		}
		if (date < 10)
		{
			DayStr = "0";
			DayStr += std::to_string(date);
		}
		else
		{
			DayStr = std::to_string(date);
		}
		printf("%d.%s.%s\n", year, monthStr.c_str(), DayStr.c_str());
	}

	void printMounth()
	{
		string monthStr;

		switch (mounth)
		{
		case 1:
			monthStr = "January";
			break;
		case 2:
			monthStr = "February";
			break;
		case 3:
			monthStr = "April";
			break;
		case 4:
			monthStr = "March";
			break;
		case 5:
			monthStr = "May";
			break;
		case 6:
			monthStr = "June";
			break;
		case 7:
			monthStr = "July";
			break;
		case 8:
			monthStr = "August";
			break;
		case 9:
			monthStr = "Septembr";
			break;
		case 10:
			monthStr = "October";
			break;
		case 11:
			monthStr = "November";
			break;
		case 12:
			monthStr = "December";
			break;
		default:
			break;
		}
		printf("%d %s %d\n", date, monthStr.c_str(), year);
	}

	void previousDate()
	{
		int nYear = year - 1;
		int nDay, nMonth = 0;
		if (mounth - 1 > 0)
		{
			nMonth = mounth - 1;//2
		}
		else
		{
			nMonth = mounth - 1;
			nMonth += 12;
			nYear--;
		}
		if (date - 1 > 0)
		{
			nDay = date - 1;//30/30
		}
		else
		{
			if (mounth - 1 > 0)
			{
				nMonth = mounth - 1;//2
			}
			else
			{
				nMonth = mounth - 1;
				nMonth += 12;
				nYear--;
			}
			nDay = date - 1;
			nDay += f(nMonth, u(nYear));
		}
		Date result(nYear, nMonth, nDay);
		result.print();
	}
	void week_day() //определ€ем дни недели с помощью тех кодов наконец-то
	{
		string daysofWeek[]{ "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday" };
		int result = (this->date + codeOfMonth(this->mounth) + codeOfYear(this->year)) % 7;

		cout << daysofWeek[result] << endl;
	}
	void nextDate()
	{
		int nYear = year + 1;
		int nDay, nMonth = 0;
		if (mounth + 1 <= 12)
		{
			nMonth = mounth + 1;
		}
		else
		{
			nMonth = mounth + 1;
			nMonth -= 12;
			nYear++;
		}

		if (date + 1 <= f(nMonth, u(nYear))) // чтобы не вышло днеЄ больше, чем в мес€це
		{
			nDay = date + 1;//30/30
		}
		else
		{
			if (mounth + 1 <= 12)
			{
				nMonth = mounth + 1;
			}
			else
			{
				nMonth = mounth + 1;
				nMonth -= 12;
				nYear++;
			}
			nDay = date + 1;
			nDay -= f(nMonth, u(nYear));

		}
		Date result(nYear, nMonth, nDay);
		result.print();
	}

	void add_day(int d) //добавл€ем к дате число (в main поставила 11 как в условии)
	{
		int nYear = year;
		int nDay = date;
		int nMonth = mounth;

		if (date + d <= f(nMonth, u(nYear)))
		{
			nDay = date + d;
		}
		else
		{
			if (mounth + 1 <= 12)
			{
				nMonth = mounth + 1;
			}
			else
			{
				nMonth = mounth + 1;
				nMonth -= 12;
				nYear++;
			}
			nDay = date + d;
			nDay -= f(nMonth, u(nYear));

		}
		Date result(nYear, nMonth, nDay);
		result.print();
	}

	Date compare(Date d2)
	{
		Date d1(this->year, this->mounth, this->date);

		int cnt_daysFirst = 0;
		int cnt_daysSecond = 0;

		for (int i = 1; i <= this->mounth; i++)
		{
			cnt_daysFirst += f(i, u(this->year)); //исп фукнцию дл€ корректного подсчЄта дней
		}
		for (int i = 1; i <= d2.mounth; i++)
		{
			cnt_daysSecond += f(i, u(d2.year));
		}
		if (this->year == d2.year)
		{
			if (cnt_daysFirst < cnt_daysSecond)
			{
				return d1;
			}
			else
			{
				return d2;
			}
		}
		if (this->year < d2.year)
		{
			return d1;
		}
		else
		{
			return d2;
		}

	}

	void diffrenece(Date d2) //разница в дн€х между годами
	{
		int diffYear = 0;
		int cnt_vys = 0;
		if (this->year != d2.year)
		{
			if (this->year < d2.year)
			{
				for (int i = this->year; i < d2.year; i++)
				{
					if (u(i))
						cnt_vys++; //узнаЄм, сколько было високосных лет между датами
				}
				diffYear = (d2.year - this->year - cnt_vys) * 364 + (cnt_vys * 365);
			}
		}

		Date d1(this->year, this->mounth, this->date);

		int cnt_daysFirst = 0;
		int cnt_daysSecond = 0;

		for (int i = 1; i <= this->mounth; i++)
		{
			cnt_daysFirst += f(i, u(this->year));
		}
		for (int i = 1; i <= d2.mounth; i++)
		{
			cnt_daysSecond += f(i, u(d2.year));
		}
		int diff = abs(cnt_daysFirst - cnt_daysSecond);

		cout << "Diffrenece: " << diff + diffYear;
	}

private:
	int year;
	int mounth;
	int date;
};

Date::Date()
{
}

Date::~Date()
{
}


Date getDate()  //вводим дату и выводим erorы, если ввели некорректно
{
	Date d1;
	int year, month, dat = 0;

	cout << "Year: " << endl;
	cin >> year;
	if (year <= 0)
	{
		cout << "Enter correct year" << endl;
		return d1;
	}

	cout << "Month: " << endl;
	cin >> month;
	if (month <= 0 || month > 12)
	{
		cout << "Enter correct month" << endl;
		return d1;
	}

	cout << "Data day: " << endl;
	cin >> dat;

	if (dat <= 0 || dat > 31 || dat > f(month, u(year)) )
	{
		cout << "Error write date!" << endl;
		return d1;
	}
	Date d2(year, month, dat);
	return d2;
}

int main()
{
	Date d1;
	d1 = getDate();
	d1.print();
	d1.printMounth();
	d1.week_day();

	cout << "Next:" << endl;
	d1.nextDate();
	cout << "Prev:" << endl;
	d1.previousDate();

	cout << "add_day to first date: " << endl;
	d1.add_day(11);



	cout << "Fill d2" << endl;
	Date d2;
	d2 = getDate();
	d2.print();
	d2.printMounth();
	d2.week_day();

	cout << "Compare: " << endl;
	d1.compare(d2).print();

	d1.diffrenece(d2);
}


