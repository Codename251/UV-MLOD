/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

struct Winner{
    int year;
    char* name;
    char* description;
};

typedef struct Winner Winner;

void readWinners(Winner **winners,int nbGagnants){
	*winners = (Winner *)calloc(nbGagnants, sizeof(Winner));
	 for(int i= 0; i< nbGagnants; i++){
		 (*winners)[i].year = scanLineAsInt();
		 (*winners)[i].name = scanLine();
		 (*winners)[i].description = scanLine();
	 }
};

void printWinners(Winner * winners, int nbGagnants){
	printf("%i\n", nbGagnants);
	for(int i= 0; i< nbGagnants; i++){
		printf("%i\n", winners[i].year);
		printf("%s\n", winners[i].name);
		printf("%s\n", winners[i].description);
	}
}

void infosAnnee(int annee, Winner *winners, int nbGagnants){
	for(int i= 0; i< nbGagnants; i++){
		if(winners[i].year == annee){
			printf("L'annee %i, ", winners[i].year);
			printf("les gagnant(s) ont été : %s\n", winners[i].name);
			printf("Nature des travaux : %s\n", winners[i].description);
		};
	}

};


int minimum(Winner *winners, int nbGagnants, int tableauIndice[nbGagnants]){
	int min = 0;
	bool found; 

	for(int i= 0; i< nbGagnants; i++){
		for(int j=0; j<nbGagnants; j++){

			if(i == tableauIndice[j]){
				found = true;
			}

		}
		if(found){
			if(min != 49) min ++;
		} 
		else break;
		
	};
	
	
	for(int i= 0; i< nbGagnants; i++){	

		if(winners[min].year > winners[i].year){
			found = false;
			for(int j= 0; j< nbGagnants; j++){
				if(i == tableauIndice[j]){
					found = true;
				}
			};

			if(found == false){
				min = i;
			};
		};
						
		
	};
	return min;
};

void sortTuringWinners(Winner *winners, int nbGagnants){
	printf("%i\n", nbGagnants);
	int tableauIndice[nbGagnants-1];
	int min;

	for(int i= 0; i<= nbGagnants-1; i++){
		tableauIndice[i] = -1;
	};

	for(int i= 0; i<= nbGagnants-1; i++){
		min = minimum(winners, nbGagnants, tableauIndice);
		tableauIndice[i] = min;
		printf("\n");
		printf("%i\n", winners[min].year);
		printf("%s\n", winners[min].name);
		printf("%s\n", winners[min].description);

	};
};


int main(void)
{

	int nbGagnants = scanLineAsInt();
	Winner *winners;
	readWinners(&winners, nbGagnants);
	//printWinners(winners, nbGagnants);
	//infosAnnee(2003, winners, nbGagnants);
	sortTuringWinners(winners, nbGagnants);
	free(winners);


	return EXIT_SUCCESS;
}
