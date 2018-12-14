#include "CodonsTable.h"
#include <fstream>
#include <iostream>

using namespace std;

///The constructor of the table.
CodonsTable::CodonsTable()
{
//Reading the file and taking the data of the table from it.

ifstream in ;
in.open("RNA_codon_table.txt");
cout <<"Loading Codon file , Please wait ."<<endl;


for(int i=0 ; i<64 ; i++){
        in>>codons[i].value[0] ;
        in>>codons[i].value[1] ;
        in>>codons[i].value[2] ;
        in>>codons[i].AminoAcid;

} ///To get the Amino Acid in it's real form.
for(int y=0 ; y<64 ; y++){

        if (codons[y].AminoAcid =='-')
                codons[y].AminoAcid=' ';
        }

/// Printing the table
for (int f=0 ;f<64 ; f++ ){
            for (int k=0 ; k<3 ;k++){
            cout<<codons[f].value[k] <<" ";}
            cout<<"  "<<codons[f].AminoAcid<<" ";

        cout<<endl ;}



in.close();

}
