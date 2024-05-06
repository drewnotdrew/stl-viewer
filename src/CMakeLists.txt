# add_executable(stl_viewer
#     stl_viewer.c
# )

set(CMAKE_PREFIX_PATH /home/drew/Qt/6.7.0/gcc_64)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(stl_viewer
    stl_viewer.cpp
    stl_viewer.qrc
)

target_link_libraries(stl_viewer
    PRIVATE Qt6::Widgets
)

qt_add_resources(stl_viewer
    FILES open.png
)
