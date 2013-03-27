#include <iostream>
#include <cstdlib>


using namespace std;

void inicializar(int tablero[7][7],int x,int y)
{
    int i,j;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            tablero[i][j]=0;

        }
    }

    tablero [x][y]=2;
    tablero [2][2]=1; // Las casillas con los peones tienen valor 1
    tablero [2][5]=1;
    tablero [5][2]=1;
    tablero [5][5]=1;
    cout<<"x funcion: "<<x <<endl;
    cout<<"y funcion: "<<y <<endl;

}

int completo(int peo[7][7])     //funcion para verificar si el tablero esta completo
{
    int i,j,contador=0;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(peo[i][j]==1 || peo[i][j]==2)
                contador++;
        }
    }

    if(contador==64)
      {
         cout<<"esta completo"<<endl;
         cout<<"contador: "<<contador<<endl;
         return 1;
      }
    else
    {
       cout<<"no esta completo"<<endl;
       cout<<"contador: "<<contador<<endl;
       return 0;
    }

}

int validar_posicion(int x, int y)
{
   if(x==2 && y==2 || x==2 && y==5 || x==5 && y==2 || x==5 && y==5 )
        return 0;
    else


        return 1;

}

void mostrar(int tablero[7][7])
{
   int i,j,contador=0;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            cout<<"Posicion: ["<<i<<","<<j<<"]: "<<tablero[i][j]<<endl;
            contador++;

        }
    }
    cout<<"Cantidad de casillas: "<<contador <<endl;
}

int main()
{

    int x,y,movimiento,contador=0,inicio=0;
    int tablero[7][7];

    while(inicio==0)
    {

    cout<<"Ingrese posicion x: ";
    cin>>x;
    cout<<"Ingrese posicion y: ";
    cin>>y;

    if(validar_posicion(x,y))
      {
           cout<<"x: "<<x <<endl;
           cout<<"y: "<<y <<endl;
       inicializar(tablero,x,y);
     //  tablero[x][y]=2;
       inicio=1;
      }

    }


     mostrar(tablero);
     cout<<"aqui!!!"<<endl;
     system("pause"); // --------------------------------------------------------------------
     int i=0;


   // while(completo(tablero)!=1)
   while(i<1000)
    {

    movimiento=(1 + rand() % 8);    // Elige al azar uno de los 8 movimientos posibles

    if(movimiento==1)
    {
       if(tablero[x-1][y+2]!=1 && x-1>=0 && y+2<=7)
       {
        tablero[x=x-1][y=y+2]=2;  // en la posicion que queda el caballo se le asigna valor 2
        contador++;
       }
    }

    if(movimiento==2)
    {
        if(tablero[x+1][y+2]!=1 && x+1<=7 && y+2<=7)
        {
         tablero[x=x+1][y=y+2]=2;
         contador++;
        }
    }
    if(movimiento==3)
    {
        if(tablero[x+2][y-1]!=1 && x+2<=7 && y-1>=0)
        {
        tablero[x=x+2][y=y-1]=2;
        contador++;
        }
    }

    if(movimiento==4)
    {
        if(tablero[x+2][y+1]!=1 && x+2<=7 && y+1<=7)
        {
        tablero[x=x+2][y=y+1]=2;
        contador++;
        }
    }
    if(movimiento==5)
    {
         if(tablero[x+1][y-2]!=1 && x+1<=7 && y-2>=0)
         {
             tablero[x=x+1][y=y-2]=2;
             contador++;
         }

    }
    if(movimiento==6)
    {
        if(tablero[x-1][y-2]!=1 && x-1>=0 && y-2>=0)
        {
            tablero[x=x-1][y=y-2]=2;
            contador++;
        }

    }
    if(movimiento==7)
    {
        if(tablero[x-2][y+1]!=1 && x-2>=0 && y+1<=7)
        {
            tablero[x=x-2][y=y+1]=2;
            contador++;
        }

    }
    if(movimiento==8)
    {
        if(tablero[x-2][y-1]!=1 && x-2>=0 && y-1>=0)
        {
          tablero[x=x-2][y=y-1]=2;
          contador++;
        }

    }
    cout<<"Movimiento: ["<<x<<","<<y<<"]"<<endl;

     i++;
    }
   cout<<"Numero de movimientos: "<<contador <<endl;
   mostrar(tablero);
   completo(tablero);
    return 0;
}
