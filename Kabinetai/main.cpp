//pridedame bibliotekas
#include <iostream>
#include <fstream>

using namespace std;

int skaiciavimas(int skaicius) { //skaitmen� kiekio skai�iavimo funkcija
    int suma = 0; //�vedame sumos kintam�j�

    if (skaicius == 0) { //jeigu skai�ius yra 0, tai jis turi 1 skaitmen�
        return 1; //gr��iname 1
    }

    while (skaicius != 0) { //ciklas, kuriame skai2ius dalinamas i� 10 tol kol jis lygus 0, kiek kart� padalinta, tiek vienet� turi skai�ius
        skaicius /= 10;
        suma++;
    }
    return suma; //sugr��iname sum�
}

int main() { //pagrindin� funkcija
    ifstream fin("duomenys.txt"); //failas i� kurio nura�ysime duomenis
    ofstream fout("rezultatai.txt"); //failas, � kur� �ra�ysime atsakymus

    if (!fin || !fout) {
        cout << "Failai neatsidaro" << endl; //tikriname, ar failai atsidaro
        return 1;
    }

    int kabinetai; //kabinet� kintamasis
    fin >> kabinetai; //nura�oma informacija nuo duomen� failo

    int suma1 = 0; //�vedamas sumos kintamasis, kuris yra = 0

    for (int i = 1; i <= kabinetai; i++) { //ciklas, kuris veikia tiek, kiek yra kabinet� ir vis� kabinet� vienet� sum� sudeda kartu
        int skaicius1 = i; //skai�ius yra lygus ciklo skai�iui
        suma1 += skaiciavimas(skaicius1); //i�kvie�iama funkcija, kuri vykdoma su skaicius1 kintamuoju ir atsakymas, kur� gr��ina funkcija pridedamas prie bendros sumos
    }

    fout << suma1; //atsakymas �ra�omas � atsakym� fail�

    //failai u�daromi
    fin.close();
    fout.close();

    return 0;
}
