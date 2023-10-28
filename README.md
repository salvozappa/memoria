# Memoria

Fantasy computer

## Compile and execute

```sh
gcc -o out/main source/main.c source/dos.c `sdl2-config --libs --cflags` -lGLEW -lGL -lm -lpthread && out/main
```