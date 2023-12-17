#include "Date.h"

using namespace std;

void Date::validate() const {
	if (month > 12 || month < 1)
		throw string("month must be in 1..12!");

	int days = daysInMonth(month, year);

	if (day < 1 || day > days)
		throw string("in this month must be ") + to_string(days) + " days!";
}

bool Date::isYearLeap(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInYear(int year) const {
	return isYearLeap(year) ? 366 : 365;
}

int Date::daysInMonth(int month, int year) const {
	switch (month) {
		case 1: // january
		case 3: // march
		case 5: // may
		case 7: // july
		case 8: // august
		case 10: // october
		case 12: // december
			return 31;

		case 4: // april
		case 6: // june
		case 9: // september
		case 11: // november
			return 30;

		case 2: // february
			return isYearLeap(year) ? 29 : 28;

		default:
			throw string("invalid month in 'daysInMonth'");
	}
}

int Date::daysFromThisYear(int day, int month, int year) const {
	int days = day;

	for (int m = 1; m < month; m++)
		days += daysInMonth(m, year);

	return days;
}

Date::Date() {
	day = 1;
	month = 1;
	year = 0;
}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;

	validate();
}

Date::Date(const Date &date) {
	day = date.day;
	month = date.month;
	year = date.year;
}

Date Date::now() {
	time_t t = time(0);
    tm* now = localtime(&t);
    
    return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

Date& Date::operator=(const Date &date) {
	if (&date != this) {
		day = date.day;
		month = date.month;
		year = date.year;		
	}

	return *this;
}

// add days to date
Date Date::operator+(int days) const {
	if (days < 0)
		return *this - (-days);

	Date result(*this);

	int fromThisYear = daysFromThisYear(result.day, result.month, result.year);

	while (days + daysFromThisYear(result.day, result.month, result.year) > daysInYear(result.year)) {
		days -= daysInYear(result.year);
		result.year++;
	}

	days += fromThisYear;

	result.month = 1; 

	while (result.month < 12 && days > daysInMonth(result.month, result.year)) {
		days -= daysInMonth(result.month, result.year);
		result.month++;
	}

	result.day = days;

	return result;
}

 // sub days from date
Date Date::operator-(int days) const {
	if (days < 0)
		return *this + (-days);

	Date result(*this);

	int fromThisYear = daysFromThisYear(result.day, result.month, result.year);

	while (daysFromThisYear(result.day, result.month, year) - days <= 0) {
		days -= daysInYear(result.year - 1);
		result.year--;
	}

	days = fromThisYear - days;

	result.month = 1; 

	while (result.month < 12 && days > daysInMonth(result.month, result.year)) {
		days -= daysInMonth(result.month, result.year);
		result.month++;
	}

	result.day = days;

	return result;
}

long Date::operator-(const Date& date) const {
	return this->toDays() - date.toDays();
}

bool Date::operator==(const Date& date) const {
	return year == date.year && month == date.month && day == date.day;
}

bool Date::operator!=(const Date& date) const {
	return !(*this == date);
}

bool Date::operator<(const Date& date) const {
	if (year != date.year)
		return year < date.year;

	if (month != date.month)
		return month < date.month;

	return day < date.day;
}

bool Date::operator<=(const Date& date) const {
	return *this < date || *this == date;
}

bool Date::operator>(const Date& date) const {
	return !(*this <= date);
}

bool Date::operator>=(const Date& date) const {
	return *this > date || *this == date;
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

Date::WeekDay Date::getDayOfWeek() const {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;

    int R = day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12;

    switch (R % 7) {
    	case 0:
    		return WeekDay::Sunday;

    	case 1:
    		return WeekDay::Monday;

    	case 2:
    		return WeekDay::Tuesday;

    	case 3:
    		return WeekDay::Wednesday;

    	case 4:
    		return WeekDay::Thursday;

    	case 5:
    		return WeekDay::Friday;

    	case 6:
    		return WeekDay::Saturday;

    	default:
    		throw "How? o_O";
    }
}

int Date::getDayOfYear() const {
	return daysFromThisYear(day, month, year);
}

int Date::getDaysInMonth() const {
	return daysInMonth(month, year);
}

bool Date::isYearLeap() const {
	return isYearLeap(year);
}

long Date::toDays() const {
	long days = day;

    for (int y = 0; y < year; y++)
        days += daysInYear(y);
    
    for (int m = 1; m < month; m++)
        days += daysInMonth(m, year);

    return days;
}

string Date::toStringWeekDay() const {
	switch (getDayOfWeek()) {
		case WeekDay::Monday:
			return "Monday";

		case WeekDay::Tuesday:
			return "Tuesday";

		case WeekDay::Wednesday:
			return "Wednesday";

		case WeekDay::Thursday:
			return "Thursday";

		case WeekDay::Friday:
			return "Friday";

		case WeekDay::Saturday:
			return "Saturday";

		case WeekDay::Sunday:
			return "Sunday";

		default:
			throw "Invalid dayOfWeek()";
	}
}

string Date::toString() const {
	return to_string(day) + "." + (month < 10 ? "0" : "") + to_string(month) + "." + to_string(year);
}

ostream& operator<<(ostream &os, const Date &date) {
	return os << date.day << "." << (date.month < 10 ? "0" : "") << date.month << "." << date.year;
}

istream& operator>>(istream &is, Date &date) {
	char c;
	is >> date.day >> c >> date.month >> c >> date.year;

	date.validate();

	return is;
}