#include <bits/stdc++.h>
#include <sstream>
using namespace std;
int contarcadenas(string cadena)
{
    int cont=1;
    for(int i=0; i<cadena.length()-1; i++)
    {

        if(cadena[i]==' ')
        {
            cont++;
        }
    }
    return cont;
}
bool ordenarxCantidad(pair<string,int>  a,pair<string,int> b)
{

    return a.second>b.second;

}
class MatchMaker
{

public:
    vector<string> getBestMatches(vector<string> members,string StringCurrentUser,int sf);

};

vector<string> MatchMaker::getBestMatches(vector<string> members,string StringCurrentUser,int sf)
{
    stringstream s;
    char op[1000];
    vector<char> opciones;

    vector<char> op1[1000];

    vector<pair<char,char> > generos;
    vector<string> nombres;
    vector<pair<string,int> >seleccionados;
    vector<string> nomselecc;
    string nombre;
    char opcion;
    char genero1;
    char genero2;
    int id;

    for(int i=0; i<members.size(); i++)
    {
        cout<<members[i]<<"\n";
        s<<members[i];
        s>>nombre>>genero1>>genero2;

        generos.push_back(pair<char,char>(genero1,genero2));

        if(nombre==StringCurrentUser)
        {
            id=i;
        }
        nombres.push_back(nombre);


        for(int j=0; j<contarcadenas(members[i])-3; j++)
        {
            s>>op[j];
            op1[i].push_back(op[j]);
        }
    }
    int cont;
    cout<<"\n";
    for(int i=0; i<members.size(); i++)
    {
        if(generos[id].second==generos[i].first)
        {
            cout<<i;
            for(int j=0; j<members.size()-3; j++)
            {
                cont=0;
                if(op1[id][j]==op1[i][j])
                {
                    cont++;

                }

            }
            cout<<cont;
            if(cont>=sf)
            {
                seleccionados.push_back(pair<string,int>(nombres[i],cont));
            }
        }
    }

    sort(seleccionados.begin(),seleccionados.end(),ordenarxCantidad);


    for(int i=0; i<seleccionados.size(); i++)
    {
        string nombre=seleccionados[i].first;
        nomselecc.push_back(nombre);
    }
    return nomselecc;
}



string usuarios[]= {"BETTY F M A A C C",
                    "TOM M F A D C A",
                    "SUE F M D D D D",
                    "ELLEN F M A A C A",
                    "JOE M F A A C A",
                    "ED M F A D D A",
                    "SALLY F M C D A B",
                    "MARGE F M A A C C"
                   };


int main()
{
    MatchMaker maker;
    vector<string> us;
    int  dim=sizeof(usuarios)/sizeof(usuarios[0]);
    for(int i=0; i<dim; i++)
    {
        string cad=usuarios[i];
        us.push_back(cad);
    }
    vector<string> res;
    res=maker.getBestMatches(us,"BETTY",1);

    for(int i=0; i<res.size(); i++)
    {

        cout<<res[i]<<" ";
    }
}


