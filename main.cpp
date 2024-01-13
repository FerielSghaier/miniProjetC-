#include <iostream>
#include<string>
#include "projet.h"
#include "fonctions.h"
#include <vector>
#include <fstream>

using namespace std;

int main()
{


string login;// le login est Admin
string mdp;// le mot de passe est ProjetC++
cout<<"\t\t\t\xB2\xB2\xB2\ SYSTEME DE GESTION DE JARDIN D'ENFANT  \xB2\xB2\xB2";
cout<<"\n\n\t\t\t\xB2\xB2\xB2\ BONJOUR ET BIENVENU  \xB2\xB2\xB2";
x:
cout<<"\n\n\nSaisir votre login"<<endl;
cin>>login;
if(login!="Admin")
{
    y:
    cout<<"login Invalide!\n1-Reessayer\n2-Quitter"<<endl;
    int choix1;
    cin>>choix1;
    if(choix1==1)
        goto x;
    else if(choix1==2)
        goto quitter;
    else
    {
        cout<<"\nreponse invalide!"<<endl;
        goto y;
    }
}
t:
cout<<"\nSaisir votre mot de passe"<<endl;
cin>>mdp;
if(mdp!="ProjetC++")
{
    z:
    cout<<"mot de passe Invalide!\n1-Reessayer\n2-Quitter"<<endl;
    int choix2;
    cin>>choix2;
    if(choix2==1)
        goto t;
    else if(choix2==2)
        goto quitter;
    else
    {
        cout<<"\nreponse invalide!"<<endl;
        goto z;
    }
}
Menu();
/*vector<Enfant>BD;
fstream f;
Niveau NiveauJunior("Niveau Junior"),Creche("Creche"),Preparatoire("Preparatoire"),GarderieScolaire("Garderie Scolaire");

inscription i;
Enfant enf;
enf=i.formulaire(BD,NiveauJunior,Creche,Preparatoire,GarderieScolaire);
i.AjoutBD(enf,BD);*/





quitter:
return 0;
}
