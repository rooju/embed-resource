# Embed Resource

Forked & modified from https://github.com/cyrilcode/embed-resource.

Embed binary files and resources (such as GLSL Shader source files) into
C++ projects. Uses C++17 features.

Include this repository in your CMake based project:

    git submodule add https://github.com/rooju/embed-resource.git lib/embed-resource

Then add to your CMakeLists.txt for your project:

    include_directories(lib/embed-resource)
    add_subdirectory(lib/embed-resource)

Now you can add your resources, by calling the provided `embed_resources()` function in your
CMakeLists.txt file:

    embed_resources(MyResources shaders/vertex.glsl shaders/frag.glsl)

Then link to your binary by adding the created variable to your add_executable statement:

    add_executable(MyApp ${SOURCE_FILES} ${MyResources})

### Credits...

https://github.com/cyrilcode/embed-resource

## License

Public Domain / [WTFPL](http://www.wtfpl.net/)
