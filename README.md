# Fract'ol

An interactive fractal explorer written in C for the 42 curriculum.

Fract'ol turns complex-number math into a real-time visual playground. You can launch different fractal families, zoom directly toward the mouse cursor, shift the viewport, cycle through palettes, and explore how tiny numerical changes create wildly different patterns.

## Why This Project Is Interesting

- It mixes math, graphics, and event-driven programming in one compact project.
- It makes the Mandelbrot and Julia worlds feel interactive instead of theoretical.
- It shows clean separation between rendering, controls, parsing, and fractal formulas.
- It includes bonus-style exploration features without losing the core project focus.

## Highlights

- Mandelbrot set
- Julia set with custom parameters
- Burning Ship fractal
- Tricorn fractal
- Cursor-centered zoom
- Arrow-key panning
- Multiple color palettes
- Iteration depth control
- Autoplay demo mode

## Quick Start

### macOS

```bash
brew install cmake glfw
make
./fractol mandelbrot
```

### Linux

```bash
sudo apt-get install cmake libglfw3-dev libxcursor-dev libxinerama-dev libxi-dev
make
./fractol mandelbrot
```

`MLX42` is already bundled in this repository, so there is no extra graphics-library clone step.

## Run

```bash
./fractol mandelbrot
./fractol julia -0.4 0.6
./fractol burning_ship
./fractol tricorn
```

If invalid arguments are provided, the program prints usage instructions and exits cleanly.

## Controls

| Input | Action |
|------|--------|
| Mouse wheel | Zoom in and out at the cursor position |
| Arrow keys | Move the viewport |
| `+` / `-` | Increase or decrease iteration depth |
| `C` | Cycle color palettes |
| `R` | Reset the active fractal view |
| `A` | Toggle autoplay mode |
| `H` | Print controls in the terminal |
| `I` | Print current fractal information |
| `ESC` | Exit the program |

## Fractals Included

### Mandelbrot

The classic set where each point is tested through repeated iteration of `z = z^2 + c`. This implementation also includes a cardioid and period-2 bulb shortcut to avoid wasting time on points known to stay bounded.

### Julia

The Julia set fixes the constant and lets the starting point vary. Small changes to the chosen constant create dramatically different structures.

Suggested values:

```bash
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
./fractol julia -0.70176 -0.3842
./fractol julia -0.835 -0.2321
./fractol julia -0.7269 0.1889
./fractol julia 0.0 -0.8
```

### Burning Ship

A sharp, flame-like fractal created by taking absolute values before squaring.

### Tricorn

A Mandelbrot-relative that uses the complex conjugate and produces a very different symmetry.

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

## Build Rules

| Command | Effect |
|--------|--------|
| `make` | Build `MLX42` and compile `fractol` |
| `make bonus` | Build the same binary with integrated bonus features |
| `make clean` | Remove object files |
| `make fclean` | Remove object files, binary, and `MLX42/build` |
| `make re` | Full rebuild |

## Technical Notes

- The project currently uses `MLX42`.
- Fractal math and navigation logic are separated from the graphics backend.
- The project is organized in small source files to stay easier to read and easier to defend.
- Build artifacts are ignored through `.gitignore` for a cleaner repository.

## Repository Goals

This repository aims to be:

- easy to clone
- easy to build
- easy to evaluate
- easy to read for another 42 student

## Author

Created by `aeldiran` as part of the 42 curriculum.
