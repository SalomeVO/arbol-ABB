/*Ingenieria en Sistemas 
  Mercy Salome Vasquez Otiz
  Carnet: 0909-20-5202
  Tercer Semestre*/

//Declaracion de libreras 
#include <iostream>
#include <conio.h>
#include <cstdlib>


using namespace std;

//estructura del nodo
struct nodo{
     int ndo;
     struct nodo *Izq, *Der;
};

typedef struct nodo *ABB;//Es un puntero

//es para crear el nodo
ABB crearNodo(int x){
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->ndo = x;
     nuevoNodo->Izq = NULL; //Inicializamos con NULL
     nuevoNodo->Der = NULL;//Inicializamos con NULL

     return nuevoNodo;
}

//funcion introducir datos al nodo
void introducir(ABB &arbol, int x){
	
     if(arbol==NULL){
     	
           arbol = crearNodo(x); }
           
     else if(x < arbol->ndo) introducir(arbol->Izq,x);
     
     else if(x > arbol->ndo) introducir(arbol->Der, x);
}//fin de funcion introducir

//funcion para observar el arbol
void vizualizar(ABB arbol, int f){
	
     if(arbol==NULL)
          return;
          
     vizualizar(arbol->Der, f+1);

     for(int i=0; i<f; i++)
         cout<<"  ";

     cout<< arbol->ndo <<endl;

     vizualizar(arbol->Izq, f+1);
}

//funcion Preorden
void Preorden(ABB arbol){
	
     if(arbol!=NULL){
     	
          cout << arbol->ndo <<" ";
          Preorden(arbol->Izq);
          Preorden(arbol->Der);
 }
}//fin de funcion 

//funcion Enorden
void Enorden(ABB arbol){
	
     if(arbol!=NULL){

          Enorden(arbol->Izq);
          cout << arbol->ndo << " ";
          Enorden(arbol->Der);
  }
}//fin de funcion
 
//funcion Posorden
void Postorden(ABB arbol){
	
     if(arbol!=NULL) {
          Postorden(arbol->Izq);
          Postorden(arbol->Der);
          cout << arbol->ndo << " ";
		  }
}


bool buscar(ABB arbol, int dat){
     int r=0;   //no lo encontre

     if(arbol==NULL)
        return r;

     if(dat<arbol->ndo)
         r = buscar(arbol->Izq, dat);

     else if(dat> arbol->ndo)
         r = buscar(arbol->Der, dat);
     else
     	r = 1;   //lo encontro

     return r;
}


int main()
{
    ABB arbol = NULL; //Inicializando arbol
    int num1=0,num2=0, x=0, op=0;//Decaracion de variables
	


	do{ system("color B0"); //color de pantalla
	    system("cls");//limpiar pantalla
		
                                   //Visualzar menu de opciones.
         cout<<"\n\t********************************************************";
         cout<<"\n\t*                     MENU PRINCIPAL                   *";
         cout<<"\n\t********************************************************";
         cout<<"\n\t* 1. Insertar nodo                                     *";
         cout<<"\n\t* 2. Mostrar el arbol                                  *";
         cout<<"\n\t* 3. Buscar nodo especifico                            *";
         cout<<"\n\t* 4. Recorrer el arbol, pre-orden, in-orden, pos-orden *";
         cout<<"\n\t* 5. Borrar nodo                                       *";
         cout<<"\n\t* 6. Finalizar programa                                *";
         cout<<"\n\t********************************************************";
         cout<<"\n\n\tIngrese la opcion que desea realizar: "; 
         cin>>op; //Leer opcion del usuario 
		
		switch(op){
			
			case 1: system("cls");//limpiar pantalla
			
			        cout<<"\n\tIngrese la cantidad de nodos del arbol que desea: ";
    				cin>>num1;//lee variable

                    //pide al usuario la cantidad de nodos que desea ingresar
    				for(int i=0; i<num1; i++){
        				cout << "\n\tNumero del nodo " << i+1 << ": ";
        				cin >> x;
        				introducir(arbol, x);//Invocacion funcion 
    				}
    				break;
    		
			case 2: system("cls");//limpiar pantalla
			
			        cout << "\n\t* Mostrando Arbol ABB *\n\n";//titulo
    				vizualizar(arbol, 0);//Invocacion de funcion 
    				_getch();
    				break;
    		
    		case 3:{ system("cls");//limpiar pantalla
    		
			        cout<<"\n\tIngrese el nodo que desea encontrar: ";
    				cin>>num2;
    				
    				if(buscar(arbol, num2)){
    					system("color A0");//color de pantalla
    					
						cout<<"\n\t* NODO ENCONTRADO *";
						_getch();   }
					else{
					    system("color C0");//color de pantalla
					    
						cout<<"\n\t* NODO NO ENCONTRADO"<<endl;
						_getch();
					    break; }
						}
			
			case 4: { system("cls");//limpiar pantala
			
			        cout << "\n\t* RECORRIDO DEL ARBOL ABB *";
					
					cout << "\n\n\tPre-Orden: ";   Preorden(arbol);//Invocacion de funcion 
				    cout << "\n\n\tIn-Orden: ";    Enorden(arbol);//Invocacion de funcion 
				    cout << "\n\n\tPos Orden: ";   Postorden(arbol);//Invocacion de funcion 
				    _getch(); break;
				}
			
			case 5: system("cls");//limpiar pantalla
			
			        cout<<"\tIntroduzca el nodo a eliminar: ";
					break;
			
			case 6:  break;
			
			default: { system("color C0");//color de pantalla
      
	     	cout<<"\tERROR: El numero que ingreso es incorrecto!"; //Mensaje de error 
		     _getch();//detener el porgrama para leer
		     break; }//mensaje de error
		}	
	}while(op!=6);

    _getch();
    return 0;
}
/*Ingenieria en Sistemas 
  Mercy Salome Vasquez Otiz
  Carnet: 0909-20-5202
  Tercer Semestre*/
