# MiniRT

## Team

---

This project was developed by:

- U-Mina (parsing and window management - hooks)
- ipuig-pa (rendering, transformations and window management - hooks)

## Project Overview

---

This project consists on a basic ray tracer. 

Three-dimensional shapes are rendered in high quality in a black space using a Ray Tracing approach: intersections of simulated rays of light with each object in a scene are computed in order to retrieve the color of each pixel in the camera viewport.

Transformation of the scene objects are rendered in real-time.

### Resources

- miniLibX: this project uses miniLibX graphical library, from 42 School.

## Rendering

---

### Compilation

- Use `make` to compile the project.

### Running

- Run the program with the scene file name as an argument: `./miniRT [scene.rt]` and wait until a high quality image of the scene is rendered.
- Instructions for real-time transformation of the scene will appear (also accessible down in the “Real-time transformation of scene” of this README).

### Scene files

The scene file must have a `.rt` extension. 

Each line should refer to one of the supported objects. They can appear in any order, and multiple line breaks are accepted between them. 

Each supported object has an identifier, which appears in brackets in the “Supported Objects” section. Uppercase identifiers can appear only once (so just one object of this type is allowed in each scene).

**Parameters**

For each object, some parameters should be given, separated by blank spaces. The parameters to be given by each object is defined in “Supported Objects” section. The parameters are checked to accomplish the following requirements:

- Colors: must be a value in the range [0-255] for each of the 3 components (R, G, B).
- Light ratio: must be in the range [0-1].
- Positions: refer to the coordinates in the 3D space (x, y, z) of the object position.
- Vectors: refer to 3D-normalized vectors, in range [-1, 1] for each axis (x, y, z).
- Material: optionally, a identifier code for the material of a solid object can be provided, being:
    - 0: Matte (will provide a matte effect to the object)
    - 1: Plastic (will provide a plastic effect to the object)
    - 2: Metallic (will provide a metallic effect to the object)
    
    If non provided, material is set to Matte (0) by default.
    

**Supported Objects**

For each of the objects 

- Camera (C)
    
    “C” |  position | vector of camera orientation | horizontal field of view (in deg. º)
    
- Lights:
    - Ambient (A)
        
        “A” | light ratio | light color
        
    - Point (L)
        
        “L” | light position | light ratio | light color
        
- Solids:
    - Sphere:
        
        “sp” | center position | diameter | color | material (optional)
        
    - Plane
        
        “pl” | position of a point in the plane | normal vector | color | material (optional)
        
    - Capped cylinder
        
        “cy” | center position | axis vector | diameter | height | color | material (optional)
        

**Example of .rt file**

```
# multi-object example scene
C 0,0,0 0,0,-1 28

A 0.1 255,255,255

L 6,0,-200 0.6 255,255,255

sp 0,0,-200 10 255,0,255 
sp 0,20,-200 5 255,0,0 2

pl 0,-7,0 0,1,0 0,0,255 2
pl -7,0,0 1,0,0 255,0,255 1
pl 0,0,-250 0,0,1 0,0,255 0

cy 2,3,-150 1,-1,1 3 10 255,0,0 2
```

### **Supported features**

- Solid representations (spheres, planes and capped cylinders)
- Colored lights
- Shadows
- Full Phong Shading (ambient light, diffuse light and specular light)
- Material effect (matte, plastic or metallic finish)
- Real-time transformations of camera, light and objects using mouse / key hooks.

### Resolution

Window width and height are specified in the environment header file (inc/env.h). 

When launching the program, wait until high quality image of the scene is rendered.
Every time any change is made, the scene will be rendered in low quality (10% resolution) for the reason of performance. Re-render the current scene in high quality, as explained in next section “Real time transformation of scene”, is always possible.

### Real-time transformation of scene

Instruction for Keyboard and Mouse Activities appear in the terminal when running the program, as follow:

**Press 'SPACE':**
Re-renders current scene with high quality.

**Left Mouse Click on Objects:**
Select or deselect the Object clicked (selected objects appear highlighted)

**Press 'L':**
Select or deselect Light (selected light appears highlighted in blue)

**'W'-'A'-'S'-'D'-'Q'-'E':**
· If any object/light has been selected, following movement will be applied to object/light.
· Else, movement will be applied to Camera
Translations:
W: move UP              S: move DOWN
A: move LEFT            D: move RIGHT
Q: move FORWARD         E: move BACKWARD

**↑ ↓ → ← '<' '>':**
· If any object has been selected, following rotation will be applied to object.
· Else, rotation will be applied to Camera
Rotations:
↑: tilt UP              ↓: tilt DOWN
←: turn LEFT            →: turn RIGHT
<: roll LEFT            >: roll RIGHT

**Press '*' in Numeric Pad, on a selected cylinder:**
Select the width (just bases will remain highlighted)

**Press '/' in Numeric Pad, on a selected cylinder:**
Select the height (just the side surface will remain highlighted)

**Scroll the wheel:**
· If any object has been selected:
Scale the object.
· If cylinder Width or Height are selected:
Scale just Width / Height of the cylinder.
· If the Light is selected:
Change the diffuse light ratio.
· If nothing is selected:
Zoom In and Out Camera

**'+' and '-' in Numeric Pad:**
· If any object has been selected:
Scale the object.
· If cylinder Width or Height are selected:
Scale just Width / Height of the cylinder.
· If the Light is selected:
Change the diffuse light ratio.
· If nothing is selected:
Change the environment light ratio.

**Press '0' in Numeric Pad:**
Erase all changes made, and revert to original parsed scene.

**Press 'ESC' or Click 'X':**
Exit this program!

## Examples of output

---

![Alt text](https://github.com/ipuig-pa/04_miniRT/blob/master/images/basic1_matte.png)
Simple sphere in matte material



![Alt text](https://github.com/ipuig-pa/04_miniRT/blob/master/images/basic1_plastic.png)
Simple sphere in plastic material



![Alt text](https://github.com/ipuig-pa/04_miniRT/blob/master/images/basic1_metallic.png)
Simple sphere in metallic material



![Alt text](https://github.com/ipuig-pa/04_miniRT/blob/master/images/columns.png)
Multi-object scene recreating a column landscape



![Alt text](https://github.com/ipuig-pa/04_miniRT/blob/master/images/multi_obj2.png)
Multi-object scene used in example .rt file and in real-time transformation video



https://user-images.githubusercontent.com/ipuig-pa/04_miniRT/assets/1/miniRT.mp4
Real-time transformations
