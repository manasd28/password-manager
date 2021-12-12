#include<bits/stdc++.h>
using namespace std;

//VIGENERE CIPHER
const int MAX = 26;

string generateKey(string str, string key)
{
	int x = str.size();
	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}
pair<string,string>vigenere_encrypt(string str)
{
	string cipher_text="";
    string res= generateCipherKey(str.length()/2);
    string key=generateKey(str,res);
	for (int i = 0; i < str.size(); i++)
	{
		char x = (str[i] + key[i]) %26;
		x = char(x+'a');
		cipher_text.push_back(x);
	}
    pair<string,string>p;
    p.first=cipher_text;
    p.second=key;
	return p;
}
string vigenere_decrypt(string cipher_text, string key)
{
	string orig_text="";
	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		char x = (cipher_text[i] - key[i] + 26) %26;
		x = char(x+'a');
		orig_text.push_back(x);
	}
	return orig_text;
}

//CEASER CIPHER
pair<string,string>caesar_encrypt(string text)
{
    string result = "";
    int s = getRandom(26, 1);
    for (int i=0;i<text.length();i++)
    {
        result += char(int(text[i]-97+s)%26 +97);
    }
    pair<string,string>p;
    p.first=result;
    p.second = to_string(s);
    return p;
}
string ceaser_decrypt(string p, string x)
{
    string dtext = "";
    int a = stoi(x);
    for (int i = 0; i < p.length(); i++)
    {
        dtext += char(int(p[i]-97-a+26)%26+97);
    }
    return dtext;
}

//RAILFENCE CIPHER
pair<string,string>railfence_encrypt(string text)
{
    int key = getRandom(1, 6);
    char rail[key][(text.length())];
    for (int i=0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';
    bool dir_down = false;
    int row = 0, col = 0;

    for (int i=0; i < text.length(); i++)
    {
        if (row == 0 || row == key-1)
            dir_down = !dir_down;
        rail[row][col++] = text[i];
        dir_down?row++ : row--;
    }

    string result;
    for (int i=0; i < key; i++)
        for (int j=0; j < text.length(); j++)
            if (rail[i][j]!='\n')
                result.push_back(rail[i][j]);

    pair<string,string>p;
    p.first=result;
    p.second = to_string(key);
    return p;
}

string railfence_decrypt(string cipher, string skey)
{
    int key = stoi(skey);
    char rail[key][cipher.length()];
    for (int i=0; i < key; i++)
        for (int j=0; j < cipher.length(); j++)
            rail[i][j] = '\n';
    bool dir_down;
    int row = 0, col = 0;
    for (int i=0; i < cipher.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        rail[row][col++] = '*';
        dir_down?row++ : row--;
    }
    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<cipher.length(); j++)
            if (rail[i][j] == '*' && index<cipher.length())
                rail[i][j] = cipher[index++];

    string result;

    row = 0, col = 0;
    for (int i=0; i< cipher.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);
        dir_down?row++: row--;
    }
    return result;
}
