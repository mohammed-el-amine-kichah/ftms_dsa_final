#pragma once

#include <iostream>
#include <string>
#include <ctime>

class Date {
	int day;
	int month;
	int year;

	void validate() const;

	bool isYearLeap(int year) const;
	int daysInYear(int year) const;
	int daysInMonth(int month, int year) const;
	int daysFromThisYear(int day, int month, int year) const;

public: 
	enum class WeekDay {
		Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
	};

	Date();
	Date(int day, int month, int year);
	Date(const Date &date);

	static Date now();

	Date& operator=(const Date &date);
	Date operator+(int days) const; // add days to date
	Date operator-(int days) const; // sub days from date
	long operator-(const Date& date) const; // difference between two dates

	bool operator==(const Date& date) const;
	bool operator!=(const Date& date) const;
	bool operator<(const Date& date) const;
	bool operator<=(const Date& date) const;
	bool operator>(const Date& date) const;
	bool operator>=(const Date& date) const;

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	WeekDay getDayOfWeek() const;
	int getDayOfYear() const;
	int getDaysInMonth() const;

	bool isYearLeap() const;
	long toDays() const;

	std::string toStringWeekDay() const;
	std::string toString() const;

	friend std::ostream& operator<<(std::ostream &os, const Date &date);
	friend std::istream& operator>>(std::istream &is, Date &date);
};
