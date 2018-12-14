#include "RNA.h"

        RNA::RNA(){
         seq = NULL;
        }


        RNA::RNA(char * sq,RNA_Type atype)
        :Sequence(strlen(sq))
        { //char* t="Unvalid characters , you can write only A,C,G,U";
            //seq=new char [10];

                seq = sq;


            cout << seq << endl;
            //seq=sq;
           // type=atype;
        }


        RNA::RNA( RNA& rhs){

        for (int i=0 ; i<9 ;i++)
        seq[i]=rhs.seq[i];
        type = rhs.type ;
        }


        RNA::~RNA(){
        cout<<"Calling the destructor of RNA"<<endl;

        }
 	 	// function to be overridden to print all the RNA information
        void RNA::Print(){
        cout<<"The type is :";
switch (type){
case (mRNA): cout<<"mRNA"<<endl;
break;
case (mRNA_exon): cout<<"mRNA_exon"<<endl;
break;
case (mRNA_intron): cout<<"mRNA_intron"<<endl;
break;
case (pre_mRNA): cout<<"pre_mRNA"<<endl;

}
}
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object

string RNA::ConvertToProtein( CodonsTable table ){

string pro ="___";
        int i=0;
        int d=0;
        while (i<9 ){
         for (int j=0 ; j<64 ; j++){

                if  ((seq[i]==table.codons[j].value[0])&& (seq[i+1]==table.codons[j].value[1])&&(seq[i+2]==table.codons[j].value[2]))
                    {

                    pro[d]=table.codons[j].AminoAcid ;
                    ;
                    d+=1;
                    break ;

                    }

                                   }
                    i+=3;
                    }

                    return  pro ;}

 	 	// function to convert the RNA sequence back to DNA
        string RNA::ConvertToDNA(){
        string d="            ";
        for (int y=0 ; y<9 ; y++)
        d[y]=seq[y];
        for(int i=0;i<9;i++)
            {
                    if( seq[i]=='U' )
                    {
                        d[i]+='T';
                        d[i]-='U';
                    }
            }   return d;}


bool RNA::operator== ( char* x ){

      for (int i=0 ; i<9 ; i++){
        if (this->seq[i]!=x[i])  return false ;
      }
        return true ;
     }

bool RNA::operator!= ( char* x ){

      for (int i=0 ; i<9 ; i++){
        if (seq[i]!=x[i])  return true  ;
     }
        return false;
     }

ostream& operator<< (ostream& out,RNA r )
{
    for (int i=0 ; i< int (strlen(r.seq)-1) ; i++){
    out<<r.seq[i];
    }
    return out;
}
char* RNA::operator+(RNA r){
char* s= new char [strlen(r.seq)+strlen(seq)];
for(int i=0 ; i<strlen(seq);i++){

s[i]=seq[i];

}
for(int i=strlen(seq) ; i<strlen(r.seq)+strlen(seq);i++){

s[i]=r.seq[i];

}return s;}



