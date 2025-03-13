IRENE (rendering):

27/02/2025
<!-- (-Adapt everything to header with cam, etc with direct structures and not pointers, or change back just to test and then change it after solving shadows etc) -->
<!-- - SHADOW OF BLUE PLANE OVER ROTATED PINK PLANE. GET RID!!! (how to handle direct rays and shadow rays in transformations: look to output, there are some hints, the direct ray is finding the hit below the blue plane (y<-50)!?!?!) -->
<!-- - try rotations, transl (create port in the main for the moment, to use the axis there for the rotations of planes, etc) -->
<!-- -> understand the proper meaning of axis rotation!!! (with respect to the base, ...? movement broadness??) (pivot point: proximal or distal) -> //to rotate uisng a specific point as pivot, combine to the origin of coordinates, with translation back and forth.
-> resize!!! -->
<!-- -> light movement!?!? -->
<!-- -> cylinder somehow attach the objects circles if there is a rotation /transl / etc? ->PROBLEMS IN SCALE, because we have to translate to circle center to origin but then not back to original position of the center, but moved having in mind the crescent ratio of the cylinder (or think how can we keep track of them) -->
<!-- E -> be careful that circles are contigupus cyl and the first is subtracting axis * h/2 and the second is adding axis * h/2 to the center of the cyl -->
<!-- -> for rotations and scaling, combine always with translation to origin and back!!! -->
<!-- E -> initialize all objects with identity matrix
E -> initialize material properties!? -->
<!-- E -> create port after parsing? -->
<!-- -> resize circles according to cylinder height and width!? -->
<!-- - Store all hits and not only the most proximal??? For reflection? --> NOT DONE
<!-- - Store all pixel hits to handle more efficiently light changes -->
<!-- - need to normalize vector after transformations?!?!! (try with different cases!) -->

<!-- - Rotations and scaling will be done in relation to the center of the object or the given point for planes!? -->
<!-- - thickness of planes?!?! when are exactly in the camera center?! -->

<!-- !!!!- Normal of planes and circles: do not use both indistintly, because if light is behind they will get illuminated?!?!??! Just the one towards the camera?? or how to chose the one to use? In fact the one towards the camera does not work with rotations/transl -->

<!-- - add w dimension in linalg utils -->
<!-- - Instead of compute the inverse matrix in find hit and shading functions, store directly the inverse mtrix in the object m?? -> for the moment it is ok bc it is just computed once! -->

<!-- LINALG: -->
<!-- - linalg funcitons, put order: use only add / sub.
- Use the same structure for points and vectors?? (tuples with w, instead of 2 different point and vector) -->
<!-- - use function create_vector/create point to be able to create without need to do the 3 dimensions? -->
<!-- - create enum in struct as RGB, to refer to both the x, y, z and iterate for the linalg operations. -->

08/03/2025
<!-- - Hooks: how to handle? (for ex. in env have int i to represent selected object. Ctrl + arrows to iterate through objects (add to i). AWSD to rotate (decide 3 dimensions: or for ex, X, Y, Z to rotate in each axis of the viewport), + - to make bigger, arrows to translate selected object). when iterating through objects, if it is a cylinder somehow attach the objects circles if there is a rotation /transl / etc? (apply the same matrix to both the next 2 and then skip them) -->
<!-- 
- light movement?
- shine in cylinder -->
- makefile: check it is correct to remake when one is resaved, and git pull minilibx

<!-- week 24/02/2025: understand matrices, transl and rotations?
week 03/03/2025: rotations etc -->
<!-- week 10/03/2025: shiny, shadows, reflection, patterns, etc -->
<!-- - Specular reflection: Shine in proper place, just in objects that haev shine, where to put shininess and where 0.9, etc. -->
<!-- - Solve shading in planes when specular reflection is added -->

<!-- - establish tmax and tmin for ray impact (r(t) = o + td) --> NOT DONE
<!-- - decide pointers or direct objects inside scene -->
<!-- - light color not working properly -->

<!-- - somehow do all the hits and then all the shading, to be easier when light changes, no need to re-render -> correspondance of each pixel to each hit (store the pixel i, j in the hit structure) and have a structure of hits inside the scene instead of just one hit that is updated -->

<!-- MORE
- include triangle intersection, so we can have complex forms represented as a meshed of triangles
- Bouncing, reflextion, refraction, etc
- Antialiasing (to smooth contours)
- optimize checking of ALL objects to find first hit? objects as a linked list according to their proximity to camera?? OR not, beause when it hits one, we have to change again the order? OR subdivide the space? -->NOT DONE

<!-- - Include functions for vector operation (add and substract without needing to do everytime in each function) -->

<!-- EDGE CASES: -->
<!-- - light inside an object (illuminated from the inside?) -->
<!-- - camera inside an object?? -->
<!-- - plane in the middle of the light!!!! Has some "pixelations", as some is hitting the plane and some the light!?!? -> IMPORTANT TO SOLVE!!! -->

TOGETHER DECIDE:
- norm_vector and u_vector are the same!?!? unify!?!
<!-- - Use float or double (different function prototype in math library function) -->
<!-- E -> Parsing material type (metal, plstic, matte) an initialize k_s and n_s accordint to that -->
<!-- - Define materials? (shiny metal / glossy plastic / matte) with specific k_s and n_s?? Or have directly the parameters in the object? -->
<!-- - Eliminate cylinder caps (make scaling and rotation difficult)?? -->
<!-- - Bonus:
	- Include light color
	- Take from the scene file if we are introducing a filter?? -->

HOOKS
<!-- - Scroll mouse has some errors!?!? -->
<!-- - Increase efficency (prerender with bad quality and when space press, rerender correctly) -->
<!-- - Rotation of objects:
	E?- Mouse click to select or to release (shade in white the selected object!?!?)
	- Cast a ray through that pixel in the viewport. Identify the object. Shade the object.
	- apply rotation to the selected object
	- E?- mouse click to select the object -->
<!-- - Double click on object to duplicate?? Or create new white objects with hooks?? --> NOT DONE YET
<!-- - Add color changing of selected object with RGB!?!? -->
<!-- - Write instructions on hooks (README) or better in a prompt in the terminal when we launch the program
E- 0 to reset to default scene! (parse again and restart) -->
<!-- - how to change parameters w, h, of a cylinder separately??? -> use / and * (/ for height, * for width, and also + i - set to increase or decrease a part from what they were doing) -->
<!-- - Use the same for camera rotation and object rotation, just depending if object is selected.
- Light movement!!!! (press L to change from camera to light, for example!?? set a flag!?)
- Change light color when it is selected!!! -->

<!-- E - Put git clone minilibx -->
<!-- E - hook to close with the CROSS, as with ESC -->
<!-- Hooks to minimize / resize / ...? -->
E - if camera / light / etc is not parsed or some other errors, we have to exit the program!? -> is it done like that?
<!-- E - create something like clean_scene that gc_free non needed things, but not everything, when 0 is pressed!!! (and solve all the problems in memory) -->

<!-- 09/03/2025 -->
<!-- - Rotation of objects with mouse --> NOT DONE WITH THE MOUSE
<!-- - Solve problems with < > after having translate the camera -> when translating it creates the viewport again by the default orientation, not the one of the new viewport. Delete the possibility to rotate viewport alone?  -->
<!-- - light hooks / transformations -->

10/03/2025
<!-- - Select /deselect light
- (deselect light before rerendering hq)
- light "scale"
- put the array of keys for windows / linux commented out -->
<!-- - Check transformations work -> scroll in the proper direction!??!? -->
<!-- - + and - work the same as mouse scrolling ?? (or when nothing is selected, leave one for zoom and one for amblight ratio?!?!?) -->
<!-- - Be able to include new objects, colors, etc. --> NOT DONE
<!-- - Change light color when it is selected!!!(see light_selection, change relative and not absolute) -->
<!-- - Obj rotation not working properly when they have been moved -> transform reference !! -->

11/03/2025
IRENE
<!-- 1 - Camera swaping problem solve! -> consider reorthogonize function!?! -->
<!-- ->CHECK IF loq true is needed! -->
<!-- 2 - Uncapped cyl after transofrmations!?!?? -->
<!-- 3 - clicking on the top to move selects an object!!! AVOID in order to move the hiq render without entering low q render -->
<!-- - some problem with Cyl when moving -->
<!-- - Cyl resize with different w and h independently: hooks -->
<!-- - problem with spehere with testfile.rt -->
<!-- 4 - Light overlaping problem solve -> when shadow ray is very tangent to the direction of light (check in find hit somehow different treatment for shadow rays!?!?) -->
<!-- - + and - add env light ratio -->
2 - change simple transformation with vector additions and not matrix if no needed
<!-- Hook 0 is working? Memory leaks?!? -->
<!-- Memory leaks?!?
- Check what happens when 0 is pressed (memory!?!?) -->
- Can the performance be increased if we assume sph with r = 1 and cyl =1 etc....? and have matrices from the start? -> other calculation optimizations (Claude!?)

12/03/2025
<!-- - check inside light correclty do -->
<!-- - cyl resize w and h independently: hooks -->
<!-- add hooks for cyl height and width to prompt! (E) -->
<!-- 1- highlight width or heigt -->
<!-- 2- scale sphere also width ang height?!? --> NOT DONE
3- improve performance: scale of sphere directly changing radius, change scale obj to use only for direct for cyl, etc
- general checking! (input errors!!!, mouse clicks sometimes not working?, light colors??)
- Minilibx in makefile, according to subject?!? copy folder!?


13/03/2025
- norm_vector and u_vector are the same!?!? unify!?!
- Improve performance? Sphere change radius instead of matrix?
- Try to have the images that appear on the subject
- Minilibx in makefile, according to subject?!? copy folder!?
- Check input errors (Elements which are defined by a capital letter can only be declared once in
the scene, etc)
- Check memory leaks
- light color and light filter?!?!
- Norminette
- Delete test files and minilibx
- maths to rad in which header?? Now is on linalg!?!?
- check with camera not in the origin!! (translations and rotations still working??)
- Errror canoot open the file is duplicated!!
- Why we have mlx in the PHONY in the makefile?!?!
- Exit sentence in blue format

ERYA:
Errors in parsing:
- Elements which are defined by a capital letter can only be declared once in
the scene
- 3d normalized orientation vector. In range [-1,1] for each x,y,z axis (FOR CAMERA, PLANES AND CYL):
0.0,0.0,1.0
- Explicit error messages saying range (must be between 0 and 180FOV : Horizontal field of view in degrees in range [0,180]: 70 (explicit message saying must be between 0 and 180); the light brightness ratio in range [0.0,1.0]:, Color values 0-255)
- All vectors are stored as unit vectors!?!?
