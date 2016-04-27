//Zvonko
//worked with Abdul,Tom,and Valay
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


int Quadratic_Probing(int hashtable[], int index, int max); //Declaring function
int Extraction_Method(int noms); //Declaring function

int Quadratic_Probing(int hashtable[], int index, int max)     //Quadratic Probing without replacement

{
    int now, ran, i;
    now = index % 70000;      //console input determines index
    ran = 1;
    for(i = 1; i < 70000; i++)     //see if the index = 0
    {
        if(hashtable [(now + (max + i)*(max + i)) % 70000] == 0)
            {
                return index;
            }
    }
    return false;       //return table
}

int Extraction_Method(int noms)     //extraction method
{
    string x = "000000000";
    char *xP = new char[100];
    sprintf(xP, "%i", noms);
    string m = (string) xP;

    int j = 0;
    int i;

    for(i = 0; i < m.size(); i++)
    {
        x[i] = m[j];
        j++;
    }
    string y = "0000";      //extract 3th, 5th, 7th, 8th position
    y[0] = x[2];
    y[1] = x[4];
    y[2] = x[6];
    y[3] = x[7];

    return atoi(y.c_str());     //return the extract
}

int main()
{
    ifstream in;      //input in
    ofstream outf;       //output outf
    string croatia;       //string croatia
    string soccer;        //string soccer
    int Enternum;       //enter number for probing
    int i;

    int * thehashtable;
    thehashtable = new int [70000];     //create a hash table of 70,000

    for(i = 0; i < 70000; i++)
    {
        thehashtable[i] = 0;        //indexes of array = 0
    }

    cout << "hello!" << endl;
    cout << "name of the file?: ";       //console output name of file
    getline(cin, croatia);         //user input file
    in.open(croatia.c_str());       //open the input file,c-style string

    while(in.fail())      //if user is wrong

    {
        cout << croatia << " " << "file not found" << endl;
        cout << "Enter in another file: ";                  //console asks the user to input the correct file
        getline(cin, croatia);
        in.open(croatia.c_str());
    }

    vector <int> zvonko;        //created a vector to store all numbers
    while(in)     //read file line by line
    {
        getline(in, croatia);
        istringstream cod(croatia);
        while(getline(cod, soccer, ','))
        {
            zvonko.push_back(atoi(soccer.c_str()));
        }

    cout << "Enter a number between 1 and 450,000,000: ";
    cin >> Enternum;

    Enternum = Enternum % 70000;

    while(!(Enternum >= 0 && Enternum <= 450000000))
    {
        cout << "Enter a number between 0 and 450000000: " << endl;
        cin >> Enternum;
    }

    int the_index;
    for(i = 0; i < zvonko.size(); i++)      //didn't cout everything
    {
        the_index = Extraction_Method(zvonko[i]);       //storing the extracted address of number
        if(thehashtable[the_index] == 0)        //store the number
        {
            thehashtable[the_index] = zvonko[i];
        }
        else
        {
            the_index = Quadratic_Probing(thehashtable, the_index, Enternum);
            if(the_index == -1)
            {

            }
            else
            {
                thehashtable[the_index] = zvonko[i];        //quadratic probing places numbers into next index

            }
        }
    }

    if(in.is_open())      //if thisfile is open
    outf.open("hashed_socials.txt");     //open an output text file
    for(int i = 0; i < 70000; i++)      //write out the hash table to the output file
    {
        outf << thehashtable[i];
        if(i < 69999)
            {
                outf << ',';
            }
    }
    in.clear();       //clear the in file
    outf.clear();        //clear the out file
	in.close();       //close the in file
    outf.close();        //close the out file

    }


    return 0;
}
