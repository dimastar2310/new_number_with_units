#include <iostream>
#include <fstream>
#include "NumberWithUnits.hpp"
//#include <windows.h>

using namespace std;



namespace ariel{
    typedef unsigned long  ulong;
  void NumberWithUnits:: read_units(ifstream& ifs){
        string number;
        string unit1;
        string equal;
        string second_number;
        string unit2;
        double number_helper =0;
        while(ifs>>number>>unit1>>equal>>second_number>>unit2){
            
            number_helper = stod(second_number);
            precios[unit1][unit2]=number_helper;//<key,value> le meshane po meter to km helper
            precios[unit2][unit1] = 1/number_helper; //for some numbers after point //km to m helper 
            cout<<"precios[unit1][unit2] = "<<precios[unit1][unit2]<<endl;
            cout<< "precios[unit2][unit1] = "<<precios[unit2][unit1]<<endl;
        }

         
     }
     
    
    NumberWithUnits::NumberWithUnits(double units,const std::string &abc ){//there is no find for value
    if(precios.count(abc) == 0){ //im kayam kaze tahzir 1 
            throw invalid_argument {"This unit does not match in the units_file"};
        }
        _str = abc;
        number = units;
    }
    double conversion(const string& in ,const string& from ,double value) { //there where const on this
        if(from == in){
            return value;
        }
        try {
            //.at nows to catch that we are not in goint where we dont need to go
            return precios.at(from).at(in)*value; //1/1000 * 1000=1 allowed or 1000*3 = 3000
        }
        catch(const exception& e) {throw invalid_argument {"Units do not match"};}
        }

    NumberWithUnits& NumberWithUnits::operator--(){
        this->number -=1;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int){
        NumberWithUnits copy = *this;
        this->number -=1;
        return copy;
    }

    NumberWithUnits& NumberWithUnits::operator++(){
        this->number +=1;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int){
        NumberWithUnits copy = *this;
        this->number +=1;
        return copy;
    }
    //so that -3 = 5 wont be allowed

     NumberWithUnits operator*(const NumberWithUnits& n, double num){
        return NumberWithUnits{n.number*num,n._str};
    }




     NumberWithUnits operator*(double num,const NumberWithUnits& n){
        return NumberWithUnits{n.number*num,n._str};
    }


    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other){
        double value = conversion(this->_str,other._str,other.number); //we are making other number unit our
        this->number +=value;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator + (const NumberWithUnits& other)const { //mahzirim obeikt lele shirshur
       double value = conversion(this->_str,other._str,other.number);
        return NumberWithUnits{this->number+value,this->_str}; //_str = units
    }
    NumberWithUnits NumberWithUnits::operator + (){ //unari pashut mahzirim et hamispar
        return *this;
    }
    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& other){ //this its const pointer to pointing to our class
        double value = conversion(this->_str,other._str,other.number);
        this->number-=value;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator - (const NumberWithUnits& other){
        double value = conversion(this->_str,other._str,other.number);
        
        return NumberWithUnits{this->number-value,this->_str}; //nahzir be yahidot shel rishon
    }
    NumberWithUnits NumberWithUnits::operator - (){  //multyply by * to -- to not having this
        return NumberWithUnits {this->number*(-1) , this->_str};
    }

    // const NumberWithUnits operator-(const NumberWithUnits& a,const NumberWithUnits b);
    // const NumberWithUnits operator+(const NumberWithUnits& a,const NumberWithUnits b);
    //*********************FRIEND FUNCTIONS******************************

    bool operator==(const NumberWithUnits& a, const NumberWithUnits& b){ //still use same techniche
    //esh hariga ktana be ehidot mida 
    const double epsilon = 0.001;
        double value = conversion(a._str,b._str,b.number); //its not pointer  //neshane yahidot shel sheni ve rishon ve nashve
        //bool check = a.number==value;
          //cout<<" iam at == operator "<<check<<endl;
        return (abs(a.number-value)<epsilon); //hariga ktana
    }
    bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b){

        return !(a==b);
    }
    //mamimirim et hasheni bodkim et erko aleino be yahidot shelanu
  
    bool operator>(const NumberWithUnits& a, const NumberWithUnits& b){
        double value = conversion(a._str,b._str,b.number);
        return a.number>value;
    }
    bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b){
        return !(a<b);
    }
    bool operator<(const NumberWithUnits& a, const NumberWithUnits& b){
        double value = conversion(a._str,b._str,b.number);
        return a.number<value;
    }
    bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b){
        return !(a>b);
    }


    ostream& operator<< (ostream& os, const NumberWithUnits& num){
        return os << num.number << "[" << num._str << "]" << endl;
    }

    istream& operator >> (istream& is, NumberWithUnits num){
        cout<<"iam at >> operator "<<endl;
         char ch = ' ';
        char ch1 = ' ';
        string unit = " ";
        double value = 0;
        is >> skipws >> value >> ch >> unit;

        if (unit.at(unit.length() - 1) != ']'){
            is>>ch1;
        }
        else{
            unit = unit.substr(0, unit.length() - 1);
        }
        if (precios.count(unit)==0){
            throw invalid_argument("Units do not match");
        }
        num.number = value;
        num._str = unit;
        return is;
    }

}