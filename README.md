# Cub3D – A 42 School Ray‑Caster

Cub3D is a lightweight 3‑D ray‑casting engine written in C for the 42 school curriculum.
It renders a first‑person view of a maze described in a **`.cub`** file, using the
[MiniLibX](https://github.com/42Paris/minilibx-linux) graphics library.

> The project is split into two binaries:
>
> - `cub3d` – the mandatory implementation.
> - `cub3d_bonus` – an optional bonus version with extra features.

---

## 🚀 Getting Started

### Prerequisites

| Component                     | Minimum Version                                                             |
| ----------------------------- | --------------------------------------------------------------------------- |
| **C compiler**                | `cc` or `gcc`                                                               |
| **X11 development libraries** | `libx11-dev`, `libxext-dev`                                                 |
| **MiniLibX**                  | `minilibx-linux` (the repository is included in `minilibx-linux/`)          |
| **libft**                     | The 42 libft library (`libft/`). It is built automatically by the Makefile. |

> On Debian‑based systems:
>
> ```bash
> sudo apt-get install build-essential libx11-dev libxext-dev
> ```

### Building

```bash
# Build the mandatory binary
make all        # creates ./cub3d

# Build the bonus binary (if you want to try the extra features)
make bonus      # creates ./cub3d_bonus
```

The Makefile will:

1. Compile `libft` and MiniLibX.
2. Compile all source files from `srcs/`.
3. Produce `./cub3d` (or `./cub3d_bonus`).

### Running

```bash
# Basic usage
./cub3d <path-to-map.cub>

# Example
./cub3d maps/good/cube.cub
```

> The program opens a window with the rendered map.
> Controls are handled via keyboard events (see `hook_init()` in the source).
> To exit, press **Esc** or close the window.

### Testing

The Makefile provides automated tests that run Valgrind on both good and bad maps:

```bash
# Run all good maps with valgrind
make testgood

# Run all bad maps (expect failures) with valgrind
make testbad

# Run a single map under valgrind
valgrind --leak-check=full --show-leak-kinds=all -q ./cub3d maps/good/works.cub
```

> **Tip:** The `test` target runs the program once on a single sample map without Valgrind.

### Cleaning

```bash
# Remove object files only
make clean

# Full cleanup (objects + binaries)
make fclean
```

---

## 📁 Project Structure

```
├── Makefile               # Build system
├── srcs/                  # Main source code
│   ├── main.c             # Entry point
│   └── ...                # Other .c files
├── srcs_bonus/            # Bonus implementation (optional)
├── includes/
│   └── cub3d.h            # Public header
├── libft/                 # 42 libft library
├── minilibx-linux/        # MiniLibX source
└── maps/
    ├── good/              # Valid map files (.cub)
    └── bad/               # Maps that should fail parsing
```

---

## 🔧 Features

- **Ray‑casting engine**: Calculates wall distances and renders vertical slices.
- **Texture mapping**: Supports different textures for north, south, east, west walls.
- **Player movement**: Forward/backward, rotation, collision detection.
- **MiniLibX integration**: Window creation, image drawing, event hooks.
- **Memory safety**: All heap allocations are freed on exit; Valgrind tests confirm no leaks.

---

## 📚 How the Code Works

1. **Input validation** (`check_input`) – verifies command‑line arguments.
2. **Initialization** (`init_all`) – loads configuration, map file, and sets up data structures.
3. **Parsing** (`parsing`) – reads the `.cub` file into a 2D array of characters.
4. **Game setup** (`game_init`, `player_init`, `init_imgs`) – prepares textures and player state.
5. **Event loop** – MiniLibX hooks (`hook_init`) bind keyboard/mouse events; `mlx_loop_hook` runs the rendering function (`handle_loop`) continuously.

---

## 📦 Bonus Build

If you want to try the extended version (e.g., support for multiple map formats or extra textures), run:

```bash
make bonus
./cub3d_bonus <map.cub>
```

The bonus binary is built from `srcs_bonus/` and follows the same API as the main one.

---

## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.

---
