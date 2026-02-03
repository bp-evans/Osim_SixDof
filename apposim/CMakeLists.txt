
add_executable(apposim src/sim_main.cc src/rk4_integ.cc)

target_include_directories(apposim 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(apposim
    PUBLIC
        Eigen3::Eigen
        libplanetmodel
        librigidbody
)