# Geometry

## Remarks Elements
| Name | Description |
| --- | --- |
| Point | A point in the plane |
| Line segment | A line segment is a finite line with two endpoints |
| Ray | A ray is a line with one endpoint and extends infinitely in one direction |
| Line | A line is a set of points that are equidistant from a fixed point |
| Plane | A plane is a flat surface that extends infinitely far |
| Vector | A vector is a quantity that has magnitude and direction |

## `Complex` Data Type
complex numbers are a data type that is used to represent a number that can be expressed in the form $a + bi$, where $a$ is the real part and $b$ is the imaginary part. The imaginary unit is denoted by $i$, and it is defined by the equation $i^2 = -1$.

| Function | Return |
| --- | --- |
| `real()` | Returns the real part of the complex number (X) $*$ |
| `imag()` | Returns the imaginary part of the complex number (Y) $*$ |
| `abs()` | Returns the absolute value of the complex number (length) |
| `arg()` | Returns the argument of the complex number (angle) |
| `conj()` | Returns the conjugate of the complex number (fliping the sign of imaginary part) |
| `norm()` | Returns the norm of the complex number (squared length) |
| `polar()` | Returns the polar coordinates of the complex number (length and angle) |

> **Note:** $*$ The real and imaginary parts of a complex number can be accessed using the `real()` and `imag()` methods respectively.

**Example:** [complex.cpp](examples/complex.cpp)

## Dot Product

## Cross Product

<!--
## Notes
- double and long double
- corner cases (lines, points, polygons) 
- elements (point, line segment, ray, line, plane)
- angles (radians (better), degrees) and cicles
- complex data type
-->