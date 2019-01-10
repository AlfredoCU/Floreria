#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>

class Time {
    private:
        int hour;
        int minute;
    public:
        Time();
        Time(Time&);
        Time(int, int);
        bool isValid(int, int);

        int getHour();
        int getMinute();
        void setHour( int);
        void setMinute( int);

        bool operator != (const Time&);
        bool operator >  (const Time&);
        bool operator == (const Time&);
        bool operator <  (const Time&);
        bool operator <= (const Time&);
        bool operator >= (const Time&);

        std::string toString();

        friend std::ostream& operator <<(std::ostream&, Time&);
        friend std::istream& operator>> (std::istream&, Time&);
    };

#endif // TIME_H_INCLUDED
