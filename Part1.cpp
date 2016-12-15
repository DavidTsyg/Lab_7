#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Computer
{
    char Processor[128];
    char Clock_Signal[64];
    char Ram[64];
    char HDD_Volume[64];
    char Graphics_Card[128];
};

int main(int argc, char* argv[])
{
    int n;
    cout << "Enter the number of computers" << endl;
    cin >> n;
    struct Computer *pc = (Computer*)malloc(n * sizeof(Computer));
    for (unsigned int i = 0; i<n; ++i)
    {
        cout << "Enter <Processor> :" << endl;
        cin >> pc[i].Processor;
        cout << "Enter <Clock Signal> :" << endl;
        cin >> pc[i].Clock_Signal;
        cout << "Enter <Ram> :" << endl;
        cin >> pc[i].Ram;
        cout << "Enter <HDD Volume> :" << endl;
        cin >> pc[i].HDD_Volume;
        cout << "Enter <Graphics Card> :" << endl;
        cin >> pc[i].Graphics_Card;
    }
    FILE *pF;
    pF = fopen( "MyProgram.txt", "wb");
    fwrite(&n, sizeof(int), 1, pF);
    fwrite(pc, sizeof(Computer), n, pF);
    fclose(pF);
    return 0;
}
