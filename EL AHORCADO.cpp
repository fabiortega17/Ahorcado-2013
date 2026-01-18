//El ahorcado

#include <fstream>
#include <conio.h>
#include <winbgim.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>


//void abrirArchivo(char *nombre);
using namespace std;

// Funciones Globales

int valor1;
int valor;
char texto[100];
int contaperdidas=0;
int contapartidas=0;
int contaGanaste=0;
int conarchi=0;
int conarchi2=0;
int contafinal=0;

// Puntaje

int puntaje1=0;
int puntaje=0;
int conpu=0;
int punmenor=0;
int pun1,pun2,pun3,pun4,pun5;
// Declaracion de funciones

int menu();//Menú del juego
int juegoAhorcado();//Diseño en la pantalla grafica
int palabrasDirectas();//Da las palabras de cualquier género
int palabras();//Da las palabras depende del genero
int buscarPalabra();//Da las palabras aleatorias
int buscarElemtos(int vector[], int tam);//Busca secuencialmente para la búsqueda aleatoria
int puntajeT();//Lee y actualiza el puntaje
int archilectu();//Abre el archivo del puntaje
int leerArchivo();//Lee el archivo del puntaje



ofstream APuntaje;

int main(void){ 
    
    
    printf("%i:",menu());


}//FIN FUCION MAIN



int menu(){
    int opcion;
    int opcion2;
    int conObci=0;
    int contaT=0;
    int contf2=0;
    
    int opc;
    int seguir=1;
    while(seguir==1)
    {
    
    do{   system("color 3F");         
          system("cls");
          printf("\t\t----------EL AHORCADO-------\n\n");
               
            printf("\t 1-JUGAR\n");
            printf("\t 2-GENERO DE PALABRAS\n");    
            printf("\t 3-VER PUNTAJES\n");
            printf("\t 4-SALIR\n");
            
            printf("\t\n Seleccionar una opcion: ");
            cin>>opc;
            
     }while(opc<1 || opc>4);
            
            do{
            
            if(opc==1){//system("color 1F");
                        if(contaT>=2){conObci=0;
                                      punmenor=0;           
                                      }
                        system("cls");
                         
                        printf("\t\t----------1-JUGAR----------\n\n");
                       
                        contafinal=contafinal+1;
                        if(conObci==0){palabrasDirectas();}
                      
                     printf("%i",juegoAhorcado());
                      contapartidas=contapartidas+1;
                          if(conObci==0){if(contaGanaste==1){puntaje=puntaje+1000;}}
                          if(punmenor==1){ if(contaGanaste==1){puntaje=puntaje+500;}}
                       
                       if(contaperdidas>1 && contaperdidas<3 && contaGanaste==0){
                                                                            
                                                                            printf("\n\n\n\t\t   %i Intento de 3",contaperdidas);
                                                                            getchar();
                                                                            }
                       printf("\n\n\t\t   Tu Puntaje Actual Es: [ %i ]\n\n",puntaje);
                        getchar();  
                        
                        if(contaperdidas==3){
                                             do{system("cls");
                                                 printf("\n\t\t            PERDEDOR");
                                                 printf("\n\n\t\t        FIN DEL JUEGO");             
                                                 printf("\n\n\t\t    Tu puntaje fue: [ %i ]",puntaje);
                                                 puntajeT();
                                                 printf("\n\n\tDesea Reiniciar el Juego? ( 1-> SI | 2-> NO )");
                                                  printf("\n\n\t\t               ---->  ");
                                                 cin>>opcion;
                                                }while(opcion<1 || opcion>2);
                                                
                                               if(opcion==1){contapartidas=0;
                                                             contaperdidas=0;
                                                             puntaje=0; 
                                                             }
                                              if(opcion==2){return 0;}
                                             }
                      
                                          
                     if(contapartidas<=3){puntaje1=puntaje;}
                     if(contapartidas==4||contaperdidas==0 ){contaperdidas=1;}
                     if(contaperdidas==1||contapartidas>5){contapartidas=contapartidas+1;}
                                                            
                        conpu=0;                                     
                          contf2=0;                  
                        fflush(stdin);
                        
                        }
                        
            if(opc==2){//system("color B0");                      
                        
                        
                        system("cls");
                        printf("\t\t----------2-GENERO DE PALABRAS----------\n\n");
                        palabras();
                        conObci=1;
                        contaT=0;
                        punmenor=1;
                        contf2=2;
                        opc=1;
                        fflush(stdin);
                        getchar();
                        
                        
                      }
                      
                   
             
            if(opc==3) 
                      {int opc2;
                        do{system("color 3F");     
                            do{ system("color 3F");
                                  system("cls");
                                  printf("\t\t----------3-VER PUNTAJE-------\n\n");
                                       
                                    printf("\t 1-PUNTAJE ACTUAL\n");
                                    printf("\t 2-RECORD\n");    
                                    printf("\t 3-BORRAR RECORD\n");
                                    printf("\t 4-VOLVER AL MENU PRINCIPAL");
                                    printf("\n\t\n Seleccionar una opcion: ");
                                    cin>>opc2;
                               }while(opc2<1 || opc2>4);
                               
                                if(opc2==1){
                                             
                                              system("cls");
                                              printf("\n\t\t----------1-VER PUNTAJE ACTUAL-------\n");
                                              printf("\n\n\t\t   Tu Puntaje Actual Es: [ %i ]\n\n",puntaje); 
                                            }
                                            
                                if(opc2==2){     
                                                  if(conpu==0){
                                                  system("cls");
                                                  printf("\n\t\t----------2-VER RECORD-------\n");
                                                  puntajeT();
                                                  conpu=1;}
                                                  
                                                  if(conpu==2){system("cls");
                                                  printf("\n\t\t----------2-VER RECORD-------\n"); 
                                                    
                                                              conarchi=1;
                                                              leerArchivo();
                                                              conarchi=0;}
                                conpu=2;
                                                }  
                                                
                                                   
                         if(opc2==3){
                                     system("color FC");  
                                     system("cls");
                                     ofstream Puntaje;
                                     Puntaje.open("PUNTAJE-AHORCADO.txt");//abrir un archivo
                        
                                        if(!Puntaje){printf("Error al tratar de abrir el archivo");}//por si no lo guarda bien
                                        else{printf("\n\n\t\t SE BORRARON LOS RECORD DE MANERA EXITOSA\n"); //cuando entra en la funcion
                                             Puntaje.close();//cerrar un archivo
                                             }
                                                     getchar();
                                                     }
                                                     fflush(stdin);
                                                getchar();
                                                
                      }while(opc2!=4);                        
                       fflush(stdin);                                                                 
             }
            
            
            
            if (opc==4){conarchi2=1;
                        puntajeT();
                        seguir=4;
                        }
                       contaT=contaT+1;
          }while(contf2==2);
         }//fin wille
    
}//fin funcion menu


int juegoAhorcado(){
    
    
    

int x=20;
char letra[100];


    
    printf("\n \t\t   ----- AHORCADO ------ \n");
    cout<< "\n";
    cout<< "\n";
    
    
   
   
int n=strlen(texto);
cout<< "\n\n Numero de letras: " <<n;
char otro[n];

for (int i=0;i<n; i++){
                        otro[i]='-';
                        }


int ce=0;
ce=0;
int completa=0;
completa=0;
int encontrado=0;
encontrado=0;
int contaGa=0;
contaGa=0;

//Inicio pestaña del juego

    initwindow(400,400);
    setcolor(YELLOW);
    settextstyle(0,0,2);
    outtextxy(20,250,"= EL AHORCADO =");
    outtextxy(50,30,otro);
    outtextxy(20,250,"= EL AHORCADO =");



   
  
    while (ce < 5 && completa==0)
    {
         
                  cout<< " \n Escriba la letra para completar la palabra ? \n";
                  cout << "\n";
                  cin >> letra;
                  encontrado=0;
                  
          for (int i1=0;i1<n; i1++){
                           if(texto[i1]==letra[0]){
                                                  encontrado=1;
                                                  otro[i1]=letra[0];
                                                  cout << "\n";
                                                  cout << " Letra acertada ";
                                                  cout << "\n";
                                                 
                                                 }
                                                 
                                 }
contaGa=contaGa+1;

//DISEÑO DEL MUÑEQUITO

if(encontrado==0){
                  contaGa=0;
                  ce=ce+1;
            switch(ce) {
                        case 1: circle(100,90,20);
                                break;
                                
                        case 2: line(100,110,100,180);
                               
                                break;
                        case 3: line(100,125,65,170);
                                line(100,125,135,170);
                                
                                break;
                        case 4: line(100,180,60,220);
                                line(100,180,140,220);
                                
                                break;
                        case 5:
                                line(100,120,140,120);
                                line(140,120,140,50);
                                line(140,50,45,50);
                                line(45,50,45,240);
                                line(45,240,160,240);
                                setcolor(LIGHTGREEN);
                                line(90,80,110,100);
                                line(90,100,110,80);
                                outtextxy(10,250,"!!!! PERDEDOR !!!!");
                                outtextxy(10,280," LA PALABRA CORECTA ES:");
                                setcolor(WHITE);
                                outtextxy(20,320,texto);
                                contaperdidas=contaperdidas+1;
                                contaGanaste=0;
                                
                               break;
                        }
                }
            completa=1;
            
            for (int i2=0;i2<n;i2++){
                                    if(otro[i2]=='-'){ completa=0;}
                                    
                                    }
            cout << otro <<endl;
            outtextxy(50,30,otro);
            outtextxy(50,30,otro);
           
           
           
             
                        
       }//FIN WHILE
     
if(contaGa>1){setcolor(WHITE);      
              outtextxy(10,250," FELICIDADES GANASTE !!!!");
              outtextxy(50,30,texto);
              outtextxy(50,30,texto);
              contaGanaste=1;
              }
getchar();
system("pause");
closegraph();

initwindow(100,100);
setcolor(4);
    settextstyle(0,0,1);
    outtextxy(20,250,"= EL AHORCADO =");
    outtextxy(50,30,otro);
    outtextxy(20,250,"= EL AHORCADO =");
circle(100,90,20);
line(100,110,100,180);line(100,125,65,170);
line(100,125,135,170);
line(100,180,60,220);
line(100,180,140,220);
line(100,120,140,120);
line(140,120,140,50);
line(140,50,45,50);
line(45,50,45,240);
line(45,240,160,240);
setcolor(2);
line(90,80,110,100);
line(90,100,110,80);
outtextxy(10,250,"!!!! PERDEDOR !!!!");
outtextxy(10,280," LA PALABRA CORECTA ES:");
setcolor(1);
outtextxy(20,320,texto);
   
closegraph();
return 0;
    
}//fin funcion juego

int palabrasDirectas(){
    
    int codigo[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
                  40,41,42,43,44,45,46,47,48};
    char *Palabras[]= {"adelaida","bonifacio","camilo","margarita","monica","valentina","constantino","enrique",
                      "sinfonia","modulacion","guitarra","interpretacion","armonia","instrumento","afinacion","melodia",
                      "galeria","imaginacion","poesia","literatura","dibujo","ceramica","escultura","precolombino",
                      "competencia","contrincante","futbol","entrenador","estadio","rivalidad","paracaidismo","motociclismo",
                      "straufemberg","willoughby","matthews","boylestad","kemmerly","bulgakov","reynolds","saint"
                      "gastronomia","culinaria","preparacion","estufa","cucharon","alimentos","estofado","condimento"};
         srand (time(NULL)); 
         int vectorP1[48];
    
         for(int i=0; i<48; i++){
            
            vectorP1[i] =1+rand()%(49-1);
            }
            for(int j=0; j<1; j++)
            {
             valor1=vectorP1[j];
             }
    
    
    valor=valor1;
    int indice=buscarElemtos(codigo,48);
    strcpy(texto,Palabras[indice]);
   
  if(indice>=0){
                        printf("\n PALABRA: "); 
                        puts (Palabras[indice]);}
    
}//fin funcion palabras directas

//INICIO FUNCION PALABRAS
int palabras(){
    int opc;
    do{
          system("cls");
          printf("\t\t----------GENERO DE PALABRAS-------\n\n");
               
            printf("\t 1-NOMBRES\n");
            printf("\t 2-APELLIDOS\n");
            printf("\t 3-MUSICA\n");    
            printf("\t 4-ARTES\n");
            printf("\t 5-DEPORTES\n");
            printf("\t 6-COCINA\n");
            
            
            printf("\t\n Seleccionar una opcion: ");
            cin>>opc;
       }while(opc<1 || opc>6);      
    
            if(opc==1){  
                         int codigo[]={1,2,3,4,5,6,7,8};
                         char *Nombre[]= {"adelaida","fernando","camilo","margarita","monica","valentina","constantino","enrique"};
                         buscarPalabra();
                         int indice=buscarElemtos(codigo,5);
                         strcpy(texto,Nombre[indice]);
                         int N=strlen(texto);
                         printf("\n PALABRA DEL GENERO [ NOMBRES ] DE: %i letras\n",N);
                          fflush(stdin);
                         //if(indice>=0){
                         //printf("\n PALABRA: "); 
                         //puts (Musica[indice]);}
                        }
            
            if(opc==2){  
                         int codigo[]={1,2,3,4,5,6,7,8};
                         char *Apellidos[]={"straufemberg","willoughby","matthews","boylestad","kemmerly","bulgakov","reynolds","saint"};
                         buscarPalabra();
                         int indice=buscarElemtos(codigo,5);
                         strcpy(texto,Apellidos[indice]);
                         int N=strlen(texto);
                         printf("\n PALABRA DEL GENERO [ APELLIDOS ] DE: %i letras\n",N);
                          fflush(stdin);
                         //if(indice>=0){
                         //printf("\n PALABRA: "); 
                         //puts (Musica[indice]);}
                        
                         }
            if(opc==3){  
                         int codigo[]={1,2,3,4,5,6,7,8};
                         char *Musica[]={"sinfonia","modulacion","guitarra","interpretacion","armonia","instrumento","afinacion","melodia"};
                         buscarPalabra();
                         int indice=buscarElemtos(codigo,8);
                         strcpy(texto,Musica[indice]);
                         int N=strlen(texto);
                         printf("\n PALABRA DEL GENERO [ MUSICA ] DE: %i letras\n",N);
                          fflush(stdin);
                         //if(indice>=0){
                         //printf("\n PALABRA: "); 
                         //puts (Musica[indice]);}
                         
                      }
            if(opc==4){  
                         int codigo[]={1,2,3,4,5,6,7,8};
                         char *Arte[]={"galeria","imaginacion","poesia","literatura","dibujo","ceramica","escultura","precolombino"};
                         buscarPalabra();
                         int indice=buscarElemtos(codigo,5);
                         strcpy(texto,Arte[indice]);
                         int N=strlen(texto);
                         printf("\n PALABRA DEL GENERO [ ARTES ] DE: %i letras\n",N);
                          fflush(stdin);
                         //if(indice>=0){
                         //printf("\n PALABRA: "); 
                         //puts (Musica[indice]);}
                         }
            if(opc==5){  
                         int codigo[]={1,2,3,4,5,6,7,8};
                         char *Deporte[]={"competencia","contrincante","futbol","entrenador","estadio","rivalidad","paracaidismo","motociclismo"};
                         buscarPalabra();
                         int indice=buscarElemtos(codigo,5);
                         strcpy(texto,Deporte[indice]);
                         int N=strlen(texto);
                         printf("\n PALABRA DEL GENERO [ DEPORTES ] DE: %i letras\n",N);
                          fflush(stdin);
                         //if(indice>=0){
                         //printf("\n PALABRA: "); 
                         //puts (Musica[indice]);}
                        
                         }
            if(opc==6){  
                         int codigo[]={1,2,3,4,5,6,7,8};
                         char *Cocina[]={"gastronomia","culinaria","preparacion","estufa","cucharon","alimentos","estofado","condimento"};
                         buscarPalabra();
                         int indice=buscarElemtos(codigo,5);
                         strcpy(texto,Cocina[indice]);
                         int N=strlen(texto);
                         printf("\n PALABRA DEL GENERO [ COCINA ] DE: %i letras\n",N);
                         fflush(stdin);
                         //if(indice>=0){
                         //printf("\n PALABRA: "); 
                         //puts (Musica[indice]);}
                        
                         }
    
}//fin funcion palabras

int buscarPalabra(){
   
    srand (time(NULL)); 
    int vectorP[8];
    
     for(int i=0; i<9; i++){
            
            vectorP[i] =1+rand()%(9-1);
            }
    for(int j=0; j<1; j++)
    {
            
            valor1=vectorP[j];
            }
    
    
    valor=valor1;
    
}//Fin funcion buscar palabras

//busqueda secuencial
int buscarElemtos(int vector[], int tam){
     for(int i=0;i<tam;i++){
             if (vector[i]==valor){
                                   return i;
                                   }
                  }
     return -1;
     
     
}//fin funcion busqueda secuencial
     
//inicio puntaje
int puntajeT(){

int vector[5];

leerArchivo();

vector[0]=pun1;
vector[1]=pun2;
vector[2]=pun3;
vector[3]=pun4;
vector[4]=pun5;
vector[5]=puntaje;

if(conarchi2==0){ if(puntaje>pun1){ printf("\n\n\t\t\t   NUEVO RECORD\n");}}
int aux;
char aux2[5][20];

        for(int i=0; i<6; i++){  
                
                for(int j=i, p=0; j<6;p=0, j++){
                        
                        if(vector[i] <= vector[j]){
                                     
                                     aux=vector[i];
                                     vector[i]=vector[j];
                                     vector[j]=aux;
                                     }
                        }
                }
if(conarchi2==0){ 
printf("\n\n\t\t PUNTAJE MAS ALTO ES: [ %i ]\n",vector[0]);  }                     
pun1=vector[0];
pun2=vector[1];
pun3=vector[2];
pun4=vector[3];
pun5=vector[4];

archilectu();
if(conarchi2==0){              
leerArchivo();}
            

}//fin funcion

int archilectu(){//ingresar el archivo

            ofstream APuntaje;
            
            APuntaje.open("PUNTAJE-AHORCADO.txt");
               if(!APuntaje){printf("Error al tratar de abrir el archivo");}//por si no lo guarda bien
               else{//cuando entra en la funcion
 
                   APuntaje<<pun1;
                   APuntaje<<"\n";
                   APuntaje<<pun2;
                   APuntaje<<"\n";
                   APuntaje<<pun3;
                   APuntaje<<"\n";
                   APuntaje<<pun4;
                   APuntaje<<"\n";
                   APuntaje<<pun5;
                   APuntaje<<endl;
               
               APuntaje.close();//cerrar un archivo
                                 }  
 if(conarchi2==0){    
conarchi=conarchi+1;}
}

int leerArchivo(){//leer el archivo
                         
              ifstream APuntajeL;
              APuntajeL.open("PUNTAJE-AHORCADO.txt");
              
              while(!APuntajeL.eof()){ //permitir que el archivo sea leido en su totalidad
                           
                           APuntajeL >> pun1; //llamar el archivo
                           APuntajeL >> pun2;
                           APuntajeL >> pun3;
                           APuntajeL >> pun4;
                           APuntajeL >> pun5;
                          
                           if(!APuntajeL.eof()){
                          
                          if(conarchi==0){
                                                pun1=pun1;
                                                pun2=pun2;
                                                pun3=pun3;
                                                pun4=pun4;
                                                pun5=pun5;
                                                conarchi2=0;
                                                }      
                          if(conarchi==1){
                                                if(pun1>0){printf("\n\n\t\t   Puntaje No 1 es: [ %i ]\n",pun1);
                                                pun1=pun1;}
                                                if(pun2>0){printf("\n\n\t\t   Puntaje No 2 es: [ %i ]\n",pun2);
                                                pun2=pun2;}
                                                if(pun3>0){printf("\n\n\t\t   Puntaje No 3 es: [ %i ]\n",pun3);
                                                pun3=pun3;}
                                                if(pun4>0){printf("\n\n\t\t   Puntaje No 4 es: [ %i ]\n",pun4);
                                                pun4=pun4;}
                                                if(pun5>0){printf("\n\n\t\t   Puntaje No 5 es: [ %i ]\n",pun5);
                                                pun5=pun5;}
                                          }
                                  }
                           APuntajeL.close();
                           } 
conarchi=0;
}

