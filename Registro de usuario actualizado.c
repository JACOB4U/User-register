// Programa de Registros
// Registros -> Con fecha y hora
// Que muestre los caracteres en mayúsculas
// Que Realice modificaciones al registro y muestre la hora de modificación
// Realizado por Freider Linares CI: 26.388.403 - Estudiante de Ingeniería de Sistemas Sección "A" Nocturno (Instituto Universitario Politécnico "Santiago Mariño")

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

bool registered();
int notregistered();
int caps(char str[]);
int lobby();
int id;
int timing();
int modregister();
char name[30], surname[30];

int main(){
		  	char weekdays [7][1][100] = {
  		{"DOMINGO"}, {"LUNES"}, {"MARTES"}, {"MIERCOLES"}, {"JUEVES"}, {"VIERNES"}, {"SABADO"}
	  };
	  
	char monthsoftheyear [12][1][100] = {
  		{"ENERO"}, {"FEBRERO"}, {"MARZO"}, {"ABRIL"}, {"MAYO"}, {"JUNIO"}, {"JULIO"}, {"AGOSTO"},
  		{"SEPTIEMBRE"}, {"OCTUBRE"}, {"NOVIEMBRE"}, {"DICIEMBRE"}
	  };
	  
	time_t rawtime;
  	struct tm * timeinfo;
  	time (&rawtime);
  	timeinfo = localtime (&rawtime);
int op;

printf("\n _____________________________MENU PRINCIPAL____________________________");
printf("\n|                      		  %s %d de %s del %d		|", weekdays[timeinfo->tm_wday - 1][1], timeinfo->tm_mday , monthsoftheyear[timeinfo->tm_mon - 1][1], (timeinfo->tm_year + 1900));
printf("\n| 1) Registrarse							|");
printf("\n| 2) Consulta de usuario						|");
printf("\n| 3) Modificacion de usuario						|");
printf("\n| 4) Salir								|");
printf("\n|_______________________________________________________________________|");
printf ("\n\n Advertencia: Si usted es nuevo usuario, debe registrarse.");
printf("\n A continuacion, teclee el numero de la opcion que desea realizar: ");
scanf("%d", &op);


      switch (op){
      case 1: 
	  system("cls");
	  notregistered();break;
      case 2: if (registered()==true){
      system("cls");
      printf("_________________________MENU CONSULTA DEL USUARIO_______________________\n");
      printf("\n Los datos de su cuenta son los siguientes: \n");
      printf("\n Nombre: %s", name);
      printf("\n Apellido: %s",surname);
      printf("\n Cedula de Identidad: %d", id);
      printf ("\n Fecha de la consulta: %s %d de %s del %d", weekdays[timeinfo->tm_wday - 1][1], timeinfo->tm_mday , monthsoftheyear[timeinfo->tm_mon - 1][1], (timeinfo->tm_year + 1900));
      printf("\n_________________________________________________________________________");
      lobby();
} break;
      case 3: modregister();break;
      case 4:
      	system ("pause");
	  	break;
}

}

int lobby(){
int x;
printf("\n\nPresione ENTER para regresar al menu principal.");

while(x != 13){
x = getch();
}
system ("cls");

main();
}

bool registered(){
if (id != 0) { 
return true;
} else {
	system ("cls");
	printf("\n Advertencia: No existe ningun usuario registrado!");
	printf("\n Seleccione la primera opcion en el menu principal para efectuar el registro.");
	lobby();
}return false;
}

bool mreg(){
	if (id !=0){
		return true;
	}else {
		system("cls");
		printf("\n Advertencia: No existe ningun usuario registrado!");
		printf("\n Seleccione la primera opcion en el menu principal para efectuar el registro.");
		lobby();
	} return false;
	}
	
	
int modregister(){
	
			  	char weekdays [7][1][100] = {
  		{"DOMINGO"}, {"LUNES"}, {"MARTES"}, {"MIERCOLES"}, {"JUEVES"}, {"VIERNES"}, {"SABADO"}
	  };
	  
	char monthsoftheyear [12][1][100] = {
  		{"ENERO"}, {"FEBRERO"}, {"MARZO"}, {"ABRIL"}, {"MAYO"}, {"JUNIO"}, {"JULIO"}, {"AGOSTO"},
  		{"SEPTIEMBRE"}, {"OCTUBRE"}, {"NOVIEMBRE"}, {"DICIEMBRE"}
	  };
	  
	time_t rawtime;
  	struct tm * timeinfo;
  	time (&rawtime);
  	timeinfo = localtime (&rawtime);
	
	if (mreg()==true){
	system("cls");
  printf("\n\n____________________________DATOS DEL USUARIO___________________________\n");
  printf("\n Los datos de su cuenta son los siguientes: \n");
  printf("\n Nombre: %s", name);
  printf("\n Apellido: %s", surname);
  printf("\n Cedula de identidad: %d", id);
  printf("\n Fecha del registro/modificacion: %s %d de %s del %d", weekdays[timeinfo->tm_wday - 1][1], timeinfo->tm_mday , monthsoftheyear[timeinfo->tm_mon - 1][1], (timeinfo->tm_year + 1900));
  printf("\n________________________________________________________________________\n\n");
         printf("________________________INGRESE SUS NUEVOS DATOS________________________\n");
         printf("Ingrese su nombre: "); 
		 scanf ("%s",&name);
		 caps (name);
         printf("Ingrese su apellido: ");
         scanf ("%s",&surname);
         caps (surname);
         printf("Ingrese su numero de cedula de identidad: "); 
		 scanf("%d", &id);
		 printf ("\n________________________________________________________________________\n\n");
		 system("cls");
         printf("Sus datos han sido actualizados exitosamente!\n");
	}

main();
}

int notregistered(){
	system("cls");
printf("__________________________REGISTRO DEL USUARIO_________________________");
printf("\n\n Introduzca los datos que se le solicita para el registro del usuario");
printf("\n\n Ingrese su nombre: ");
scanf("%s", &name);
caps(name);
printf(" Ingrese su apellido: ");
scanf("%s", &surname);
caps(surname);
printf(" Ingrese su numero de cedula de identidad: ");
scanf("%d", &id);
system("cls");
printf ("Registro completado!\n\n");

main();
}

int caps(char str[]){
int largo = strlen(str);
int caract = 0;
for (caract=0; caract<largo; caract++){
str[caract] = toupper(str[caract]);
}
}

