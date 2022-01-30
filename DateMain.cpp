#include <iostream>
#include "Date.h"
using namespace std;
bool Valide(int,int,int) ;
bool Valide(int j,int m, int a){
if (j>=1 && j<=31 && m>=1 && m<=12 && a>=1){
if(m==2){
if(a%4==0) return j<=29 ;
else return j<=28 ;
}
if(m==4 || m==6 || m==9 || m==11) return j<=30 ;
else return j<=31 ;
}
else return false ;
}

int main()
{
int j,m,a;
cout <<"Saisir la data D1: ";
cin >>j>>m>>a;
if (Valide(j,m,a)){
Date d1;
d1.Set_date(j,m,a);
cout<<"D1= ";d1.Affiche();
cout <<"Lendemain de D1: ";d1.Lendemain().Affiche();
cout <<"Saisir la data D1: ";
cin >>j>>m>>a;
if (Valide(j,m,a)){
Date d2;
d2.Set_date(j,m,a);
if (d1==d2) cout <<"D1==D2"<<endl;
if (d1!=d2) cout <<"D1!=D2"<<endl;
if (d1<d2) cout <<"D1<D2"<<endl;
if (d1>d2) cout <<"D1>D2"<<endl;
cout << d1.Jours_entre(d2);
}
else cout <<"La date D2 est incorrecte." <<endl;
}
else cout <<"La date D1 est incorrecte." <<endl;
return 0;
}
