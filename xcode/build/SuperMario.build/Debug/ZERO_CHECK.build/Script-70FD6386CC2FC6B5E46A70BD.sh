#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/shanechen/Desktop/MSD/project/CS6010Final/xcode
  make -f /Users/shanechen/Desktop/MSD/project/CS6010Final/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/shanechen/Desktop/MSD/project/CS6010Final/xcode
  make -f /Users/shanechen/Desktop/MSD/project/CS6010Final/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/shanechen/Desktop/MSD/project/CS6010Final/xcode
  make -f /Users/shanechen/Desktop/MSD/project/CS6010Final/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/shanechen/Desktop/MSD/project/CS6010Final/xcode
  make -f /Users/shanechen/Desktop/MSD/project/CS6010Final/xcode/CMakeScripts/ReRunCMake.make
fi

