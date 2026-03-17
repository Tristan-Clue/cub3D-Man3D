# cub3D-Man3D
### Checklist
- run `make`
- wait for compilation (be patient)
- run `./cub3D` with path to maps inside `levels` directory
- example: `./cub3D levels/42.cub`
- now try it out

#### Controls:
- WASD (Movement)
- Left and Right (Camera panning)
- Mouse movement (Only left and right, no looking up or down, twat)
- That's it, it's supposed to be simple

## Description
This is a game, a game to replicate Wolfenstein 3D, dubbed Cub 3D.
The goal is to learn about <b>Ray Casting</b>.<br>Raycasting is
a technique that shoots an invisible, straight-line ray from an origin point to detect collisions or render 3D-looking environments from 2D maps. (Thanks Gemini AI for explanation)<br>
There's also parsing, which takes information from the `.cub` files to extract the textures and map data needed for the game, and to make sure to verify all resources needed for the game to make sure everything works so the rendering (my part) doesn't go haywire and implode like an unstable nuclear plant.<br>
# <s>(Thanks <b>Pointer King, Chiang</b>)</s><br><br>
#### Other features?
- Wall Collisions (This broke me fr fr)
- Mouse movement (Made me thought I broke my code like big time)
- Animated Sprites, the lantern (Actual proper sampling and upscaling, not that bad)
<br><br>
The game is still prone to bugs to be fixed, not even thoroughly checked so if it breaks, please raise and issue and I shall look into it.... someday....
<br><br>
### Credits and Licensing
- What am I supposed to put here, this is my first time
<br>

#### References
- https://lodev.org/cgtutor/raycasting.html (Best Guide there is)
- ChatGPT (Helped me understand what I'm writing sometimes)
- My friend's code 
