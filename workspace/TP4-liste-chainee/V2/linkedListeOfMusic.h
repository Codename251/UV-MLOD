#pragma once

#include <stdbool.h>
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>

// ============
// Types
// ============

typedef struct{
    char * name;
    char * artist;
    char * album;
    char * genre;
    int discNumber;
    int trackNumber;
    int year;
}Music;

// ============
// External Functions
// ============

void afficheElement(Element e);
void detruireElement(Element e);
bool equalsElement(Element e1, Element e2);

Music* lireLigneMusique();
Liste creationListeMusique(FILE* f, Liste l);
Liste triMusique(Liste l);