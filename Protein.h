#ifndef PROTEIN_H
#define PROTEIN_H
#include <iostream>
#include <Cstring>
#include "Sequence.h"
#include "CodonsTable.h"
#include "DNA.h"
class Protein : public Sequence
{

      public:
      enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
      Protein_Type type;
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p ,Protein_Type atype );
 	 	Protein(char * p  );
 	 	~Protein();
 	 	// return an array of DNA sequences that can possibly
                // generate that protein sequence

void GetDNAStrandsEncodingMe( DNA bigDNA,CodonsTable table);
void Print();
bool operator== ( char* x );
bool operator!= ( char* x );
friend ostream& operator<< (ostream& out,Protein p );
friend istream& operator>> (istream& in,Protein p );
char* operator+(Protein p);

};




#endif // PROTEIN_H
