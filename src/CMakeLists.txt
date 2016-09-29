SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# convert gff to refflat
add_executable(gff2refFlat gff2refFlat.cpp)
target_link_libraries(gff2refFlat gclib)

# get gff length
add_executable(mRNA_length mRNA_length.cpp)
target_link_libraries(mRNA_length gclib)

# install
install(TARGETS gff2refFlat mRNA_length
        RUNTIME DESTINATION bin)