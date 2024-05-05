#include <stdio.h>

#include "include/image.h"

Image *cacher(Image *support, Image *secret){
    secret = redim(secret, (support->haut-1)/2, (support->larg-1)/2);
    Image *img= copieImage(support);
    for (int i = 0; i < secret->haut; i+=1)
    {
        for (int j = 0; j < secret->larg; j+=1)
            {
                uint8_t secretPix= getPix(secret, i, j);
                for (int k = 0; k < 2; k+=1){
                    for(int l = 0; l < 2; l+=1){
                        uint8_t mask = 0b11 << (6 - 2*(2*k+l));
                        setPix(img, (2*i)+k, (2*j)+l, (getPix(img, (2*i)+k, (2*j)+l) & 0b11111100) | ((secretPix&mask)>>(6-2*(2*k+l))));
                    }
                }
            }
    }
    return img;
}

void usage(){
    printf("Usage: cache [inputImage] [secretImage] [pathOfFinalImage]\n");
    printf("Hide an image inside another a pgm image\n");
}

int main(int argc, char *argv[])
{
    if(argc<4){
        usage();
        return 1;
    } else {
        exporterImage(cacher(importerImage(argv[1]), importerImage(argv[2])), argv[3]);
    }

    return 0;
}