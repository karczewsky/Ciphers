#!/bin/bash

function prepCipher() {
 echo $JAWNY > plain.txt
 echo $KLUCZ > key.txt
 echo $SZYFROGRAM > out.txt 
}

function compare() {
    if [ "$file1" = "$file2" ]
    then
    echo "[OK]-$msg"
    else
    echo "[ERR]-$msg"
    fi
}

# CLEANUP/PREP
rm -f *.txt

# BLOCK CIPHER
JAWNY="0123456789abcdef0123456789abcdef"
KLUCZ="00112233445566778899aabbccddeeff00112233445566778899aabbccddeeff"
SZYFROGRAM="126c6b92c0653a3e126c6b92c0653a3e"

prepCipher
./Cryptology -bc c -i plain.txt -k key.txt -o t.txt > /dev/null
./Cryptology -bc d -i out.txt -k key.txt -o o.txt > /dev/null

file1=`sha256sum t.txt | cut -f 1 -d " "`
file2=`sha256sum out.txt | cut -f 1 -d " "`
msg="Szyfrowanie blokowe"
compare

file1=`sha256sum plain.txt | cut -f 1 -d " "`
file2=`sha256sum o.txt | cut -f 1 -d " "`
msg="Deszyfrowanie blokowe"
compare

# STREAM CIPHER
JAWNY="0123456789abcdef0123456789abcdef"
KLUCZ="ffffffff"
SZYFROGRAM="fedcba9876543210fedcba9876543210"

prepCipher
./Cryptology -sc c -i plain.txt -k key.txt -o t.txt > /dev/null
./Cryptology -sc d -i out.txt -k key.txt -o o.txt > /dev/null

file1=`sha256sum t.txt | cut -f 1 -d " "`
file2=`sha256sum out.txt | cut -f 1 -d " "`
msg="Szyfrowanie strumieniowe"
compare

file1=`sha256sum plain.txt | cut -f 1 -d " "`
file2=`sha256sum o.txt | cut -f 1 -d " "`
msg="Deszyfrowanie strumieniowe"
compare

rm *.txt