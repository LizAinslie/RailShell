if ($env:APPVEYOR_REPO_TAG -e "true") {
    cmake . -DVERSION=$env:APPVEYOR_REPO_TAG_NAME
} else {
    cmake . -DVERSION=$(git rev-parse --short HEAD)
}

cpack -G NSIS .