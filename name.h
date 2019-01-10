#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstdio>
#include<string>

class Name {
    private:
        std::string first;
        std::string last;
    public:
        Name();
        Name( Name&);
        Name(std::string, std::string);

        std::string getFirst();
        std::string getLast();
        void setLast(std::string);
        void setFirst(std::string);
        std::string toString();

        bool operator == (Name&);
        bool operator != (Name&);
        bool operator <= (Name&);
        bool operator < (Name&);
        bool operator >= (Name&);
        bool operator > (Name&);

        friend std::ostream& operator <<(std::ostream&, Name&);
        friend std::istream& operator>> (std::istream&, Name&);
    };

#endif // NAME_H_INCLUDED
