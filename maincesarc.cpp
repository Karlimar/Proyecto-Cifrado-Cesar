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
	    switch (opc[0]){
	        	if (1==1){
	                case '1':	        	
						bool continuar1;            
				        do{
							bandera=0;
							fflush(stdin);
					        system("cls");
							cout<<"\n Ingrese el nombre del archivo a codificar: \n";
							cout<<"\n Tomando en cuenta que no se aceptaran estos simbolos: <,>,?,:,|,/,*,\" \n\nR: ";
			                getline(cin,NombreAtemp);
			                
			                limite=NombreAtemp.size();
			    			for(int x=0;x<limite;x++){
			    				if ((NombreAtemp[x]==47 ||NombreAtemp[x]==58 || NombreAtemp[x]==124 || NombreAtemp[x]==62|| NombreAtemp[x]==63 || NombreAtemp[x]==42|| NombreAtemp[x]==60|| NombreAtemp[x]==34) && bandera==1){
						    		cout<<"\n Por favor, siga las normas y no coloques simbolos no aceptados\n";	
						    		system("pause");
						    		system("cls");
									bandera=1;
								}
							}   						
						}while(bandera==1);
						NombreA=strdup(NombreAtemp.c_str());
						system("pause");	
						if(bandera==0){
							ofstream ArchivoBorrar(NombreA,std::ios::trunc);
							ArchivoBorrar.close();
							bandera=1;
						}
						do {	
							continuar1 = false;
					        cin.clear();
							if(contar1 >0 ) cin.ignore(1024, '\n');
		        			cout << "\n Introduce el numero del desplazamiento deseado: \n" << endl; 
                      		cin >> n;
                            Cesar.setNumero(n);
                            contar1++;
					            if( n<0 || cin.fail() && cin.rdstate()){
						            cout << "\n DATO NO VALIDO...! \n" << endl;
						            continuar1 = true;
					            }
				        } while (continuar1);  	
        	        	cin.ignore(256,'\n');
						fflush(stdin);
			cout << "\n IMPORTANTE: Para salir del mensaje a codificar escriba al final :SACAME" <<endl;
                        cout << "\n Introduce el mensaje a codificar: \n" <<endl; 
                             
						do{     
							bandera=0;
							ofstream Archivo(NombreA,std::ios::app);	 
							getline(cin, cadena);
							if(cadena==":SACAME" || cadena==":sacame"){
								bandera=1;
								cadena=" ";
							}
							Cesar.Codificar(-Cesar.getNumero(),cadena);
							Cesar.setMensaje(cadena);
							Archivo<<Cesar.getMensaje()<<endl;
							Archivo.close();
						}while(bandera==0);
                    break;
                    
                    case'2':
						fflush(stdin);      
                       	cout<<"\n Ingrese el nombre del archivo a decodificar: \n\n";
			            getline(cin,NombreAtemp);						                
						NombreA=strdup(NombreAtemp.c_str());		
		                
						ifstream MostrarTexto(NombreA);
						if(MostrarTexto.is_open()){
							int contar = 0;
				            bool continuar;	
							do {
								system("cls");				  	
				              	continuar = false;
				                cin.clear();
				                if(contar >0 ) cin.ignore(1024, '\n');
			                    cout << "\n Introduce el numero del desplazamiento deseado: \n" << endl; 
                                cin >> n;
				                contar++;
				                if( n<0 || cin.fail() && cin.rdstate()){
					                cout << "\n DATO NO VALIDO...!\n" << endl;
					                continuar = true;
				                } 
								system("cls");	   
					        } while (continuar);
		            		Cesar.setNumero(n);
						  	while(getline(MostrarTexto,MostrarCadena)){
								Cesar.Decodificar(Cesar.getNumero(), MostrarCadena);
								cout<< MostrarCadena<<endl;	
						  	}
						}else{
							cout<<"\n El archivo no se encontro...\n"<<endl;
						} 
			        	system("pause");	  
		            break;
		        }
	                case '3':
    	            	return 0;
                    break;
                    
					default:
		            	system("cls");
		            	cout<<"\n ERROR!! Opcion no valida \n\n";
		            	system("pause");
	                break;	
						
	        }  
	  
    }while(1==1);  
    system ("pause");
    return 0;		
}		
