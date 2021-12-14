echo "Starting Compilation..."
echo "Compiling Source Files..."
gcc ../"Source"/*.cpp ../Source/glad.c -o Main -I../Headers -I../Libraries/include -lstdc++ -lglfw -lGL -ldl -lm -fcompare-debug-second
echo "Binary Compilation Done."
echo "Copying Resource Folder..."
cp -r ../Resources/ .
echo "Done."
