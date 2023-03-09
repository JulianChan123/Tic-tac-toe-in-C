#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Variables globales
int i,j,k;

//Function prototypes
void data(char c[3][3]);
void board(char c[3][3]);
void enterdata(char c[3][3]);
void iadata (char c[3][3]);
int winner (char c[3][3]);

//Principal function
int main() {
	int y=0,w=2;
	char c[3][3];

	data (c);
	
	do{
		system ("cls");
		
		board (c);
		
		if (y%2==0){
		enterdata(c);
		}
		else{
		iadata(c);
		}
		
		w=winner (c);
		
		y++;
	}while(y<9 && w==2);
	
	system ("cls");
	board (c);
	
	if(w==0){
		printf("Ganaste");
	}
	else if(w==1){
		printf("Perdiste");
	}
	else{
		printf("Empataste");
	}
	
	return 0;
	getchar();
}


//Function to assing values to the bidimensional array
void data(char c[3][3]){
	char aux='1';
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			c[i][j]=aux++;
		}
	}
}

//Function to print the game board
void board(char c[3][3]){
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			if (j<2){
				printf (" %c |", c[i][j]);
			}
			else{
				printf (" %c", c[i][j]);	
			}
		}
		if(i<2){
		printf("\n-----------\n");
		}
	}
	printf("\n\n");
}

//Fuction to introduce a file by a player 
void enterdata(char c[3][3]){
	char ficha;
	
	do{
		do{
			printf("Ingrese un numero para colocar una ficha: ");
			fflush(stdin);
			scanf("%c", &ficha);
		}while(ficha<'1' || ficha>'9');
		
		k=0;
		
		switch (ficha){
			case '1':{
				i=0;
				j=0;
				if (c[i][j]== 'X' || c[i][j]== 'O'){
					k=1;
					printf("La casilla esta ocupada, intenta con otro numero\n");
				}
				break;
			}
				
			case '2':{
				i=0;
				j=1;
				if (c[i][j]== 'X' || c[i][j]== 'O'){
					k=1;
					printf("La casilla esta ocupada, intenta con otro numero\n");
				}
				break;
			}	
				
			case '3':{
				i=0;
				j=2;
				if (c[i][j]== 'X' || c[i][j]== 'O'){
					k=1;
					printf("La casilla esta ocupada, intenta con otro numero\n");
				}
				break;
			}
				
			case '4':{
				i=1;
				j=0;
				if (c[i][j]== 'X' || c[i][j]== 'O'){
					k=1;
					printf("La casilla esta ocupada, intenta con otro numero\n");
				}
				break;
			}	
						
			case '5':{
				i=1;
				j=1;
				if (c[i][j]== 'X' || c[i][j]== 'O'){
					k=1;
					printf("La casilla esta ocupada, intenta con otro numero\n");
				}
				break;
			}	
							
			case '6':{
				i=1;
				j=2;
				if (c[i][j]== 'X' || c[i][j]== 'O'){
					k=1;
					printf("La casilla esta ocupada, intenta con otro numero\n");
				}
				break;
			}	
								
			case '7':{
				i=2;
				j=0;
				if (c[i][j]== 'X' || c[i][j]== 'O'){
					k=1;
					printf("La casilla esta ocupada, intenta con otro numero\n");
				}
				break;
			}
				
			case '8':{
				i=2;
				j=1;
				if (c[i][j]== 'X' || c[i][j]== 'O'){
					k=1;
					printf("La casilla esta ocupada, intenta con otro numero\n");
				}
				break;
			}
				
			case '9':{
				i=2;
				j=2;
				if (c[i][j]== 'X' || c[i][j]== 'O'){
					k=1;
					printf("La casilla esta ocupada, intenta con otro numero\n");
				}
				break;
			}	
		}
	}while(k==1);
	
	c[i][j]= 'X';
}
//Fuction to introduce a file by the CPU 
void iadata (char c[3][3]){
	char aux;
	
	srand (time(NULL));
	
	do{
		i=rand() % 3;
		j=rand() % 3;
		
		k=0;
		
		if(c[i][j]=='X' || c[i][j]== 'O'){
			k=1;
		}
	}while(k==1);
	
	c[i][j]='O';
}
//Fuction to decide who´s the winner
int winner (char c[3][3]){ //0 player 1 win and 1 player 2 wins
	
	if (c[0][0]=='X' || c[0][0]=='O' ){ //lines 1 & 2
		if (c[0][0]==c[0][1] && c[0][0]==c[0][2]){//1
			if (c[0][0]=='X'){
				return 0;
			}
			else{
				return 1;
			}
		}
		if (c[0][0]==c[1][0] && c[0][0]==c[2][0]){//2
			if (c[0][0]=='X'){
				return 0;
			}
			else{
				return 1;
			}
		}
	}
	
	if (c[1][1]=='X'|| c[1][1]=='O' ){//lines 3, 4 & diagonals
		if (c[1][1]==c[0][0] && c[1][1]==c[2][2]){ //d1
			if (c[1][1]=='X'){
				return 0;
			}
			else{
				return 1;
			}
		}
		if (c[1][1]==c[0][2] && c[1][1]==c[2][0]){ //d2
			if (c[1][1]=='X'){
				return 0;
			}
			else{
				return 1;
			}
		}
		if (c[1][1]==c[1][0] && c[1][1]==c[1][2]){ //3
			if (c[1][1]=='X'){
				return 0;
			}
			else{
				return 1;
			}
		}
		if (c[1][1]==c[0][1] && c[1][1]==c[0][2]){ //4
			if (c[1][1]=='X'){
				return 0;
			}
			else{
				return 1;
			}
		}
	}
	
	if (c[2][2]=='X'|| c[2][2]=='O' ){ //lines 5 & 6
		if (c[2][2]==c[1][2] && c[2][2]==c[0][2]){//5
			if (c[2][2]=='X'){
				return 0;
			}
			else{
				return 1;
			}
		}
		if (c[2][2]==c[2][0] && c[2][2]==c[2][1]){//6
			if (c[2][2]=='X'){
				return 0;
			}
			else{
				return 1;
			}
		}
	}
	
	return 2;
}
