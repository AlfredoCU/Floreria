#include "time.h"

bool Time::isValid(int h, int m) {
    return h >= 0 and h < 24  and m >= 0 and m < 60;
    }

Time::Time() {
    time_t myTime;
    time(&myTime);

    struct tm* localTime;
    localTime = localtime(&myTime);

    hour = localTime->tm_hour;
    minute = localTime->tm_min;
    }

Time::Time( Time& t) {
    hour = t.hour;
    minute = t.minute;
    }

Time::Time(int h, int m):Time() {
    if(isValid(h, m)) {
        hour = h;
        minute = m;
        }
    }

int Time::getHour() {
    return hour;
    }

int Time::getMinute() {
    return minute;
    }

void Time::setHour( int h) {
    if(isValid(h,minute)) {
        hour = h;
        }
    }

void Time::setMinute(  int m) {
    if(isValid(hour, m)) {
        minute = m;
        }
    }

bool Time::operator!=(const Time&h) {
    return hour!=h.hour;
    }

bool Time::operator>(const Time&h) {
    return hour>h.hour;
    }

bool Time::operator==(const Time&h) {
    return hour==h.hour;
    }

bool Time::operator<(const Time&h) {
    return hour<h.hour;
    }

bool Time::operator<=(const Time&h) {
    return hour<=h.hour;
    }

bool Time::operator>=(const Time&h) {
    return hour>=h.hour;
    }

std::string Time::toString() {
    char myTime[6]; //myTime ya trae el formato de dos números.
    sprintf(myTime, " %02d:%02d", hour, minute);
    return myTime;
    }

std::ostream& operator <<(std::ostream& os, Time&t) {
    os << t.hour;
    os << ":";
    os << t.minute;
    return os;
    }

std::istream& operator>>(std::istream& is, Time&t) {
    std::string strH,strM;
    std::getline(is,strH,':');
    std::getline(is,strM);
    t.hour=atoi(strH.c_str());
    t.minute=atoi(strM.c_str());
    return is;
    }
