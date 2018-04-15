#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/kathleen/fetch_ws/src/moveit_python"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/kathleen/fetch_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/kathleen/fetch_ws/install/lib/python2.7/dist-packages:/home/kathleen/fetch_ws/build/moveit_python/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/kathleen/fetch_ws/build/moveit_python" \
    "/usr/bin/python" \
    "/home/kathleen/fetch_ws/src/moveit_python/setup.py" \
    build --build-base "/home/kathleen/fetch_ws/build/moveit_python" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/kathleen/fetch_ws/install" --install-scripts="/home/kathleen/fetch_ws/install/bin"
