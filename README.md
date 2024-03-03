<div align="center">

# Welcome to My First Fractal Renderer!

</div>

<kbd style="font-size: 18px">
  <h1 align="center">Prerequisites:</h2>
  <p align="center">You will need X11 and its dependencies for Linux and Mac.</p>
  <p align="center">If you want to run it on Windows, you will have to use WSL2.</p>

  <pre align="center">
    <code align="center">
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
    </code>
  </pre>
  <p align="center">(replace `apt-get` with your package manager if you don't have it)</p>

  <h1 align="center">Getting Started:</h2>
  <pre align="center">
    <code align="center">
git submodule init
git submodule update
make
    </code>
  </pre>

  <h1 align="center">Usage:</h2>

  <h3 align="center">Julia Set:</h3>
  <p align="center">Julia is different from the other sets provided. You will have to add a seed (any value between -2 and 2 for both the real and imaginary components):</p>
    <pre align="center">
    <code align="center">
./fractol julia a b
    </code>
  </pre>
  

<p align="center">When it starts, you can lock and unlock it using the `A` key. The shape will change depending on your mouse position in the window!</p>

<p align="center">The others are simpler to run:</p>
    <pre align="center">
    <code align="center">
./fractol mandelbrot
./fractol other
    </code>
  </pre>

<h1 align="center">Controls:</h2>
<ul align="center">
  <li>ARROW KEYS: Movement/Navigation.</li>
  <li>MOUSEWHEEL: Zoom (currently a bit bugged, placing your cursor at the top-left corner of the window will help. It zooms in the middle! xD).</li>
  <li>R: Resets the fractal (zoom and everything, including Julia).</li>
</ul>

</kbd>
