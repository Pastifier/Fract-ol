# Welcome to my first Fractal renderer!

## YOU WILL NEED X11 AND ITS DEPENDENCIES FOR LINUX AND MAC
## IF YOU WANT TO RUN IT ON WINDOWS, YOU WILL HAVE TO USE WSL2
```
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
(replace `apt-get` with your package manager if you don't have it)


To start, clone the repository and build from source like so:
```
git submodule init
git submodule update
make
```

<kbd>
  <h3>Usage:</h3>
  <p>This is some content inside a box.</p>
</kbd>

Julia is different from the other sets provided. You will have to add a seed (any value between -2 and 2 for both the real and imaginary components:
```
./fractol julia a b
```
 
When it starts, you can lock and unlock it using the `A` key. The shape will change depending on your mouse position in the window!

The others are simpler to run:
```
./fractol mandelbrot
./fractol other
```

## Controls:
- ARROW KEYS \- movement/navigation.
- MOUSEWHEEL \- zoom (currently a bit bugged, placing your cursor at the top-left corner of the window will help. It zooms in the middle! xD).
- R \- resets the fractal (zoom and everything. Including Julia).
