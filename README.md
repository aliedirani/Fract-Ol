# Fract'ol

Interactive fractal explorer written in C for the 42 curriculum.

This project renders mathematical fractals in real time using MLX42, with zoom, panning, palette switching, multiple fractal types, and a small autoplay demo mode.

## Features

- Mandelbrot set
- Julia set with custom parameters
- Burning Ship fractal
- Tricorn fractal
- Zoom at cursor position
- Arrow-key panning
- Multiple color palettes
- Iteration depth controls
- Autoplay mode

## Build

### macOS

```bash
brew install cmake glfw
make
```

### Linux

```bash
sudo apt-get install cmake libglfw3-dev libxcursor-dev libxinerama-dev libxi-dev
make
```

MLX42 is bundled in this repository, so you do not need to clone it separately.

## Usage

```bash
./fractol mandelbrot
./fractol julia -0.4 0.6
./fractol burning_ship
./fractol tricorn
```

If invalid arguments are passed, the program prints usage instructions and exits cleanly.

## Controls

| Input | Action |
|------|--------|
| Mouse wheel | Zoom in and out at cursor position |
| Arrow keys | Move the view |
| `+` / `-` | Increase or decrease iteration count |
| `C` | Change color palette |
| `R` | Reset the current fractal view |
| `A` | Toggle autoplay mode |
| `H` | Print controls in terminal |
| `I` | Print current fractal info |
| `ESC` | Exit |

## Project Structure

```text
Fractol/
|-- main.c
|-- init.c
|-- render.c
|-- fractal_calc.c
|-- events.c
|-- events_utils.c
|-- controls.c
|-- color.c
|-- color_palettes.c
|-- autoplay.c
|-- parse.c
|-- cleanup.c
|-- utils.c
|-- fractol_help.c
|-- fractol.h
|-- Makefile
`-- MLX42/
```

## Notes

- The project currently uses MLX42 instead of the historical MiniLibX.
- The fractal math and most project logic are independent from the graphics layer.
- Mandelbrot includes a cardioid and period-2 bulb shortcut for better rendering performance.

## Julia Examples

```bash
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
./fractol julia -0.70176 -0.3842
./fractol julia -0.835 -0.2321
./fractol julia -0.7269 0.1889
./fractol julia 0.0 -0.8
```

## Repository Status

- Clean project structure
- Vendor library kept inside `MLX42/`
- Build artifacts ignored through `.gitignore`
- Ready for GitHub and 42-style evaluation workflow
