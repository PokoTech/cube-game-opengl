#ifndef COMMON_H
#define COMMON_H

/**
 * ApplicationMode denotes the global state of the application.  There are three
 * global states for this application:
 * 1. Transform -- load the correct shaders to do a transformation of a simple
 *    asset.
 * 2. Rotate -- load the correct shader to rotate a simple asset.
 * 3. Scale -- load the correct shader to scale a simple asset.
 */
enum ApplicationMode {TRANSFORM, ROTATE, SCALE};

#endif
