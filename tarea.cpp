#include <iostream>
#include <cstdlib>
#include <ctime>


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
   cout<<"7,6 en inicializar: "<<tablero[7][6] <<endl;
  //  cout<<"6,7: "<<tablero[6][7] <<endl;
    cout<<"7,7 en inicializar: "<<tablero[7][7] <<endl;
   // cout<<"x funcion: "<<x <<endl;
   // cout<<"y funcion: "<<y <<endl;

}

int completo(int peo[7][7])     //funcion para verificar si el tablero esta completo
{
    int i,j,contador=0;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
          //  if(peo[i][j]==1 || peo[i][j]==2)
          if(peo[i][j]!=0)
                contador++;
        }
    }

    if(contador==64)
      {
         cout<<"esta completo"<<endl;
         cout<<"posiciones utilizadas: "<<contador<<endl;
         return 1;
      }
    else
    {
       cout<<"no esta completo"<<endl;
   //    cout<<"posiciones utilizadas: "<<contador<<endl;
       return 0;
    }

}

int validar_posicion(int x, int y)
{
   if(x==2 && y==2 || x==2 && y==5 || x==5 && y==2 || x==5 && y==5 ) // falta agregar 0<x<7 , 0<y<7
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
   // cout<<"i mostrar: "<<i <<endl;
   // cout<<"j mostrar: "<<j <<endl;
    cout<<"Total de casillas: "<<contador <<endl;
}


int main()
{

    int x,y,movimiento,contador=0,inicio=0;
    int a=0,b=0,c=0,d=0;
    int tablero[7][7];
    srand((unsigned)time(0));


 while(inicio==0)
    {

    cout<<"Ingrese posicion x: ";
    cin>>x;
    cout<<"Ingrese posicion y: ";
    cin>>y;
    if((x || y)<0 || (x||y)>7)
    cout<<"Los numeros ingresados deben ser entre 0 y 7"<<endl;
    else
    
    a=validar_posicion(x,y);
    if(a==1)
      {
 //          cout<<"x: "<<x <<endl;
//           cout<<"y: "<<y <<endl;
       inicializar(tablero,x,y);
     //  tablero[x][y]=2;
       inicio=1;
      }


    }


    mostrar(tablero);
   //  cout<<"aqui!!!"<<endl;
     system("pause"); // --------------------------------------------------------------------
     int i=0;

    cout<<"7,6 en main dp de todo: "<<tablero[7][6] <<endl;
   // cout<<"6,7: "<<tablero[6][7] <<endl;
    cout<<"7,7 en main dp de todo: "<<tablero[7][7] <<endl;

    while(completo(tablero)!=1)

    {

    movimiento=(1 + rand() % 8);    // Elige al azar uno de los 8 movimientos posibles
    cout<<"movimiento :"<<movimiento<<endl;

    if(movimiento==1)
    {
       if(tablero[x-1][y+2]!=1 && x-1>=0 && y+2<=7)
       {
        x=x-1;
        y=y+2;
        tablero[x][y]=2;  // en la posicion que queda el caballo se le asigna valor 2
        contador++;
       }
    }

    if(movimiento==2)
    {
        if(tablero[x+1][y+2]!=1 && x+1<=7 && y+2<=7)
        {
         x=x+1;
         y=y+2;
         tablero[x][y]=2;
         contador++;
        }
    }
    if(movimiento==3)
    {
        if(tablero[x+2][y-1]!=1 && x+2<=7 && y-1>=0)
        {
        x=x+2;
        y=y-1;
        tablero[x][y]=2;
        contador++;
        }
    }

    if(movimiento==4)
    {
        if(tablero[x+2][y+1]!=1 && x+2<=7 && y+1<=7)
        {
            x=x+2;
            y=y+1;
            tablero[x][y]=2;
            contador++;
        }
    }
    if(movimiento==5)
    {
         if(tablero[x+1][y-2]!=1 && x+1<=7 && y-2>=0)
         {
             x=x+1;
             y=y-2;
             tablero[x][y]=2;
             contador++;
         }

    }
    if(movimiento==6)
    {
        if(tablero[x-1][y-2]!=1 && x-1>=0 && y-2>=0)
        {
            x=x-1;
            y=y-2;
            tablero[x][y]=2;
            contador++;
        }

    }
    if(movimiento==7)
    {
        if(tablero[x-2][y+1]!=1 && x-2>=0 && y+1<=7)
        {
            x=x-2;
            y=y+1;
            tablero[x][y]=2;
            contador++;
        }

    }
    if(movimiento==8)
    {
        if(tablero[x-2][y-1]!=1 && x-2>=0 && y-1>=0)
        {
            x=x-2;
            y=y-1;
            tablero[x][y]=2;
            contador++;
        }

    }
    cout<<"Movimiento: ["<<x<<","<<y<<"]"<<endl;

     i++;
    }

    cout<<"Numero de movimientos: "<<contador <<endl;
   mostrar(tablero);
   completo(tablero);
   system("pause");
    return 0;
}

