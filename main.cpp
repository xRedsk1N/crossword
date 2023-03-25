#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void read_my_work(char mywork[7][6])
{
    int i,j;
    for(i=0;i<7;i++){
        for(j=0;j<6;j++){
            cout << mywork[i][j];
        }
        cout << endl;
    }
}

void read_questions(string tips[7],string directions[7],int x[7],int y[7])
{
    for(int i=0;i<7;i++){
        cout << x[i] << " ";
        cout << y[i] << " ";
        cout << directions[i] << " " << endl;
        cout << tips[i] << " ";
        cout << endl;
        cout << endl;
    }
}

int main () {
    string input;
    string lines1[7];
    vector<string> lines;
    char xword[7][6];
    char mywork[7][6];
    ifstream file ("dane1.txt");

    int i = 0,j = 0;
    while(i<7)
    {
        file >> input;
        lines.push_back(input);
        i++;
    }

    i=0;
    for(string line: lines){
        lines1[i] = line;
        i++;
    }

    string tempstr;
    for(i=0;i<7;i++){
        for(j=0;j<6;j++){
            tempstr = lines1[i];
            xword[i][j] = tempstr[j];
            if(tempstr[j] == '#')
                mywork[i][j] = '#';
            else
                mywork[i][j] = '_';
        }
    }

/* CALA KRZYZOWKA:
    for(i=0;i<7;i++){
        for(j=0;j<6;j++){
            cout << xword[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
*/
    int x[7];
    int y[7];
    string directions[7];
    string tips[7];
    int length[7] = {7,4,6,6,4,4,4};
    i=0;
    while(i<7)
    {
        file >> input;
        x[i] = stoi(input);
        file >> input;
        y[i] = stoi(input);
        file >> input;
        directions[i] = input;
        file >> input;
        tips[i] = input;

        i++;
    }

    for(i=0;i<7;i++){
        //cout << x[i] << " ";
        //cout << y[i] << " ";
        //cout << directions[i] << " " << endl;
        cout << tips[i] << " (" << x[i] << " " << y[i] << " " << directions[i] << ") ";
        cout << endl;
        cout << endl;
    }

    read_my_work(mywork);




    int ct1 = 0; //counter1
    int curx=x[ct1];
    int cury=y[ct1];
    char tmp1 = ' ';
    //cout << endl;
    //cout << "pion: " << curx << " ";
    //cout << "poziom: " << cury << " " << endl;
    //cout << tips[ct1] << endl;
    cout << endl;
    i=0;
    string direction = directions[ct1];
    while(i<50)
    {
        cout << "Aktualna pozycja: " << curx << " " << cury << endl;
        cout << "Wpisz znak(Jesli chcesz zmienic pytanie, wpisz 1. Jesli chcesz wyswietlic pytania, wpisz 2): ";
        cin >> tmp1;
        if(tmp1 == '1')
        {
            cout << "Wybierz numer pytania od 0 do 6: " << endl;
            cin >> ct1;
            curx = x[ct1];
            cury = y[ct1];
        }else if(tmp1 == '2')
        {
            read_questions(tips,directions,x,y);
        }else if(tmp1 == xword[ cury ][ curx ])
        {
            if(directions[ct1] == "pion")
            {
                mywork[cury][curx] = tmp1;
                cury += 1;
            }
            else if(directions[ct1] == "poziom")
            {
                mywork[cury][curx] = tmp1;
                curx += 1;
            }
            read_my_work(mywork);
        }else if(tmp1 != '1' && tmp1 != '2'  && tmp1 != xword[ cury ][ curx ])
        {
            cout << "Wpisano nie to co czeba, dawaj jeszcze raz";
        }
        i++;
        cout << endl;
    }











    //vector<string> lines;
/*
    if (file.is_open())
    {
        getline (myfile,tmpline);
        line0 >> myfile;
        line1 >> myfile;
        myfile.close();


    }

    else cout << "Unable to open file";
*/
    return 0;
}
