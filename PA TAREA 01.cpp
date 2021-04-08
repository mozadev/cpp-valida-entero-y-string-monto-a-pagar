 #include <iostream>  
 #include <cstdlib>  
 #include <cstdio>  
 #include <cstring>  
 

 
using namespace std;

//prototipos de la funcion
 bool entero(char *a);  
 int validarNumero(string a);  
 int validarNombre(string x);
int validaDia(char di);
float MontoTotalPagar(char dia,int cant ,float montoV);

void error();  // funcion global  con mensaje de error
 char nuS[100]; //  cadena de caracteres 

 int main(){
	//validando el ingreso del nombre del cliente
	string nombre;
	do{
		cout<<"ingrese el nombre del cliente "<<endl;
	getline(cin, nombre);
		
	}while(validarNombre(nombre)==0);
	
	
	//validando el ingreso de la cantidad de producto
		int x;  
      string mensaje="Ingrese la cantidad pedida: ";  
      x=validarNumero(mensaje); 
      
      
    //validando el ingreso del dia de la semana
    	char dia;
	do{
		
	cout<<"ingresa el dia de la compra ejemplo : viernes (V o v)  miercoles (X o x) "<<endl;
	
	cin>>dia;
	
	}while(validaDia(dia)==0);


	//validando el ingreso del monto vendido	
		int monto;  
      string mensajeMonto="Ingrese monto vendido ";  
      monto=validarNumero(mensajeMonto); 

	//calculando el monto total a pagar
	
	float montoConDescuento;
	montoConDescuento=MontoTotalPagar(dia,x,monto);
	
	// imprimiendo el reporte
	cout<<"el nombre del cliente es : " <<nombre<<endl;
	cout<<"el cantidad de productos es : " <<x<<endl;
	cout<<"el dia es "<<dia<<endl;
	cout<<"el MONTO VENDIDO es "<<monto<<endl;
	cout<<"el monto total vendido con descuento es: " <<montoConDescuento<<endl; 

	system("pause");
	return 0;
	
}

// implementacion de  las funciones o metodos 

// validando el nombre del cliente

	int validarNombre(string x){
	char c;
	for (int i=0; i< x.size();i++){
		 c=x[i];
		 if(isalpha(c)==0){ // isappha() metodo q comprueba si es caracter
		 	if(isspace(c)==0){
		 		error(); // funcion con mensaje de error
		 		return 0;
			 }
		 }
		
	}
	cout<<"el nombre es valida"<<endl;
}

// valindando el caracter dia  --------------------------------------------
	int validaDia(char di){
			if(di!='L'&& di!='l'&& di!='M'&& di!='m'&& di!='X'&& di!='x'&& di!='J'&& di!='j'&& 
			di!='V'&&di!='v'&& di!='S'&& di!='s'&& di!='D'&& di!='d'){
			error();  
			return 0;
		
		}
			return 1;
	}
	
		
// validadando los numeros ------------------------------	
 int validarNumero(string a){  
      do{  
           cout<<a;  // mensaje 
           cin>>nuS;  // guarda el mensaje en el arreglo de caracteres
           if(!entero(nuS)){   // validando si el arreglo de caracteres es un enetero
           error();  
           }       
      }while(!entero(nuS));  
      return atoi(nuS);   // metodo atoi() convierte el arreglo de caracteres en un entero
 }  
 void error(){  
      cout<<"\nDato no valido, verifique.."<<endl;  
 }  
 
 bool entero(char *a){  
      for(int i = 0; i<strlen(a); i++){  
           if(!isdigit(a[i])){  // validando si los caracteres son digitos
                return false;  
           }  
      }  
      return true;  
 }  
 
 
 // funcion calcula el monto con descuento ---------------
 float MontoTotalPagar(char dia,int cant,float montoV){
 	float pago=0;
 	
 	switch(dia){
 		case 'v':
 			if(cant>20){
 					pago=montoV*(1-0.15);
 					break;
 					 }
 					 else{
 					 	pago=montoV;
 					 	break;
					  }
 					 
 		
 		
	 
	 	case 'V':
 			if(cant>20){
 				pago=montoV*(1-0.15);
 			break;
			 }
			 else{
 					 	pago=montoV;
 					 	break;
					  }
 			
 		
	 
	 case 'l':
	 	
 			if(cant>45){
 					pago=montoV*(1-0.25);
 			break;
			 }	 else{
 					 	pago=montoV;
 					 	break;
					  }
 			
 		
 		
	 
	  case 'L':
 			if(cant>45){
 			pago=montoV*(1-0.25);
 			break;
			 }
			 	 else{
 					 	pago=montoV;
 					 	break;
					  }
 			
		default:
			pago = montoV;
			break;
			 
	
		 		
	 }
	 
 		return pago;
 }
 
 
 
