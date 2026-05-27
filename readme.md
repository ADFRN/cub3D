*This project has been created as part of the 42 curriculum by ttiprez, afournie.*

# CUB3D

## Description

CUB3D is a 3D maze exploration project inspired by the legendary game **Wolfenstein 3D**. The goal is to implement a basic raycasting engine from scratch in C, using the **miniLibX** graphical library.

The player navigates through a map defined in a `.cub` configuration file, rendered in a pseudo-3D perspective. The project covers key concepts in computer graphics, mathematics, and low-level programming.

Key features:
- Raycasting-based 3D rendering
- Textured walls (North, South, East, West)
- Configurable floor and ceiling colors
- Keyboard-controlled player movement and rotation
- Strict `.cub` map format parsing with error handling

---

## Instructions

### Requirements

- GCC compiler
- miniLibX (included or installed separately depending on your system)
- GNU Make

### Compilation

```bash
make
```

### Usage

```bash
./cub3D <path/to/map.cub>
```

**Example:**
```bash
./cub3D maps/example.cub
```

### Controls

| Key | Action |
|-----|--------|
| `W` `A` `S` `D` | Move forward / left / back / right |
| `←` `→` | Rotate camera |
| `ESC` | Quit the program |

### Map format (`.cub`)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
1N0001
111111
```

---

## Resources

### Documentation & References

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — The essential reference for understanding raycasting from scratch
- [miniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx) — Unofficial but thorough guide to the graphical library
- [42 miniLibX Linux sources](https://github.com/42Paris/minilibx-linux) — Official repository
- [DDA Algorithm (Wikipedia)](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)) — The line-stepping algorithm used in raycasting
- [Wolfenstein 3D source code](https://github.com/id-Software/wolf3d) — Historical reference, the original raycasting game

### AI Usage

AI (Claude / ChatGPT) was used during this project for the following tasks:

- **Debugging**: Identifying off-by-one errors in raycasting calculations and wall distance formulas
- **Code review**: Checking for memory leaks and validating edge cases in map parsing
- **Explanations**: Clarifying mathematical concepts (DDA, FOV, fisheye correction) when the tutorial wasn't sufficient
- **Refactoring suggestions**: Improving code structure and readability in large functions
