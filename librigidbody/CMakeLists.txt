
add_library(librigidbody src/RigidBody.cc)

target_include_directories(librigidbody
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(librigidbody 
    PUBLIC 
        Eigen3::Eigen
)