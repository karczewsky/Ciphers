#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

// cipherFlags
#define NO_CIPHER 0
#define BLOCK_CIPHER 1
#define STREAM_CIPHER 2
#define ASYM_CIPHER 3

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
        int cipherFlag = NO_CIPHER;
        int cipherMode = NO_MODE;

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
                        cipherFlag = BLOCK_CIPHER;
                        if (string(argv[i + 1]) == "c") {
                            cipherMode = CIPHER_MODE;
                            cout << "Szyfr blokowy bedzie pracowal w trybie szyfrowania: " << argv[++i] << endl;
                        }
                        else if (string(argv[i + 1]) == "d")
                        {
                            cipherMode = DECIPHER_MODE;
                            cout << "Szyfr blokowy bedzie pracowal w trybie deszyfrowania: " << argv[++i] << endl;
                        }
                        else {
                            cout << argv[i] << ": ";
                            cout << "Niepoprawny tryb pracy szyfru;" << endl;
                        }
                    }

                    else if (string(argv[i]) == "-sc") {
                        if (cipherFlag) {
                            cout << "Podano 2 rodzaje szyfrow/trybow pracy. Bledna konfiguracja programu" << endl;
                            return 1;
                        }
                        cipherFlag = STREAM_CIPHER;
                        if (string(argv[i + 1]) == "c") {
                            cipherMode = CIPHER_MODE;
                            cout << "Szyfr strumieniowy bedzie pracowal w trybie szyfrowania: " << argv[++i] << endl;
                        }
                        else if(string(argv[i + 1]) == "d")
                        {
                            cipherMode = DECIPHER_MODE;
                            cout << "Szyfr strumieniowy bedzie pracowal w trybie deszyfrowania: " << argv[++i] << endl;
                        }
                        else {
                            cout << argv[i] << ": ";
                            cout << "Niepoprawny tryb pracy szyfru;" << endl;
                        }
                    }

                    else if (string(argv[i]) == "-ac") {
                        if (cipherFlag) {
                            cout << "Podano 2 rodzaje szyfrow/trybow pracy. Bledna konfiguracja programu" << endl;
                            return 1;
                        }
                        cipherFlag = ASYM_CIPHER;
                        if (string(argv[i + 1]) == "c") {
                            cipherMode = CIPHER_MODE;
                            cout << "Szyfr asymetryczny bedzie pracowal w trybie szyfrowania: " << argv[++i] << endl;
                        }
                        else if(string(argv[i + 1]) == "d")
                        {
                            cipherMode = DECIPHER_MODE;
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


        string i_str;
        string k_str;
        stringstream ss_out;

        input >> i_str;
        key >> k_str;
        input.close();
        key.close();

        switch (cipherFlag) {
            default:
            case NO_CIPHER: {
                cout << "Brak wybranego sposobu dzialania programu";
                break;
            }
            case BLOCK_CIPHER: {
                switch (cipherMode) {
                    default:
                    case NO_MODE: {
                        cout << "Brak poprawnego wybrania trybu pracy(szyfruj/deszyfruj)" << endl;
                        return 0;
                    }
                    case CIPHER_MODE: {
                        int len = i_str.length() / 16;
                        cout << i_str.length() << endl;
                        for (int i = 0; i < len; i++) {
                            string v_s = i_str.substr(i * 16, 16);
                            string k_s = k_str.substr(i * 32, 32);

                            uint32_t v[2];
                            uint32_t k[4];

                            for (int j = 0; j < 2; j++) {
                                v[j] = strtoul(v_s.substr(j * 8, 8).c_str(), NULL, 16);
                            }

                            for (int j = 0; j < 4; j++) {
                                k[j] = strtoul(k_s.substr(j * 8, 8).c_str(), NULL, 16);
                            }

                            uint32_t sum = 0;
                            uint32_t delta = 0x9E3779B9;

                            for (int j = 0; j < 32; j++) {
                                sum += delta;
                                v[0] += ((v[1] << 4) + k[0]) ^ (v[1] + sum) ^ ((v[1] >> 5) + k[1]);
                                v[1] += ((v[0] << 4) + k[2]) ^ (v[0] + sum) ^ ((v[0] >> 5) + k[3]);
                            }

                            stringstream ss_temp;
                            ss_temp << hex << v[0] << v[1];
                            string s_temp = ss_temp.str();
                            while(s_temp.length() < 16) {
                                s_temp = "0" + s_temp;
                            }
                            ss_out << s_temp;
                        }
                        break;
                    }
                    case DECIPHER_MODE: {
                        int len = i_str.size() / 16;

                        for (int i = 0; i < len; i++) {
                            string v_s = i_str.substr(i * 16, 16);
                            string k_s = k_str.substr(i * 32, 32);

                            uint32_t delta = 0x9E3779B9;
                            uint32_t sum = 32 * delta;
                            uint32_t v[2];
                            uint32_t k[4];

                            for (int j = 0; j < 2; j++) {
                                v[j] = strtoul(v_s.substr(j * 8, 8).c_str(), NULL, 16);
                            }

                            for (int j = 0; j < 4; j++) {
                                k[j] = strtoul(k_s.substr(j * 8, 8).c_str(), NULL, 16);
                            }

                            for (int j = 0; j < 32; j++) {
                                v[1] -= ((v[0] << 4) + k[2]) ^ (v[0] + sum) ^ ((v[0] >> 5) + k[3]);
                                v[0] -= ((v[1] << 4) + k[0]) ^ (v[1] + sum) ^ ((v[1] >> 5) + k[1]);
                                sum -= delta;
                            }

                            stringstream ss_temp;
                            ss_temp << hex << v[0] << v[1];
                            string s_temp = ss_temp.str();
                            while(s_temp.length() < 16) {
                                s_temp = "0" + s_temp;
                            }
                            ss_out << s_temp;
                        }
                        break;
                    }
                }
            }
            case STREAM_CIPHER: {
                int len = i_str.length() / 8;
                uint32_t lfsr = strtoul(k_str.c_str(), NULL, 16);
                for (int i = 0; i < len; i++) {
                    uint32_t i_frag = strtoul(i_str.substr(i * 8, 8).c_str(), NULL, 16);
                    stringstream ss_temp;

                    uint32_t leaving_block = 0;
                    for (int j = 0; j < 32; j++) {
                        uint32_t bit = ((lfsr >> 31) ^ (lfsr >> 1) ^ (lfsr >> 0)) & 1;
                        leaving_block = (leaving_block << 1) | (lfsr & 1);
                        lfsr = (lfsr >> 1) | (bit << 31);
                    }

                    i_frag = i_frag ^ leaving_block;
                    ss_temp << hex << i_frag;
                    string s_temp = ss_temp.str();
                    while(s_temp.length() < 8) {
                        s_temp = "0" + s_temp;
                    }
                    ss_out << s_temp;
                }
                break;
            }
        }
        output << ss_out.str();
        output.close();
    }

    return 0;
}
