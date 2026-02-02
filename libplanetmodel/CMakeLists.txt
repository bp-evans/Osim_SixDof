
add_library(libplanetmodel src/EarthModel.cc)

target_include_directories(libplanetmodel
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(libplanetmodel 
    PUBLIC 
        Eigen3::Eigen
)