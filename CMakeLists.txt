cmake_minimum_required(VERSION 3.10)
project(SimpleSensoray_Project)
find_package( OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_LINUX -no-pie -lm")
link_directories("/home/ashkan/sensoray/driver")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_definitions(-DOSTYPE_linux)


add_library(
	telerobcamera
	telerobcamera.cpp
	telerobcamera.hpp
	)

add_library(
	simple826
	simple826.cpp
	simple826.hpp
	)
add_executable(Sensoray_demo main.cpp)

INCLUDE_DIRECTORIES("/home/ashkan/sensoray/driver")
INCLUDE_DIRECTORIES(/home/ashkan/eigen, /usr/local/lib, /usr/include/flycapture)

target_link_libraries(telerobcamera PRIVATE  "/usr/lib/libflycapture.so" ${OpenCV_LIBS})
target_link_libraries(simple826 PRIVATE  "/home/ashkan/sensoray/demo/lib826_64.a" m)

# target_link_libraries(pigi PRIVATE "/home/ashkan/Desktop/naghi_C/build/libghazam.a" )
target_link_libraries(Sensoray_demo PRIVATE telerobcamera simple826 "/usr/lib/libflycapture.so"  ${OpenCV_LIBS} "/home/ashkan/sensoray/demo/lib826_64.a" m)

# target_link_libraries(SystemRun PRIVATE omnimagnet type "/usr/local/lib/libcomedi.a")

# add_executable(CameraCalibration camera_calibration.cpp)

# target_link_libraries(CameraCalibration "/usr/lib/libSpinnaker.so"  ${OpenCV_LIBS})
