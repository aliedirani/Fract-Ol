# Fract'ol

An interactive fractal explorer written in C for the 42 curriculum.

This project is about turning abstract math into something you can drive with your hands. Fract'ol lets you move through fractal space in real time, zoom straight toward the mouse cursor, switch palettes, test different Julia constants, and watch tiny numeric changes explode into completely different shapes.

It is both a graphics project and a curiosity project: part rendering engine, part mathematical playground.

## At a Glance

- 4 fractal types: Mandelbrot, Julia, Burning Ship, Tricorn
- Cursor-centered zoom
- Arrow-key panning
- Multiple color palettes
- Iteration depth controls
- Autoplay mode for ambient exploration
- Clean source split by responsibility

## What Makes This Version Fun

- You are not locked into one static render. The project is built for exploration.
- Julia values are easy to try, which makes the project feel different every time you run it.
- Burning Ship and Tricorn give the repo more personality than a mandatory-only submission.
- The controls are simple enough to demo quickly, but rich enough to keep exploring.

## First Minute Demo

If someone opens the repo and wants to feel the project immediately, this is the fastest route:

```bash
make
./fractol mandelbrot
```

Then try:

1. Zoom into the edge of the Mandelbrot set with the mouse wheel.
2. Pan with the arrow keys.
3. Press `C` a few times to shift the mood of the image.
4. Press `+` to increase detail.
5. Launch a Julia set and compare how different it feels from Mandelbrot.

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

`MLX42` is bundled inside this repository, so there is no extra graphics-library clone step.

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

The classic escape-time fractal. Each pixel is mapped to the complex plane, then tested through repeated iteration of:

```text
z = z^2 + c
```

This implementation also includes a cardioid and period-2 bulb shortcut to skip work on points that are known to remain bounded.

### Julia

Julia sets fix the constant and let the starting point vary. That makes them perfect for experimentation: small parameter changes can produce entirely different structures.

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

A sharper, more dramatic fractal that uses absolute values before squaring. It creates aggressive flame-like forms and feels very different from Mandelbrot.

### Tricorn

A Mandelbrot-relative based on the complex conjugate. It has a colder symmetry and gives the project a strong bonus identity.

## Suggested Exploration Routes

### Route 1: Classic

```bash
./fractol mandelbrot
```

Start wide, zoom toward the boundary, increase iterations, and look for mini-Mandelbrots.

### Route 2: Organic

```bash
./fractol burning_ship
```

Use slow zoom and color changes. This fractal becomes more interesting the deeper you go.

### Route 3: Experimental

```bash
./fractol julia -0.7269 0.1889
```

Try several Julia constants back-to-back and compare how much the geometry changes.

### Route 4: Ambient

```bash
./fractol tricorn
```

Then press `A` to let autoplay take over and turn the project into a self-moving demo.

## Under the Hood

The project is split to keep the code easy to read and easier to defend:

- `main.c` handles startup and argument flow
- `init.c` and `controls.c` manage view defaults and interaction state
- `fractal_calc.c` contains the actual mathematical formulas
- `render.c` maps pixels to the complex plane and paints the frame
- `events.c` and `events_utils.c` handle keyboard, scroll, and zoom logic
- `color.c` and `color_palettes.c` control the visual style
- `parse.c` validates Julia parameters safely
- `cleanup.c` centralizes shutdown behavior

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

## What I Wanted From This Repo

I wanted this repository to feel:

- clear to read
- fast to build
- easy to demo
- pleasant to explore
- more alive than a bare school hand-in

## Technical Notes

- The project currently uses `MLX42`.
- Fractal math and navigation logic are separated from the graphics backend.
- Build artifacts are ignored through `.gitignore`.
- The source is organized in small files to keep the project easier to maintain and explain.

## Author

Created by `aeldiran` as part of the 42 curriculum.
