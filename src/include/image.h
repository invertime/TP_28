#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_image
{
    int haut;
    int larg;
    uint8_t *pixels;
} Image;

/**
 * Manipulation d'images
 **/

uint8_t getPix(Image *img, int i, int j);

void setPix(Image *img, int i, int j, uint8_t v);

Image *creerImage(int haut, int larg);

void detruireImage(Image *img);

Image *copieImage(Image *img);
void printImage(Image *img);

/**
 * Image test
 **/
Image *imageTest(int n, int p);

/**
 *   Import / Export
 **/
// renvoie NULL en cas d'erreur
Image *importerImage(char *filename);

// renvoie false en cas d'erreur
bool exporterImage(Image *img, char *filename);

/**
 * Traitement d'image
 **/

Image *miroir(Image *img);

Image *redim(Image *img, int haut, int larg);




