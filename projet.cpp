#include <iostream>
#include<string>
#include <vector>
#include "projet.h"
#include <fstream>

using namespace std;
// Date
Date::Date(int j,int m,int a)
{
    jour=j;
    mois=m;
    annee=a;
}
Date::Date()
{

}
ostream& operator<< (ostream& out,Date& d)
{
    out<<d.jour<<'/'<<d.mois<<'/'<<d.annee;
    return out;
}
istream& operator>> (istream& in,Date& d)
{
  repeat:
    cout<<endl<<"jour: ";
    in>>d.jour;
    if ((d.jour<1) || (d.jour>31))
        {goto repeat;}
    again:
    {cout<<endl<<"mois: "; in>>d.mois; }
    if ((d.mois<1)||d.mois>12) goto again;
    also:
    cout<<endl<<"annee:";
    in>>d.annee;
    if ((d.annee>2022)) goto also;
    return in;

}
bool Date::operator== (const Date& d)
{
    if(jour==d.jour && mois==d.mois && annee==d.annee)
        return true;
    else
        return false;
}
Date& Date::operator= (const Date& d)
{
    if(this!=&d)
    {
    jour=d.jour; mois=d.mois;annee=d.annee;}
    return *this;
}

//Facture
Facture::Facture(int Num,double Montant,Date d,bool P)
{
    NumFacture=Num;
    montantFacture=Montant;
    DateLimite=d;
    PayeeOuNon=P;
}
Facture::Facture()
{

}
void Facture::Payer()
{
    PayeeOuNon=true;
}
ostream& operator<< (ostream& out,Facture& fact)
{
    out<<"\n\n\tFACTURE\n\nFacture numero: " <<fact.NumFacture<<"\nMontant a payer: "<<fact.montantFacture<<"\nDate limite: "<<fact.DateLimite;
    if(fact.PayeeOuNon==true)
        out<<"\n\nFacture payee\n";
    else
        out<<"\n\nFacture non payee\n";
    return out;
}
istream& operator>> (istream& in,Facture& fact)
{
    cout<<"\nSaisir la numero de facture"<<endl;
    in>>fact.NumFacture;
    cout<<"\nSaisir le montant a payer"<<endl;
    in>>fact.montantFacture;
    cout<<"\nSaisir la date limite de payement"<<endl;
    in>>fact.DateLimite;
    int choix;
    cout<<"\nFacture payee ou non\n1-payee\n2-non payee"<<endl;
    in>>choix;
    if(choix==1)
        fact.PayeeOuNon=true;
    if(choix==2)
        fact.PayeeOuNon=false;
    return in;
}
//Parent responsable
ParentResponsable::ParentResponsable(long CIN,string nom,string prenom,Date dateNaiss,long tel,string Email,string Adresse,string Fonction)
{
    this->CIN=CIN;
    this->nom=nom;
    this->prenom=prenom;
    this->dateNaiss=dateNaiss;
    this->tel=tel;
    this->Email=Email;
    this->Adresse=Adresse;
    this->Fonction=Fonction;
}
ParentResponsable::ParentResponsable()
{

}
ostream& operator<< (ostream& out,ParentResponsable& pr)
{
    out<<"\n\n\tPARENT RESPONSABLE\n\nCIN: " <<pr.CIN<<"\nNom & Prenom: "<<pr.nom<<" "<<pr.prenom<<"\nDate de naissance: "<<pr.dateNaiss<<"\nNumero de telephone: "<<pr.tel<<"\nEmail: "<<pr.Email;
    out<<"\nAdresse: "<<pr.Adresse<<"\nFonction: "<<pr.Fonction<<endl;
    return out;
}
istream& operator>> (istream& in,ParentResponsable& pr)
{
    cout<<"\nSaisir le numero CIN"<<endl;
    in>>pr.CIN;
    cout<<"\nSaisir le nom"<<endl;
    in>>pr.nom;
    cout<<"\nSaisir prenom"<<endl;
    in>>pr.prenom;
    cout<<"\nSaisir la date de naissance"<<endl;
    in>>pr.dateNaiss;
    cout<<"\nSaisir le numero de telephone"<<endl;
    in>>pr.tel;
    cout<<"\nSaisir l'email"<<endl;
    in>>pr.Email;
    cout<<"\nSaisir l'adresse"<<endl;
    in>>pr.Adresse;
    cout<<"\nSaisir la fonction"<<endl;
    in>>pr.Fonction;
    return in;
}
ParentResponsable& ParentResponsable::operator= (const ParentResponsable& pr)
{
        if(this!=&pr)
    {
        CIN=pr.CIN;
        nom=pr.nom;
        prenom=pr.prenom;
        dateNaiss=pr.dateNaiss;
        tel=pr.tel;
        Email=pr.Email;
        Adresse=pr.Adresse;
        Fonction=pr.Fonction;
    }
    return *this;
}
void ParentResponsable::ModifierDonnees()
{
    int choix;
    cout<<"\nQuelle information vous voulez changer?\n1.Email\n2.Numero de telephone\n3.Adresse\n4.Fonction\n\nSaisir le numero de votre choix:"<<endl;
    cin>>choix;
    if(choix==1)
    {
        string NEmail;
        cout<<"Saisir votre nouvel Email"<<endl;
        cin>>NEmail;
        Email=NEmail;
    }
    if(choix==2)
    {
        long Ntel;
        cout<<"Saisir votre nouveau numero de telephone"<<endl;
        cin>>Ntel;
        tel=Ntel;
    }
    if(choix==3)
    {
        string NAdresse;
        cout<<"Saisir votre nouvel Adresse"<<endl;
        cin>>NAdresse;
        Adresse=NAdresse;
    }
    if(choix==4)
    {
        string NFonction;
        cout<<"Saisir votre nouvelle fonction"<<endl;
        cin>>NFonction;
        Fonction=NFonction;
    }

}
//Groupe
Groupe::Groupe()
{
}
Groupe::Groupe(string s,string niv)
{
    designationgrp=s;
    niveau=niv;
    for(int i=0;i<6;i++)
        for(int j=0;j<9;j++)
        emploi[i][j]="--";
}
ostream& operator<< (ostream& out,Groupe& grp)
{
    out<<"\n\GROUPE: "<<grp.designationgrp<<"\nNiveau: "<<grp.niveau;

    return out;
}
istream& operator>> (istream& in,Groupe& grp)
{
    cout<<"\nSaisir la designation du groupe"<<endl;
    in>>grp.designationgrp;
    x:
    cout<<"Selectionner le niveau \n1-Niveau Junior\n2-Creche\n3-Preparatoire\n4-Garderie Scolaire\n";
    int choixNiv;
    in>>choixNiv;
    if(choixNiv==1)
        grp.niveau="Niveau Junior";
    else if(choixNiv==2)
        grp.niveau="Creche";
    else if(choixNiv==3)
        grp.niveau="Preparatoire";
    else if(choixNiv==4)
        grp.niveau="Garderie Scolaire";
    else
        goto x;



    return in;
}
Groupe& Groupe::operator= (const Groupe& grp)
{
    if(this!=&grp)
    {
        designationgrp=grp.designationgrp;
        niveau=grp.niveau;
        for(int i=0;i<6;i++)
            for(int j=0;j<9;j++)
                emploi[i][j]=grp.emploi[i][j];
    }
    return *this;
}
void Groupe::SetEmploi()
{

    cout<<"\n EMPLOI DE TEMPS"<<endl;
    for(int i=0;i<6;i++)
    {
        if(i==0)
            cout<<"\n Lundi"<<endl;
        if(i==1)
            cout<<"\n Mardi"<<endl;
        if(i==2)
            cout<<"\n Mercredi"<<endl;
        if(i==3)
            cout<<"\n Jeudi"<<endl;
        if(i==4)
            cout<<"\n Vendredi"<<endl;
        if(i==5)
            cout<<"\n Samedi"<<endl;
        for(int j=0;j<9;j++)
        {
            if(j==0)
                cout<<"\n 8h--9h"<<endl;
            if(j==1)
                cout<<"\n 9h--10h"<<endl;
            if(j==2)
                cout<<"\n 10h--11h"<<endl;
            if(j==3)
                cout<<"\n 11h--12h"<<endl;
            if(j==4)
                cout<<"\n 12h--13h"<<endl;
            if(j==5)
                cout<<"\n 13h--14h"<<endl;
            if(j==6)
                cout<<"\n 14h--15h"<<endl;
            if(j==7)
                cout<<"\n 15h--16h"<<endl;
            if(j==8)
                cout<<"\n 16h--17h"<<endl;
            string ch;
            cout<<"Saisir une activité"<<endl;
            cin>>ch;
            emploi[i][j]=ch;
    }
}
cout<<"Votre Emploi\n"<<endl;

for(int i=0;i<6;i++)
{
        if(i==0)
            cout<<"\n Lundi \t";
        if(i==1)
            cout<<"\n Mardi \t";
        if(i==2)
            cout<<"\n Mercredi \t";
        if(i==3)
            cout<<"\n Jeudi \t";
        if(i==4)
            cout<<"\n Vendredi \t";
        if(i==5)
            cout<<"\n Samedi \t";
    for(int j=0;j<9;j++)
        cout<<emploi[i][j]<<'\t';
    cout<<'\n';
}
}
void Groupe::afficherEmploi()
{
    cout<<"\n\t\tEmploi de temps:\n";
    for(int i=0;i<6;i++)
{
        if(i==0)
            cout<<"\n Lundi \t";
        if(i==1)
            cout<<"\n Mardi \t";
        if(i==2)
            cout<<"\n Mercredi \t";
        if(i==3)
            cout<<"\n Jeudi \t";
        if(i==4)
            cout<<"\n Vendredi \t";
        if(i==5)
            cout<<"\n Samedi \t";
    for(int j=0;j<9;j++)
        cout<<emploi[i][j]<<'\t';
    cout<<'\n';
}
}
void Groupe::modifierEmploi()
{
    string jour;
    int temps;
    j:
    cout<<"preciser le jour de l'activite a changer"<<endl;
    cin>>jour;
    cin>>temps;
    int i,j;
      if(jour=="lundi")
    i=0;
   else if(jour=="mardi")
    i=1;
   else if(jour=="mercredi")
    i=2;
   else if(jour=="jeudi")
    i=3;
   else if(jour=="vendredi")
    i=4;
   else if(jour=="samedi")
    i=5;
     else
    {
    cout<<"\nchoix invalide\nreesayer\n";
    goto j;
    }
    t:
cout<<"preciser le temps de debut de l'activite a changer"<<endl;
    cin>>temps;
   if(temps==8)
    j=0;
   else if(temps==9)
    j=1;
   else if(temps==10)
    j=2;
   else if(temps==11)
    j=3;
   else if(temps==12)
    j=4;
   else if(temps==13)
    j=5;
   else if(temps==14)
    j=6;
   else if(temps==15)
    j=7;
   else if(temps==16)
    j=8;
 else
    {
    cout<<"\nchoix invalide\nreesayer\n";
    goto t;
    }


string ch;
cout<<"Saisir la nouvelle activite"<<endl;
cin>>ch;
emploi[i][j]=ch;
}
bool Groupe::operator== (const Groupe& grp)
{
    if(designationgrp==grp.designationgrp && niveau==grp.niveau)
        return true;
    else
        return false;
}
string Groupe::getDesignation()
{
    return designationgrp;
}
void Groupe::setDesignation()
{
    cout<<"\nSaisir la designation du groupe:  ";
    cin>>designationgrp;
}
string Groupe::getniveau()
{
    return niveau;
}
bool Groupe::AjouterEnfant()
{
    if(nbEnf<25)
        {nbEnf++;
        return true;}
    else
    {cout<<"\nCe groupe est complet!"<<endl;
    return false;}


}

//Niveau
Niveau::Niveau()
{

}
Niveau::Niveau(string design)
{
    designationNiv=design;
    vector<Groupe>tabGrp;

}
ostream& operator<< (ostream& out,Niveau& niv)
{
    out<<"\n\n\tNIVEAU\n\nDesignation du niveau: "<<niv.designationNiv;
    out<<"\nListe des Groupe:\n";
    for(int i=0;i<niv.tabGrp.size();i++)
        out<<niv.tabGrp[i].getDesignation()<<'\t';
    return out;
}
istream& operator>> (istream& in,Niveau& niv)
{
    n:
    cout<<"Selectionner le niveau \n1-Niveau Junior\n2-Creche\n3-Preparatoire\n4-Garderie Scolaire\n";
    int choixNiv;
    in>>choixNiv;
    if(choixNiv==1)
        niv.designationNiv="Niveau Junior";
    else if(choixNiv==2)
        niv.designationNiv="Creche";
    else if(choixNiv==3)
        niv.designationNiv="Preparatoire";
    else if(choixNiv==4)
        niv.designationNiv="Garderie Scolaire";
    else
    {
        cout<<"\nreponse invalide\nreesayer\n";
        goto n;
    }
    int choix;
    string des;

    do
    {
        cout<<"\nSaisir la designation d'un groupe\n";
        in>>des;
        Groupe grp(des,niv.designationNiv);
        niv.tabGrp.push_back(grp);
        cout<<"\n ajouter encore\n1-oui\n2-non"<<endl;
        cin>>choix;
    }
    while(choix==1);
    vector<Groupe>tabGrp;

    return in;
}
void Niveau::SaisirTab()
{
    string des;
    int choix;
    do
    {
    Groupe grp;
    cin>>grp;
    tabGrp.push_back(grp);
    cout<<"Voulez vous ajouter un groupe ? \n 1-Oui\n2-Non"<<endl;

    cin>>choix;
    }
    while(choix==1);

}

void Niveau::AjouterGrp(Groupe grp)
{
    tabGrp.push_back(grp);
}
void Niveau::AjouterGrp()
{
    Groupe g;
    cin>>g;
    tabGrp.push_back(g);
}
void Niveau::SupprimerGrp(Groupe grp)
{
    for(int i=0;i<tabGrp.size();i++)
        if(tabGrp[i]==grp)
        {
            tabGrp.erase(tabGrp.begin()+i);
        }
}
void Niveau::SupprimerGrp()
{
    Groupe g;
    cin>>g;
    SupprimerGrp(g);
}
string Niveau::getDes()
{
    return designationNiv;
}
Niveau::~Niveau()
{
    tabGrp.clear();
}
Niveau::Niveau(const Niveau &Niv)
{
    this->designationNiv=Niv.designationNiv;
    for(int i=0;i<Niv.tabGrp.size();i++)
        this->tabGrp[i]=Niv.tabGrp[i];

}
//Enfant
Enfant::Enfant(Date dInsc,string nom,string prenom,Date dateNaiss,ParentResponsable PR,string sexe,string nation,string GrpS,bool vaccine,Groupe grp)
{

    this->DateInscription=dInsc;
    this->nomE=nom;
    this->prenomE=prenom;
    this->DateNaissE=dateNaiss;
    this->PR=PR;
    this->sexe=sexe;
    this->nationalite=nation;
    this->GroupeSanguin=GrpS;
    this->Vaccine=vaccine;
    this->grp=grp;

}
Enfant::Enfant()
{

}
Enfant::Enfant(const Enfant &enf)
{

    this->DateInscription=enf.DateInscription;
    this->nomE=enf.nomE;
    this->prenomE=enf.prenomE;
    this->DateNaissE=enf.DateNaissE;
    this->PR=enf.PR;
    this->sexe=enf.sexe;
    this->nationalite=enf.nationalite;
    this->GroupeSanguin=enf.GroupeSanguin;
    this->Vaccine=enf.Vaccine;
    for(int i=0;i<enf.maladies.size();i++)
    {
        maladies.push_back(enf.maladies[i]);
    }
    for(int i=0;i<enf.allergies.size();i++)
    {
        allergies.push_back(enf.allergies[i]);
    }
    this->grp=enf.grp;

}


ostream& operator<< (ostream& out,Enfant& enf)
{
    out<<"\n\n\tENFANT\n\nDate d'inscription: "<<enf.DateInscription;
    out<<enf.grp;
    out<<"\nNom & Prenom: "<<enf.nomE<<" "<<enf.prenomE<<"\nDate de naissance: "<<enf.DateNaissE<<"\nSexe: "<<enf.sexe<<"\nNationalite: "<<enf.nationalite;
    out<<"\nGroupe Sanguin: "<<enf.GroupeSanguin;
    if(enf.Vaccine==true)
        out<<"\nEnfant vaccine";
    else
        out<<"\nEnfant non vaccine";
    out<<"\nMaladies: ";
    if(enf.maladies.size()==0)
        out<<"N'existent pas";
    else
        for(int i=0;i<enf.maladies.size();i++)
            out<<enf.maladies[i]<<'\t';
    out<<"\nAllergies: ";
    if(enf.allergies.size()==0)
        out<<"N'existent pas";
    else
        for(int i=0;i<enf.allergies.size();i++)
            out<<enf.allergies[i]<<'\t';
    out<<enf.PR;

    return out;
}
istream& operator>> (istream& in,Enfant& enf)
{

    cout<<"\nSaisir la date d'inscription"<<endl;
    in>>enf.DateInscription;
    cout<<"\nSaisir le nom de l'enfant"<<endl;
    in>>enf.nomE;
    cout<<"\nSaisir le prenom de l'enfant"<<endl;
    in>>enf.prenomE;
    cout<<"\nSaisir la date de naissance de l'enfant"<<endl;
    in>>enf.DateNaissE;
    cout<<"\nSaisir le sexe de l'enfant"<<endl;
    in>>enf.sexe;
    cout<<"\nSaisir la nationalite de l'enfant"<<endl;
    in>>enf.nationalite;
    cout<<"\nSaisir le groupe sanguin de l'enfant"<<endl;
    in>>enf.GroupeSanguin;
    int choix;
    l:
    cout<<"\nl'enfant est-il vaccine\n1-oui\n2-non"<<endl;
    in>>choix;
    if(choix==1)
        enf.Vaccine=true;
    else if(choix==2)
        enf.Vaccine=false;
    else
    {
        cout<<"\nReponse invalide"<<endl;
        goto l;
    }
    string mal,al;
    int choixm,choixa,choixniv;
    cout<<"Saisir les maladies de cet enfant s'il y en a"<<endl;
    do
    {
        cin>>mal;
        enf.maladies.push_back(mal);
        cout<<"\n ajouter encore\n1-oui\n2-non"<<endl;
        cin>>choixm;
    }
    while(choixm==1);
        cout<<"Saisir les allergies de cet enfant s'il y en a"<<endl;
    do
    {
        cin>>al;
        enf.allergies.push_back(al);
        cout<<"\n ajouter encore\n1-oui\n2-non"<<endl;
        cin>>choixa;
    }
    while(choixa==1);
    in>>enf.grp;
    cout<<"\n\tPARENT RESPONSABLE \n";
    in>>enf.PR;
    in>>enf.grp;
    return in;
}
bool Enfant::operator== (const Enfant& enf)
{
    if(DateInscription==enf.DateInscription && nomE==enf.nomE && prenomE==enf.prenomE && DateNaissE==enf.DateNaissE && sexe==enf.sexe && nationalite==enf.nationalite && grp==enf.grp)
        return true;
    else
        return false;
}
void Enfant::Vacciner()
{
  if(Vaccine==false)
    {Vaccine=true;
    cout<<"\nEnfant vaccine avec succes!\n";}
 else
    cout<<"\nEnfant deja vaccine!\n";
}
void Enfant::AjouterMaladie()
{
    cout<<"\nSaisir une maladie: "<<endl;
    string mal;
    cin>>mal;
    maladies.push_back(mal);
}
void Enfant::AjouterAllergie()
{
    cout<<"\nSaisir une allergie: "<<endl;
    string all;
    cin>>all;
    allergies.push_back(all);
}
void Enfant::SupprimerMaladie()
{
    cout<<"\nSaisir une maladie: "<<endl;
    string mal;
    cin>>mal;
    bool t=false;
    for(int i=0;i<maladies.size();i++)
    {
        if(maladies[i]==mal)
            {maladies.erase(maladies.begin()+i);
            t=true;}
    }
    if(t==false)
        cout<<"\ncette maladie n'existe pas ici!!"<<endl;
}
void Enfant::SupprimerAllergie()
{
    cout<<"\nSaisir une allergie: "<<endl;
    string all;
    cin>>all;
    bool t=false;
    for(int i=0;i<allergies.size();i++)
    {
        if(allergies[i]==all)
            {allergies.erase(allergies.begin()+i);
            t=true;}
    }
    if(t==false)
        cout<<"\ncette allergie n'existe pas ici!!"<<endl;
}

void Enfant::ouvrir(fstream& f)
{
    f.open("Enfants.txt",ios::in|ios::out|ios::app);
    if(!f.is_open())
        exit(-1);
}
void Enfant::enregistrer(fstream& f,Enfant& enf)
{
    f<<enf;
    cout<<"\nAjout avec succes"<<endl;
}
void Enfant::afficher(fstream& f)
{
    Enfant enf;
    if(!f.is_open())
        exit(-1);
    f.seekg(0);
    while(!f.eof())
    {
        f>>enf;
        cout<<enf<<endl;
    }
    f.close();
}
Enfant Enfant::getEnfant(fstream& f)
{
        Enfant enf;
    if(!f.is_open())
        exit(-1);
    f.seekg(0);
    while(!f.eof())
    {
        f>>enf;
        return enf;
    }
    f.close();
}
Enfant::~Enfant()
{
    maladies.clear();
    allergies.clear();
}
//Inscription
Enfant inscription::formulaire(vector<Enfant>BD,Niveau n1,Niveau n2,Niveau n3,Niveau n4)
{
    Enfant enf;
    cout<<"\n\n\tBONJOUR ET BIENVENU\n\n"<<endl;
    cout<<"\nsaisir la date d'aujourd'hui"<<endl;
    Date di;
    cin>>di;
    enf.DateInscription=di;
    cout<<"\tPARENT RESPONSABLE"<<endl;
    ParentResponsable pr;
    cin>>pr;
    enf.PR=pr;

    cout<<"\n\tEnfant"<<endl;
    cout<<"\nSaisir le nom"<<endl;
    cin>>enf.nomE;
    cout<<"\nSaisir le prenom"<<endl;
    cin>>enf.prenomE;
    cout<<"\nSaisir la date de naissance"<<endl;
    cin>>enf.DateNaissE;
    cout<<"\nSaisir le sexe"<<endl;
    cin>>enf.sexe;
    cout<<"\nSaisir la nationalite"<<endl;
    cin>>enf.nationalite;
    cout<<"\nSaisir le groupe sanguin"<<endl;
    cin>>enf.GroupeSanguin;
    int choix;
    l:
    cout<<"\nl'enfant est-il vaccine\n1-oui\n2-non"<<endl;
    cin>>choix;
    if(choix==1)
        enf.Vaccine=true;
    else if(choix==2)
        enf.Vaccine=false;
    else
    {
        cout<<"\nReponse invalide"<<endl;
        goto l;
    }
    string mal,al;
    int choixm,choixa,choixniv;
    cout<<"Saisir les maladies de cet enfant s'il y en a"<<endl;
    do
    {
        cin>>mal;
        enf.maladies.push_back(mal);
        cout<<"\n ajouter encore\n1-oui\n2-non"<<endl;
        cin>>choixm;
    }
    while(choixm==1);
        cout<<"Saisir les allergies de cet enfant s'il y en a"<<endl;
    do
    {
        cin>>al;
        enf.allergies.push_back(al);
        cout<<"\n ajouter encore\n1-oui\n2-non"<<endl;
        cin>>choixa;
    }
    while(choixa==1);
    Groupe g;
    int choixNiv;
    cout<<"Selectionner le niveau de votre enfant\n1-Niveau Junior\n2-Creche\n3-Preparatoire\n4-Garderie Scolaire\n";
    cin>>choixNiv;
string n,desGrp;
bool t;

    if(choixNiv==1)
        {n="Niveau Junior";
        cout<<n1<<endl;
        if(n1.tabGrp.size()==0)
        {
            cout<<"\nIl n'y a pas de groupes associes a ce niveau!\nVeuillez ajouter un grouoe svp :)"<<endl;
            n1.AjouterGrp();
            desGrp=n1.tabGrp[0].getDesignation();
            g=n1.tabGrp[0];
        }
        else
            for(int i=0;i<n1.tabGrp.size();i++)
            {
                t=n1.tabGrp[i].AjouterEnfant();
                if(t==true)
                {
                    desGrp=n1.tabGrp[i].getDesignation();
                    g=n1.tabGrp[i];
                    break;}
            }
        }
    if(choixNiv==2)
        {n="Creche";
        cout<<n2<<endl;
                if(n2.tabGrp.size()==0)
        {
            cout<<"\nIl n'y a pas de groupes associes a ce niveau!\nVeuillez ajouter un grouoe svp :)"<<endl;
            n2.AjouterGrp();
            desGrp=n2.tabGrp[0].getDesignation();
            g=n2.tabGrp[0];
        }
        else
                for(int i=0;i<n2.tabGrp.size();i++)
            {
                t=n2.tabGrp[i].AjouterEnfant();
                if(t==true)
                {
                    desGrp=n2.tabGrp[i].getDesignation();
                    g=n2.tabGrp[i];
                    break;}
            }
        }
    if(choixNiv==3)
        {n="Preparatoire";
        cout<<n3<<endl;
                if(n3.tabGrp.size()==0)
        {
            cout<<"\nIl n'y a pas de groupes associes a ce niveau!\nVeuillez ajouter un grouoe svp :)"<<endl;
            n3.AjouterGrp();
            desGrp=n3.tabGrp[0].getDesignation();
            g=n3.tabGrp[0];
        }
        else
                for(int i=0;i<n3.tabGrp.size();i++)
            {
                t=n3.tabGrp[i].AjouterEnfant();
                if(t==true)
                {
                    desGrp=n3.tabGrp[i].getDesignation();
                    g=n3.tabGrp[i];
                    break;}
            }}
    if(choixNiv==4)
        {n="Garderie Scolaire";
        cout<<n4<<endl;
                if(n4.tabGrp.size()==0)
        {
            cout<<"\nIl n'y a pas de groupes associes a ce niveau!\nVeuillez ajouter un grouoe svp :)"<<endl;
            n4.AjouterGrp();
            desGrp=n4.tabGrp[0].getDesignation();
            g=n4.tabGrp[0];
        }
                else
                    for(int i=0;i<n1.tabGrp.size();i++)
            {
                t=n4.tabGrp[i].AjouterEnfant();
                if(t==true)
                {
                    desGrp=n4.tabGrp[i].getDesignation();
                    g=n4.tabGrp[i];
                    break;}
            }}
enf.grp=g;
int numinsc=1;
if(BD.size()==0)
    numinsc=1;
else
    {
       for(int i=0;i<BD.size();i++)
        {
          if(numinsc==BD[i].NumInscription)
          numinsc++;
          else
            break;
        }
    }
    enf.NumInscription=numinsc;
    return enf;

}


void inscription::AjoutBD(Enfant enf,vector<Enfant>BD)
{
    fstream f;
    bool t=true;
   /*Enfant e;
    Enfant::ouvrir(f);
    if(!f.is_open())
        exit(-1);
    f.seekg(0);
    while(!f.eof())
    {
        f>>e;
        BD.push_back(e);
    }*/
    for(int i=0;i<BD.size();i++)
        if(enf==BD[i])
    {cout<<"\nCet enfant existe deja!"<<endl;
    t=false;}
    if(t==true)
    {
        BD.push_back(enf);
        Enfant::ouvrir(f);
        Enfant::enregistrer(f,enf);
        f.close();
    }
}
/*istream& operator>> (istream& in,inscription ins)
{
    in.seekg(0);
    while(1)
    {
        if(in.eof())
            break;
        Enfant e;
        in>>e;
        int num=ins.AffecterNuminsc();
        e.NumInscription=num;
        ins.BD.push_back(e);
    }
    return in;
}
ostream& operator<< (ostream& out, inscription ins)
{
    for(int i=0;i<ins.BD.size();i++)
    {

            out<<ins.BD[i]<<endl;
    }
    return out;
}
void inscription::enregistrer()
{
    fstream f;
    f.open("Enfants.txt",ios::out|ios::trunc);
    if(!f.is_open())
        exit(-1);
    f<<this;
    f.close();
}
int inscription::AffecterNuminsc()
{
    int numinsc=1;
    for(int i=0;i<BD.size();i++)
    {
        if(BD[i].getNumIns()==numinsc)
            numinsc++;
        else
            break;
    }
    return numinsc;
}
void inscription::formulaire()
{
    inscription ins;
    fstream f;
    f.open("Enfants.txt");
    f<<ins;
    f>>ins;
    enregistrer();
    f.close();
}*/
//*********************************************************************************************
//employe
employe::employe():DateNaissEmp(),DateEmboche()
{
    CIN=1234567 ;
    NomEmp ="" ;
    PrenomEmp="" ;
    Salaire=1000;
    AdresseEmp="";
    NbJoursConges=25 ;
    NbCongesPris=0 ;
    Tel=20234567 ;
    mail="";
}

ostream& operator<< ( ostream &out, employe& e)
{
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"\n\tEMPLOYE"<<endl;
    out<<"\n cin : "<<e.CIN<<endl;
    out<<"\n nom : "<<e.NomEmp<<endl;
    out<<"\n prenom : "<<e.PrenomEmp<<endl;
    out<<"\n date de naissance : "; cout<< e.DateNaissEmp <<endl;
   out<<"\n date d'emboche  : " ; cout<<  e.DateEmboche <<endl;
    out<<"\n Salaire : "<<e.Salaire<<" DT"<<endl;
    out<<"\n adresser: "<<e.AdresseEmp<<endl;
    out<<"\n nombre de conges autorise :  "<<e.NbJoursConges<<endl;
    out<<"\n Telephone :  "<<e.Tel<<endl;
    out<<"\n Mail   : "<<e.mail<<endl;
    return out ;
}


istream& operator>>(  istream& in , employe& e)
 {
    cout<<"\n\tEMPLOYE"<<endl;
    cout<<"\n cin : ";
     in>>e.CIN;
     cout<<"\n nom employe : ";
    in>>e.NomEmp;
    cout<<"\n prenom employe : " ;
    in>>e.PrenomEmp;
    cout<<"\ndate de naissance : " ;
      cin>> e.DateNaissEmp;
    cout<<"\n date d'emboche : ";
      cin>> e.DateEmboche;
    cout<<"\n salaire : ";
     in>>e.Salaire;
     cout<<"\n adresse employe : ";
    in>>e.AdresseEmp;
    e.NbJoursConges=25;
    cout<<"\n numero de telephone : " ;
    in >>e.Tel;
    cout<<"\n mail : ";
    in>>e.mail;
    return in ;
 }



int employe::nbcongepris()
{
    cout<<"\n le nombre de conges pris:   "<<NbCongesPris;
    return NbCongesPris;
}

void employe::AjouterConges()
{
    x:
    cout<<"\nSaisir le nombre de jours que vous voulez prendre"<<endl;
    int n;
    cin>>n;
    if(n<0)
    {
        cout<<"Reponse Invalide\nveuillez reessayer"<<endl;
        goto x;
    }
    if  (  NbCongesPris<NbJoursConges)
    {
        if (  (NbCongesPris+n)  <=  NbJoursConges)
           {
                      cout<<" \n\n\nVous avez "<<n<<"  jours de congés pour cet employe"<<endl;
                      NbCongesPris +=n;
           }

         else
           {
             cout<<"\n\n\n Cet employe ne peut pas avoir   "<<n << "\t jours de conges ! "<<endl;
                 while  ((NbCongesPris+n)  >  NbJoursConges)
                   {
                      n--;
                    }
                cout<<"\n\n\tMais il peut  prendre"<<n<<"\t jours"<<endl;
             }
         }
    else
        cout<<"\n\n\n\tDESOLE ,  Cet employe a depasser le nombre maximal de conges  ! "<<endl;
    }
int employe::NbCongesRestant()
{
    int nb_R;
    nb_R=NbJoursConges-NbCongesPris;
    cout<<"\n Nombre de jours restants  : \t"<<nb_R;
    return nb_R;
}

void employe::ModifierDonnee()
{
    int n, nbr;
    double s;
    string adr, m;
    long T;

    cout<<"\n\n\tModification des  donnees : "<<endl;
    cout<<"\n\tQuelle donnée voulez vous changer ?"<<endl;
    repeat:
    cout<<" \n\t1- Salaire "<<endl;
    cout<<" \n\t2- Adresse employe"<<endl;
    cout<<" \n\t3- Nombre de jours maximal de conge "<<endl;
    cout<<" \n\t4- Telephone "<<endl;
    cout<<"\n\t5- mail  "<<endl;
    cin>>n;
    if(( n>=6 )|| ( n<=0 ))
    {
        goto repeat ;
    }
    switch (n)
    {
        case  1 : {cout<<"\n Le nouveau salaire est:";cin>>s;Salaire=s;} break;
        case 2 : {cout<<"\n La nouvelle adresse est:";cin >>adr ;AdresseEmp=adr;}break;
         case 3 : {cout<<"\n Nombre de jours maximal de conges autorises:";cin>>nbr;NbJoursConges=nbr;}break;
         case 4 : {cout<<"\n Le nouveau numero de telephone est:";cin>>T;Tel=T;}break;
        case 5 : {cout<<"\n La nouvelle adresse mail est:";cin >> m;mail=m;}break ;
    }
}

//instituteur
 instituteur::instituteur():employe()
  {
    for( int i=0; i<6;i++)
    {
        for( int j=0 ; j<9 ; j++)
        {
             emploi[i][j]="None ";
         }
    }
  }

ostream& operator << (ostream& out ,  instituteur& ins)
{
    employe *e=&ins;
    out<<*e;
    for(int i=0; i<6;i++)
      {
        for(int j=0; j<9 ;j++)
          out<<ins.emploi[i][j] <<"\t";
         cout<<"\n";
      }
  return out;
}

/*istream & operator >>(istream& in ,  instituteur& ins)
{
    cout<<"\n\tINSTITUTEUR"<<endl;
    employe *e=&ins;
    in>>*e;
    for(int i=0; i<7;i++)
    {
        for(int j=0; j<9 ; j++)
    {ins.emploi[i][j]="None";}
    }
   return in;
}*/

void  instituteur::remplirEmploi()
{

 cout<<"\n EMPLOI DE TEMPS"<<endl;
    for(int i=0;i<6;i++)
    {
        if(i==0)
            cout<<"\n Lundi"<<endl;
        if(i==1)
            cout<<"\n Mardi"<<endl;
        if(i==2)
            cout<<"\n Mercredi"<<endl;
        if(i==3)
            cout<<"\n Jeudi"<<endl;
        if(i==4)
            cout<<"\n Vendredi"<<endl;
        if(i==5)
            cout<<"\n Samedi"<<endl;
        for(int j=0;j<9;j++)
        {
            if(j==0)
                cout<<"\n 8h--9h"<<endl;
            if(j==1)
                cout<<"\n 9h--10h"<<endl;
            if(j==2)
                cout<<"\n 10h--11h"<<endl;
            if(j==3)
                cout<<"\n 11h--12h"<<endl;
            if(j==4)
                cout<<"\n 12h--13h"<<endl;
            if(j==5)
                cout<<"\n 13h--14h"<<endl;
            if(j==6)
                cout<<"\n 14h--15h"<<endl;
            if(j==7)
                cout<<"\n 15h--16h"<<endl;
            if(j==8)
                cout<<"\n 16h--17h"<<endl;
            string ch;
            cout<<"Saisir une activité"<<endl;
            cin>>ch;
            emploi[i][j]=ch;
    }
}
cout<<"Votre Emploi\n"<<endl;

for(int i=0;i<6;i++)
{
        if(i==0)
            cout<<"\n Lundi \t";
        if(i==1)
            cout<<"\n Mardi \t";
        if(i==2)
            cout<<"\n Mercredi \t";
        if(i==3)
            cout<<"\n Jeudi \t";
        if(i==4)
            cout<<"\n Vendredi \t";
        if(i==5)
            cout<<"\n Samedi \t";
    for(int j=0;j<9;j++)
        cout<<emploi[i][j]<<'\t';
    cout<<'\n';
}
}

void instituteur::afficherEmploi()
{
    cout<<"Votre Emploi\n"<<endl;

for(int i=0;i<6;i++)
{
        if(i==0)
            cout<<"\n Lundi \t";
        if(i==1)
            cout<<"\n Mardi \t";
        if(i==2)
            cout<<"\n Mercredi \t";
        if(i==3)
            cout<<"\n Jeudi \t";
        if(i==4)
            cout<<"\n Vendredi \t";
        if(i==5)
            cout<<"\n Samedi \t";
    for(int j=0;j<9;j++)
        cout<<emploi[i][j]<<'\t';
    cout<<'\n';
}
}
void instituteur::modifierEmploi()
{
    string jour;
    int temps;
    j:
    cout<<"preciser le jour de l'activite a changer"<<endl;
    cin>>jour;
    int i,j;
      if(jour=="lundi")
    i=0;
   else if(jour=="mardi")
    i=1;
   else if(jour=="mercredi")
    i=2;
   else if(jour=="jeudi")
    i=3;
   else if(jour=="vendredi")
    i=4;
   else if(jour=="samedi")
    i=5;
    else
    {
    cout<<"\nchoix invalide\nreesayer\n";
    goto j;
    }
    t:
cout<<"preciser le temps de debut de l'activite a changer"<<endl;
cin>>temps;
   if(temps==8)
    j=0;
   else if(temps==9)
    j=1;
   else if(temps==10)
    j=2;
   else if(temps==11)
    j=3;
   else if(temps==12)
    j=4;
   else if(temps==13)
    j=5;
   else if(temps==14)
    j=6;
   else if(temps==15)
    j=7;
   else if(temps==16)
    j=8;
else
{
    cout<<"\nchoix invalide\nreesayer\n";
    goto t;
}


string ch;
cout<<"Saisir la nouvelle activite"<<endl;
cin>>ch;
emploi[i][j]=ch;
}
//administrateur
administrateur::administrateur():employe()
{
    login="Admin";
    mdp="ProjetC++";
}
ostream& operator<<(ostream& out , administrateur& admin)
{
    employe *e=&admin;
    out<<*e;
    out<<"\nLogin: "<<admin.login<<"\nMot de passe: "<<admin.mdp<<endl;
    return out;
}
//Nourrice
Nourrice::Nourrice():employe()
{

}
//Ouvrier
Ouvrier::Ouvrier():employe()
{

}
//Psychologue
Psychologue::Psychologue():employe()
{

}
//calendrier
void calendrier::creer_calen(void)

{
 int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 cout <<"\n\n";

 cout <<"\t\tCALENDRIER D'ACTIVITE ";

 cout <<"\n\n";

 cout<<"\n\t\t\tCalendrier d'annee   \n\n\n";
repeat:
 cout<<"\tENTRER ANNEE  [2000...] : ";
 cin>>yy;
 if(yy<=1999)
 {

    cout<<"\n\nChoix invalide.Reessayez !  .";
    goto repeat;
 }
 if(yy%4==0)
 {
    if(yy%100==0)
    {
     if(yy%400==0)
     month[1]=29;
     else
     month[1]=28;
    }
    else
    month[1]=29;
 }
 again:
 cout<<"\tChoisir Mois   [1-12] : ";
 cin>>mon;
 if(mon>12||mon<1)
 {
    cout<<"\tChoix invalide .Reessayez !!  . ";
    goto again;

 }
 cout<<"\n\n\t\t\t\tANNEE "<<yy<<"\n\n";
 switch(mon)
 {
    case 1:cout<<"\n\n\t\t\t\tJANVIER\n\n";break;

    case 2:cout<<"\n\n\t\t\t\tFEVRIER\n\n";break;

    case 3:cout<<"\n\n\t\t\t\tMARS\n\n";break;

    case 4:cout<<"\n\n\t\t\t\tAVRIL\n\n";break;

    case 5:cout<<"\n\n\t\t\t\tMAI\n\n";break;

    case 6:cout<<"\n\n\t\t\t\tJUIN\n\n";break;

    case 7:cout<<"\n\n\t\t\t\tJUILLER\n\n";break;

    case 8:cout<<"\n\n\t\t\t\tAOUT\n\n";break;

    case 9:cout<<"\n\n\t\t\t\tSEPTEMBRE\n\n";break;

    case 10:cout<<"\n\n\t\t\t\tOCTOBRE\n\n";break;

    case 11:cout<<"\n\n\t\t\t\tNOVEMBRE\n\n";break;

    case 12:cout<<"\n\n\t\t\t\tDECEMBRE\n\n";break;

    default:cout<<"\n\nCHOIX INVALIDE ! ";exit(0);
 }
 p=5;
 for(r=1999;r<yy;r++)
 {
    if(r%4==0)
    {
     if(r%100==0)
     {
        if(r%400==0)
        p=p+2;
        else
        p++;
     }
     else
     p=p+2;
    }
    else
    p++;
    if(p==7)
    p=0;
    if(p==8)
    p=1;
 }
 for(mm=0;mm<12;mm++)
 {
    days=month[mm];
    k=0;
    for(z=0;z<7;z++)
    calen[0][z]=0;
    for(i=0;i<5;i++,p=0)
    for(j=p;j<7&&k<days;j++)
    {
     calen[i][j]=k+1;
     k++;
     if(k==days&&i==4&&j<7)
     {
        for(p=j+1;p<7;p++)
        calen[i][p]=0;
     }
     if(k<days&&i==4&&j==6)
     {
        for(p=0;p<7&&k<days;p++,k++)
        calen[0][p]=k+1;
        j=p-1;
     }
     if(k==days&&i==4&&j==6)
     {
        j=-1;
     }
     if(k==days&&i==3&&j==6)
     {
        for(p=0;p<7;p++)
        calen[4][p]=0;
     }
    }
    p=j;
    if(mm+1==mon)
    return;
 }
}

void calendrier::marquer_date()
{
    calendrier c;
    int a;
    string ch , rep ;

     c.creer_calen();
     c.afficher_calen();

     again :

         cout<<"\n\n\t\tAjoutez une activitee et la date  : \n\n";
              cout<<"\t\t";   cin>>ch;
              cout<<"\t\t";   cin>>s ;
         cout<<"\n\n\t\tAjouter une autre activitee ? O/N ."<<endl;
         cin>>rep;
         { if ( rep =="O")
         goto again ;
          }

}

void calendrier::afficher_calen()
{
    cout<<"\n\t Di\tlu\tMa\tMer\tJe\tVe\tSa\n\n";

    for(i=0 ;i<5; i++)
    {
        for(j=0; j<7;j++)
            cout<<"\t"<<calen[i][j];
          cout<<"\n\n";
    }
}
//class salle
salle::salle()
{numSalle=0; designation="";}
void salle::changerdesignation()
{
string nvd;
cout<<"saisir la nouvelle designation de la salle :"<<endl;
cin>>nvd;cout<<endl;
this->designation=nvd;
}

ostream& operator<<(ostream& out, salle&s)
{
    cout<<"\n\tSALLE\n"<<endl;
    out<<"\nNumero "<<s.numSalle<<endl;
    out<<"\nDesignation: "<<s.designation<<endl;
    return out ;
}

istream& operator>>(istream& in ,salle&s)
{
    cout<<"\n\tSALLE"<<endl;
    cout<<"saisir le numero de la salle: "<<endl;
    in>>s.numSalle;
    cout<<"saisir la designation de la salle: "<<endl;
    in>>s.designation;
    return in;
}
salle& salle::operator= (const salle& s)
{
    if(this!=&s)
    {
    numSalle=s.numSalle; designation=s.designation;}
    return *this;
}
//class activite
activite::activite():dateAct(),salleAct()
{nomAct=" "; nbparticipants=0;nbmaxiparticipants=100;}

void activite::ajouterparticipantAct()
{   int n;
    cout<<"saisir le nombre des participants a ajouter:";cin>>n;
    if(nbparticipants+n>nbmaxiparticipants)
    {
        cout<<"\nL'activite "<<nomAct<<" a atteint le nombre maximal des participants"<<endl;
    }
    else
        this->nbparticipants+=n;
    cout<<"le nombre total des participants:";
    cout<<nbparticipants;

}
void activite::supprimerparticipantAct()
{    int n;

    cout<<"saisir le nombre des participants a supprimer:"<<endl;
    cin>>n;
    if(this->nbparticipants-n<0)
        {this->nbparticipants=0;
        goto quit;}
    else
        this->nbparticipants-=n;
    quit:
    cout<<"le nombre total des participants:";
    cout<<endl;
    cout<<nbparticipants;
}
void activite::changerdate()
{
    Date nouvelledate;
    cout<<"saisir la nouvelle date: ";
    cin>>nouvelledate;
    this->dateAct=nouvelledate;
}

ostream& operator<<(ostream& out, activite&act)
{   cout<<"----------------------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
       cout<<"\n\tACTIVITE\n\n";
    out<<"                    *le nom de l'activite: "<<act.nomAct;cout<<endl;
    out<<"                    *la date de l'activite: "<<act.dateAct;cout<<endl;
    out<<"                    *la salle: "<<endl<<act.salleAct ;cout<<endl;
    out<<"                    *le nombre des participants: "<<act.nbparticipants;cout<<endl;
    out<<"                    *le nombre des participants maximal: "<<act.nbmaxiparticipants;cout<<endl;

    return out ;
}

istream& operator>>(istream& in ,activite&act)
{

   cout<<"\n\tACTIVITE\n\n";
    cout<<"saisir le nom de l'activite:"<<endl;
    in>>act.nomAct;
    cout<<"saisir la date de l'activite:"<<endl;
    in>>act.dateAct;
    cout<<"salle :"<<endl;
    in>>act.salleAct ;
    cout<<"saisir le nombre maximal des participants:"<<endl;
    in>>act.nbmaxiparticipants;
    while(1)
    {cout<<"saisir le nombre des participants:"<<endl;
    in>>act.nbparticipants;
    if(act.nbparticipants<=act.nbmaxiparticipants)
        break;
    }


    return in;
}
void activite::changersalleAct()
{   salle nouveausalle;
    cout<<"\n\tNOUVELLE SALLE:"<<endl;
    cin>>nouveausalle;cout<<endl;
    this->salleAct=nouveausalle;
}
//class evenement
evenement::evenement():salleEvent()
{
    nomEvent=" ";budget=100;nbparticipants=0;depenses=0;nbmaxiparticipants=100;
}

void evenement::ajouterparticipant()
{
    int n;
    cout<<"saisir le nombre des participants a ajouter: ";
    cin>>n;
    if(nbparticipants+n>nbmaxiparticipants)
        cout<<"\nL'evenement "<<nomEvent<<" a atteint le nombre maximal des participants"<<endl;
    else
        this->nbparticipants+=n;
    cout<<"\nle nombre total des participants: ";
    cout<<nbparticipants<<endl;
}

void evenement::supprimerparticipant()
{
     int n;

    cout<<"saisir le nombre des participants a supprimer:"<<endl;
    cin>>n;
    if(this->nbparticipants<n)
        this->nbparticipants=0;
    else
     this->nbparticipants-=n;
    cout<<"\nle nombre total des participants: ";
    cout<<nbparticipants<<endl;
}
double evenement::budgetrestant()
{
    double res;
    res=(this->budget)- (this->depenses);
    cout<<" le budget restant de cette evenement: "<<res<<endl;
    return res;
}

ostream& operator<<(ostream& out, evenement&event)
{   cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n\tEVENEMENT\n\n"<<endl;
    out<<"Nom: "<<event.nomEvent<<endl;
    out<<event.salleEvent<<endl;
    out<<"\nBudget: "<<event.budget<<endl;
    out<<"\nDepenses: "<<event.depenses<<endl;
    out<<"\nNombre des participants:"<<event.nbparticipants<<endl;
    out<<"\nNombre maximal des participants:"<<event.nbmaxiparticipants<<endl;
    return out;
}

istream& operator>>(istream& in ,evenement&event)
{
    cout<<"\n\tEVENEMENT\n\n";
    cout<<"saisir le nom de l'evenement: "<<endl;
    in>>event.nomEvent;
    in>>event.salleEvent;
    cout<<"saisir le budget: "<<endl;
    in>>event.budget;
    while(1)
    {
        cout<<"saisir les depenses de l'evenement:"<<endl;
        in>>event.depenses;
        if(event.depenses<event.budget)
            break;
        else
            cout<<"\nVeuillez respecter le budget de cet evenement svp"<<endl;
    }
    cout<<"saisir le nombre maximal des participants:"<<endl;
    in>>event.nbmaxiparticipants;
    while(1)
    {
        cout<<"saisir le nombre des participants:"<<endl;
        in>>event.nbparticipants;
        if(event.nbparticipants<event.nbmaxiparticipants)
            break;
    }
    return in;
}
void evenement::changersalle()
{ salle nouveausalle;
    cout<<"\n\tNOUVELLE SALLE\n\n";
    cin>>nouveausalle;
    this->salleEvent=nouveausalle;
}
// class etude
etude::etude():instituteurEtude(),salleEtude()
{
 nomEtude=" ";
 nbenfants=0;
 nbmaxenfants=30;
}
void etude::remplacerinstituteur()
{
    instituteur nouveauins;
         cin>>nouveauins;
        this->instituteurEtude=nouveauins;
}
int etude::ajouterenfant()
{
    int n;
    cout<<"saisir le nombre des enfants a ajouter:";cin>>n;
    if(nbenfants+n>nbmaxenfants)
        cout<<"\nVous avez atteint le nombre maximal des enfants dans cette seance\n";
    else
        this->nbenfants+=n;
    cout<<"\nle nombre total des enfants: ";
    cout<<nbenfants;
}
int etude::supprimerenfant()
{
     int n;
    cout<<"saisir le nombre des enfants a supprimer:"<<endl;
    cin>>n;
    if(this->nbenfants<n)
        this->nbenfants=0;
    else
        this->nbenfants-=n;
    cout<<"\nle nombre total des enfants: ";
    cout<<nbenfants;
}
ostream& operator<<(ostream& out, etude&e)
{
    instituteur ins;
    out<<e.instituteurEtude<<endl;
    out<<e.salleEtude <<endl;
    out<<"le nombre des enfants:"<<e.nbenfants<<endl;
    out<<"le nombre maximal des enfants:"<<e.nbenfants<<endl;
    return out ;
}
istream& operator>>(istream& in ,etude&e)
{
    in>>e.instituteurEtude ;
    in>>e.salleEtude ;
    cout<<"saisir le nombre maximal des enfants:"<<endl;
    in>>e.nbmaxenfants;
     while(1)
    {
        cout<<"saisir le nombre des enfants:"<<endl;
        in>>e.nbenfants;
        if(e.nbenfants<e.nbmaxenfants)
            break;
    }
    return in;
}
void etude::changersalleEtude()
{   salle nouveausalle;
    cin>>nouveausalle;
    this->salleEtude=nouveausalle;
}
//class menurepas
menurepas::menurepas()
{
    for (int i=0;i<6;i++)
        menu[i]="none";
}

void menurepas::changerrepas()
{   string Jour; string nvrepas; int i;
    repeat:
    cout<<endl<<"\nvous voulez changer le repas de quel jour[Lundi..Samedi] ?";
    cin>>Jour;
    if ( Jour== "Lundi")
        {i=0 ;}
     else if ( Jour ==  "Mardi")
     i=1;
     else if ( Jour == "Mercredi")
      i=2;
     else if ( Jour == "Jeudi")
          i=3;
     else if ( Jour == "Vendredi")
     i=4;
     else if ( Jour == "Samedi")
     i=5;
     else {cout<<"choix invalide ! \t "; goto repeat;}



    cout<<endl<<"saisir le nouveau repas:";
    cin>>nvrepas;
    this->menu[i]=nvrepas;

}

ostream& operator<<(ostream& out, menurepas&m)
{
    cout<<"\n\tMENU DU RESTAU\n\n";
    for(int i=0;i<6;i++)
        out<<m.menu[i]<<"\t";
    return out ;
}

istream& operator>>(istream& in ,menurepas&m)
{   int i;
    cout<<"\n\tMENU DU RESTAU\n\n";
    cout<<"Les repas de la semaine:"<<endl;
    for(int i=0;i<6;i++)
    {
        in>>m.menu[i];

    }
    return in;
}










