#ifndef DNA_H
#define DNA_H
#include <iostream>
#include <Cstring>
#include "Sequence.h"
using namespace std;

class DNA : public Sequence
{
  	private:


        char *complementary_strand;
        int startIndex;
        int endIndex;
    public:
    enum DNA_Type {promoter, motif,tail,noncoding};
 	 	// constructors and destructor
     DNA_Type type;
        DNA();
      //  char* Align(Sequence * s1, Sequence * s2);
        DNA(char * sq,DNA_Type atype);
        DNA(char * sq);
       // DNA(DNA& rhs);
       void ConvertToRNA();

        ~DNA();
 	 	// function printing DNA sequence information to user
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.

 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand(int v1,int v2);

         void Print();

        DNA(DNA& rhs);

        bool operator== ( char* x );

        bool operator!= ( char* x );

        friend ostream& operator<< (ostream& out,DNA d );
        friend istream& operator>> (istream& in,DNA d );
        char* operator+(DNA d);


};


#endif // DNA_H
