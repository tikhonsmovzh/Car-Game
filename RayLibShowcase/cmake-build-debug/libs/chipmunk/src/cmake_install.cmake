# Install script for directory: C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/src

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

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/mingw32/bin/objdump.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/efarinov/Uni/RayLibShowcase/cmake-build-debug/libs/chipmunk/src/libchipmunk.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/chipmunk" TYPE FILE FILES
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/chipmunk.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/chipmunk_ffi.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/chipmunk_private.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/chipmunk_types.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/chipmunk_unsafe.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpArbiter.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpBB.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpBody.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpConstraint.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpDampedRotarySpring.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpDampedSpring.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpGearJoint.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpGrooveJoint.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpHastySpace.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpMarch.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpPinJoint.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpPivotJoint.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpPolyShape.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpPolyline.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpRatchetJoint.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpRobust.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpRotaryLimitJoint.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpShape.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpSimpleMotor.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpSlideJoint.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpSpace.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpSpatialIndex.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpTransform.h"
    "C:/Users/efarinov/Uni/RayLibShowcase/libs/chipmunk/include/chipmunk/cpVect.h"
    )
endif()

