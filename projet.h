#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Date
{
    int jour;
    int mois;
    int annee;
public:
    Date(int,int,int);
    Date();
    friend ostream& operator<<(ostream&, Date&);
    friend istream& operator>>(istream&, Date&);
    bool operator== (const Date&);
    Date& operator= (const Date&);
};
class Facture
{
    int NumFacture;
    double montantFacture;
    Date DateLimite;
    bool PayeeOuNon;
public:
    Facture(int,double,Date,bool);
    Facture();
    void Payer();
    friend ostream& operator<<(ostream&, Facture&);
    friend istream& operator>>(istream&, Facture&);
};
class ParentResponsable
{
    long CIN;
    string nom;
    string prenom;
    Date dateNaiss;
    long tel;
    string Email;
    string Adresse;
    string Fonction;
public:
    ParentResponsable(long,string,string,Date,long,string,string,string);
    ParentResponsable();
    friend ostream& operator<<(ostream&, ParentResponsable&);
    friend istream& operator>>(istream&, ParentResponsable&);
    ParentResponsable& operator= (const ParentResponsable&);
    void ModifierDonnees();
    void Afficher();

};
class Groupe
{
    string designationgrp;
    string niveau;
    int nbEnf;
    string emploi[7][9];
public:
    Groupe();
    Groupe(string,string);
    friend ostream& operator<<(ostream&, Groupe&);
    friend istream& operator>>(istream&, Groupe&);
    Groupe& operator= (const Groupe&);
    void modifierEmploi();
    void SetEmploi();
    bool operator== (const Groupe&);
    string getDesignation();
    void setDesignation();
    string getniveau();
    bool AjouterEnfant();
    void afficherEmploi();

};
class Niveau
{
    string designationNiv;
public:
    vector<Groupe>tabGrp;
public:
    Niveau();
    Niveau(string);
    friend ostream& operator<<(ostream&, Niveau&);
    friend istream& operator>>(istream&, Niveau&);
    Niveau(const Niveau&);
    void SaisirTab();
    void AjouterGrp(Groupe);
    void AjouterGrp();
    void SupprimerGrp(Groupe);
    void SupprimerGrp();
    string getDes();
    ~Niveau();
};
class Enfant
{
public:

    int NumInscription;
    Date DateInscription;
    string nomE;
    string prenomE;
    Date DateNaissE;
    ParentResponsable PR;
    string sexe;
    string nationalite;
    string GroupeSanguin;
    bool Vaccine;
    vector<string>maladies;
    vector<string>allergies;
    Groupe grp;


public:
    Enfant(Date,string,string,Date,ParentResponsable,string,string,string,bool,Groupe);
    Enfant();
    Enfant(const Enfant&);
    friend ostream& operator<<(ostream&, Enfant&);
    friend istream& operator>>(istream&, Enfant&);
    bool operator== (const Enfant&);
    void AjouterMaladie();
    void SupprimerMaladie();
    void AjouterAllergie();
    void SupprimerAllergie();
    void Vacciner();
    static void ouvrir(fstream&);
    static void enregistrer(fstream&,Enfant&);
    static void afficher(fstream&);
    static Enfant getEnfant(fstream&);
    ~Enfant();
};
class inscription
{
public:

    vector<Enfant>BD;
public:
    Enfant formulaire(vector<Enfant>,Niveau,Niveau,Niveau,Niveau);
    void AjoutBD(Enfant,vector<Enfant>);

    /*ostream& operator<< (ostream&, inscription);
    void enregistrer();
    void formulaire();*/
};
//*************************************************************************************************************************************************
class employe
{
protected:
    long CIN ;
    string  NomEmp;
    string PrenomEmp;
    Date  DateNaissEmp;
    Date DateEmboche ;
    double  Salaire;
    string AdresseEmp;
    int NbJoursConges;
    int NbCongesPris;
    long Tel;
    string mail;
public :
     employe();
     virtual~employe(){ }
     void AjouterConges();
     int nbcongepris();
     int  NbCongesRestant();
     virtual void ModifierDonnee(void);

     friend std::ostream& operator<< (std::ostream&,  employe&);
     friend  std::istream& operator >> (std::istream&,   employe&);
};
 class instituteur : public employe
 {
 protected:
     string emploi[6][9];
public :
     instituteur();
     ~instituteur(void){ }
    void remplirEmploi(void);
    void afficherEmploi(void);
    void modifierEmploi();
     friend ostream& operator<<(ostream&,instituteur&);
     // friend  istream& operator >>(istream&,instituteur&);=>cet opérateur n'est pas necessaire car on peut appeler l'operateur de l'employé et l'emploi est initialisé par defaut
 };
class administrateur : public employe
{
protected:
    string  login;
    string  mdp;
public:
    administrateur();
    ~administrateur(){ };
    friend ostream& operator<< (ostream&, administrateur&);
};
class Nourrice : public employe
{
public:
    Nourrice();
    ~Nourrice(){};
};
class Ouvrier : public employe
{
public:
    Ouvrier();
    ~Ouvrier(){};
};
class Psychologue : public employe
{
public:
    Psychologue();
    ~Psychologue(){};
};
class  calendrier
{
    int i,j,days, mm,mon,k,z,p,yy,r ,s;
    int calen[5][7];
public:
    void creer_calen(void);
    void afficher_calen(void);
    void marquer_date(void);
};
class salle
{
private:
    int numSalle;
    string designation;
public:
     salle();
     ~salle(){};
     void changerdesignation();
     friend ostream& operator<<(ostream&,salle&);
     friend istream& operator>>(istream&,salle&);
     salle& operator= (const salle&);
};
class activite
{
private:
    string nomAct;
    Date dateAct;
    salle salleAct;
    int nbparticipants;
    int nbmaxiparticipants;
public:
    activite();
    ~activite(){}
    void changerdate();
    void ajouterparticipantAct();
    void supprimerparticipantAct();
    void changersalleAct();
    friend ostream& operator<<(ostream&,activite&);
    friend istream& operator>>(istream&,activite&);
};
class evenement
{
private:
    string nomEvent;
    salle salleEvent;
    double budget;
    int nbparticipants;
    int nbmaxiparticipants;
    double depenses;
public:
    evenement();
    ~evenement(){};
    void ajouterparticipant();
    void supprimerparticipant();
    void changersalle();
    double budgetrestant();
    friend ostream& operator<<(ostream&,evenement&);
    friend istream& operator>>(istream&,evenement&);
};
class etude
{
private:
    string nomEtude;
    instituteur instituteurEtude;
    salle salleEtude;
    int nbenfants;
    int nbmaxenfants;
public:
    etude();
    ~etude(){}
    void changersalleEtude();
    void remplacerinstituteur();
    int ajouterenfant();
    int supprimerenfant();
    friend ostream& operator<<(ostream&,etude&);
    friend istream& operator>>(istream&,etude&);
};
class menurepas
{
private:
   string menu[6];
public:
    menurepas();
    ~menurepas(){}
    void changerrepas();
    friend ostream& operator<<(ostream&,menurepas&);
    friend istream& operator>>(istream&,menurepas&);
};











#endif // PROJET_H_INCLUDED
