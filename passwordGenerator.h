#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
int getRandom(int hi,int lo){
    srand(time(0));
    int num=(rand()%(hi-lo+1))+lo;
    return num;
}
int* getRandomArray(int hi,int lo,int n, int* arr){

    srand(time(0));
    for(int i=0;i<n;i++){

        int num=(rand()%(hi-lo+1))+lo;
        arr[i]=num;
    }
    return arr;

}

string generatePassword(){

    char characterList[26];
    int i=0;
    for(i=0;i<26;i++){

        characterList[i]=(char)(i+97);

    }
    int passLen = getRandom(12,8);
    string password;
    int arr[passLen];
    int *ptr=getRandomArray(25,0,passLen,arr);

    for(i=0;i<passLen;i++){
        password.push_back(characterList[ptr[i]]);
    }

    return password;

}

string generateCipherKey(int n){

    char characterList[26];
    int i=0;
    for(i=0;i<26;i++){
        characterList[i]=(char)(i+97);
    }
    int passLen = n;
    string password;
    int arr[passLen];
    int *ptr=getRandomArray(25,0,passLen,arr);

    for(i=0;i<passLen;i++){
        password.push_back(characterList[ptr[i]]);
    }

    return password;
}

