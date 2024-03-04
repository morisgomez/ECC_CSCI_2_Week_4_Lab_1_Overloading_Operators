/*
 Program Name: OverloadingOperators.cpp
 Programmer: Moris Gomez
 Date: Saturday 03/02/2024
 Version Control: 4.0
 About: Week 4, CSCI 2, Lab 1.
 Description:
    Write a program which overloads fractions, arithmetic
    operations for division, and comparison operator overloading to
    divide and compare two fractions. And include the overloading
    operators which we did in the class like multiplication
    insertion, and extraction operators.
*/

#include <iostream> //library for insertion and extraction.
using namespace std;

//START Fraction class:
class Fraction
{
private:
    double num; //numerator.
    double denom; //denominator.
    
public:
    //default constructor:
    Fraction()
    {
        num = 0.0;
        denom = 1.0;
    }
    //constructor w/ 2 arguments:
    Fraction(double n, double d)
    {
        num = n;
        denom = d;
    }
    
    //getters:
    double getNumerator()
    {
        return num;
    }
    double getDenominator()
    {
        return denom;
    }
    
    //setters:
    void setNumerator(double nu)
    {
        num = nu;
    }
    void setDenominator(double de)
    {
       denom = de;
    }
    
//START declaration of friend functions for operator overloadind inside class.
    //protoype for multiplication operator overload -> allows mulptlying of fractions:
    friend Fraction operator * (Fraction f1, Fraction f2);
    
    //protoype for insertion operator overload -> allows 'cout' of a fraction:
    friend ostream& operator << (ostream&o, const Fraction&f);
    
    //protoype for extraction operator overload -> allows 'cin' of a fraction:
    friend istream& operator >> (istream&i, Fraction&f);
    
    //protoype for division operator overload -> allows dividing of fractions:
    friend Fraction operator / (Fraction f1, Fraction f2);
    
    //protoype for comparison operator overload -> allows comparing of fractions:
    friend void operator == (Fraction f1, Fraction f2);
//END declaration of friend functions for operator overloadind inside class.
}; //END FRACTION CLASS.

//START definition of friend functions for operator overloadind outside class.
    //body for multiplication operator overload:
    Fraction operator * (Fraction f1, Fraction f2)
    {
        Fraction temp;
        temp.num = f1.num * f2.num;
        temp.denom = f1.denom * f2.denom;
        return temp;
    } //end multiplication operator overload friend function.

    //body for insertion operator overload:
    //return type is 'ostream&'
    //'o' is the argument and passed down.
    //'&' is just part of the return type?
    //'ostream' is similar to using 'cout'
    ostream& operator << (ostream&o, Fraction&f)
    //does not return object like * overloader.
    //returns a data type of cout.
    //arguments are (a data type of cout, a data type of Fraction object).
    //'o' and 'f' are where the 2 data types stored.
    {
        o << f.getNumerator() << "/" << f.getDenominator();
        //e.g cout << 13 << << "/" << 15;
        //whenver we use << it will take in cout << num/denom.
        //a fraction is what we are passing through friend function.
        return o; //return a 'cout' or ostream&.
    } //end insertion operator overload friend function.

    //body for extraction operator overload:
    istream& operator >> (istream&i, Fraction&f)
    {
        char slash = '/';
        i >> f.num >> slash >> f.denom;
        return i;
    } //end extraction operator overload friend function.

    //body for division operator overload:
    Fraction operator / (Fraction f1, Fraction f2)
    {
        Fraction temp;
        temp.num = f1.num * f2.denom;
        temp.denom = f1.denom * f2.num;
        return temp;
    } //end dvision operator overload friend function.

    //body for comparison operator overload:
    void operator == (Fraction f1, Fraction f2)
    //void bc do not need return value, just cout a decision path.
    {
        double fracOne = f1.num * f2.denom;
        double fracTwo = f1.denom * f2.num;
        if (fracOne > fracTwo)
        {
            cout << f1 << " > " << f2 << endl;
        }
        else if(fracOne < fracTwo)
        {
            cout << f1 << " < " << f2 << endl;
        }
        else
        {
            cout << f1 << " = " << f2 << " so fractions are the same" << endl;
        }
    } //end comparison operator overload friend function.
//END OF DEFINTION OF FRIEND FUNCTIONS OUTSIDE OF CLASS.

//START driver for program via main function:
int main()
{
    Fraction fr1; //create object from user input.
    cout << "enter first fraction: "; //using insertion operator overloader.
    cin >> fr1; //using extraction operator overloader.
    
    Fraction fr2; //create object from user input.
    cout << "enter second fraction: "; //using insertion overloader.
    cin >> fr2; //using extraction operator overloader.
    
    //using muliplication opertor overloader:
    Fraction product; //create default object.
    product = fr1 * fr2;
    //pass user's 2 objects (w/ num and denom each) from Fraction class into the '*' friend function.
    //friend function returns a single Fraction object (product of f1 * f2 w/ num and denom) & assigns it to object 'product'.
    cout << "your fractions mulitplied: " << product << endl; //using insertion operator overloader.
    
    //using division operator overloader:
    Fraction quotient;
    quotient = fr1 / fr2;
    cout << "your fractions divided: " << quotient << endl; //using insertion operator overloader.
    
    //using comparison operator overloader:
    fr1 == fr2;
    //note: why am I not using an object to call == function like in 
    //the multplication and quotient operator overloading?
    //answer: we dont need an object to left of 'fr1 == fr2' bc we are not
    //returning an object; we are returning nothing and instead couting a string.
    return 0;
} //END driver for program via main function.
