#include <iostream>
#include <vector>
using namespace std;

vector<int> factoradi(long long int num,int n)
{

    vector<int> aux;
    int i=1;
    long long int res;
    while(i<=num)
    {
        res=num%i;
        num=num/i;
        if(num<=i)
        {
            aux.push_back(res);
            aux.push_back(num);
        }
        else
        {
            aux.push_back(res);
        }
        i++;
    }


    while(aux.size()<n)
    {


        aux.push_back(0);


    }
    return aux;
}

int main()
{
    vector<int> fac;
    vector<int> ini;
    vector<int> sol;
    vector<int> aux;
    int n;
    long long int k;
    while(cin>>n>>k)
    {
        sol.clear();
        ini.clear();
        aux.clear();

        for(int i=0; i<=n; i++)
        {
            ini.push_back(i);
        }


        vector<int> num=factoradi(k,n+1);
        cout<<num.size()<<"\n";
        for(int i=0;i<num.size();i++){
        cout<<num[i]<<" ";
        }
        cout<<"\n";

        if(k==0)
        {

            for(int i=0; i<ini.size(); i++)
            {
                cout<<ini[i]<<" ";
            }
            cout<<"\n";

        }

        else
        {
            fac=factoradi(k,n+1);
            for(int i=fac.size(); i>0; i--)
            {
                aux.clear();

                sol.push_back(ini[fac[i-1]]);
                for(int j=0; j<ini.size(); j++)
                {

                    if(ini[j]!=ini[fac[i-1]])
                    {
                        aux.push_back(ini[j]);
                    }
                }
                ini.clear();

                for(int j=0; j<aux.size(); j++)
                {

                    ini.push_back(aux[j]);
                }

            }
            for(int i=0; i<sol.size()-1; i++)
            {
                cout<<sol[i]<<" ";
            }
            cout<<sol[n];
            cout<<"\n";
        }
    }
    return 0;
}
