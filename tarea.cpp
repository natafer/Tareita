#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream> 

using namespace std;

void inicializar(int tablero[7][7],int x,int y)  // crea el tablero
{
    int i,j;

    for(i=0;i<8;i++) // recorre el tablero
    {
        for(j=0;j<8;j++)
        {
            tablero[i][j]=0;  // asigna el valor 0 a cada casilla, en nuestro caso indica que el tablero está vacio
        }
    }
    tablero [x][y]=2; // Casillas por donde pasa el caballo
    tablero [2][2]=1; // Las casillas con los peones tienen valor 1
    tablero [2][5]=1;
    tablero [5][2]=1;
    tablero [5][5]=1;
}

int completo(int tabl[7][7])     //función para verificar si el tablero esta completo
{
    int i,j,contador=0;

    for(i=0;i<8;i++)  // recorre el tablero
    {
        for(j=0;j<8;j++)
        {         
          if(tabl[i][j]!=0)
                contador++;  // cuenta todas las casillas que tienen un valor distinto a 0, es decir, por donde hay un peon o por donde pasó o está el caballo 
        }
    }
    if(contador==64)
      {
         cout<<endl<<"*(Lo anterior son las posiciones y movimientos realizados)"<<endl;
         cout<<endl<<"El caballo paso por todas las casillas del tablero"<<endl;    
         return 1;
      }
         else
      {
         return 0;  // si no llega al número 64, no ha pasado por todas las casillas el caballo
      }
}

int validar_posicion(int x, int y) // revisa si la posición inicial del caballo es posible
{
   if(x==2 && y==2 || x==2 && y==5 || x==5 && y==2 || x==5 && y==5 || x<0 || y<0 || x>7 || y>7) // son las posiciones donde estan ubicados los peones y los límites del tablero
        return 0;
    else
        return 1;  // posición válida
}

void mostrar(int tablero[7][7])
{
   int i,j,contador=0;

    for(i=0;i<8;i++) // recorre el tablero
    {
        for(j=0;j<8;j++)
        {
            cout<<"Posicion: ["<<i<<","<<j<<"]: "<<tablero[i][j]<<endl; // muestra todas las posiciones del tablero y su valor
            contador++;
        }
    }
    cout<<"Total de casillas: "<<contador <<endl;
}

int main()
{

    int tablero[7][7],x,y,movimiento,contador=0,inicio=0,a=0,b=0;
    ofstream fs("movimientos.txt");    //crea un documento txt con los movimientos (se ubica donde esta el main)
    fs<<"Movimientos del caballo"<<endl <<endl;
    srand((unsigned)time(0));

 while(inicio==0) // ciclo para dar una ubicación válida al caballo
{
    cout<<endl<<"POSICION EN LA QUE PARTIRA EL CABALLO"<<endl;
    cout<<"(Debe ser entre 0 y 7)"<<endl<<endl;
    cout<<"Ingrese posicion x: ";
    cin>>x;
    cout<<"Ingrese posicion y: ";
    cin>>y;
 
      a=validar_posicion(x,y);
    if(a==1)
      {
       inicializar(tablero,x,y);
       inicio=1;       
      }
      
}
   
    cout<<endl<<" POSICION ACTUAL Y MOVIMIENO REALIZADO"<<endl;
    b=completo(tablero);
   fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
    
    while(b!=1)
{
   
    movimiento=(1 + rand() % 8);    // Elige al azar uno de los 8 movimientos posibles

    if(movimiento==1)
    {
       if(tablero[x-1][y+2]!=1 && x-1>=0 && y+2<=7) // revisa si al hacer el movimiento se cae en posicion de algunos de los peones y si se está dentro de los límites del tablero 
       {
        x=x-1; // mueve al caballo en la coordenada x
        y=y+2; // mueve al caballo en la coordenada y
        tablero[x][y]=2;  // en la posicion que queda el caballo se le asigna valor 2
        cout<<"Movimiento: "<<movimiento<<endl;
        cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
        fs<<"Movimiento: "<<movimiento<<endl;    // envia el numero del movimiento al archivo txt
        fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  // envia la posicion resultante del movimiento al txt
        contador++; // cuenta la cantidad de movimientos realizados 
       }
    }
    if(movimiento==2)
    {
        if(tablero[x+1][y+2]!=1 && x+1<=7 && y+2<=7) // revisa si al hacer el movimiento se cae en posicion de algunos de los peones y si se está dentro de los límites del tablero 
        {
         x=x+1;
         y=y+2;
         tablero[x][y]=2;
         cout<<"Movimiento: "<<movimiento<<endl;
         cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
         fs<<"Movimiento: "<<movimiento<<endl;  
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
        cout<<"Movimiento: "<<movimiento<<endl;
        cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
        fs<<"Movimiento: "<<movimiento<<endl;
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
            cout<<"Movimiento: "<<movimiento<<endl;
            cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
            fs<<"Movimiento: "<<movimiento<<endl;
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
            cout<<"Movimiento: "<<movimiento<<endl;
            cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
            fs<<"Movimiento: "<<movimiento<<endl;
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
            cout<<"Movimiento: "<<movimiento<<endl;
            cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
            fs<<"Movimiento: "<<movimiento<<endl;
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
            cout<<"Movimiento: "<<movimiento<<endl;
            cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
            fs<<"Movimiento: "<<movimiento<<endl;
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
            cout<<"Movimiento: "<<movimiento<<endl;
            cout<<"Posicion: ["<<x<<","<<y<<"]"<<endl;  
            fs<<"Movimiento: "<<movimiento<<endl;
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl; 
            contador++;
        }
    }       
       b=completo(tablero); // ve si el tablero está completo o no, de no estarlo continúa el ciclo
}

   
   fs.close(); // cierra el archivo txts
   cout<<endl<<"Cantidad de movimientos: "<<contador <<endl<<endl; // indica la cantidad de movimientos hechos para recorrer el tablero completo
   system("pause"); 
   cout<<endl<<endl<<endl<<"----VALORES DE CADA CASILLA AL TERMINAR EL RECORRIDO----"<<endl<<endl;
   mostrar(tablero);
   system("pause");
}
