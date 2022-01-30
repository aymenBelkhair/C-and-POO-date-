#include <iostream>
#include "Date.h"
using namespace std;
Date::Date()//:jour(1),mois(1),annee(2018)
{
}
Date::~Date()
{
}
int Date::Get_jour() {return jour;}
int Date::Get_mois(){return mois;}
int Date::Get_annee(){return annee;}
void Date::Set_jour(int j){jour=j;}
void Date::Set_mois(int m){mois=m;}
void Date::Set_annee(int a){annee=a;}
void Date::Set_date(int j, int m, int a){jour=j; mois=m; annee=a;}
void Date::Affiche(){
cout<<jour<<"/"<<mois<<"/"<<annee<<endl;
}
int Date::nombre_jours(int m,int a){
if(m==2){
if(a%4==0) return 29 ;
else return 28 ;
}
if(m==4 || m==6 || m==9 || m==11) return 30 ;
else return 31 ;
}
Date Date::Lendemain(){
Date d1;
if(jour<nombre_jours(mois,annee)) d1.Set_date(jour+1,mois,annee);
else{
if( mois == 12) d1.Set_date(1,1,annee+1);
else d1.Set_date(1,mois+1,annee);
}
return d1;
}

bool Date::Egale(Date d)
{return (jour==d.jour && mois==d.mois && annee==d.annee);}
bool Date::operator==(Date d){ return Egale(d);}
bool Date::Different(Date d){ return !Egale(d);}
bool Date::operator!=(Date d){ return Different(d);}
bool Date::Avant(Date d)
{
return (annee<d.annee) || (annee==d.annee && mois<d.mois)||
(annee==d.annee && mois==d.mois && jour<d.jour);
}
bool Date::operator<(Date d){ return Avant(d);}
bool Date::Apres(Date d)
{
return (annee>d.annee) || (annee==d.annee && mois>d.mois)||
(annee==d.annee && mois==d.mois && jour>d.jour);
}
bool Date::operator>(Date d){ return Apres(d);}
int Date::Jours_entre(Date d)
{
Date d1,d2;
int j=0;
if (Avant(d)) {d1=*this; d2=d;}
else {d2=*this; d1=d;}
for (Date i=d1; i<d2; i=i.Lendemain()) { i.Affiche(); j++;}
return j;
}
