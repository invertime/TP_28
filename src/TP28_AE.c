#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct s_image {
    int haut;
    int larg;
    uint8_t* pixels;
};

typedef struct s_image Image;

/**
 * Manipulation d'images
 **/

uint8_t getPix(Image* img, int i, int j){
    assert(img != NULL && i >= 0 && i < img->haut && j >=0 && j < img->larg);
    return img->pixels[i*img->larg+j];
}

void setPix(Image* img, int i, int j, uint8_t v){
    assert(img != NULL && i >= 0 && i < img->haut && j >=0 && j < img->larg);
    img->pixels[i*img->larg+j] = v;
}

Image* creerImage(int haut, int larg) {
    Image *img = (Image*) malloc(sizeof(Image));
    img->pixels = (uint8_t*)malloc(haut*larg*sizeof(uint8_t));
    img->haut = haut;
    img->larg = larg;

    return img;
}

void detruireImage(Image* img) {
  free(img->pixels);
  free(img);
}

void printImage(Image* img){
    int n = img->haut;
    int p = img->larg;
    int ind = 0;
    printf("-------IMAGE-------\n");
    for (int i = 0; i < n; i+=1){
        for (int j = 0; j < p; j += 1){
            printf("%d ", img->pixels[ind]);
            ind += 1;
        }
        printf("\n");
    }
    printf("-------FIN-------\n");
}

/**
 * Image test
 **/
Image* imageTest(int n, int p){
  Image *img = creerImage(n, p);
  for (int i = 0; i<n; i += 1) {
    for (int j = 0; j<p; j += 1) {
      if((i+j)%2==0){
        setPix(img, i, j, 255);
      } else {
        setPix(img, i, j, 0);
      }
    }
  }  
  return img;
}

/**
 *   Import / Export
 **/
// renvoie NULL en cas d'erreur
Image* importerImage(char* filename){
  FILE* f = fopen(filename, "r");
  if(f==NULL){
    return NULL;
  }
  char rand[8];
  fscanf(f, "%s\n", rand);
  int haut, larg;
  fscanf(f, "%d %d\n", &larg, &haut);
  int goodbye;
  fscanf(f, "%d", &goodbye);
  Image *img = creerImage(haut, larg);
  int val;
  int i = 0;
  while(fscanf(f, "%d", &val)==1){
    img->pixels[i] = (uint8_t)val;
    i += 1;
  }
  return img;
}

// renvoie false en cas d'erreur
bool exporterImage(Image* img, char* filename){
  FILE* f = fopen(filename, "w");
  if(f == NULL) return false;
  fprintf(f, "P2\n");
  fprintf(f, "%d %d\n", img->larg, img->haut);
  fprintf(f, "255\n");
  for (int i = 0; i<img->haut; i+=1) {
    for (int j = 0; j<img->larg; j += 1) {
      fprintf(f, "%d ", getPix(img, i, j));
    }
    fprintf(f, "\n");
  }
  fclose(f);
  return true;
}

/**
 * Traitement d'image 
 **/

void miroir(Image *img){
  for(int i = 0; i<img->haut; i += 1){
    for (int j = 0; j<(img->larg)/2; j += 1) {
      uint8_t temp = getPix(img, i, j);
      setPix(img, i, j, getPix(img, i, img->larg-j-1));
      setPix(img, i, img->larg-j-1, temp);
    }
  }
}

/**
 * Steganographie
 **/

// A FAIRE


int main(){
  printf("TP Images\n");
  printImage(importerImage("mp2i.pgm"));


  return 0;
}




    
