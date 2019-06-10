if [[ ! -z "$TRAVIS_TAG" ]]; then
  cmake . -DVERSION=$TRAVIS_TAG;
elif [[ "$APPVEYOR_REPO_TAG" == "True" ]]; then
  cmake . -DVERSION=$APPVEYOR_REPO_TAG_NAME
else
  cmake . -DVERSION=$(git rev-parse --short HEAD);
fi
if [[ "$TRAVIS_OS_NAME" == "windows" || "$APPVEYOR" == "True" ]]; then
  cmake --build .;
else
  cmake --build . -- -j3;
fi
if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then cpack -G DEB .; cpack -G RPM .; fi
if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then cpack -G DragNDrop .; fi
if [[ "$TRAVIS_OS_NAME" == "windows" || "$APPVEYOR" == "True" ]]; then cpack -G NSIS .; fi