//pridedame bibliotekas
#include <iostream>
#include <fstream>

using namespace std;

int skaiciavimas(int skaicius) { //skaitmenø kiekio skaièiavimo funkcija
    int suma = 0; //ávedame sumos kintamàjá

    if (skaicius == 0) { //jeigu skaièius yra 0, tai jis turi 1 skaitmená
        return 1; //gràþiname 1
    }

    while (skaicius != 0) { //ciklas, kuriame skai2ius dalinamas ið 10 tol kol jis lygus 0, kiek kartø padalinta, tiek vienetø turi skaièius
        skaicius /= 10;
        suma++;
    }
    return suma; //sugràþiname sumà
}

int main() { //pagrindinë funkcija
    ifstream fin("duomenys.txt"); //failas ið kurio nuraðysime duomenis
    ofstream fout("rezultatai.txt"); //failas, á kurá áraðysime atsakymus

    if (!fin || !fout) {
        cout << "Failai neatsidaro" << endl; //tikriname, ar failai atsidaro
        return 1;
    }

    int kabinetai; //kabinetø kintamasis
    fin >> kabinetai; //nuraðoma informacija nuo duomenø failo

    int suma1 = 0; //ávedamas sumos kintamasis, kuris yra = 0

    for (int i = 1; i <= kabinetai; i++) { //ciklas, kuris veikia tiek, kiek yra kabinetø ir visø kabinetø vienetø sumà sudeda kartu
        int skaicius1 = i; //skaièius yra lygus ciklo skaièiui
        suma1 += skaiciavimas(skaicius1); //iðkvieèiama funkcija, kuri vykdoma su skaicius1 kintamuoju ir atsakymas, kurá gràþina funkcija pridedamas prie bendros sumos
    }

    fout << suma1; //atsakymas áraðomas á atsakymø failà

    //failai uþdaromi
    fin.close();
    fout.close();

    return 0;
}
