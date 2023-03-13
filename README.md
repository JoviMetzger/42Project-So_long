# 🐬 so_long

This repository contains a 2D game called "so_long" that was created as a basic computer graphics project. The game helps to improve skills in window management, event handling, colors, textures, and more using the MiniLibX library. 

## About

The game involves navigating a player through a map composed of only 5 characters: 
- 0 for an empty space,
- 1 for a wall,
- C for a collectible,
- E for a map exit,
- P for the player’s starting position.

Example of a minimal **.ber** map:
```bash
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Installation

To execute the program, follow the steps below:

1. Compile the game by running the following command:
```bash
make
```
2. Finally, execute the program using the following command: 
```bash
./so_long <./path_to_map/map.ber>
```
OR alternatively, you can use the following command to compile and run the game in one step:
```bash
make open
```

## Resources

- [MiniLibX documentation](https://github.com/codam-coding-college/MLX42)
- [Project subject](https://cdn.intra.42.fr/pdf/pdf/68774/en.subject.pdf)
