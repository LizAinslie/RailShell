if ($env:APPVEYOR_REPO_TAG -eq "true") {
    cmake . -DVERSION=$env:APPVEYOR_REPO_TAG_NAME
} else {
    cmake . -DVERSION=$(git rev-parse --short HEAD)
}

cpack -G NSIS .