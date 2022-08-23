#include <iostream>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;

int main(){

    float c = 299792458, v = 299000000;
    float gamma = 1/sqrt(1-pow(v,2)/pow(c,2));

    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // stores the local time of the computer.

    int seconds = (timePtr->tm_sec);
    int minutes = (timePtr->tm_min);
    int hrs = (timePtr->tm_hour);


////////////////////////////////////////////
        //pentru ceasul din sistemul S' cinematic(asa cum il vedem noi ticaind din sistemul S)
 cout<<endl;

while (true){

 system("cls");

        cout << "La o viteza relativa a SR tau de cca "<<v<<" m/s;"<<endl;
        cout << "Asa pare din punctul meu de vedere ca trece timpul in sistemul tau de referinta; ";
        cout << " " << hrs << " : " << minutes << " : " << seconds << " " << endl;

        seconds++;

        if (seconds >= 60){

            seconds = 1;
            minutes++;
        }

        if (minutes >= 60){
            minutes = 0;
            hrs++;
        }
        // This increases the hours
        if (hrs > 24){
            hrs = 00;
        }

        Sleep(1000*gamma);

}

    return 0;
}
