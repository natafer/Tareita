#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream> 

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
    tablero [x][y]=2; // Casillas por donde pasa el caballo
    tablero [2][2]=1; // Las casillas con los peones tienen valor 1
    tablero [2][5]=1;
    tablero [5][2]=1;
    tablero [5][5]=1;
}

int completo(int tabl[7][7])     //funcion para verificar si el tablero esta completo
{
    int i,j,contador=0;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {         
          if(tabl[i][j]!=0)
                contador++;  // cuenta todas las casillas que tienen un valor distinto a 0, es decir, por donde hay un peon o por donde ha pasado el caballo 
        }
    }
    if(contador==64)
      {
         cout<<"Se paso por todas las casillas del tablero"<<endl;    
         return 1;
      }
         else
      {
         return 0;
      }
}

int validar_posicion(int x, int y)
{
   if(x==2 && y==2 || x==2 && y==5 || x==5 && y==2 || x==5 && y==5 || x<0 || y<0 || x>7 || y>7) // Ubicaciones donde no puede ubicarse el caballo el iniciar el tablero
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
            cout<<"Posicion: ["<<i<<","<<j<<"]: "<<tablero[i][j]<<endl; // recorre todas las posiciones del tablero y muestra el valor de la casilla
            contador++;
        }
    }
    cout<<"Total de casillas: "<<contador <<endl;
}

int main()
{

    int tablero[7][7],x,y,movimiento,contador=0,inicio=0,a=0,b=0;
    ofstream fs("movimientos.txt"); 
    srand((unsigned)time(0));

 while(inicio==0)
{
    cout<<"Ingrese posicion x: ";
    cin>>x;
    cout<<"Ingrese posicion y: ";
    cin>>y;
 
      a=validar_posicion(x,y);
    if(a==1)
      {
       inicializar(tablero,x,y);
       tablero[x][y]=2;
       inicio=1;       
      }
}
    mostrar(tablero);
    system("pause");
    
    b=completo(tablero);
    while(b!=1)
{
    movimiento=(1 + rand() % 8);    // Elige al azar uno de los 8 movimientos posibles
    cout<<"Movimiento: "<<movimiento<<endl;

    if(movimiento==1)
    {
       if(tablero[x-1][y+2]!=1 && x-1>=0 && y+2<=7)
       {
        x=x-1;
        y=y+2;
        tablero[x][y]=2;  // en la posicion que queda el caballo se le asigna valor 2
        cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
        fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
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
         cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
         fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
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
        cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
        fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
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
            cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
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
            cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
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
            cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
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
            cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
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
            cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl; 
            contador++;
        }
    }
      
       b=completo(tablero);
    
}
   fs.close();
   cout<<"Numero de movimientos: "<<contador <<endl;
   system("pause"); 
   mostrar(tablero);
   system("pause");
}
