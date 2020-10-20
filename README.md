# FDF

## Wireframing project for 42 curriculum at Hive Helsinki

### To-do

- Check that GNL works.
Map needs to:
- Change colours.
- Change altitude.
- You'll need to be able to zoom in and out and pan the camera.
- As an example, you'll need first to start with drawing the lines between points.
- Bresenham: Tracing.
- Choose between three views: Isometric, parallel and conical.
- File parsing.
- What is a valid file?
Valid file has only one newline per row, and one space between numbers.
- Create a function that assigns values to a struct that holds points in space.
- Create a struct that stores all the points of the map.
- Add click to draw.
- Zoom in.
- Zoom out.
- Altitude.
- Scaling.
- Specify the color spectrum in parameter.
- Manage correctly the hidden surfaces.
- Change types of projection.


### Notes

To convert from hexadecimal trgb to one colour channel;

	trgb(0, 255, 0, 0)
	0x00FF0000
	t = 0 x 256 x 256 x 256
	r = 255 x 256 x 256
	g = 0 x 256
	b = 0

2D line, but how to implement 3rd dimension?
- Trigonometry with isometric transformations in Kirupa's and VBrazhnik's wiki sites.
- Middlepoint should be window's origo.
- Translation Figure slides in any direction.
- Reflection Figure flips over a line.
- Rotation Figure turns over a fixed point.
- Dilation Figure is enlarged or reduced.
  An isometry is a rigid transformation that preserves length and angle measures, as well as perimeter and area.
- X is right, z is outward and y is up.
- Vector's length is norm or magnitude.
- a · b = |a| * |b| * cos(a, b)
Eli pistetulo on vektorien pituuksien tulo kertaa niiden välisen kulman kosini.


### Reasonings
- I use g42 prefix for project files that I deem usable in other projects and fdf to be project specific prefix.
- I created g42 struct coord to hold x, y, z coordinates as doubles.
- Struct map holds the coordinates for the points in the original map. However, image has a coordinates of it's own, where you need to change coordinates of the 3d (x,y,z) match 2d (x,y) plane. Point z has an equivalent in a 2d coordinate system, and that has to be found in order to create rotation and dilation.
- x, y, z could be 0,0,0 and other point could be 1, 0, 10, but in x, y axis, that could be x, y (0,0 and 0, 10 respectively) or even 20, 200, since pixels.
- Origo of the 2d plane is at 300, 400 pixels, or 200, 300 pixels.
- Vector's length in first rendering is 30 pixels move in coordinates.
- Screen space is set to left -1 right +1, +1 bottom and -1 up.
- Camera needs to have set coordinates, let's assume that is 0, 0, 0.
- To get isometric view of the object, set the Rotation order to zyx,
  the z Rotation to 45 and the y Rotation to 35.264.
- 3d space.
- Object coordinates to world coordinates.
- World coordinates to camera coordinates.
- Camera coordinates to ndc.
- NDC to raster space.

### Links
- MinilibX documentation by Codam students [Link](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux)
- Neener's tutorial how to use MinilibX, and DDA algorithm. [Link](https://gontjarow.github.io/MiniLibX/)
- Red Blob games tutorial on line tracing [Link](https://www.redblobgames.com/grids/line-drawing.html)
- How to perform isometric transformations [Link](https://github.com/VBrazhnik/FdF/wiki/How-to-perform-isometric-transformations%3F)
- How to do isometric transformations with [Link](https://www.kirupa.com/developer/actionscript/isometric_transforms.htm)
- Essence of Linear Algebra [Link](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
- Wikipedia article on rotation matrix [Link](https://en.wikipedia.org/wiki/Rotation_matrix)
- Vectors, points in space and matrices [Link](https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/coordinate-systems)
- Why to use floats against doubles [Link](https://stackoverflow.com/questions/24231389/struct-or-class-for-matrix-4x4-object)

### To-do
- Read about vectors and matrices, and how to use them.
- If vectors and matrices fail, then use ready-made trigonometric solution.
- Test by creating a
- z depth/height
- x point
- y point
-