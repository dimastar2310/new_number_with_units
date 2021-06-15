// #include "NumberWithUnits.hpp"
// #include "doctest.h"
// #include <iostream>
// #include <fstream>
// #include <ctime>


// using namespace ariel;
// using namespace std;
// /**
//  * Random good snowmans
// **/

// ifstream units_file{"units.txt"}; //loading file

// TEST_CASE("addition and substraction") {
//     //CHECK( nwu.read_units == " "); //kovez reik einlanu ma laasot ito
//     NumberWithUnits::read_units(units_file);
//     //we converting to first object units
    
//     NumberWithUnits b{5,"ton"}; //b i this
//     NumberWithUnits a{3000,"kg"};
//     //b is this and a is this
//     CHECK((b+a) == NumberWithUnits{8,"ton"});
//     CHECK((a+b) == NumberWithUnits{8000,"kg"});
//     CHECK((b-a) == NumberWithUnits{2,"ton"});
//     CHECK((a-b) == NumberWithUnits{-2000,"kg"});
    
//     // CHECK((a+b)=5) == throw "cannot assigth right value");
//     //CHECK_THROWS_WITH((a+b)=5,"cant assight right hand value with right hand value");
//     b+=a;
//     //and its changing now
//     //b assiment is other from now on
//     CHECK(b == NumberWithUnits{8,"ton"});

//     a-=b;

//     CHECK(a == NumberWithUnits{-5000,"kg"});

//     NumberWithUnits h{1,"hour"};
    
//     CHECK_THROWS_WITH(a+h ,"cant add 2 different messures");
//     CHECK(-a == NumberWithUnits{5000,"kg"});
       
// }   

//    TEST_CASE("increament decreament operations") {

//     NumberWithUnits::read_units(units_file);
//     //we converting to first object units
    
//     NumberWithUnits a{5,"m"}; //b i this
    
//     //b is this and a is this
//     CHECK((a++) == NumberWithUnits{5,"m"}); //not changing if we print should retorn 5
//     CHECK(a==NumberWithUnits{6,"m"});

//     CHECK((a--) == NumberWithUnits{6,"m"});
//     CHECK(a==NumberWithUnits{5,"m"});

//     CHECK((++a) == NumberWithUnits{6,"m"});

//     CHECK((--a) == NumberWithUnits{4,"m"});

   
    
       
// }   

// TEST_CASE("Multiplication operator "){
//     //CHECK( nwu.read_units == " "); //kovez reik einlanu ma laasot ito
//     NumberWithUnits::read_units(units_file);
//     //we converting to first object units
    
//     NumberWithUnits b{5,"ton"}; //b i this
//     NumberWithUnits a{3000,"kg"};
//     //b is this and a is this
//     CHECK((b+a) == NumberWithUnits{8,"ton"});
//     CHECK((a+b) == NumberWithUnits{8000,"kg"});
//     CHECK((b-a) == NumberWithUnits{2,"ton"});
//     CHECK((a-b) == NumberWithUnits{-2000,"kg"});
    
//     // CHECK((a+b)=5) == throw "cannot assigth right value");
//     //CHECK_THROWS_WITH((a+b)=5,"cant assight right hand value with right hand value");
//     b+=a;
//     //and its changing now
//     //b assiment is other from now on
//     CHECK(b == NumberWithUnits{8,"ton"});

//     a-=b;

//     CHECK(a == NumberWithUnits{-5000,"kg"});

//     NumberWithUnits h{1,"hour"};
    
//     CHECK_THROWS_WITH(a+h ,"cant add 2 different messures");
//     CHECK(-a == NumberWithUnits{5000,"kg"});
       
// }   

//    TEST_CASE("increament decreament operations") {

//     NumberWithUnits::read_units(units_file);
//     //we converting to first object units
    
//     NumberWithUnits a{10,"minutes"}; //b i this
    
//     CHECK((a*5)==NumberWithUnits{50,"minuntes"});

//     CHECK((20*a)==NumberWithUnits{200,"minutes"});

// }
// TEST_CASE("Comparison operatos"){
//     NumberWithUnits::read_units(units_file);
//     NumberWithUnits a{1000,"USD"};
//     NumberWithUnits b{2000,"USD"};
//     CHECK(a<b == true);
//     CHECK(a>b == false);
//     CHECK(a>=b == false);
//     CHECK(a<=b == true);
//     CHECK(a==b == false);
//     CHECK(a!=b == true);


    

// }

#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <fstream>
#include <string>


using namespace ariel;
using namespace std;


ifstream units_file{"units.txt"};


TEST_CASE("addition and subtraction"){
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{10, "ton"};
    NumberWithUnits b{5000, "kg"};

    CHECK((a+b) == NumberWithUnits{15,"ton"});
    CHECK((b+a) == NumberWithUnits{15000,"ton"});
    CHECK((a-b) == NumberWithUnits{5,"ton"});
    CHECK((b-a) == NumberWithUnits{-5000,"ton"});
    a += b;
    CHECK(a == NumberWithUnits{15,"ton"});
    b -= a;
    CHECK(b == NumberWithUnits{-10000,"kg"});

    NumberWithUnits d{20, "USD"};
    CHECK_THROWS(a+d);
    CHECK_THROWS(d+b);
    CHECK(-a == NumberWithUnits{-15,"ton"});
}

TEST_CASE("inc/dec operators"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{30, "m"};
    CHECK(++a == NumberWithUnits{31, "m"});
    CHECK(--a == NumberWithUnits{30, "m"});
    CHECK(a++ == NumberWithUnits{30, "m"});
    CHECK(a == NumberWithUnits{31, "m"});
    CHECK(a-- == NumberWithUnits{31, "m"});
    CHECK(a == NumberWithUnits{30, "m"});
}

TEST_CASE("Multiplication operator "){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{10, "sec"};

    CHECK((a*5) == NumberWithUnits{50, "sec"});
    CHECK((100*a) == NumberWithUnits{1000, "sec"});
}

TEST_CASE("Comparison operators"){
    NumberWithUnits::read_units(units_file);

    CHECK_EQ(NumberWithUnits{1000, "USD"}  , NumberWithUnits{3330, "ILS"});
    CHECK_EQ(NumberWithUnits{1, "hour"}  , NumberWithUnits{3600, "sec"});
    CHECK_NE(NumberWithUnits{1000, "USD"}  , NumberWithUnits{3333, "ILS"});
    CHECK_NE(NumberWithUnits{1001, "USD"}  , NumberWithUnits{3330, "ILS"});

    CHECK_LT(NumberWithUnits{2, "ton"}  , NumberWithUnits{3000, "kg"});
    CHECK_GT(NumberWithUnits{5000, "g"}, NumberWithUnits{3, "kg"});
    CHECK_NE(NumberWithUnits{2, "m"}  , NumberWithUnits{3000, "cm"});

    CHECK_LT(NumberWithUnits{9000, "cm"} , NumberWithUnits{3000, "m"});
    CHECK_GT(NumberWithUnits{1, "km"}, NumberWithUnits{10000, "cm"});
}


