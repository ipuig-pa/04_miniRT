IRENE (rendering):

27/02/2025
<!-- (-Adapt everything to header with cam, etc with direct structures and not pointers, or change back just to test and then change it after solving shadows etc) -->
<!-- - SHADOW OF BLUE PLANE OVER ROTATED PINK PLANE. GET RID!!! (how to handle direct rays and shadow rays in transformations: look to output, there are some hints, the direct ray is finding the hit below the blue plane (y<-50)!?!?!) -->
<!-- - try rotations, transl (create port in the main for the moment, to use the axis there for the rotations of planes, etc) -->
<!-- -> understand the proper meaning of axis rotation!!! (with respect to the base, ...? movement broadness??) (pivot point: proximal or distal) -> //to rotate uisng a specific point as pivot, combine to the origin of coordinates, with translation back and forth.
-> resize!!! -->
-> light movement!?!?
<!-- -> cylinder somehow attach the objects circles if there is a rotation /transl / etc? ->PROBLEMS IN SCALE, because we have to translate to circle center to origin but then not back to original position of the center, but moved having in mind the crescent ratio of the cylinder (or think how can we keep track of them) -->
E -> be careful that circles are contigupus cyl and the first is subtracting axis * h/2 and the second is adding axis * h/2 to the center of the cyl
<!-- -> for rotations and scaling, combine always with translation to origin and back!!! -->
E -> initialize all objects with identity matrix
E -> create port after parsing? 
- Store all hits and not only the most proximal??? For reflection?
- need to normalize vector after transformations?!?!! (try with different cases!)

<!-- - Rotations and scaling will be done in relation to the center of the object or the given point for planes!? -->
- thickness of planes?!?! when are exactly in the camera center?!

<!-- !!!!- Normal of planes and circles: do not use both indistintly, because if light is behind they will get illuminated?!?!??! Just the one towards the camera?? or how to chose the one to use? In fact the one towards the camera does not work with rotations/transl -->

<!-- - add w dimension in linalg utils -->
- Instead of compute the inverse matrix in find hit and shading functions, store directly the inverse mtrix in the object m?? -> for the moment it is ok bc it is just computed once!

LINALG:
<!-- - linalg funcitons, put order: use only add / sub.
- Use the same structure for points and vectors?? (tuples with w, instead of 2 different point and vector) -->
<!-- - use function create_vector/create point to be able to create without need to do the 3 dimensions? -->
<!-- - create enum in struct as RGB, to refer to both the x, y, z and iterate for the linalg operations. -->

- Hooks: how to handle? (for ex. in env have int i to represent selected object. Ctrl + arrows to iterate through objects (add to i). AWSD to rotate (decide 3 dimensions: or for ex, X, Y, Z to rotate in each axis of the viewport), + - to make bigger, arrows to translate selected object). when iterating through objects, if it is a cylinder somehow attach the objects circles if there is a rotation /transl / etc? (apply the same matrix to both the next 2 and then skip them)

<!-- week 24/02/2025: understand matrices, transl and rotations?
week 03/03/2025: rotations etc -->
week 10/03/2025: shiny, shadows, reflection, patterns, etc
- Specular reflection: Shine in proper place, just in objects that haev shine, where to put shininess and where 0.9, etc.
- Solve shading in planes when specular reflection is added

- establish tmax and tmin for ray impact (r(t) = o + td)
<!-- - decide pointers or direct objects inside scene -->
- light color not working properly

- somehow do all the hits and then all the shading, to be easier when light changes, no need to re-render

MORE
- include triangle intersection, so we can have complex forms represented as a meshed of triangles
- Bouncing, reflextion, refraction, etc
- Antialiasing (to smooth contours)
- optimize checking of ALL objects to find first hit? objects as a linked list according to their proximity to camera?? OR not, beause when it hits one, we have to change again the order? OR subdivide the space?

- Include functions for vector operation (add and substract without needing to do everytime in each function)

EDGE CASES:
- light inside an object (illuminated from the inside?)
- camera inside an object??

TOGETHER DECIDE:
- Use float or double (different function prototype in math library function)
E -> Parsing material type (metal, plstic, matte) an initialize k_s and n_s accordint to that
- Define materials? (shiny metal / glossy plastic / matte) with specific k_s and n_s?? Or have directly the parameters in the object?
<!-- - Eliminate cylinder caps (make scaling and rotation difficult)?? -->
- Bonus:
	- Include light color
	- Take from the scene file if we are introducing a filter??
