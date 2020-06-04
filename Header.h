#ifndef HEADER_H
#define HEADER_H

#define MAX_LEN 20
#define MAX_ZAM 15

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SLEEP(sleepMs) Sleep(sleepMs)
#endif

typedef struct {
	int den, mesiac, rok;
} Datum;

typedef struct {
	char meno[MAX_LEN];
	Datum d_narod;
} OsobneUdaje;

typedef struct Zamestnanec {
	int id;
	char pozicia[MAX_LEN];
	int plat;
	OsobneUdaje udaje;
} Zamestnanec;

void printZam(Zamestnanec z);
void deleteZam(Zamestnanec db[], int poc, char atr[], char log, int val);


#endif