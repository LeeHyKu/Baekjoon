/*
 * Einreich 33774329
 * 
 * Copyright (C) 2021. Hyun-Ku Lee
 * 
 *  Dieses Programm ist freie Software. Sie können es unter den Bedingungen
 *  der GNU General Public License, wie von der Free Software Foundation
 *  veröffentlicht, weitergeben und/oder modifizieren, entweder gemäß Version 3
 *  der Lizenz oder (nach Ihrer Option) jeder späteren Version.
 * 
 *  Die Veröffentlichung dieses Programms erfolgt in der Hoffnung, daß es Ihnen
 *  von Nutzen sein wird, aber OHNE IRGENDEINE GARANTIE, sogar ohne die implizite
 *  Garantie der MARKTREIFE oder der VERWENDBARKEIT FÜR EINEN BESTIMMTEN ZWECK.
 *  Details finden Sie in der GNU General Public License.
 *
 *  Sie sollten ein Exemplar der GNU General Public License zusammen mit diesem
 *  Programm erhalten haben. Falls nicht, siehe http://www.gnu.org/licenses/.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#pragma warning(disable:4996)

#define PTRSIZ 8

int hasch(char* schnur) {
	unsigned int erg = 0;
	for (char* zei = schnur; *zei; zei++)
		erg = (erg * 0x47 + *zei - 0x60) % 4294967295;
	return (int)erg;
}


typedef struct vektor {
	void** daten;
	int gross;
} Vektor;

Vektor* schaffen_vektor() {
	Vektor* erg = (Vektor*)malloc(sizeof(Vektor));
	erg->daten = (void**)malloc(0);
	erg->gross = 0;
	return erg;
}

void anfugen_vektor(Vektor* v, void* daten) {
	v->daten = (void**)realloc(v->daten, PTRSIZ * (v->gross + 1));
	v->daten[v->gross] = daten;
	v->gross++;
}

int vektor_hat(Vektor* v, void* ziel) {
	for (int i = 0; i < v->gross; i++)
		if (v->daten[i] == ziel) return 1;
	return 0;
}

void frei_alledaten(Vektor* v) {
	for (int i = 0; i < v->gross; i++)
		free(v->daten[i]);
	free(v->daten);
	free(v);
	return;
}


typedef struct stapel {
	void** daten;
	int niveau;
} Stapel;

Stapel* schaffen_stapel() {
	Stapel* erg = (Stapel*)malloc(sizeof(Stapel));
	erg->daten = (void**)malloc(0);
	erg->niveau = 0;
	return erg;
}

void anfugen_stapel(Stapel* s, void* daten) {
	s->daten = (void**)realloc(s->daten, PTRSIZ * (s->niveau + 1));
	s->daten[s->niveau] = daten;
	s->niveau++;
}

void* pop_stapel(Stapel* s) {
	s->niveau--;
	void* erg = s->daten[s->niveau];
	s->daten = (void**)realloc(s->daten, PTRSIZ * (s->niveau));
	return erg;
}


typedef struct HTMLElement {
	char* id;
	Vektor* klassen;
	Vektor* kinder;
} Node;

Node* schaffen_nodeN() {
	Node* erg = (Node*)malloc(sizeof(Node));
	erg->id = (char*)0;
	erg->klassen = schaffen_vektor();
	erg->kinder = schaffen_vektor();
	return erg;
}

Node* schaffen_node(char* id) {
	Node* erg = (Node*)malloc(sizeof(Node));
	erg->id = (char*)malloc(sizeof(id));
	strcpy(erg->id, id);
	erg->klassen = schaffen_vektor();
	erg->kinder = schaffen_vektor();
	return erg;
}

void anfugen_klassen(Node* e, char* klasse) {
	anfugen_vektor(e->klassen, (void*)hasch(klasse));
}

void anfugen_kind(Node* e, int kind) {
	anfugen_vektor(e->kinder, (void*)kind);
}


typedef struct SelectorElement {
	int typ;
	Vektor* klassen;
} FilterNode;

FilterNode* schaffen_filternode(int typ) {
	FilterNode* erg = (FilterNode*)malloc(sizeof(FilterNode));
	erg->typ = typ;
	if (typ == 2) erg->klassen = schaffen_vektor();
	return erg;
}

void anfugen_klassen_filternode(FilterNode* f, char* klasse) {
	anfugen_vektor(f->klassen, (void*)hasch(klasse));
}

int prufen_node(FilterNode* f, Node* n) {
	for (int i = 0; i < f->klassen->gross; i++)
		if (!vektor_hat(n->klassen, f->klassen->daten[i])) return 0;
	return 1;
}


Vektor* dokument_lasen() {
	int G; scanf("%d", &G);

	Stapel* vorfahren = schaffen_stapel();
	Vektor* erg = schaffen_vektor();

	anfugen_vektor(erg, schaffen_nodeN());
	anfugen_stapel(vorfahren, 0);

	for (int i = 0; i < G; i++) {
		char schildsanfang[11];
		scanf("%s", schildsanfang);
		if (!strcmp(schildsanfang, "</div>")) pop_stapel(vorfahren);
		else {
			char name[31];
			scanf(" id='%[^']'", name);
			anfugen_vektor(erg, schaffen_node(name));
			anfugen_kind((Node*)erg->daten[(int)vorfahren->daten[vorfahren->niveau - 1]], erg->gross - 1);
			anfugen_stapel(vorfahren, (void*)(erg->gross - 1));
			scanf(" class='");
			char klasse_name[31];
			while (scanf(" %[^ ']", klasse_name)) anfugen_klassen((Node*)erg->daten[erg->gross - 1], klasse_name);
			scanf("'>");
		}
	}
	return erg;
}

Vektor* wahler_lasen() {
	Vektor* erg = schaffen_vektor();

	char c;
	while (scanf("%c", &c)) {
		switch (c) {
		case 0x20:
			goto FORT;
		case 0x0A:
			goto BREC;
		case 0x3E:
			anfugen_vektor(erg, schaffen_filternode(0));
			scanf(" %c", &c);
			break;
		default:
			anfugen_vektor(erg, schaffen_filternode(1));
			break;
		}
		anfugen_vektor(erg, schaffen_filternode(2));
		char klasse_name[21];
		while (scanf("%[^. \n]", klasse_name)) {
			FilterNode* n = (FilterNode*)erg->daten[erg->gross - 1];
			anfugen_klassen_filternode(n, klasse_name);
			scanf(".");
		}
	FORT:
		continue;
	}
BREC:
	return erg;
}


typedef struct tragen {
	Vektor* wahler;
	Vektor* antworten;
	bool hat_besucht[2][5010][5010];
} Tragen;

Tragen* schaffen_tragen() {
	Tragen* erg = (Tragen*)malloc(sizeof(Tragen));
	return erg;
}

void frei_tragen(Tragen* tra) {
	frei_alledaten(tra->wahler);
	frei_alledaten(tra->antworten);
	free(tra);
	return;
}


void dfs(Tragen* tra, Vektor* dokumentenbaum, bool spr, int nod, int pos) {
	if (tra->hat_besucht[spr][nod][pos]) return;
	tra->hat_besucht[spr][nod][pos] = 1;

	if (pos == tra->wahler->gross) {
		if (!spr) anfugen_vektor(tra->antworten, (void*)nod);
		return;
	}

	Vektor* kdr;
	switch (((FilterNode*)tra->wahler->daten[pos])->typ) {
	case 0:
		kdr = ((Node*)dokumentenbaum->daten[nod])->kinder;
		for (int i = 0; i < kdr->gross; i++)
			dfs(tra, dokumentenbaum, 0, (int)kdr->daten[i], pos + 1);
		break;
	case 1:
		if (spr) dfs(tra, dokumentenbaum, 0, nod, pos + 1);
		kdr = ((Node*)dokumentenbaum->daten[nod])->kinder;
		for (int i = 0; i < kdr->gross; i++)
			dfs(tra, dokumentenbaum, 1, (int)kdr->daten[i], pos);
		break;
	case 2:
		if (!prufen_node((FilterNode*)tra->wahler->daten[pos], (Node*)dokumentenbaum->daten[nod])) return;
		dfs(tra, dokumentenbaum, 0, nod, pos + 1);
		break;
	}
}


int compare(const void* a, const void* b) {
	return (*(int*)a) - (*(int*)b);
}

int main(void) {
	Vektor* baum = dokument_lasen();

	int G; scanf("%d\n", &G);
	for (int i = 0; i < G; i++) {
		Vektor* fil = wahler_lasen();
		Tragen* tra = schaffen_tragen();

		tra->wahler = fil;
		tra->antworten = schaffen_vektor();
		memset(tra->hat_besucht, 0, sizeof tra->hat_besucht);

		dfs(tra, baum, 0, 0, 0);

		Vektor* ant = tra->antworten;
		printf("%d ", ant->gross);
		qsort((int*)ant->daten, ant->gross, PTRSIZ, compare);
		for (int j = 0; j < ant->gross; j++)
			printf("%s ", ((Node*)baum->daten[(int)ant->daten[j]])->id);
		printf("\n");

		//frei_tragen(tra);
	}
	return 0;
}