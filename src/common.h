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
enum Control_Key {MOVE_FORWARD_D, MOVE_BACKWARD_D, MOVE_UP_D, MOVE_DOWN_D, MOVE_LEFT_D, MOVE_RIGHT_D,
                  MOVE_FORWARD_U, MOVE_BACKWARD_U, MOVE_UP_U, MOVE_DOWN_U, MOVE_LEFT_U, MOVE_RIGHT_U,NO_KEY};
#endif
