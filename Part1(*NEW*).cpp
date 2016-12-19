#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

struct Computer
{
    char Processor [64];
    char Clock_Signal [64];
    char Ram [64];
    char HDD_Volume [64];
    char Graphics_Card [64];
};

int main(int argc, char* argv[])
{
    unsigned int n, p;
    cout << "Enter the number of computers" << endl;
    cin >> n;
    cin.ignore();
    string buff;
    struct Computer *pc = (Computer*)malloc(n * sizeof(Computer));
    for (unsigned int i = 0; i<n; ++i)
    {
        cout << "Enter <Processor> :" << endl;
        p = 0;
        while (!p)
        {
            getline(cin, buff);
            if (buff.length() < 64) {
                strcpy(pc[i].Processor, buff.c_str());
                p = 1;
            }
            else cout << "Введенное название должно быть длиной не более 64 символов " << endl;
        }
        cout << "Enter <Clock Signal> :" << endl;
        p = 0;
        while (!p)
        {
            getline(cin, buff);
            if (buff.length() < 64) {
                strcpy(pc[i].Clock_Signal, buff.c_str());
                p = 1;
            }
            else cout << "Введенное название должно быть длиной не более 64 символов " << endl;
        }
        cout << "Enter <Ram> :" << endl;
        p = 0;
        while (!p)
        {
            getline(cin, buff);
            if (buff.length() < 64) {
                strcpy(pc[i].Ram, buff.c_str());
                p = 1;
            }
            else cout << "Введенное название должно быть длиной не более 64 символов " << endl;
        }
        cout << "Enter <HDD Volume> :" << endl;
        p = 0;
        while (!p)
        {
            getline(cin, buff);
            if (buff.length() < 64) {
                strcpy(pc[i].HDD_Volume, buff.c_str());
                p = 1;
            }
            else cout << "Введенное название должно быть длиной не более 64 символов " << endl;
        }
        cout << "Enter <Graphics Card> :" << endl;
        p = 0;
        while (!p)
        {
            getline(cin, buff);
            if (buff.length() < 64) {
                strcpy(pc[i].Graphics_Card, buff.c_str());
                p = 1;
            }
            else cout << "Введенное название должно быть длиной не более 64 символов " << endl;
        }
    }
    FILE *pF;
    pF = fopen( "MyProgram.txt", "wb");
    fwrite(&n, sizeof(int), 1, pF);
    fwrite(pc, sizeof(Computer), n, pF);
    fclose(pF);
    return 0;
}
