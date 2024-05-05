#include <stdio.h>

#include "include/image.h"

Image *reveler(Image *img){
    Image *secret= creerImage(img->haut/2, img->larg/2);
    for (int i = 0; i < secret->haut; i+=1)
    {
        for (int j = 0; j < secret->larg; j+=1)
            {
                uint8_t pix = 0;
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        pix |= (getPix(img, 2*i+k, 2*j+l) & 0b00000011)<<(6-2*(k+l));
                    }
                }
                setPix(secret, i, j, pix);
            }
    }
    return secret;
}

void usage(){
    printf("Usage: revele [inputFile] [pathOfDiscoveredImage]\n");
    printf("Reveal an hidden image inside a pgm image\n");
}

int main(int argc, char *argv[])
{
    if(argc<3){
        usage();
        return 1;
    } else {
        exporterImage(reveler(importerImage(argv[1])), argv[2]);
    }

    return 0;
}