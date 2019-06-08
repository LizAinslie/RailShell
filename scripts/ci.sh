if [[ -z "$TRAVIS_TAG" ]]; then
  cmake . -DVERSION=$TRAVIS_TAG;
else
  cmake .;
fi
if [[ "$TRAVIS_OS_NAME" == "windows" ]]; then
  cmake --build .;
else
  cmake --build . -- -j3;
fi
if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then cpack -G DEB .; cpack -G RPM .; cpack -G NSIS .; fi
if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then cpack -G DragNDrop .; fi