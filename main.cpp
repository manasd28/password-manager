#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<regex>
#include<fstream>

#include "passwordGenerator.h"
#include "encryption_decryption.h"

using namespace std;

int main()
{
    map<string, pair<string, string>>store_creds;
    int choice;
    store_creds = load_creds();
    do
    {
        string username, url, password;
        cout<<"Enter the url\n";
        cin>>url;
        transform(url.begin(), url.end(), url.begin(), ::tolower);
        regex removeHttps("[^A-Za-z]");
        url = regex_replace(url, removeHttps, "");

        if(store_creds.find(url)!=store_creds.end())
        {
            pair<string, string>creds = store_creds[url];
            cout<<"CREDENTIALS FOUND!\n";
            cout<<"User Name: "<<creds.first<< '\n';
            cout<<"Password: "<<creds.second<< '\n';
        }
        else
        {
            cout<<"No Credentials found, please enter below:\n";
            cout<<"Username: "; cin>>username;
            cout<<"Do you wish to use a strongly generated password? (1/0) ";
            cin>>choice;
            if(choice) password = generatePassword();
            else {cout<<"Password: "; cin>>password;}
            cout<<"Do you wish to save these information? (1/0) "; cin>>choice;
            if(choice)
            {
                save_creds({url, username, password});
                store_creds[url] = make_pair(username, password);
            }
        }
        cout<<"\nWant to enter more website's information? (1/0) "; cin>>choice;
    }while(choice);
    return 0;
}
