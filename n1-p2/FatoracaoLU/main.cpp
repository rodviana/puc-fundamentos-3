#include <iostream>
using namespace std;

int main()
{
    int i,n=2,k;
    double soma,m, y[2],x[2];
    double a[2][2] = {{1,2},{3,5}};
    double L[2][2] ={{1,0},{0,1}};
    double b[2] = {4,11};

     // L recebe uma matriz identidade

    for(k = 1;k<=n;k++){
        for(i = k + 1; i!=n; i++){ // percorre os elementos a frente da diagonal principal; pra k=0, i vai de 1 ate n.
                                    // 		pra k=0, i vai de 1 ate n.
                                    // 		pra k=1, i vai de 2 ate n.
            m = a[i][k]/a[k][k]; // dividindo o elemento da linha pelo elemento da diagonal principal
            a[i][k] = 0; // zerando os elementos embaixo da diagonal principal
            L[i][k] = m; // colocando o elemento m na diagonal de baixo
        }
            for(int j = k + 1; j!=n; j++){ // aqui parece q ele faz Gauss
                a[i][j] = a[i][j] - m*a[k][j];
            }
    }

    for(int i=0;i<n; i++){
        for(int j=0;j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"so com os elementos da diagonal de cima"<<endl;
    // saindo dos for, A esta so com os elementos da diagonal de cima,
    //e L com os elementos da diagonal de baixo e diagonal principal com um, por causa da identidade do comeco

    //Queremos a solução para um determinando A e b. Os passos são os seguintes:
    //Primeiro, resolvemos Ly=b para y
    //Segundo, resolvemos Ax=y para x.
    //Ly = b, para y = Ux.

    y[0] = b[0];

    for(i=1;i!=n;i++){  // entao ele percorre L pra fazer  L*y
        soma = 0;
        for (int j=0;j!=i;j++){
            soma=soma+L[i][j]*y[j]; //fazendo a multiplicacao
            y[i]=b[i] - soma;
            x[n-1]=y[n-1]/a[n-1][n-1]; // salva o valor de x no vetor x
        }
    }

    cout<<"x[n-1] = "<<x[n-1]<<endl;
    for(int i=0;i<n;i++)cout<<y[i]<<" ";
    cout<<endl;


    for(i=n-1;i!=1;i--){ // percorre A pra A*x
        soma = 0;
        for(int j=i+1;j!=n;j++){
            soma=soma+a[i][j]*x[j];
            x[i]=(y[i]-soma)/a[i][i];
        }
    }
    for(int i=0;i<n;i++)cout<<"x= "<<x[i]<<" ";
    cout<<endl;
    return 0;
}
