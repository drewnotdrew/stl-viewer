# add_executable(stl_viewer
#     stl_viewer.c
# )

set(CMAKE_PREFIX_PATH /home/drew/Qt/6.7.0/gcc_64)
find_package(Qt6 REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets)
qt_standard_project_setup()

# qt_add_library(stl_widget
#     stl_widget.cpp stl_widget.h
# )

# qt_add_library(geometry_engine
#     geometry_engine.cpp geometry_engine.h
# )

qt_add_executable(stl_viewer
    geometry_engine.cpp geometry_engine.h
    stl_widget.cpp stl_widget.h
    main.cpp
)

target_link_libraries(stl_viewer PRIVATE
    Qt6::Core    
    Qt6::Widgets
    Qt6::Gui
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    # stl_widget
    # geometry_engine
)

# # Resources:
# set(shaders_resource_files

# )

# qt6_add_resources(cube "shaders"
#     FILES
#         "fshader.glsl"
#         "vshader.glsl"
# )

# set(textures_resource_files
#     "cube.png"
# )

# qt6_add_resources(cube "textures"
#     FILES
#         ${textures_resource_files}
# )
