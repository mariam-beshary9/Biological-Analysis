#ifndef CODON_H
#define CODON_H

struct Codon
{
  	char *value=new char[4];    	    // 4th location for null character
    char AminoAcid;

    /// Did not free the memory
    	    // corresponding AminoAcid according to Table
    ~Codon ();

};
#endif // CODON_H
