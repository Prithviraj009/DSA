//dikstra alogorith for shortest path

#include<iostream>
using namespace std;

void dikstra(int a[3][3])
{
     for(int k=0;k<3;k++)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
               if(a[i][j]>a[i][k]+a[k][j]) 
               {
                   a[i][j]=a[i][k]+a[k][j];
               }
            }
        }
    }
    
}
int main()
{
    int a[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> a[i][j];
        }
    }
    
    dikstra(a);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << a[i][j] << "";
        }
        cout << endl;
    }
    
}
