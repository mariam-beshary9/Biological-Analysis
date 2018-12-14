#include "Protein.h"
int s=0;
 	 	Protein::Protein(){
 	 	seq =NULL;
 	 	}
 	 	Protein::Protein(char * p ,Protein_Type atype ){

 	 	    seq=p;
 	 	    type = atype;

 	 	}
 	 	Protein::Protein(char * p  ){
 	 	    seq=p;
 	 	}
 	 	Protein::~Protein(){
 	 	delete []seq;
 	 	}
 	 	// return an array of DNA sequences that can possibly
                // generate that protein sequence
void Protein::GetDNAStrandsEncodingMe( DNA bigDNA,CodonsTable table){

bigDNA.seq=new char [10];
int a=0;
while (a<3){
for (int i=0 ; i<64 ; i++){
    if (seq[a]== table.codons[i].AminoAcid){
     a++ ;
    for (int f=0 ;f<3 ; f++){

                               ///     represents row . represents col
            bigDNA.seq[s]= table.codons[i].value[f];
                            s+=1 ;

                }             }
                                  }
}


                  for(int i=0;i<9;i++)
            {
                    if( bigDNA.seq[i]=='U' )
                    {
                        bigDNA.seq[i]+='T';
                        bigDNA.seq[i]-='U';
                    }
            }
                           for(int m=0;m<9;m++)
                     {
                          cout<<bigDNA.seq[m];

                     }

                                                            }
/*
for (int i=0 ; i<61 ; i++){

    if ((seq[0]== table.codons[i].AminoAcid)&& (seq[1]== table.codons[i+1].AminoAcid)&&(seq[2]== table.codons[i+2].AminoAcid)){

                 for (int r=i ; r<i+3 ; r++){

                       for (int f=0 ;f<3 ; f++){

                               ///     represents row . represents col
                       bigDNA.seq[s]= table.codons[r].value[f];

                            s+=1 ;
                       }

                 }               }
                                  }



                  for(int i=0;i<9;i++)
            {
                    if( bigDNA.seq[i]=='T' )
                    {
                        bigDNA.seq[i]-='T';
                        bigDNA.seq[i]+='U';
                    }
            }
                           for(int m=0;m<9;m++)
                     {
                          cout<<bigDNA.seq[m];

                     }}*/

void Protein::Print()
        { cout<<"The type is :";

switch (type){
case (Hormon): cout<<"Hormon"<<endl;
break;
case (Enzyme): cout<<"Enzyme"<<endl;
break;
case (TF): cout<<"TF"<<endl;
break;
case (Cellular_Function): cout<<"Cellular_Functione"<<endl;


}
}


bool Protein::operator== ( char* x ){

      for (int i=0 ; i<9 ; i++){
        if (seq[i]!=x[i])  return false ;
      }
        return true ;
     }

bool Protein::operator!= ( char* x ){

      for (int i=0 ; i<9 ; i++){
        if (seq[i]!=x[i])  return true  ;
      }
        return false;
     }
ostream& operator<< (ostream& out,Protein p )
{
    for (int i=0 ; i< int (strlen(p.seq)-1) ; i++){
    out<<p.seq[i];
    }
    return out;
}
char* Protein ::operator+(Protein p){
char* s= new char [strlen(p.seq)+strlen(seq)];
for(int i=0 ; i<3;i++){

s[i]=seq[i];

}
for(int i=strlen(seq)  ; i<strlen(p.seq)+strlen(seq);i++){

s[i]=p.seq[i];

} return s;}

istream&  operator>> (istream& in,Protein p )
{

   /* for (int i=0;i<int(strlen(d.seq));i++){
    if(d.seq[i]>'a' && d.seq[i]<'z')
    {
        throw(" The DNA sequence should be in Uppercase. ");
    }}*/
    for (int i=0 ; i<3; i++){
    in>>p.seq[i];
    }

    return in;
}
