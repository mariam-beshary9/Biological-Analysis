#ifndef RNA_H
#define RNA_H
#include <iostream>
#include <Cstring>
#include "Sequence.h"
#include "CodonsTable.h"
#include "DNA.h"
using namespace std;
class RNA : public Sequence
{

  	public:
        enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};
 	 	// constructors and destructor
        RNA();

        RNA(char * sequ, RNA_Type atype);
        RNA(char * sq);
        RNA( RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object

        string ConvertToProtein( CodonsTable table );

 	 	// function to convert the RNA sequence back to DNA
        string ConvertToDNA();
        bool operator== ( char* x );
        bool operator!= ( char* x );
        friend ostream& operator<< (ostream& out,RNA r );
        friend istream& operator>> (istream& in,RNA d );
        char* operator+(RNA r);

private:
        RNA_Type type;
};

#endif // RNA_H
