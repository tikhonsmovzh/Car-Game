# Install script for directory: D:/Cpp/RayLibShowcase/chipmunk/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/RayLibShowcase")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Cpp/RayLibShowcase/cmake-build-debug/chipmunk/src/libchipmunk.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/chipmunk" TYPE FILE FILES
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/chipmunk.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/chipmunk_ffi.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/chipmunk_private.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/chipmunk_types.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/chipmunk_unsafe.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpArbiter.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpBB.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpBody.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpConstraint.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpDampedRotarySpring.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpDampedSpring.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpGearJoint.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpGrooveJoint.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpHastySpace.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpMarch.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpPinJoint.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpPivotJoint.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpPolyShape.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpPolyline.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpRatchetJoint.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpRobust.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpRotaryLimitJoint.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpShape.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpSimpleMotor.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpSlideJoint.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpSpace.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpSpatialIndex.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpTransform.h"
    "D:/Cpp/RayLibShowcase/chipmunk/include/chipmunk/cpVect.h"
    )
endif()

