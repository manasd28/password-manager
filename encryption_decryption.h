#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include "ciphers.h"

typedef pair<string, string> (*encrypt_texts) (string text);
typedef string (*decrypt_texts) (string password, string key);

int CHOICE = 1;


encrypt_texts encrypt_text[] = {
    vigenere_encrypt,
    caesar_encrypt,
    railfence_encrypt
};

decrypt_texts decrypt_text[] = {
    vigenere_decrypt,
    ceaser_decrypt,
    railfence_decrypt
};

map<string, pair<string, string>>load_creds()
{
    fstream file;
    file.open("credentials.txt");
    map<string, pair<string, string>>creds;
    string url, username, password, key, temp;
    int counter = 0;
    while(getline(file, temp))
    {
        switch(counter/2)
        {
            case 0: ((~counter&1)?key=temp:url=decrypt_text[CHOICE](temp, key)); break;
            case 1: ((~counter&1)?key=temp:username=decrypt_text[CHOICE](temp, key)); break;
            case 2: ((~counter&1)?key=temp:password=decrypt_text[CHOICE](temp, key)); break;
        }
        ++counter; counter%=6;
        if(counter == 0)
        {
            creds[url] = make_pair(username, password);
        }
    }
    file.close();
    return creds;
}

void save_creds(vector<string>items)
{
    fstream file;
    file.open("credentials.txt", ios::app);
    pair<string, string>creds;
    for(auto it: items)
    {
        creds = encrypt_text[CHOICE](it);
        file<<creds.second<< '\n'<< creds.first<< '\n';
    }
    file.close();
}
