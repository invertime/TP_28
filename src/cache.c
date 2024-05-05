#include <stdio.h>

#include "include/image.h"

Image *cacher(Image *support, Image *secret){
    redim(secret, support->haut/2, support->larg/2);
    Image *img= copieImage(support);
    for (int i = 0; i < secret->haut; i+=1)
    {
        for (int j = 0; j < secret->larg; j+=1)
            {
                uint8_t secretPix = getPix(secret, i, j);
                for (int k = 0; k < 4; k++)
                {
                    uint8_t mask = 0b11 << (6 - 2*k);
                    setPix(img, i+k, j+k, (getPix(support, i+k, j+k)|0b1111110)|((secretPix&mask)>>2*k));
                }
            }
    }
    return img;
}

void usage(){
    printf("Command usage:");
    printf("cache [inputImage] [secretImage] [pathOfFinalImage]");
    printf("Hide an image inside another a pgm image");
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