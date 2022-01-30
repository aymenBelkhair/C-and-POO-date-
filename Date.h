#ifndef DATE_H
#define DATE_H
class Date {
public:
Date();
~Date();
int Get_jour();
int Get_mois();
int Get_annee();
void Set_jour(int);
void Set_mois(int);
void Set_annee(int);
void Set_date(int,int,int);
void Affiche();
Date Lendemain();
bool Egale(Date);
bool operator==(Date);
bool Different(Date);
bool operator!=(Date);
bool Avant(Date);
bool operator<(Date);
bool Apres(Date);
bool operator>(Date);
int Jours_entre(Date);
private:
int jour, mois, annee;
int nombre_jours(int,int);
};
#endif
