cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# Project's name
project(RailShell)
set(CMAKE_PROJECT_NAME "railshell")

# Set the output folder where your program will be created
# set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(PROJECT_SRC ${PROJECT_SOURCE_DIR}/src)
set(PROJECT_INCLUDES ${PROJECT_SOURCE_DIR}/includes)

# The following folder will be included
include_directories("${PROJECT_SRC}" "${PROJECT_INCLUDES}")

# Add the executable
add_executable(rsh ${PROJECT_SRC}/main.cpp)

# Create installations
install(TARGETS rsh DESTINATION bin)

# CPack
set(CPACK_GENERATOR "DEB;RPM")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Landon Gravat") #required
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_PACKAGE_NAME "railshell")
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "railinator4903@gmail.com")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")

# NSIS
set(CPACK_NSIS_MENU_LINKS
	"README.md" "Help")
set(CPACK_NSIS_CONTACT "Landon Gravat <railinator4903@gmail.com>")

include(CPack)

