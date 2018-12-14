#include "DNA.h"

        DNA::DNA(){
          seq=NULL;

        }
 DNA::DNA(char * sq,DNA_Type type)
        :Sequence(strlen(sq))
        {
            //seq=new char [10];
            seq=sq;
            cout << seq << endl;
            //seq=sq;
           // type=atype;
        }

       // DNA(DNA& rhs);
       void DNA::ConvertToRNA()
        {

         for(int i=0;i<100;i++)
         {
        if( seq[i]=='T' )
        {
            seq[i]-='T';
            seq[i]+='U';
        }

         }
         cout<<"the rna is:"<<seq<<endl;

        }
        DNA::~DNA()
        {
            delete []seq;
            delete []complementary_strand;
        };
 	 	// function printing DNA sequence information to user
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.

 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void DNA::BuildComplementaryStrand(int v1,int v2)
        {
            startIndex=v1;
            endIndex=v2;
            complementary_strand=new char[v2-v1+1];

            for(int i = 0 ; i < v2-v1+1; i++)
                complementary_strand[i]=seq[v1+i];

            for(int i=0;i<v2-v1+1;i++)
            {
                if(complementary_strand[i]=='A')
                {
                    complementary_strand[i]-='A';
                    complementary_strand[i]+='T';
                }
                else if(complementary_strand[i]=='G')
                {
                    complementary_strand[i]-='G';
                    complementary_strand[i]+='C';

                }
                 else if(complementary_strand[i]=='C')
                {
                    complementary_strand[i]-='C';
                    complementary_strand[i]+='G';

                }
                 else if(complementary_strand[i]=='T')
                {
                    complementary_strand[i]-='T';
                    complementary_strand[i]+='A';

                }}

               for (int i=0;i<(v2-v1+1)/2 ; i++) {
                   char c;
                        c=complementary_strand[i] ;
                         complementary_strand[i]=  complementary_strand[v2-v1-i] ;
                        complementary_strand[v2-v1-i]=c;
                }
                //complementary_strand=complementary_strandtemp;
                cout<<"complementary_strand:"<<endl;
                for (int j=0 ; j<v2-v1+1 ; j++)
                cout<<complementary_strand[j];




        }
        void DNA::Print()
        { cout<<"The type is :";

switch (type){
case (promoter): cout<<"promoter"<<endl;
break;
case (tail): cout<<"tail"<<endl;
break;
case (noncoding): cout<<"noncoding"<<endl;

}
}

        DNA::DNA(DNA& rhs){

        for (int i=0 ; i<int(strlen(rhs.seq)) ;i++)
        seq[i]=rhs.seq[i];
        type = rhs.type ;

        }

bool DNA::operator== ( char* x ){

      for (int i=0 ; i<9 ; i++){
        if (seq[i]!=x[i])  return false ;
      }
        return true ;
     }

bool DNA::operator!= ( char* x ){

      for (int i=0 ; i<9 ; i++){
        if (seq[i]!=x[i])  return true  ;
      }
        return false;
     }
ostream& operator<< (ostream& out,DNA d )
{
    for (int i=0 ; i< int (strlen(d.seq)-1) ; i++){
    out<<d.seq[i];
    }
    return out;
}
istream&  operator>> (istream& in,DNA d )
{

   /* for (int i=0;i<int(strlen(d.seq));i++){
    if(d.seq[i]>'a' && d.seq[i]<'z')
    {
        throw(" The DNA sequence should be in Uppercase. ");
    }}*/
    for (int i=0 ; i<10; i++){
    in>>d.seq[i];
    }

    return in;
}
char* DNA::operator+(DNA d){
char* s= new char [strlen(d.seq)+strlen(seq)];
for(int i=0 ; i<strlen(seq);i++){

s[i]=seq[i];

}
for(int i=strlen(seq) ; i<strlen(d.seq)+strlen(seq);i++){

s[i]=d.seq[i];

}

return s;
}
