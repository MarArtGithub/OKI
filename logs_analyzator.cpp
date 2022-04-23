/*
Rozwiązanie zadania z zajęć #24 - Analizator logów
Link do zajęć:
Link do zadania:
v. 1.0

Wykorzystane funkcje:
-- mapy
-- switch / case
*/


#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Porownaj {
 bool operator()(const vector<int> &lewy, const vector<int> &prawy) const    {
     if ( lewy[3] != prawy[3] )
     return (lewy[3] < prawy[3]);
     if ( lewy[0] != prawy[0] )
     return (lewy[0] < prawy[0]);
     if ( lewy[1] != prawy[1] )
     return (lewy[1] < prawy[1]);
     return (lewy[2] < prawy[2]);
 }
};

void WczytajAdresIP (vector<int> &adres_ip_vector) {
 int oktet, i;
 adres_ip_vector.clear(); 
 for (i=0; i<=3; ++i) {
    cin >> oktet;
 adres_ip_vector.push_back(oktet);
 } 
}

void WypiszAdresIP (const vector<int> &adres_ip_vector) {
 int i;
 for (i=0; i<=3; ++i)
  cout << adres_ip_vector[i] << ' ';
}

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 
//      0 - 3 
// indeks: adres ip  ile_razy_wystapil
 map < vector<int>, int,  Porownaj > ile_razy_adres_ip;
 map < vector<int>, int >::iterator it;
 vector<int> adres_ip_vector;

 int liczba_polecen, i, j, oktet;
 char polecenie;
 
 cin >> liczba_polecen;
 for (i=1; i<=liczba_polecen; ++i) {
    cin >> polecenie;
    switch (polecenie) {
    case 'k':
          WczytajAdresIP (adres_ip_vector); 
//                            192 168 1 32         
          ++ile_razy_adres_ip[adres_ip_vector];
          break;
    case 'z':
          WczytajAdresIP (adres_ip_vector); 
          WypiszAdresIP (adres_ip_vector);
          if ( ile_razy_adres_ip.count(adres_ip_vector) == 0 )
             cout << 0 << "\n";
          else
          cout << ile_razy_adres_ip[adres_ip_vector] << "\n";       break;
    case 'w':
          for (it=ile_razy_adres_ip.begin(); it!=ile_razy_adres_ip.end(); ++it) {
           WypiszAdresIP (it->first); //pierwszy element to indeks/klucz a to u nas vector
             cout << it->second << "\n";
    }      break;
    default:
      cout << "Blad\n";
      break;
    }
 }


 return 0;
}