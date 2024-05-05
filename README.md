# Cache/Revele image

little utility tool to hide pgm images inside other pgm images

## How to use it:

First, install and build the project

```bash
git clone https://github.com/invertime/TP_28.git
cd TP_28
make
```

Then you can use it

```bash
./bin/cache [inputImage] [secretImage] [pathOfFinalImage]
```

or

```bash
./bin/revele [inputFile] [pathOfDiscoveredImage]
```

## Utilities:

(located in `./utils`)

ConvertNG.py: convert .png files to .pgm
