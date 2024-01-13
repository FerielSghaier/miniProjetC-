#include "fonctions.h"
#include <iostream>
#include<string>
#include "projet.h"
void Quitter()
{
    cout<<"\n\n\tMERCI POUR VOTRE PARTICIPATION!\n\n";
}
void MenuIns()
{
    instituteur ins;
int choix;
repeat:
cout<<"\n\n\t\t1.Creer instituteur\n\t\t2.Modifier donnees\n\t\t3.Prendre un conge\n\t\t4.nombre de conges pris\n\t\t5.nombre de conges restants\n\t\t6.Remplir l'emploi de temps\n\t\t7.Modifier l'emploi\n\t\t8.Afficher l'emploi\n\t\t9.afficher les donnees\n\t\t10.retour au menu principal\n\t\t11.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>ins; goto repeat;}
        break;
        case 2:{ins.ModifierDonnee(); goto repeat;}
        break;
        case 3:{ins.AjouterConges(); goto repeat;}
        break;
        case 4:{ins.nbcongepris(); goto repeat;}
        break;
        case 5:{ins.NbCongesRestant(); goto repeat;}
        break;
        case 6:{ins.remplirEmploi(); goto repeat;}
        break;
        case 7:{ins.modifierEmploi(); goto repeat;}
        break;
        case 8:{ins.afficherEmploi(); goto repeat;}
        break;
        case 9:{cout<<ins; goto repeat;}
        break;
        case 10:Menu();
        break;
        case 11:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuEmployes()
{
     employe n,psy,ouv;
     administrateur admin;
     instituteur ins;
int choix;
repeat:
cout<<"\n\n\t\t1.Administrateur\n\t\t2.Instituteur\n\t\t3.Nourrice\n\t\t4.Ouvrier\n\t\t5.Psychologue\n\t\t6.retour au menu principal\n\t\t7.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cout<<"entrer vos données"<<endl;cin>>admin;cout<<admin; goto repeat;}
        break;
        case 2:{MenuIns(); goto repeat;}
        break;
        case 3:{cout<<"creer nourrice\n";cin>>n;cout<<n; goto repeat;}
        break;
        case 4:{cout<<"creer ouvrier\n";cin>>n;cout<<n; goto repeat;}
        break;
        case 5:{cout<<"creer psychologue\n";cin>>n;cout<<n; goto repeat;}
        break;
        case 6:Menu();
        break;
        case 7:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuRestau()
{
     menurepas m;
int choix;
repeat:
cout<<"\n\n\t\t1.Creer table des repas\n\t\t2.Changer un repas\n\t\t3.afficher table des repas\n\t\t4.retour au menu principal\n\t\t5.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>m; goto repeat;}
        break;
        case 2:{m.changerrepas(); goto repeat;}
        break;
        case 3:{cout<<m; goto repeat;}
        break;
        case 4:Menu();
        break;
        case 5:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuEvent()
{
     evenement e;
int choix;
repeat:
cout<<"\n\n\t\t1.Creer evenement\n\t\t2.Ajouter participants\n\t\t3.Supprimer participants\n\t\t4.changer salle\n\t\t5.budget restant\n\t\t6.afficher donnees\n\t\t7.retour au menu principal\n\t\t8.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>e; goto repeat;}
        break;
        case 2:{e.ajouterparticipant(); goto repeat;}
        break;
        case 3:{e.supprimerparticipant(); goto repeat;}
        break;
        case 4:{e.changersalle(); goto repeat;}
        break;
        case 5:{e.budgetrestant(); goto repeat;}
        break;
        case 6:{cout<<e; goto repeat;}
        break;
        case 7:Menu();
        break;
        case 8:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuActivite()
{
     activite a;
int choix;
repeat:
cout<<"\n\n\t\t1.Creer activite\n\t\t2.Ajouter participant\n\t\t3.Supprimer participant\n\t\t4.changer date\n\t\t5.changer salle\n\t\t6.afficher donnees\n\t\t7.retour au menu principal\n\t\t8.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>a; goto repeat;}
        break;
        case 2:{a.ajouterparticipantAct(); goto repeat;}
        break;
        case 3:{a.supprimerparticipantAct(); goto repeat;}
        break;
        case 4:{a.changerdate(); goto repeat;}
        break;
        case 5:{a.changersalleAct(); goto repeat;}
        break;
        case 6:{cout<<a; goto repeat;}
        break;
        case 7:Menu();
        break;
        case 8:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuEtude()
{
    etude e;
int choix;
repeat:
cout<<"\n\n\t\t1.Creer Etude\n\t\t2.Ajouter enfant\n\t\t3.Supprimer enfant\n\t\t4.changer salle\n\t\t5.remplacer instituteur\n\t\t6.afficher donnees\n\t\t7.retour au menu principal\n\t\t8.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>e; goto repeat;}
        break;
        case 2:{e.ajouterenfant(); goto repeat;}
        break;
        case 3:{e.supprimerenfant(); goto repeat;}
        break;
        case 4:{e.changersalleEtude(); goto repeat;}
        break;
        case 5:{e.remplacerinstituteur(); goto repeat;}
        break;
        case 6:{cout<<e; goto repeat;}
        break;
        case 7:Menu();
        break;
        case 8:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuCalendrier()
{
    calendrier c;
int choix;
repeat:
cout<<"\n\n\t\t1.Creer calendrier annuelle\n\t\t2.Afficher\n\t\t3.marquer une date\n\t\t4.retour au menu principal\n\t\t5.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{c.creer_calen(); goto repeat;}
        break;
        case 2:{c.afficher_calen(); goto repeat;}
        break;
        case 3:{c.marquer_date(); goto repeat;}
        break;
        case 4:Menu();
        break;
        case 5:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuSalle()
{
    salle s;
int choix;
repeat:
cout<<"\n\n\t\t1.Creer salle\n\t\t2.changer designation\n\t\t3.Afficher Donnees\n\t\t4.Menu principal\n\t\t5.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>s; goto repeat;}
        break;
        case 2:{s.changerdesignation(); goto repeat;}
        break;
        case 3:{cout<<s; goto repeat;}
        break;
        case 4:Menu();
        break;
        case 5:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuGrp()
{
    Groupe g;

int choix;
repeat:
cout<<"\n\n\t\t1.Creer groupe\n\t\t2.Creer emploi\n\t\t3.modifier emploi\n\t\t4.Afficher emploi\n\t\t5.Modifier designation\n\t\t6.Ajouter enfant\n\t\t7.Afficher donnees\n\t\t8.Menu principal\n\t\t9.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>g; goto repeat;}
        break;
        case 2:{g.SetEmploi(); goto repeat;}
        break;
        case 3:{g.modifierEmploi(); goto repeat;}
        break;
        case 4:{g.afficherEmploi(); goto repeat;}
        break;
        case 5:{g.setDesignation(); goto repeat;}
        break;
        case 6:{g.AjouterEnfant(); goto repeat;}
        break;
        case 7:{cout<<g; goto repeat;}
        break;
        case 8:Menu();
        break;
        case 9:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuNiveaux()
{
    Niveau niv;

int choix;
repeat:
cout<<"\n\n\t\t1.Creer niveau\n\t\t2.Saisir tableau des groupes\n\t\t3.Ajouter un groupe\n\t\t4.Supprimer un groupe\n\t\t5.Menu Principal\n\t\t6.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>niv; goto repeat;}
        break;
        case 2:{niv.SaisirTab(); goto repeat;}
        break;
        case 3:{niv.AjouterGrp(); goto repeat;}
        break;
        case 4:{niv.SupprimerGrp(); goto repeat;}
        break;
        case 5:Menu();
        break;
        case 6:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuFacture()
{
        Facture fac;

int choix;
repeat:
cout<<"\n\n\t\t1.Creer facture\n\t\t2.Payer Facture\n\t\t3.Afficher facture\n\t\t4.Menu Principal\n\t\t5.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>fac; goto repeat;}
        break;
        case 2:{fac.Payer(); goto repeat;}
        break;
        case 3:{cout<<fac; goto repeat;}
        break;
        case 4:Menu();
        break;
        case 5:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuParentsResponsables()
{
    ParentResponsable pr;

int choix;
repeat:
cout<<"\n\n\t\t1.Creer Parent responsable\n\t\t2.Modifier Donnees\n\t\t3.Afficher donnees\n\t\t4.Menu Principal\n\t\t5.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>pr; goto repeat;}
        break;
        case 2:{pr.ModifierDonnees(); goto repeat;}
        break;
        case 3:{cout<<pr; goto repeat;}
        break;
        case 4:Menu();
        break;
        case 5:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}
}
void MenuEnfants()
{
Enfant enf;
int choix;
repeat:
cout<<"\n\n\t\t1.Creer Enfant\n\t\t2.Ajouter Maladie\n\t\t3.Supprimer Maladie\n\t\t4.Ajouter Allergie\n\t\t5.Supprimer Allergie\n\t\t6.Vacciner\n\t\t7.Afficher Donnees\n\t\t8.Menu Principal\n\t\t9.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";

again:
    cin>>choix;
    switch(choix)
    {
        case 1:{cin>>enf; goto repeat;}
        break;
        case 2:{enf.AjouterMaladie(); goto repeat;}
        break;
        case 3:{enf.SupprimerMaladie(); goto repeat;}
        break;
        case 4:{enf.AjouterAllergie(); goto repeat;}
        break;
        case 5:{enf.SupprimerAllergie(); goto repeat;}
        break;
        case 6:{enf.Vacciner(); goto repeat;}
        break;
        case 7:{cout<<enf; goto repeat;}
        break;
        case 8:Menu();
        break;
        case 9:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}}
void FInscription()
{
vector<Enfant>BD;
fstream f;
Niveau NiveauJunior("Niveau Junior"),Creche("Creche"),Preparatoire("Preparatoire"),GarderieScolaire("Garderie Scolaire");

inscription i;
Enfant enf;
enf=i.formulaire(BD,NiveauJunior,Creche,Preparatoire,GarderieScolaire);
i.AjoutBD(enf,BD);

}
void Menu()
{
    int choix;
    cout<<"\n\n\t\t1.Employes\n\t\t2.Restaurant\n\t\t3.Evenements\n\t\t4.Activites\n\t\t5.Etudes\n\t\t6.Calendrier annuelle\n\t\t7.Salles\n\t\t8.Groupes\n\t\t9.Niveaux\n\t\t10.Facture\n\t\t11.Parents responsables \n\t\t12.Enfants\n\t\t13.Inscription\n\t\t14.Quitter\n\n\n\n\n\t\t Saisir votre choix: ";
    again:
    cin>>choix;
    switch(choix)
    {
       case 1:MenuEmployes();
        break;
        case 2:MenuRestau();
        break;
        case 3:MenuEvent();
        break;
        case 4:MenuActivite();
        break;
        case 5:MenuEtude();
        break;
        case 6:MenuCalendrier();
        break;
        case 7:MenuSalle();
        break;
        case 8:MenuGrp();
        break;
        case 9:MenuNiveaux();
        break;
        case 10:MenuFacture();
        break;
        case 11:MenuParentsResponsables();
        break;
        case 12:MenuEnfants();
        break;
        case 13:FInscription();
        break;
        case 14:Quitter();
        break;
        default: {cout<<"\nReponse invalide!\nreesayer"<<endl; goto again;}
}}

