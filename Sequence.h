#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
using namespace std;
class Sequence
{
public:
        char * seq;
 	 	// constructors and destructor
        Sequence();
        Sequence(int length);
        Sequence(Sequence& rhs);
        virtual ~Sequence();
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        virtual void Print();
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
      /// char* Align(Sequence * s1, Sequence * s2);
       bool operator== (char* x);
       bool operator!= (char* x);
       friend ostream& operator<< (ostream& out,Sequence s);
       friend istream& operator>> (ostream& in,Sequence s);
};
#endif // SEQUENCE_H
