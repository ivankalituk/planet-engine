# Planet Engine

A highly focused game engine designed to build a tactical simulator inspired by the military aspects 
of the Civilization series, with a stronger focus on tactical gameplay and a 3D spherical planet 
replacing the traditional 2D map.

## About

The engine was created primarily as a learning project, but its long-term goal is to provide the 
foundation for a game.

The core concept is the creation of a spherical terrain planet with mountains, hills, plains, and other
terrain features, with additional 3D objects such as forests, jungles, and cities placed on its surface.
A hexagonal grid is then applied over the planet.

## Current State

The engine base, shaders, and a procedurally generated spherical mesh have been implemented.

## Planned Features

### Current Plans

* Add a camera
* Add camera orbit controls around the planet
* Add mouse-based camera rotation
* Add camera movement inertia
* Add a hexagonal grid

### Future Plans

* Add terrain mesh generation
* Implement the user interface
* Implement planet customization and editing
* Add map saving and loading

## Building

The current debug build can be run from:

`out/build/x64-debug/planet-engine.exe`

## Project Structure

* `src/main.cpp` — main application file
* `external/` — GLAD files and configuration
* `src/graphics/` — shaders and graphics-related code
* `src/geometry/` — procedural generation of 3D geometry

## Roadmap

* Create a world editor for assigning terrain properties to cells and configuring map size
* Add map saving, editing, loading, and deletion
* Add units, including movement, combat, and animation
* Implement a hotseat-style multiplayer mode
* Further features will be planned as development progresses
