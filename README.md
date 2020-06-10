
# <center> SyntheseImage : RayTracing
### Authors: LOPES MENDES Ailton, LAMBERT-DELAVAQUERIE Fabien

# Introduction
Ray tracing is a rendering technique for generating an image by tracing the path of light as pixels in an image plane and simulating the effects of its encounters with virtual objects. This technique will produce a high degree of visual realism.
# Installation

Linux installation of sdl library
```bash
sudo apt install libsdl2-2.0-0 libsdl2-gfx-1.0-0 libsdl2-image-2.0-0 libsdl2-mixer-2.0-0 libsdl2-net-2.0-0 libsdl2-ttf-2.0-0
```
Refer to [sdl](https://doc.ubuntu-fr.org/sdl) for more details

Make sure you have -std=c++11 version of c++

Then in the repertory raytracer you will find a makefile
```bash
make
```
### Exemple

```bash
/raytracer$  make
/raytracer$  ./lray -n 1 -i input/sphere.txt -o image.ppm
```
Futher explanations can be found in the raytracer/doc.
