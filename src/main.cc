#define GLEW_STATIC // Easier debugging

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

#include <boost/program_options.hpp>

#define RUN_GRAPHICS_DISPLAY 0x00;

#include "common.h"
#include "GameWorld.h"

/*
 * SDL timers run in separate threads.  In the timer thread
 * push an event onto the event queue.  This event signifies
 * to call display() from the thread in which the OpenGL
 * context was created.
 */
Uint32 tick(Uint32 interval, void *param) {
  SDL_Event event;
  event.type = SDL_USEREVENT;
  event.user.code = RUN_GRAPHICS_DISPLAY;
  event.user.data1 = 0;
  event.user.data2 = 0;
  SDL_PushEvent(&event);
  return interval;
}

struct SDLWindowDeleter {
  inline void operator()(SDL_Window* window) {
    SDL_DestroyWindow(window);
  }
};

void Draw(const std::shared_ptr<SDL_Window> window, const std::shared_ptr<GameWorld> game_world) {
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  game_world->Draw();

  // Don't forget to swap the buffers
  SDL_GL_SwapWindow(window.get());
}

std::shared_ptr<SDL_Window> InitWorld() {
  Uint32 width = 640;
  Uint32 height = 480;
  SDL_Window * _window;
  std::shared_ptr<SDL_Window> window;

  // Glew will later ensure that OpenGL 3 *is* supported
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

  // Do double buffering in GL
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  // Initialise SDL - when using C/C++ it's common to have to
  // initialise libraries by calling a function within them.
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)<0) {
    std::cout << "Failed to initialise SDL: " << SDL_GetError() << std::endl;
    return nullptr;
  }

  // When we close a window quit the SDL application
  atexit(SDL_Quit);

  // Create a new window with an OpenGL surface
  _window = SDL_CreateWindow("Shader Example"
                             , SDL_WINDOWPOS_CENTERED
                             , SDL_WINDOWPOS_CENTERED
                             , width
                             , height
                             , SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  if (!_window) {
    std::cout << "Failed to create SDL window: " << SDL_GetError() << std::endl;
    return nullptr;
  }

  SDL_GLContext glContext = SDL_GL_CreateContext(_window);
  if (!glContext) {
    std::cout << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
    return nullptr;
  }

  // Initialise GLEW - an easy way to ensure OpenGl 3.0+
  // The *must* be done after we have set the video mode - otherwise we have no
  // OpenGL context to test.
  glewInit();
  if (!glewIsSupported("GL_VERSION_3_0")) {
    std::cerr << "OpenGL 3.0 not available" << std::endl;
    return nullptr;
  }

  // OpenGL settings
  //glDisable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);
  //glDepthFunc(GL_LESS);

  window.reset(_window, SDL_DestroyWindow);
  return window;
}

ApplicationMode ParseOptions (int argc, char ** argv) {
  namespace po = boost::program_options;

  po::options_description desc("Allowed options");
  desc.add_options()
     ("help", "print this help message")
     ("translate", "Show translation example (default)")
     ("rotate", "Show rotation example")
     ("scale", "Show scale example")
  ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if(vm.count("help")) {
    std::cout << desc << std::endl;
    exit(0);
  }

  if(vm.count("rotate")) {
    return ROTATE;
  }

  if(vm.count("scale")) {
    return SCALE;
  }

  // The default
  return TRANSFORM;
}

int main(int argc, char ** argv) {
  Uint32 delay = 1000/60; // in milliseconds

  auto mode = ParseOptions(argc, argv);
  auto window = InitWorld();
  auto game_world = std::make_shared<GameWorld>(mode);
  if(!window) {
    SDL_Quit();
  }

  // Call the function "tick" every delay milliseconds
  SDL_AddTimer(delay, tick, NULL);
  SDL_SetRelativeMouseMode(SDL_TRUE);

  // Add the main event loop
 // Add the main event loop
  SDL_Event event;
  Control_Key key = NO_KEY;
  int mouse_x_rel = 0;
  int mouse_y_rel = 0;
  while (SDL_WaitEvent(&event)) {
    //mouse_x_rel = event.motion.xrel;
    //mouse_y_rel = event.motion.yrel;
    SDL_GetRelativeMouseState(&mouse_x_rel, &mouse_y_rel);
	
    // Initialised SDLK camera movement cases for KeyDown & keyUp events
    switch (event.type) {
      case SDL_QUIT:
        SDL_Quit();
        break;
      case SDL_USEREVENT:
        Draw(window, game_world);
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_LEFT:
            key = MOVE_LEFT_D;
            break;
          case SDLK_RIGHT:
            key = MOVE_RIGHT_D;
            break;
          case SDLK_UP:
            key = MOVE_FORWARD_D;
            break;
          case SDLK_DOWN:
            key = MOVE_BACKWARD_D;
            break;
          case SDLK_SPACE:
            key = MOVE_UP_D;
            break;
          case SDLK_LSHIFT:
            key = MOVE_DOWN_D;
            break;
          }
          break;
      case SDL_KEYUP:
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
              key = MOVE_LEFT_U;
              break;
            case SDLK_RIGHT:
              key = MOVE_RIGHT_U;
              break;
            case SDLK_UP:
              key = MOVE_FORWARD_U;
              break;
            case SDLK_DOWN:
              key = MOVE_BACKWARD_U;
              break;
            case SDLK_SPACE:
              key = MOVE_UP_U;
              break;
            case SDLK_LSHIFT:
              key = MOVE_DOWN_U;
              break;
        }break;
    }
    //initialise mouse movement events
    game_world->UpdateCamera(key, mouse_x_rel, mouse_y_rel);
  }
}
