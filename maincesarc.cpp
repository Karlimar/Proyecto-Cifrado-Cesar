#include <iostream> 
#include <string.h> 
#include <fstream>
#include <sstream>
using namespace std; 
 
class cifrado
{
	public:

		void setNumero(int n){
			numero = n;	
		}
		int getNumero(){
			return numero;
		}
		void setMensaje(string n){
			mensaje = n;
		}
		string getMensaje(){
			return mensaje;
		}
		
		void Codificar(int n, string & cadena){
			for (int i = 0; i < cadena.length(); i++) { 
		        if (cadena[i] >= 'a' && cadena[i] <= 'z') { 
		            if (cadena[i] + n > 'z') { 
		                cadena[i] = 'a' - 'z' + cadena[i] + n - 1; 
		            } else if (cadena[i] + n < 'a') { 
		                cadena[i] = 'z' - 'a' + cadena[i] + n + 1; 
		            } else { 
		                cadena[i] += n; 
		            } 
		        } else if (cadena[i] >= 'A' && cadena[i] <= 'Z') { 
		            if (cadena[i] + n > 'Z') { 
		                cadena[i] = 'A' - 'Z' + cadena[i] + n - 1; 
		            } else if (cadena[i] + n < 'A') { 
		                cadena[i] = 'Z' - 'A' + cadena[i] + n + 1; 
		            } else { 
		                cadena[i] += n; 
		            } 
		        } 
		    }
		    this->mensaje=cadena;
		}
		
		void Decodificar(int n, string & cadena){
			Codificar(n, cadena);
		}
	private:
		int numero;
		string mensaje;		
};
   char opc[100];
 int resp=0;
 
int main() {
   	cifrado Cesar;
   	string NombreAtemp;
   	char *NombreA;
    string cadena,MostrarCadena; 
    int n,limite; 
    int contar1 = 0;
    int bandera=0;
	system("cls");
	do{
		system("cls");
   		cout<<"\n\t   Bienvenidos al programa!!! \n\n";
   		cout<<"\t|------------------------------|\n\n";
   		cout<<"\t| 1. Codificar                 |\n\n";
   		cout<<"\t|------------------------------|\n\n";
   		cout<<"\t| 2. Descodificar              |\n\n";
   		cout<<"\t|------------------------------|\n\n";
   		cout<<"\t| 3. Salir                     |\n\n";
   		cout<<"\t|------------------------------|\n\n";
   	   	cout<<" Ingrese una opcion: \n\n ";
		cin>>opc;
		int O=0;
		if(opc[1]!='\0'){
			opc[0]=0;
		}
        for(int t=0;t<100;t++){
    	    if(opc[t]!='\0'){
    	        	O++;
            }
        }
        if(O>=2){
			opc[0]=0;
        }
	        
	  
    }while(1==1);  
    system ("pause");
    return 0;		
}		
