//prijungiame bibliotekas
#include <iostream>
#include <fstream>

using namespace std;

void nurasymas.skaiciavimas() { //nurašymo ir skaičiavimo funkcija
    ifstream fin("duomenys.txt"); //failas, iš kurio nuskaitys duomenis
    ofstream fout("tarpinis.txt"); //failas, į kurį įrašysiu tarpinius rezultatus

    //sukuriami kintamieji
    int plotis;
    int aukstis;
    int kiekis;
    int x1;
    int x2;
    int y1;
    int y2;
    int sienos_pl = 0;

     if (!fin) {
        cout << "Duomenų failas nerastas." << endl; //patikriname, ar yra duomenų failas
        return;

    fin >> plotis; //nurašomas pirmas skaitmuo nuo duomeų failo
    if (plotis <= 0 || plotis >= 1000) { //patikriname, ar duomenys teisingi
        cout << "Plotis netinkamas" << endl;
        return;
    }

    fin >> aukstis; //nuskaitome plotį nuo duomenų failo
    if (aukstis <= 0 || aukstis >= 1000) { //patikriname, ar duomenys teisingi
        cout << "Aukstis netinkamas" << endl;
        return;
    }
    sienos_pl = aukstis * plotis; //apskaičiuojame sienos plotą
    fout << sienos_pl << endl; //įrašome atsakymą į duomenų failą

    fin >> kiekis; //nuskaitome plakatų kiekį nuo duomenų failo
    int suma = 0; //kintamasis
    for (int i = 0; i < kiekis; i++) { //ciklas, kuris nurašo kiekvieno plakato duomenis nuo duomenų failo, apskaičiuoja plakatų ilgius, pločius ir plotus ir prideda plakato plotą prie bendos sumos
        fin >> x1 >> y1 >> x2 >> y2;
        int ilgis = x2 - x1;
        int augis = y2 - y1;
        int plotass = ilgis * augis;

        suma += plotass;
    }
    fout << suma << endl; //į tarpinį failą nurašome gautą plakatų bendrą plotų sumą
    //uždarome failus
    fout.close();
    fin.close();
}

int main() { //pagrindinė funkcija
    nurasymas.skaiciavimas(); //iškviečiame kitą funkciją
    ifstream fin("tarpinis.txt"); //failas, iš kurio nuskaitys duomenis
    ofstream fout("rezultatai.txt"); //failas, į kurį įrašysiu tarpinius rezultatus

     if (!fin) {
        cout << "Tarpinis failas nerastas." << endl; //patikriname, ar yra tarpinis failas
        return;

    //įvewdami kintamieji
    int sienu;
    int bendras;
    int atsakymas;

    //nurašoma informacija nuo tarpinio failo
    fin >> sienu;
    fin >> bendras;

    atsakymas = sienu - bendras; //suskaičiuojamas skirtumas tarp sienos ploto ir bendro plakatų ploto

    fout << atsakymas << endl; //atsakymas įvedamas į atsakymų failą

    //uždarome failus
    fout.close();
    fin.close();

    return 0;
}
