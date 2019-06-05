# Remove Directories
rm -rf _CPack_Packages CMakeFiles rsh.dir Debug

# Remove Config and Etc. Files
rm cmake_install.cmake CMakeCache.txt Makefile install_manifest.txt CPackConfig.cmake CPackSourceConfig.cmake

# Remove Binaries
rm rsh *.deb *.rpm *.dmg

# Remove VS Build Files
rm *.sln *.vcxproj *.vcxproj.filters