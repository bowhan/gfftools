# static linking
OPTION(BUILD_STATIC "Build staticly linked binaries" OFF)
if (BUILD_STATIC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
    set(GCLIB gclib_static)
else ()
    SET(CMAKE_SKIP_BUILD_RPATH FALSE)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
    SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
    set(GCLIB gclib)
endif ()

# convert gff to refflat
add_executable(gff2refFlat gff2refFlat.cpp)
target_link_libraries(gff2refFlat ${GCLIB})

# get gff length
add_executable(mRNA_length mRNA_length.cpp)
target_link_libraries(mRNA_length ${GCLIB})

add_executable(extUtr extUtr.cpp)
target_link_libraries(extUtr ${GCLIB} z)

# install
install(TARGETS gff2refFlat mRNA_length extUtr
        RUNTIME DESTINATION bin)