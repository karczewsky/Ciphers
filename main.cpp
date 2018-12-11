#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

// cipherFlags
#define NO_CIPHER 0
#define BLOCK_CIPHER 1
//#define STREAM_CIPHER 2
//#define ASYM_CIPHER 3

// cipherModes
#define NO_MODE 0
#define CIPHER_MODE 1
#define DECIPHER_MODE 2

using namespace std;

void printHelp() {
    cout << "* Prosze uzupelnic pole pomocy w miare rozwoju aplikacji.            *" << endl;
    cout << "* W chwili obecnej program zbudowany jest jako szablon,              *" << endl;
    cout << "* ktory powinien byc uzupelniany o kolejne algorytmy                 *" << endl;
    cout << "* kryptograficzne. Powodzenia.                                       *" << endl;
    cout << "**********************************************************************" << endl;
    cout << "* Dolecowy program powinien dzialac w nastepujacy sposob:            *" << endl;
    cout << "* W wierszu polecen wywolujemy nazwe programu i parametry            *" << endl;
    cout << "* programu, gdzie:                                                   *" << endl;
    cout << "* -bc szyfr blokowy w trybie c/d (szyfrowanie/deszyfrowanie);        *" << endl;
    cout << "* -sc szyfr strumieniowy w trybie c/d (szyfrowanie/deszyfrowanie);   *" << endl;
    cout << "* -hf funkcja skrotu bez trybow;                                     *" << endl;
    cout << "* -ac szyfr asymetryczny w trybie c/d (szyfrowanie/deszyfrowanie);   *" << endl;
    cout << "* -i sciezka pliku wejsciowego (tekstu jawnego, wiadomosci);         *" << endl;
    cout << "* -o sciezka pliku wyjsciowego (tekstu zaszyfrowanego, skrotu);      *" << endl;
    cout << "* -k sciezka klucza;                                                 *" << endl;
    cout << "* -h, --help to pomoc (wystepuje bez innych parametrow);             *" << endl;
    cout << "**********************************************************************" << endl;
    cout << "* Przyklad:                                                          *" << endl;
    cout << R"(* crypto_2018.exe -bc d -i C:\in.txt -o D:\out.txt -k C:\key.txt     *)" << endl;
    cout << "**********************************************************************" << endl;
    cout << "* Program operuje na plikach tekstowych.                             *" << endl;
    cout << "**********************************************************************" << endl;
}

bool validateFiles(fstream *i, fstream *o, fstream *k) {
    bool res = true;
    if(i->fail() || !i->is_open()) {
        res = false;
        cout << "Blad zwiazny z plikiem wejsciowym" << endl;
    }

    if(o->fail() || !o->is_open()) {
        res = false;
        cout << "Blad zwiazany z plikiem wyjsciowym" << endl;
    }

    if(k->fail() || !k->is_open()) {
        res = false;
        cout << "Blad zwiazany z plikiem klucza" << endl;
    }

    return res;
}

int main(int argc, char** argv)
{
    cout << "**********************************************************************" << endl;
    cout << "*\t\t\t\t\t     *******************   \t\t\t\t\t     *" << endl;
    cout << "*\t\t\t\t\t     * CRYPTO WKR 2018 *   \t\t\t\t\t     *" << endl;
    cout << "*\t\t\t\t\t     *******************   \t\t\t\t\t     *" << endl;
    cout << "**********************************************************************" << endl;

    if (argc == 1) {
        printHelp();
    }
    else if (argc == 2) {
        if (string(argv[1]) == "-h" || string(argv[1]) == "--help") {
            printHelp();
        }
        else {
            cout << argc << endl;
            cout << "Blednie wprowadzone parametr/parametry. (Blad: E001)" << endl;
        }
    }
    else {
        int cipherFlag = 0;
        int cipherMode = 0;

        fstream input;
        fstream output;
        fstream key;

        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-') {
                if (argc == i + 1 || argv[i + 1][0] == '-') {
                    if (string(argv[i]) == "-hf") {
                        cout << argv[i] << ":";
                        cout << "Ok, wyznaczenie skrotu do dzialania nie potrzebuje parametru ani pliku klucza;" << endl;
                    }
                    else if (string(argv[i]) == "-bc") {
                        cout << argv[i] << ": ";
                        cout << "Nie podano parametru pracy szyfru blokowego;" << endl;
                    }
                    else if (string(argv[i]) == "-sc") {
                        cout << argv[i] << ": ";
                        cout << "Nie podano parametru pracy szyfru strumieniowego;" << endl;
                    }
                    else if (string(argv[i]) == "-ac") {
                        cout << argv[i] << ": ";
                        cout << "Nie podano parametru pracy szyfru asymetrycznego;" << endl;
                    }
                    else if (string(argv[i]) == "-i") {
                        cout << argv[i] << ": ";
                        cout << "Nie podano sciezki pliku wejsciowego;" << endl;
                    }

                    else if (string(argv[i]) == "-o") {
                        cout << argv[i] << ": ";
                        cout << "Nie podano sciezki pliku wyjsciowego;" << endl;
                    }
                    else if (string(argv[i]) == "-k") {
                        cout << argv[i] << ": ";
                        cout << "Nie podano pliku klucza;" << endl;
                    }
                    else {
                        cout << argv[i] << ": ";
                        cout << "Niepoprawny parametr pracy programu;" << endl;
                    }
                }
                else {

                    if (string(argv[i]) == "-i") {
                        input.open(argv[i + 1], ios::in);

                        if (input.good()) {
                            cout << "Dane wejsciowe zostana pobrany z pliku: " << argv[++i] << endl;
                        }
                        else {
                            cout << argv[i] << ": ";
                            cout << "Niepoprawna sciezka pliku wejsciowego!" << endl;
                        }
                    }

                    else if (string(argv[i]) == "-o") {
                        output.open(argv[i + 1], ios::out);

                        if (output.good()) {
                            cout << "Dane wyjsciowe zostana zapisane do pliku: " << argv[++i] << endl;
                        }
                        else {
                            cout << argv[i] << ": ";
                            cout << "Niepoprawna sciezka pliku wejsciowego!" << endl;
                        }
                    }
                    else if (string(argv[i]) == "-k") {
                        key.open(argv[i + 1], ios::in);

                        if (key.good()) {
                            cout << "Klucz zostanie pobrany z pliku: " << argv[++i] << endl;
                        }
                        else {
                            cout << argv[i] << ": ";
                            cout << "Niepoprawna sciezka klucza!" << endl;
                        }
                    }

                    else if (string(argv[i]) == "-bc") {
                        cipherFlag = 1;
                        if (string(argv[i + 1]) == "c") {
                            cipherMode = 1;
                            cout << "Szyfr blokowy bedzie pracowal w trybie szyfrowania: " << argv[++i] << endl;
                        }
                        else if (string(argv[i + 1]) == "d")
                        {
                            cipherMode = 2;
                            cout << "Szyfr blokowy bedzie pracowal w trybie deszyfrowania: " << argv[++i] << endl;
                        }
                        else {
                            cout << argv[i] << ": ";
                            cout << "Niepoprawny tryb pracy szyfru;" << endl;
                        }
                    }

                    else if (string(argv[i]) == "-sc") {
                        cipherFlag = 2;
                        if (string(argv[i + 1]) == "c") {
                            cipherMode = 1;
                            cout << "Szyfr strumieniowy bedzie pracowal w trybie szyfrowania: " << argv[++i] << endl;
                        }
                        else if(string(argv[i + 1]) == "d")
                        {
                            cipherMode = 2;
                            cout << "Szyfr strumieniowy bedzie pracowal w trybie deszyfrowania: " << argv[++i] << endl;
                        }
                        else {
                            cout << argv[i] << ": ";
                            cout << "Niepoprawny tryb pracy szyfru;" << endl;
                        }
                    }

                    else if (string(argv[i]) == "-ac") {
                        cipherFlag = 3;
                        if (string(argv[i + 1]) == "c") {
                            cipherMode = 1;
                            cout << "Szyfr asymetryczny bedzie pracowal w trybie szyfrowania: " << argv[++i] << endl;
                        }
                        else if(string(argv[i + 1]) == "d")
                        {
                            cipherMode = 2;
                            cout << "Szyfr asymetryczny bedzie pracowal w trybie deszyfrowania: " << argv[++i] << endl;
                        }
                        else {
                            cout << argv[i] << ": ";
                            cout << "Niepoprawny tryb pracy szyfru;" << endl;
                        }
                    }
                    else {
                        cout << argv[i] << ": ";
                        cout << "Niepoprawny parametr pracy programu;" << endl;
                    }
                }
            }
        }

        switch (cipherFlag) {
            default:
            case NO_CIPHER:
                cout << "Brak wybranego sposobu dzialania programu";
                break;
            case BLOCK_CIPHER:
                if(!validateFiles(&input, &output, &key)) {
                    cout << "Program nie moze kontynuowac z bledna konfiguracja plikow" << endl;
                    return 0;
                }

                string i_str;
                string k_str;
                stringstream ss_out;

                input >> i_str;
                key >> k_str;

                switch (cipherMode) {
                    default:
                    case NO_MODE: {
                        cout << "Brak poprawnego wybrania trybu pracy(szyfruj/deszyfruj)" << endl;
                        return 0;
                    }
                    case CIPHER_MODE: {
                        int len = i_str.size() / 16;

                        for(int i=0; i<len; i++) {
                            string v_s = i_str.substr(i*16, 16);
                            string k_s = k_str.substr(i*32, 32);

                            uint32_t sum = 0;
                            uint32_t delta=0x9E3779B9;
                            uint32_t v[2];
                            uint32_t k[4];

                            for (int j=0; j<2; j++) {
                                v[j] = strtoul(v_s.substr(j*8, 8).c_str(), NULL, 16);
                            }

                            for (int j=0; j<4; j++) {
                                k[j] = strtoul(k_s.substr(j*8, 8).c_str(), NULL, 16);
                            }

                            for (int j=0; j<32; j++) {
                                sum += delta;
                                v[0] += ((v[1]<<4) + k[0]) ^ (v[1] + sum) ^ ((v[1]>>5) + k[1]);
                                v[1] += ((v[0]<<4) + k[2]) ^ (v[0] + sum) ^ ((v[0]>>5) + k[3]);
                            }

                            ss_out << hex << v[0] << v[1];
                            output << hex << v[0] << v[1];
                        }

                        cout << "Wiadomosc plaintext: " << i_str << endl;
                        cout << "Klucz: " << k_str << endl;
                        cout << "Wiadomosc zaszyfrowana: "  << ss_out.str() << endl;
                        break;
                    }
                    case DECIPHER_MODE: {
                        int len = i_str.size() / 16;

                        for(int i=0; i<len; i++) {
                            string v_s = i_str.substr(i*16, 16);
                            string k_s = k_str.substr(i*32, 32);

                            uint32_t delta = 0x9E3779B9;
                            uint32_t sum = 32*delta;
                            uint32_t v[2];
                            uint32_t k[4];

                            for (int j=0; j<2; j++) {
                                v[j] = strtoul(v_s.substr(j*8, 8).c_str(), NULL, 16);
                            }

                            for (int j=0; j<4; j++) {
                                k[j] = strtoul(k_s.substr(j*8, 8).c_str(), NULL, 16);
                            }

                            for (int j=0; j<32; j++) {
                                v[1] -= ((v[0]<<4) + k[2]) ^ (v[0] + sum) ^ ((v[0]>>5) + k[3]);
                                v[0] -= ((v[1]<<4) + k[0]) ^ (v[1] + sum) ^ ((v[1]>>5) + k[1]);
                                sum -= delta;
                            }

                            ss_out << hex << v[0] << v[1];
                            output << hex << v[0] << v[1];
                        }


                        cout << "Wiadomosc zaszyfrowana: " << i_str << endl;
                        cout << "Klucz: " << k_str << endl;
                        cout << "Wiadomosc plaintext: "  << ss_out.str() << endl;
                        break;
                    }
                }
        }
    }

    getchar();
    return 0;
}
