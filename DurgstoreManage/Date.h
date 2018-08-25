#pragma once

#include <ctime>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;


class Date {
private:
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
public:
	Date(){}

	Date(const Date &d) {
		this->year = d.year;
		this->mon = d.mon;
		this->day = d.day;
		this->hour = d.hour;
		this->min = d.min;
		this->sec = d.sec;
	}

	Date(int year, int mon, int day, int hour, int min, int sec){
		this->year = year;
		this->mon = mon;
		this->day = day;
		this->hour = hour;
		this->min = min;
		this->sec = sec;
	}

	//%Y-%m-%d %H:%M:%S
	Date(string str) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '-' || str[i] == ':' || str[i] == ',')
				str[i] = ' ';
		}

		stringstream ss(str);
		string res;
		ss >> res;
		year = atoi(res.c_str());
		ss >> res;
		mon = atoi(res.c_str());
		ss >> res;
		day = atoi(res.c_str());
		ss >> res;
		hour = atoi(res.c_str());
		ss >> res;
		min = atoi(res.c_str());
		ss >> res;
		sec = atoi(res.c_str());
	}

	Date(tm & timeinfo) {
		this->year = timeinfo.tm_year + 1900;
		this->mon = timeinfo.tm_mon + 1;
		this->day = timeinfo.tm_mday;
		this->hour = timeinfo.tm_hour;
		this->min = timeinfo.tm_min;
		this->sec = timeinfo.tm_sec;
	}

	/*
		检查日期是否相同（忽略时分秒）
	*/
	bool checkDay(Date &d) {
		return (d.year == year && d.mon == mon && d.day == day);
	}

	string toString() {
		string date;
		date.append(to_string(year));
		date.append("-");
		date.append(to_string(mon));
		date.append("-"); 
		date.append(to_string(day));
		date.append(",");
		date.append(to_string(hour));
		date.append(":"); 
		date.append(to_string(min));
		date.append(":"); 
		date.append(to_string(sec));
		return date;
	}


};