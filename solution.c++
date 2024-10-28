#include <iostream>
#include<string.h>
using namespace std;

struct employe{
    string nom;
    string prenom;
    double salaire;
    };

    struct liste{
    employe*tab;
    int t;
    };

employe saisir(){
    employe e;
cout<<"enter les infos employe: "<<endl;
cout<<"enter le prenom: "<<endl;
cin>>e.prenom;
cout<<"enter le nom: "<<endl;
cin>>e.nom;
cout<<"enter le salaire: "<<endl;
cin>>e.salaire;
return e;
}

void aff_e(liste *l , int index){
    cout<<l->tab[index].prenom<<endl;
    cout<<l->tab[index].nom<<endl;
    cout<<l->tab[index].salaire<<endl;
}

void init(liste &l){
    l.tab = NULL;
    l.t = 0;
}

void aff_l(liste*l){
    if(l->t == 0){
        cout<<"aucun employe"<<endl;
    }
    else{
    for(int i=0 ; i<l->t ; i++){
    aff_e(l,i);
    //cout<<l->tab[i].nom<<endl;
    //cout<<l->tab[i].prenom<<endl;
    //cout<<l->tab[i].salaire<<endl;
    }
    }
}

void ajouter(liste*l){
employe e = saisir();
employe* newtab = new employe[l->t+1];
for(int i=0 ; i<l->t ; i++)
    newtab[i] = l->tab[i];

newtab[l->t]=e;
l->t++;
delete[] l->tab;
l->tab = newtab;
}

int rechercher(string name , liste * l){
for(int i=0 ; i<l->t ; i++){
if(l->tab[i].nom == name)
    return 1;
}
return 0;
}

int choix(){
int c;
cout<<"1-Ajouter un employe"<<endl;
cout<<"2-Affiche la liste"<<endl;
cout<<"3-Rechercher un employe"<<endl;
cout<<"4-Quitter"<<endl;
cout<<"saisir un choix"<<endl;
cin>>c;
return c ;
}

void menu(liste &l){
    string nom;
    int b,r ;
    init(l);
do{
    b = choix();
    switch(b){
            case 1:
                ajouter(&l);
                break;

            case 2:
                aff_l(&l);
                break;

            case 3:
                cout<<"saisir un nom: "<<endl;
                cin>>nom;
                r = rechercher(nom,&l);
                if(r==1)
                    cout<<"existe"<<endl;
                else
                    cout<<"n'existe pas"<<endl;
                break;

            case 4:
                cout<<"Quitter le programme."<<endl;
                break;

            default:
                cout<<"Option invalide. Veuillez choisir une option valide."<<endl;
        }
    } while (b != 4);
}

int main()
{liste l;
menu(l);
    return 0;
}
