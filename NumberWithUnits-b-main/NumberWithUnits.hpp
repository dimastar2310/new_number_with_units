#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>


namespace ariel{
    static std::unordered_map<std::string,std::unordered_map<std::string, double>> precios;
    class NumberWithUnits
    {
    private:
        double number;
        std::string _str;
    public:
        // NumberWithUnits():number{0},_str("")
        // {

        // }
        NumberWithUnits(double value,const std::string& units);

        
        static void read_units(std::ifstream& units_file);
        double getNumber(){
            return number;
        }
        std::string getUnit(){
            return _str;
        }

        
        NumberWithUnits& operator--();
        NumberWithUnits operator--(int);
        NumberWithUnits& operator++();
        NumberWithUnits operator++(int);

        friend NumberWithUnits operator*(const NumberWithUnits& n, double num);
        friend NumberWithUnits operator*(double num,const NumberWithUnits& n);


        NumberWithUnits& operator+=(const NumberWithUnits& other);
        NumberWithUnits& operator-=(const NumberWithUnits& other);
        NumberWithUnits operator + (const NumberWithUnits& other)const;
        NumberWithUnits operator + (); //ze operator naniah mishu asa +5 she yahzir 5
        NumberWithUnits operator - (const NumberWithUnits& other);
        NumberWithUnits operator - ();


        friend bool operator==(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator>(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator<(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b);


        friend std::ostream& operator << (std::ostream& os, const NumberWithUnits& num);
        friend std::istream& operator >> (std::istream& is, NumberWithUnits num);
    };
}