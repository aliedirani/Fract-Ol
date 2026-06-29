*This project has been created as part of the 42 curriculum by aeldiran.*

# Fract'ol 🌀

> An interactive fractal explorer written in C — zoom infinitely into mathematically beautiful sets.

---

## Description

Fract'ol renders complex mathematical fractals in real time using the MLX42 graphics library. The program maps each pixel on screen to a point in the complex plane and iterates a formula to determine whether the sequence escapes to infinity, then colors the pixel based on how quickly it escapes. The result is an infinitely detailed boundary between order and chaos.

This project was built as a 42 School assignment to explore complex numbers, computer graphics optimization, and event-driven programming in C.

**Supported fractals:**
- **Mandelbrot** — the iconic set defined by z² + c, with a cardioid/bulb shortcut for performance
- **Julia** — a family of sets derived from Mandelbrot where c is fixed and z is the variable
- **Burning Ship** — a variation that takes the absolute value of real and imaginary parts before squaring
- **Tricorn** (Mandelbar) — uses complex conjugate iteration instead of standard multiplication

---

## Instructions

### Dependencies

**macOS**
```bash
brew install cmake glfw
```

**Linux (Ubuntu/Debian)**
```bash
sudo apt-get install cmake libglfw3-dev libxcursor-dev libxinerama-dev libxi-dev
```

### Clone and build

```bash
git clone <your-repo-url> fractol
cd fractol
git clone https://github.com/codam-coding-college/MLX42.git
make
```

### Run

```bash
./fractol mandelbrot
./fractol julia -0.4 0.6
./fractol burning_ship
./fractol tricorn
```

If no argument or an invalid one is given, the program prints usage and exits cleanly.

### Makefile rules

| Rule | Action |
|------|--------|
| `make` / `make all` | Build MLX42 then compile `fractol` |
| `make bonus` | Same as `all` (bonuses are integrated into the main binary) |
| `make clean` | Remove object files |
| `make fclean` | Remove object files, binary, and MLX42 build cache |
| `make re` | Full rebuild from scratch |

---

## Controls

| Input | Action |
|-------|--------|
| Mouse wheel | Zoom in / out **at the cursor position** |
| Arrow keys | Pan the view |
| `+` / `-` | Increase / decrease iteration depth |
| `C` | Cycle through 4 color palettes |
| `R` | Reset current fractal to default view |
| `A` | Toggle autoplay (random zoom animation) |
| `H` | Print controls to terminal |
| `I` | Print current fractal state to terminal |
| `ESC` | Close the window and exit cleanly |
| Window ✕ | Close the window and exit cleanly |

---

## Interesting Julia constants to try

```bash
./fractol julia -0.4 0.6          # Dendrite
./fractol julia 0.285 0.01        # Douady's rabbit
./fractol julia -0.70176 -0.3842  # Siegel disk
./fractol julia -0.835 -0.2321    # Dragon
./fractol julia -0.7269 0.1889    # Snowflake
./fractol julia 0.0 -0.8          # San Marco
```

---

## Project structure

```
fractol/
├── fractol.h          # Main header — all types, constants, prototypes
├── main.c             # Entry point, argument parsing, window init
├── init.c             # Fractal view initialization
├── fractal_calc.c     # Mandelbrot, Julia, Burning Ship, Tricorn math
├── render.c           # Pixel-to-complex mapping, render loop
├── color.c            # Color dispatch by scheme index
├── color_palettes.c   # Rainbow, electric, fire, grayscale palettes
├── events.c           # Key, scroll, and close hooks
├── events_utils.c     # Pan, zoom-at-point, move/action key handlers
├── controls.c         # Iteration, reset, color scheme changers
├── autoplay.c         # Auto-zoom animation loop
├── parse.c            # ft_atof with validation (ok flag)
├── cleanup.c          # MLX resource cleanup, error_exit
├── fractol_help.c     # Usage, controls, info, banner printers
├── utils.c            # ft_isdigit, ft_strcmp
└── Makefile
```

---

## Bonus features implemented

All bonus points from the subject are included in the main binary:

- ✅ Two extra fractals: **Burning Ship** and **Tricorn**
- ✅ Zoom follows the **actual mouse cursor position**
- ✅ **Arrow key** panning
- ✅ **Color range shift** — 4 cycling palettes (rainbow, electric, fire, grayscale)

Additional extras beyond the subject:
- `+` / `-` iteration depth control
- `R` view reset per fractal type
- `A` autoplay mode with random zoom animation
- Mandelbrot cardioid and period-2 bulb skip optimization
- Clean resource-freeing on all exit paths

---

## ⚠️ Important pre-defense note

This project uses **MLX42** (the Codam rewrite of MiniLibX using OpenGL/GLFW). The subject specifies **MiniLibX**. Before your defense, verify with your campus staff whether MLX42 is accepted for Fract'ol. If your campus strictly requires the original MiniLibX, the rendering and hook API calls would need to be ported — the math and logic files are completely independent of the graphics library and would not change.

---

## Known issues and things to verify

- `fprintf` is used in `cleanup.c` for error output. The subject's allowed functions list does not include `fprintf` — only `write`, `perror`, `strerror`, and `ft_printf`. Replace with `ft_putstr_fd(message, 2)` before submission if strict norm checking is enforced at your campus.
- Bonus features live in the same source files as mandatory ones (no `_bonus.c` separation). Some evaluators accept this; others apply the strict rule. Check with your campus.
- Run `norminette` on all files before the defense. The 42 Norm forbids functions over 25 lines, more than 5 function definitions per file, and more than 4 parameters per function.

---

## Resources

### Fractals and complex numbers
- [Mandelbrot Set — Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia Set — Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- [Burning Ship Fractal — Wikipedia](https://en.wikipedia.org/wiki/Burning_Ship_fractal)
- [Lode's Computer Graphics Tutorial — Fractals](https://lodev.org/cgtutor/juliamandelbrot.html)
- [The Mandelbrot Set: How It Works — YouTube, Numberphile](https://www.youtube.com/watch?v=NGMRB4O922I)
- [Smooth coloring for the Mandelbrot set](http://linas.org/art-gallery/escape/escape.html)

### MLX42
- [MLX42 GitHub — Codam Coding College](https://github.com/codam-coding-college/MLX42)
- [MLX42 Documentation / Wiki](https://github.com/codam-coding-college/MLX42/wiki)

### How AI was used in this project

AI (Claude) was used for the following tasks during development:

| Task | Files affected |
|------|----------------|
| Color palette math (smooth iteration coloring, sinusoidal palette formulas) | `color_palettes.c` |
| Zoom-at-cursor formula derivation | `events_utils.c` — `zoom_at_point` |
| Cardioid / period-2 bulb shortcut for Mandelbrot performance | `fractal_calc.c` — `in_cardioid_or_bulb` |
| Makefile cross-platform Darwin/Linux flag detection | `Makefile` |
| `ft_atof` with validity flag (`ok`) for safe Julia argument parsing | `parse.c` |
| README structure and compliance check against the subject | This file |

All AI-generated code was reviewed, understood, and tested manually before inclusion. Nothing was copy-pasted without verifying the logic line by line.
