cmake .
if [[ "$1" == "windows" ]]; then
	cmake --build .;
fi

if [[ "$1" == "linux" ]]; then
	cmake --build . -- -j3;
fi