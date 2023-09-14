#include <iostream>
#include <string>

using namespace std;

// Functia pentru criptare
string Caesar(string text, int nrPozitii)

{
string rezultat = "";
   //65 - 90: Coduri ASCII litere mici, 97 - 122: Coduri ASCII litere mari
    // parcurgem textul de la prima litera pana la ultima
    for (int i=0;i<text.length();i++)
    {
        //daca pe pozitia i din text este o litera
        if(isalpha(char(text[i])))
        {
            //daca este majuscula
        if (isupper(text[i]))
            rezultat += char(int(text[i]+nrPozitii-65)%26 +65); //criptez rezultatul

    // altfel, daca este litera mica
        else
            rezultat += char(int(text[i]+nrPozitii-97)%26 +97);
        }
        else //altfel, daca nu este o litera pe pozitia i
        {
            if(char(text[i]) != ' ') //verific daca pe pozitia i se afla spatiu
            {
                rezultat += text[i]; //concatenez orice nu este spatiu, ex: cifra, semn intrebare/exclamare etc.
            }
            else //daca este spatiu
                rezultat += " "; //spatiul este concatenat la rezultat
        }

    }

    // returneaza string-ul rezultat
    return rezultat;
}


int main()
{

    // Citim de la tastatura textul care urmeaza a fi criptat

    string text;
    cout << "Introduceti textul de criptat: ";
    getline(cin, text);

    // Citim numarul de pozitii cu care se realizeaza mutarea
    int mutare;
    cout << "Introduceti numarul de pozitii pentru a realiza deplasarea caracterelor: ";
    cin >> mutare;

    //se realizeaza criptarea
    string textCriptat = Caesar(text, mutare);
    cout << "Textul criptat este: " << textCriptat << endl; //se afiseaza criptarea

    return 0;
}
