#include <iostream>

using namespace std;
int main() {
    string cad=" fs    7jgfh434 dfgdfg   normalizame    por   favor   ";
    int j=0;
    bool n;
    for(int i=0; i<cad.length()-1; i++) {
        n=true;
        int lon=0;
        while(n) {
            if(cad[i]!=' ' && i<cad.length()-1) {
                cout<<cad[i];
                i++;
                lon++;
            }
            if(cad[i]==' ') {
                n=false;
                if(lon>0) {
                    cout<<" ";
                }
            }
        }
    }
    return 0;
}


