IRENE (rendering):

27/02/2025
- try rotations, transl (create port in the main for the moment, to use the axis there for the rotations of planes, etc)
- add w dimension in linalg utils

- linalg funcitons, put order: use only add / sub. Use the same for points and vectors?? (tuples with w, instead of 2 different point and vector), use function create_vector/create point to be able to create without need to do the 3 dimensions?
week 24/02/2025: understand matrices, transl and rotations?
week 03/03/2025: rotations etc
week 10/03/2025: shiny, shadows, reflection, etc

- establish tmax and tmin for ray impact (r(t) = o + td)
- decide pointers or direct objects inside scene
- light color not working properly

MORE
- include triangle intersection, so we can have complex forms represented as a meshed of triangles
- Bouncing, reflextion, refraction, etc
- Antialiasing (to smooth contours)
- optimize checking of ALL objects to find first hit? objects as a linked list according to their proximity to camera?? OR not, beause when it hits one, we have to change again the order? OR subdivide the space?

- Include functions for vector operation (add and substract without needing to do everytime in each function)

EDGE CASES:
- light inside an object (illuminated from the inside?)
- 


TOGETHER DECIDE:
- Use float or double (different function prototype in math library function)
- Bonus:
	- Include light color
	- Take from the scene file if we are introducing a filter??
