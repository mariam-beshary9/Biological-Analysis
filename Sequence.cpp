#include "Sequence.h"
#define NULL 0
#include <Cmath>
#define max(a,b) ((a)>(b) ? (a):(b))

        Sequence::Sequence(){
        seq=NULL;

        }
        Sequence::Sequence(int length){
           seq=new char [length];
        }
        Sequence::Sequence(Sequence& rhs){
           seq= rhs.seq;

        }
        Sequence::~Sequence(){

        delete []seq;
        }
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        // virtual void Print()=0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism



void Sequence::Print()
{

}

istream& operator>> (istream& in,Sequence s )
{
    for (int i=0;i<9;i++){
    if(s.seq[i]>'a' && s.seq[i]<'z')
    {
        throw(30);
    }}
    for (int i=0 ; i<9 ; i++){
    in>>s.seq[i];
    }
    return in;
}
