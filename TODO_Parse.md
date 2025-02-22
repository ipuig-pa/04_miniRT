By 22/02
- MLX42 included to avoid header error everytime
- makefile edited with MLX42 included
- some changes in header structs(with comments aside for everything i changed)
- parser.h (not sure necessary or not, but alighn with your struct of isolate header for different functionality part, easy to delete later if unwanted)
- Parsing folder: 
	- valid_file(); parse_line(); parse_vector(); parse_color();parse_camera(); parse_light(); parse_obj()==>sphere/		cylinder/plane()
- LOGIC FLOW: valid_file => read_file()(into string with many lines) => valid_para()(to split string into tokens and check_validity) => parse_scene()

CHECK_LIST:
- File management (non-existent, empty files, etc.)
- The types correspond to the requested types and nothing else 
- There is a MAXIMUM of one camera, one diffused light and one ambient light (there can be 0 or one, but no more!)
- Each line corresponding to a type must have the right number of elements
- If it's a color, it has to be in the right range (0 - 255) and the same goes for orientation vectors (-1,1), etc. Make sure all digits are in the correct range for each type.
- For each object, you also need to pay attention to its specific characteristics (whether the diameter or height of a cylinder is non-negative, for example, or other things).

PARSE FILE
    - correct name.rt
    - non-empty file
PARSE SCENE
    - verify pasred ID: A, C, L pl(plane), cy(cylinder), sp(sphere)
    - check num of paras: (A3, C4, L3, sp4, pl4, cy6)
    - put in to struct
        - camera
        - objs: sp, cy, pl
        - light: ambiance, point of lights

(struct map)
├── 1. Setup & Basics
│   ├── Setup Makefile & MLX
│   ├── Define Structs: Camera, Ray, Objects, Light
│   ├── Read Scene File (.rt format)
│
├── 2. Scene Parsing
│   ├── Parse Camera
│   ├── Parse Lights
│   ├── Parse Objects (Sphere, Plane, Cylinder)
│   ├── Store parsed data into a Scene struct
│
├── 3. Ray Casting
│   ├── Generate Rays from Camera
│   ├── Compute Ray-Object Intersections
│   │   ├── Sphere Intersection
│   │   ├── Plane Intersection
│   │   ├── Cylinder Intersection
│   ├── Find Closest Object Hit
│
├── 4. Lighting & Shadows
│   ├── Implement Phong Lighting Model
│   │   ├── Ambient Light
│   │   ├── Diffuse Light
│   │   ├── Specular Light
│   ├── Cast Shadow Rays
│
├── 5. Rendering & Display
│   ├── Convert Colors to Pixels
│   ├── Display Scene in MLX Window
│   ├── Handle User Inputs (Exit, Camera Movement)
│
└── 6. Bonus Features (Optional)
    ├── Reflections & Refractions
    ├── Anti-Aliasing
    ├── Textures & Multi-threading