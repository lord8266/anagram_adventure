#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
using namespace std;
void printLettersInAGrid(char []);
vector <string> dictionary;
void readFile()
{
    fstream f;
    f.open("word_refined.txt",ios::in);
    {
        char a[100];
        while(f.getline(a,100,'\n'))
        {
            dictionary.push_back(a);
        }
    }
}

void makeRandomLetters(char a[]) // Creates a sequence of 20 random letters consisting 5 vowels and 15 consonants.
{
    srand(time(0));
    int vowelCount=0;
    int consonantCount=0;
    char vowels[]="AEIOU";
    for(int i=0;i<20;i++)
    {
        a[i]=rand()%26;
        a[i]+=65;
        if((a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U'))
            ++vowelCount;
        else
            ++consonantCount;
        if(consonantCount>15)
        {
            a[i]=rand()%5;
            a[i]=vowels[int(a[i])];
            --consonantCount;
        }
        if(vowelCount>5)
        {
            --i;
            --vowelCount;
        }
    }
    printLettersInAGrid(a);
}
void printLettersInAGrid(char a[])
{
    cout<<" ---------------------\n";
    for(int i=0;i<4;i++)
    {
        cout<<" |";
        for(int j=0;j<5;j++)
        {
            cout<<" "<<a[i*5+j]<<" |";
        }
        cout<<"\n ---------------------\n";
    }

}
int main()
{
    char letters[20];
    makeRandomLetters(letters);
    readFile();
}