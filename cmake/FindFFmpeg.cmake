# - Try to find FFMPEG
# Once done this will define
#  
#  FFMPEG_FOUND        - system has FFMPEG
#  FFMPEG_INCLUDE_DIR  - the include directory
#  FFMPEG_LIBRARY_DIR  - the directory containing the libraries
#  FFMPEG_LIBRARIES    - Link these to use FFMPEG
#   

# FindAvformat
FIND_PATH(AVFORMAT_INCLUDE_DIR libavformat/avformat.h
        PATHS /usr/include/
        /usr/include/ffmpeg/
        $ENV{FFMPEGDIR}/include/
        $ENV{FFMPEGDIR}/include/ffmpeg/)

FIND_LIBRARY(AVFORMAT_LIBRARY avformat avformat-55 avformat-57
        PATHS /usr/lib/
        /usr/lib/ffmpeg/
        $ENV{FFMPEGDIR}/lib/
        $ENV{FFMPEGDIR}/lib/ffmpeg/
        $ENV{FFMPEGDIR}/bin/)

#FindAvcodec
FIND_PATH(AVCODEC_INCLUDE_DIR libavcodec/avcodec.h
        PATHS /usr/include/
        /usr/include/ffmpeg/
        $ENV{FFMPEGDIR}/include/
        $ENV{FFMPEGDIR}/include/ffmpeg/)

FIND_LIBRARY(AVCODEC_LIBRARY avcodec avcodec-55 avcodec-57
        PATHS /usr/lib/
        /usr/lib/ffmpeg/
        $ENV{FFMPEGDIR}/lib/
        $ENV{FFMPEGDIR}/lib/ffmpeg/
        $ENV{FFMPEGDIR}/bin/)

#FindAvutil
FIND_PATH(AVUTIL_INCLUDE_DIR libavutil/avutil.h
        PATHS /usr/include/
        /usr/include/ffmpeg/
        $ENV{FFMPEGDIR}/include/
        $ENV{FFMPEGDIR}/include/ffmpeg/)

FIND_LIBRARY(AVUTIL_LIBRARY avutil avutil-52 avutil-55
        PATHS /usr/lib/
        /usr/lib/ffmpeg/
        $ENV{FFMPEGDIR}/lib/
        $ENV{FFMPEGDIR}/lib/ffmpeg/
        $ENV{FFMPEGDIR}/bin/)

#FindAvdevice
FIND_PATH(AVDEVICE_INCLUDE_DIR libavdevice/avdevice.h
        PATHS /usr/include/
        /usr/include/ffmpeg/
        $ENV{FFMPEGDIR}/include/
        $ENV{FFMPEGDIR}/include/ffmpeg/)

FIND_LIBRARY(AVDEVICE_LIBRARY avdevice avdevice-55 avdevice-56
        PATHS /usr/lib/
        /usr/lib/ffmpeg/
        $ENV{FFMPEGDIR}/lib/
        $ENV{FFMPEGDIR}/lib/ffmpeg/
        $ENV{FFMPEGDIR}/bin/)

#FindSwscale
FIND_PATH(SWSCALE_INCLUDE_DIR libswscale/swscale.h
        PATHS /usr/include/
        /usr/include/ffmpeg/
        $ENV{FFMPEGDIR}/include/
        $ENV{FFMPEGDIR}/include/ffmpeg/)

FIND_LIBRARY(SWSCALE_LIBRARY swscale swscale-2 swscale-4
        PATHS /usr/lib/
        /usr/lib/ffmpeg/
        $ENV{FFMPEGDIR}/lib/
        $ENV{FFMPEGDIR}/lib/ffmpeg/
        $ENV{FFMPEGDIR}/bin/)

#FindAvresample
FIND_PATH(AVRESAMPLE_INCLUDE_DIR libavresample/avresample.h
        PATHS /usr/include/
        /usr/include/ffmpeg/
        $ENV{FFMPEGDIR}/include/
        $ENV{FFMPEGDIR}/include/ffmpeg/)

FIND_LIBRARY(AVRESAMPLE_LIBRARY avresample avresample-2 avresample-3
        PATHS /usr/lib/
        /usr/lib/ffmpeg/
        $ENV{FFMPEGDIR}/lib/
        $ENV{FFMPEGDIR}/lib/ffmpeg/
        $ENV{FFMPEGDIR}/bin/)


#FindAvfilter
FIND_PATH(AVFILTER_INCLUDE_DIR libavfilter/avfilter.h
        PATHS /usr/include/
        /usr/include/ffmpeg/
        $ENV{FFMPEGDIR}/include/
        $ENV{FFMPEGDIR}/include/ffmpeg/)

FIND_LIBRARY(AVFILTER_LIBRARY avfilter avfilter-52 avfilter-55
        PATHS /usr/lib/
        /usr/lib/ffmpeg/
        $ENV{FFMPEGDIR}/lib/
        $ENV{FFMPEGDIR}/lib/ffmpeg/
        $ENV{FFMPEGDIR}/bin/)


#FindSwresample
FIND_PATH(Swresample_INCLUDE_DIR libswresample/swresample.h
        PATHS /usr/include/
        /usr/include/ffmpeg/
        $ENV{FFMPEGDIR}/include/
        $ENV{FFMPEGDIR}/include/ffmpeg/)

FIND_LIBRARY(Swresample_LIBRARY swresample swresample-52 swresample-55
        PATHS /usr/lib/
        /usr/lib/ffmpeg/
        $ENV{FFMPEGDIR}/lib/
        $ENV{FFMPEGDIR}/lib/ffmpeg/
        $ENV{FFMPEGDIR}/bin/)


SET(FFMPEG_FOUND FALSE)

IF (AVFORMAT_INCLUDE_DIR AND AVFORMAT_LIBRARY)
    MESSAGE("FOUND AVFORMAT!")
    SET(AVFORMAT_FOUND TRUE)
ENDIF (AVFORMAT_INCLUDE_DIR AND AVFORMAT_LIBRARY)

IF (AVCODEC_INCLUDE_DIR AND AVCODEC_LIBRARY)
    MESSAGE("FOUND AVCODEC!")
    SET(AVCODEC_FOUND TRUE)
ENDIF (AVCODEC_INCLUDE_DIR AND AVCODEC_LIBRARY)

IF (AVUTIL_INCLUDE_DIR AND AVUTIL_LIBRARY)
    MESSAGE("FOUND AVUTIL!")
    SET(AVUTIL_FOUND TRUE)
ENDIF (AVUTIL_INCLUDE_DIR AND AVUTIL_LIBRARY)

IF (AVDEVICE_INCLUDE_DIR AND AVDEVICE_LIBRARY)
    MESSAGE("FOUND AVDEVICE!")
    SET(AVDEVICE_FOUND TRUE)
ENDIF (AVDEVICE_INCLUDE_DIR AND AVDEVICE_LIBRARY)

IF (SWSCALE_INCLUDE_DIR AND SWSCALE_LIBRARY)
    MESSAGE("FOUND SWSCALE!")
    SET(SWSCALE_FOUND TRUE)
ENDIF (SWSCALE_INCLUDE_DIR AND SWSCALE_LIBRARY)

IF (AVRESAMPLE_INCLUDE_DIR AND AVRESAMPLE_LIBRARY)
    MESSAGE("FOUND AVRESAMPLE!")
    SET(AVRESAMPLE_FOUND TRUE)
ENDIF (AVRESAMPLE_INCLUDE_DIR AND AVRESAMPLE_LIBRARY)


IF (AVFILTER_INCLUDE_DIR AND AVFILTER_LIBRARY)
    MESSAGE("FOUND AVFILTER!")
    SET(AVFILTER_FOUND TRUE)
ENDIF (AVFILTER_INCLUDE_DIR AND AVFILTER_LIBRARY)

IF (Swresample_INCLUDE_DIR AND Swresample_LIBRARY)
    MESSAGE("FOUND Swresample!")
    SET(Swresample_FOUND TRUE)
ENDIF (Swresample_INCLUDE_DIR AND Swresample_LIBRARY)


IF (AVFORMAT_INCLUDE_DIR OR
        AVCODEC_INCLUDE_DIR OR
        AVUTIL_INCLUDE_DIR OR
        AVDEVICE_FOUND OR
        SWSCALE_FOUND OR
        AVRESAMPLE_FOUND OR
        AVFILTER_FOUND OR
        Swresample_FOUND)

    MESSAGE("FOUND FFMPEG!")
    SET(FFMPEG_FOUND TRUE)

    SET(FFMPEG_INCLUDE_DIR
            ${AVFORMAT_INCLUDE_DIR}
            ${AVCODEC_INCLUDE_DIR}
            ${AVUTIL_INCLUDE_DIR}
            ${AVDEVICE_INCLUDE_DIR}
            ${SWSCALE_INCLUDE_DIR}
            ${AVRESAMPLE_INCLUDE_DIR}
            ${AVFILTER_INCLUDE_DIR}
            ${Swresample_INCLUDE_DIR})

    SET(FFMPEG_LIBRARIES
            ${AVFORMAT_LIBRARY}
            ${AVCODEC_LIBRARY}
            ${AVUTIL_LIBRARY}
            ${AVDEVICE_LIBRARY}
            ${SWSCALE_LIBRARY}
            ${AVRESAMPLE_LIBRARY}
            ${AVFILTER_LIBRARY}
            ${Swresample_LIBRARY})

ENDIF (AVFORMAT_INCLUDE_DIR OR
        AVCODEC_INCLUDE_DIR OR
        AVUTIL_INCLUDE_DIR OR
        AVDEVICE_FOUND OR
        SWSCALE_FOUND OR
        AVRESAMPLE_FOUND OR
        AVFILTER_FOUND OR
        Swresample_FOUND)

MARK_AS_ADVANCED(
        FFMPEG_LIBRARY_DIR
        FFMPEG_INCLUDE_DIR
)

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set FFMPEG_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(FFMPEG DEFAULT_MSG
        FFMPEG_LIBRARIES FFMPEG_INCLUDE_DIR)
