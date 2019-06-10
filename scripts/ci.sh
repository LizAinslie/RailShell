if [[ ! -z "$TRAVIS_TAG" ]]; then
  cmake . -DVERSION=$TRAVIS_TAG;
else
  cmake . -DVERSION=$(git rev-parse --short HEAD);
fi
if [[ "$TRAVIS_OS_NAME" == "windows" ]]; then
  cmake --build .;
else
  cmake --build . -- -j3;
fi
if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then cpack -G DEB .; cpack -G RPM .; fi
if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then cpack -G DragNDrop .; fi
if [[ "$TRAVIS_OS_NAME" == "windows" ]]; then cpack -G NSIS .; fi