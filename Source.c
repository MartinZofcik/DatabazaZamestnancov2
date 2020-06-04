#define _CRT_SECURE_NO_DEPRECATE
#include "Header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() {
	FILE *fp;
	Zamestnanec z;
	Zamestnanec *db = (Zamestnanec*)malloc(sizeof(Zamestnanec));
	int poc = 0, id, plat, dd, mm, rok, val;
	char pr[7], atr[8], log;
	fp = fopen("databaza.txt", "r+");

	while (fscanf(fp, "%d %d %s %s %d %d %d", &z.id, &z.plat, z.pozicia, z.udaje.meno, &z.udaje.d_narod.den, &z.udaje.d_narod.mesiac, &z.udaje.d_narod.rok) != EOF) {
		db[poc] = z;
		poc++;
		db = (Zamestnanec*)realloc(db, (poc+1)*sizeof(Zamestnanec));
	}

	for (int i = 0; i < poc; i++)
		printZam(db[i]);


	printf("Zadaj prikaz: ");
	scanf("\n%s", pr);


	if (strcmp(pr, "insert") == 0) {
		scanf("\n%d %d %s %s %d %d %d", &z.id, &z.plat, z.pozicia, z.udaje.meno, &z.udaje.d_narod.den, &z.udaje.d_narod.mesiac, &z.udaje.d_narod.rok);
		fprintf(fp, "\n%d %d %s %s %d %d %d", z.id, z.plat, z.pozicia, z.udaje.meno, z.udaje.d_narod.den, z.udaje.d_narod.mesiac, z.udaje.d_narod.rok);
		db[poc] = z;
	}

	else {
		scanf("\n%s %c %d", atr, &log, &val);
		deleteZam(db, poc, atr, log, val);
	}

	fclose(fp);
	getchar();getchar();

	return 1;
}

void printZam(Zamestnanec z) {
		printf("| % 6d | %d | % 8s | % 10s | %02d.%02d.%d |\n",
			z.id,
			z.plat,
			z.udaje.meno,
			z.pozicia,
			z.udaje.d_narod.den,
			z.udaje.d_narod.mesiac,
			z.udaje.d_narod.rok);
}


void deleteZam(Zamestnanec db[], int poc, char atr[], char log, int val) {
	FILE *fp;
	char meno[15], pozicia[15];
	int dd, mm, rok;
	fp = fopen("databaza.txt", "w");
	switch (atr[1]) {

	case 'd'://id
		if (log == '=') {
			for (int i = 0; i < poc;i++) {
				if (db[i].id != val)
					fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
			}
		}
	
		if (log == '<') {
			for (int i = 0; i < poc;i++) {
				if (db[i].id > val)
					fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
			}
		}
		if (log == '>') {
			for (int i = 0; i < poc;i++) {
				if (db[i].id < val)
					fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
			}
		}
		break;

	case 'l'://plat
		if (log == '>') {
			for (int i = 0; i < poc;i++)
				if (db[i].plat < val)
					fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
		}
		if (log == '<') {
			for (int i = 0; i < poc;i++)
				if (db[i].plat > val)
					fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
		}
		if (log == '=') {
			for (int i = 0; i < poc;i++)
				if (db[i].plat != val)
					fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
		}
		break;
	case 'o'://pozicia
		printf("pozicia: ");
		scanf("\n%s", &pozicia);
		for (int i = 0; i < poc;i++) {
			if (strcmp(db[i].pozicia, pozicia) != 0)
				fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
		}
		break;
	case 'e'://meno
		printf("meno: ");
		scanf("\n%s", &meno);
		for (int i = 0; i < poc;i++) {
			if (strcmp(db[i].udaje.meno, meno) != 0)
				fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
		}
		break;

	case 'a'://datum
		printf("Zadaj DD MM RRRR: ");
		scanf("%d %d %d", &dd, &mm, &rok);
		if (log == '='){
			for (int i = 0; i < poc;i++) {
				if (db[i].udaje.d_narod.den != dd && db[i].udaje.d_narod.mesiac != mm && db[i].udaje.d_narod.rok != rok)
					fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
			}
		}
		if (log == '>') {
			for (int i = 0; i < poc;i++) {
				if (db[i].udaje.d_narod.rok < rok) {
					if (db[i].udaje.d_narod.mesiac < mm) {
						if (db[i].udaje.d_narod.den < dd)
							fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
					}
				}
			}
		}
		if (log == '<') {
			for (int i = 0; i < poc;i++) {
				if (db[i].udaje.d_narod.rok > rok) {
					if (db[i].udaje.d_narod.mesiac > mm) {
						if (db[i].udaje.d_narod.den > dd)
							fprintf(fp, "%d %d %s %s %d %d %d\n", db[i].id, db[i].plat, db[i].pozicia, db[i].udaje.meno, db[i].udaje.d_narod.den, db[i].udaje.d_narod.mesiac, db[i].udaje.d_narod.rok);
					}
				}
			}
		}
		break;
	}
}





