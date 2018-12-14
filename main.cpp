#include <iostream>
#include <Cstring>
#include <cmath>
#include "Sequence.h"
#include "DNA.h"
#include "Codon.h"
#include "CodonsTable.h"
#include "RNA.h"
#include "Protein.h"
#include <exception>

using namespace std;

char* Align(char* s1 , char* s2 ,int x,int y)
{


    int **lcs = new int* [x+1];
    *lcs= new int[y+1];

    for (int r=0;r<=x;r++){
        for (int c=0;c<=y;c++){
            if (r == 0 || c == 0)
                lcs[r][c]=0;

            else if(s1[r-1] == s2[c-1])
				lcs[r][c] = lcs[r-1][c-1]+1;

            else
                lcs[r][c] = max(lcs[r-1][c],lcs[r][c-1]);

                                    }
                             }
            //fill char* LCS


    int index=lcs[x][y];
    char p[index+1];
    p[index]='  ';
    int i = x, j = y;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (s1[i-1] == s2[j-1])
      {
          p[index-1] = s1[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }

      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (lcs[i-1][j] > lcs[i][j-1])
         i--;
      else
         j--;
   }


   return p ;
}


int main(){
try{
char * seq ;
while (true){

  int ans ;
  cout<<endl<<"________________________"<<endl<<"Enter the type of sequence you want to operate on "<<endl<<"1)DNA"<<endl<<"2)RNA"<<endl<<"3)Protein"<<endl ;
  cin>> ans ;

  if (ans==1) {
  seq=new char[10];
  cout<<endl<<"Enter the DNA sequence"<<endl ;
  cin>>seq;
  cout<<endl<<endl<<"Your DNA sequence is :"<<endl;

   DNA d(seq, DNA::tail);
   d.Print();
  int ans2;
  cout<<endl<<"Enter the number of operation you want to apply on."<<endl<<"1)Convert to RNA. "<<endl<<"2)Get complemetary strand"<<endl<<"3)Know if if equla another sequence"<<endl<<"4)know if it does not equal anoter sequence"<<endl<<"5)Alignment"<<endl<<"6)Merge two sequences"<<endl;
  cin>>ans2;
  if (ans2==1)           {
        d.ConvertToRNA();}

  else if (ans2==2) {
        int v1,v2;
        cout<<"Enter the first index and the end index .. Index start from 0"<<endl ;
        cin>>v1>>v2;
        d.BuildComplementaryStrand(v1, v2);
                    }
  else if (ans2==3){
  char *eq = new char [10];
  cout<<endl<<"Enter the another sequence"<<endl;
  cin>>eq ;
  if(d==eq) cout<<endl<<"The two sequences are equal"<<endl;
  else cout<<"The two sequences are not equal"<<endl;
  delete []eq;
  }

  else if (ans2==4){
  char *eq = new char [10];
  cout<<"Enter the another sequence"<<endl;
  cin>>eq ;
  if(d!=eq) cout<<endl<<"The two sequences are not equal"<<endl;
  else cout<<"The two sequences are equal"<<endl;
  delete []eq;
  }

  else if (ans2==5){
  cout<<"Enter the another object sequence. "<<endl;
  DNA d2 ;
  cin>> d2.seq ;
 Align(d.seq, d2.seq,int (strlen(d.seq)),int (strlen(d2.seq)));

 }


  else if(ans2==6){
  cout<<"Enter the another object sequence. "<<endl;
  DNA d2 ;
  cin>>d2.seq;
  cout<< d+d2;

  }
  else  cout<<"Not valid operator"<<endl;

  }

  else if (ans==2){
 seq=new char[10];
  cout<<endl<<"Enter the RNA sequence"<<endl ;
  cin>>seq;


  RNA r(seq,RNA::mRNA);
  r.Print();
  cout<<endl<<endl<<"Enter the number of the operation you want to apply on."<<endl<<"1)Convert to protein."<<endl<<"2)Convert to DNA."<<endl<<"3) Vertify two RNA sequences are equal. "<<endl<<"4)Vertify two RNA sequences are not equal."<<endl<<"5)Alignment"<<endl<<"6)Merge two sequences"<<endl;
int n;

cin>>n;
if (n==1){
cout<<"The table of Codons is :"<<endl ;
CodonsTable table;
    cout<<endl<<r.ConvertToProtein( table );
}
else if (n==2){
cout<<r.ConvertToDNA()<<endl;


}
else if(n==3){
char *eq = new char [10];
  cout<<"Enter the another sequence"<<endl;
  cin>>eq ;
  if(r==eq) cout<<endl<<"The two sequences are equal"<<endl;
  else cout<<endl<<"The two sequences are not equal"<<endl;
  delete []eq;
  }

  else if (n==4){
  char *eq = new char [10];
  cout<<"Enter the another sequence"<<endl;
  cin>>eq ;
  if(r!=eq) cout<<endl<<"The two sequences are not equal"<<endl;
  else cout<<endl<<"The two sequences are equal"<<endl;
  delete []eq;
  }
 else if (n==5){
 cout<<"Enter the another object sequence. "<<endl;
  RNA r2 ;
  cin>> r2.seq ;
Align(r.seq, r2.seq,int (strlen(r.seq)),int (strlen(r2.seq)));
  }
  else if(n==6){
  cout<<endl<<"Enter the another object sequence. "<<endl;
  RNA r2 ;
  cin>>r2.seq;
  cout<< r+r2;

  }
 else  cout<<endl<<"Not valid operator"<<endl;


  }
  else if (ans==3){
    seq=new char[4];
  cout<<"Enter the Protein sequence"<<endl ;
  cin>>seq;
  Protein p(seq,Protein::TF);
  p.Print();
 cout<<endl<<"Enter the number of the operation you want to apply on."<<endl<<"1)Convert to DNA."<<endl<<"2) Vertify two RNA sequences are equal. "<<endl<<"3)Vertify two RNA sequences are not equal."<<endl<<"4)Alignment"<<endl<<"5)Merge two sequences."<<endl;
  int j;
  cin>>j;
  if(j==1){
  DNA bigDNA;
  CodonsTable table;
       p.GetDNAStrandsEncodingMe( bigDNA,table);
  }
   else if(j==2){
   char *eq = new char [10];
  cout<<"Enter the another sequence"<<endl;
  cin>>eq ;
  if(p==eq) cout<<endl<<"The two sequences are equal"<<endl;
  else cout<<endl<<"The two sequences are not equal"<<endl;
  delete []eq;
  }

  else if (j==3){
  char *eq = new char [10];
  cout<<"Enter the another sequence"<<endl;
  cin>>eq ;
  if(p!=eq) cout<<endl<<"The two sequences are not equal"<<endl;
  else cout<<endl<<"The two sequences are equal"<<endl;
  delete []eq;
  }
 else if (j==4){
 cout<<endl<<"Enter the another object sequence. "<<endl;
  Protein p2 ;
  cin>> p2.seq ;
Align(p.seq, p2.seq,int (strlen(p.seq)),int (strlen(p2.seq)));  }
  else if (j==5){
  cout<<endl<<"Enter the another object sequence. "<<endl;
  Protein p2 ;
  cin>>p2.seq;
  cout<< p+p2;

  }
 else  cout<<"Not valid operator"<<endl;

  }
 else cout<<"Unvalid choice"<<endl;

}
delete [] seq ;
}
catch (string e){
cout<<e;

}
cout<<"There is a problem.";
return 0 ;}
