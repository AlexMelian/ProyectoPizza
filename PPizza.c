/* Archivo:  PPizza.c
 * Autores:     Didier Stevenson Grajales
                Alexander David Melian
 * Fecha:    Mayo de 2019 		*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calP(int i){		//				FUNCION CALCULAR PIZZA
	float total = 0;
	int tama=0, gusto=0, gusto2=0, nGustos=0,corte=0;
	while(nGustos<1 || nGustos>2){		//	Ciclo para validar  nGustos
     	printf("\n    Quedan %i pizzas para elegir, desea esta pizza con 1 gusto o 2: ",i);
  		scanf("%i", &nGustos);
  		fflush(stdin);
  		system("cls");
  	}
	printf(	"    ================== GUSTOS =================== "//Menu de Gustos
			"\n    1- Muzza"
			"\n    2- Napolitana"
           	"\n    3- Morrones"
		 	"\n    4- Hawaiana"
           	"\n    5- Calabresa"
			"\n    6- Pollo y champiñones");
		if(nGustos==2){
			while(gusto<1 || gusto>6){		//Ciclo para validar datos de Gusto
          	printf("\n     Elija el gusto 1: ");
  			scanf("%i", &gusto);
  			}
  			while(gusto2<1 || gusto2>6){	//Ciclo para validar datos de Gusto2
          	printf("\n     Elija el gusto 2: ");
  			scanf("%i", &gusto2);
  			}
  		}else{
  			while(gusto<1 || gusto>6){		//Ciclo para validar datos de Gusto
          	printf("\n     Elija el gusto: ");
  			scanf("%i", &gusto);
  			}
		  }
  	if(gusto2>gusto){
  		gusto = gusto2;
	  }
  	switch(gusto){	//	Calcular el coste de la pizza
  		case 1: total = 100; break;
  		case 2: total = 120; break;
  		case 3: total = 130; break;
  		case 4: total = 140; break;
  		case 5: total = 170; break;
  		case 6: total = 200; break;
    }
    system ("cls");

    while(tama<1 || tama>3){ 		//	Ciclo para validar datos de Tamaño
		printf("================== Tamaño de pizza =================="
				"\n	    1- Normal"
				"\n	    2- Grande"
				"\n	    3- Extra grande"
				"\n     Ingrese el Tamaño: ");
       	scanf("%i",&tama);
       	fflush(stdin);
       	if (tama == 3){				//	Calcular Precio por Tamaño por Pizza
           	total=total*1.25;
       	}else {
       		if (tama == 2){
       	total=total*1.1;
       		}
		}
		system("cls");
   	}

   	while(corte<1 || corte>5){ 		//	Ciclo para validar cortes
		printf(	"======================= CORTES ================= "	//Menu de Cortes
		 		"\n  1- Sin Corte"
				"\n  2- Dos (2) Cortes"
           		"\n  3- Cuatro (4) Cortes"
		 		"\n  4- Ocho (8) Cortes"
           		"\n  5- Doce (12) Cortes"
				"\n  Elija el corte que desea: ");
			scanf("%i",&corte);
			fflush(stdin);
			system("cls");
   	}
  	switch(corte){	//	Calcular Precio mas Corte por Pizza
  		case 2: total = total + 5; break;
  		case 3: total = total + 10; break;
  		case 4: total = total + 15; break;
  		case 5: total = total + 20; break;
    }

    return total;
}
//							    FUNCION PARA MOSTRAR RESULTADOS DE FINAL DEL DIA
void findia(float dinerototal,
			float maxdinerocli,
			int maxpizzascli,
			char maxncli[],
			int deliverys,
			int totalpizzas,
			float maxdinpizz,
			float *vectorPedidos){
			    system("cls");
	printf(	"========================= FIN DEL DIA =========================="
			"\n\tEl TOTAL FACTURADO es: $%.2f"
			"\n\tEl facturado de PIZZAS es: $%.2f"
			"\n\tSe han pedido %d pizzas",dinerototal,maxdinpizz,totalpizzas);
	if (deliverys==0){
    printf("\n    No se han pedido deliverys");
	}else{
  	if (deliverys==1){
		printf("\n\tSe ha pedido UN (1) Delivery");
		}else{
		printf("\n\tSe han pedido %d Deliverys",deliverys);
		}
  }
	printf(	"\n\tEl cliente que más ha gastado fue: %s"
			"\n\tCon un total de: $%.2f",maxncli,maxdinerocli);
	if (maxpizzascli==1){
    printf("\n\tPidiendo una pizza");
	}else{
    printf(	"\n\tPidiendo %d pizzas"
			"\n\n\t========================================================="
			"\n\t===== Lista ORDENADA de PRECIOS PAGADOS por pedidos ====="
			"\n\t=========================================================\n\n",maxpizzascli);
	}
	int i,cont=0;
	for(i=0 ;i<40; i++, cont++){
		if((cont%4)!=0){
			printf("\t%2d) %.2f",cont+1,*(vectorPedidos+i));
		}else{
			printf("\n\t%2d) %.2f",cont+1,*(vectorPedidos+i));
		}
	}
	float sumPromed=0;
	for(i=0, cont=0 ;i<40; i++){
		if(*(vectorPedidos+i)!=0){
		sumPromed = sumPromed+*(vectorPedidos+i);
		cont++;
		}
	}
	printf(	"\n\n\t========================================================="
			"\n\t======= El PROMEDIO de Precios Pagados es: %.2f ======="
			"\n\t=========================================================\n\n",(sumPromed/cont));

//============================== Seccion de Guardar archivo ===============================//
    FILE *archivo;
    //archivo=fopen("FinalesDias.txt","w"); Escribe, si existía archivo lo borra
    //archivo=fopen("FinalesDias.txt","r"); Lee un archivo que debe existir
    archivo=fopen("FinalesDias.txt","a"); // adiciona, si no existe crea
    if(archivo==NULL){
        printf("Apertura de Archivo erronea");
    }else{
        fprintf(archivo,"========================= FIN DEL DIA =========================="
						"\n\tEl TOTAL FACTURADO es: $%.2f"
						"\n\tEl facturado de PIZZAS es: $%.2f"
						"\n\tSe han pedido %d pizzas",dinerototal,maxdinpizz,totalpizzas);
	if (deliverys==0){
    	fprintf(archivo,"\n\tNo se han pedido deliverys");
	}else{
  		if (deliverys==1){
			fprintf(archivo,"\n\tSe ha pedido UN (1) Delivery");
		}else{
			fprintf(archivo,"\n\tSe han pedido %d Deliverys",deliverys);
		}
  	}
	fprintf(archivo,	"\n\tEl cliente que más ha gastado fue: %s"
						"\n\tCon un total de: $%.2f",maxncli,maxdinerocli);
	if (maxpizzascli==1){
    	fprintf(archivo,"\n\tPidiendo una pizza");
	}else{
    	fprintf(archivo,"\n\tPidiendo %d pizzas"
						"\n\n\t========================================================="
						"\n\t===== Lista ORDENADA de PRECIOS PAGADOS por pedidos ====="
						"\n\t=========================================================\n\n",maxpizzascli);
	}
	for(i=0,cont=0 ;i<40; i++, cont++){
		if((cont%4)!=0){
			fprintf(archivo,"\t%2d) %.2f",cont+1,*(vectorPedidos+i));
		}else{
			fprintf(archivo,"\n\t%2d) %.2f",cont+1,*(vectorPedidos+i));
		}
	}
	for(i=0, cont=0, sumPromed=0 ;i<40; i++){
		if(*(vectorPedidos+i)!=0){
		sumPromed = sumPromed+*(vectorPedidos+i);
		cont++;
		}
	}
	fprintf(archivo,"\n\n\t========================================================="
			"\n\t======= El PROMEDIO de Precios Pagados es: %.2f ======="
			"\n\t=========================================================\n\n",(sumPromed/cont));
    }
	fclose(archivo);
}
int posMayor(int posIni, float vector[], int tam){
	int posMay=posIni, i;
	float mayor=vector[posIni];
	for(i=posIni;i<tam;i++){
		if (mayor<vector[i]){
			mayor=vector[i];
			posMay=i;
		}
	}
	return posMay;
}
void ordenarVec(float *vector, int tam){
	int i, posMay;
	float temp;
	for (i=0; i<tam-1 ; i++){
        posMay = posMayor(i, vector, tam);
        temp = vector[i];
        vector[i] = vector [posMay];
        vector [posMay] = temp;
       }
}
//========================================== FUNCION PRINCIPAL ========================
int main() {
  //										Definicion de Variables
  	int cantPizzas=0, i, maxpizza=0, contadordelivery=0, contadorpizzas=0, contadorPedidos=0;
  	char rta[3], rtaDelivery[3], nCliente[10], maxnCliente[10];
  	float total, preciof=0,dinerototal=0, maxdinerototal=0, maxdineropizzas=0,
  	      preciosPagados[40]={0}, *puntPreciosPag=preciosPagados;

  	printf("============== BIENVENIDO AL PROGRAMA DE ATENCION ==================");
  	printf("\n\n\t¿Desea ingresar un nuevo cliente?"
	  "\n\tIngrese -NO- pasa terminar el dia"
	  "\n\n\tRta: ");

    scanf("%s",&rta);
    fflush(stdin);
	while((!strcmp("Si",rta) || !strcmp("si",rta)|| !strcmp("SI",rta))){		//	Ciclo para ingresar los pedidos
		preciof=0;
 		cantPizzas=0;
    	printf("\tIngrese el NOMBRE del cliente: ");
    	scanf("%s",&nCliente);
    	fflush(stdin);
    	while(cantPizzas<1){					//	Ciclo
    		printf("\tCantidad de Pizzas: ");
    		scanf("%i",&cantPizzas);
    		fflush(stdin);
        	system("cls");
		}
    	for(i = cantPizzas; i>0; i--){  //	Ciclo para la cantidad de pizzas
        	total = calP(i);
        	preciof = preciof+total;		//	Calculo Precio Total del Pedido
		}
		maxdineropizzas = maxdineropizzas + preciof;
		system("cls");
		printf("\n\tEl precio total de PIZZAS es: %.2f",preciof);	//Muestra Precio Total de pizzas
  		printf("\n\t¿Incluye DELIVERY?: ");
  		scanf("%s",&rtaDelivery);
  		fflush(stdin);
  		if((!strcmp("Si",rtaDelivery) || !strcmp("si",rtaDelivery)  || !strcmp("SI",rtaDelivery))){
    		contadordelivery++;
    		if(cantPizzas>0 && cantPizzas<4){
    			preciof = preciof + 50;
    		}
    		if(cantPizzas>3 && cantPizzas<7){
    			preciof = preciof + 30;
    		}
		}
		printf("\n\tEl precio TOTAL es: %.2f \n\n",preciof); //Muestra Precio Total del Pedido
						//Asignación del Precio del pedido a un lugar del Vector de Pedidos
		preciosPagados[contadorPedidos]=preciof;
    	contadorPedidos++;
		system("pause");
							//Uso de Acumuladores y asignacion de Mayores
		dinerototal=dinerototal+preciof;
		contadorpizzas=contadorpizzas+cantPizzas;
		if (preciof>maxdinerototal){
			maxdinerototal=preciof;
			strncpy(maxnCliente,nCliente,10);
			maxpizza=cantPizzas;
    	}
  		system("cls");
 		printf("\n\t¿Desea ingresar más clientes?   Rta: ");
  		scanf("%s",&rta);
    	fflush(stdin);
    	system("Cls");
    }
    ordenarVec(puntPreciosPag,40);					//Llamado a l Funcion OrdenarVector
				// Funcion para mostrar y guardar Resultados del Día
    findia(dinerototal,maxdinerototal,maxpizza,maxnCliente, contadordelivery,contadorpizzas,maxdineropizzas,preciosPagados);
    return 0;
}
