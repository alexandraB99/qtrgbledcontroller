# qtrgbledcontroller
qtrgbledcontroller is a simple Qt application that allows controlling an RGB Led light connected on an Arduino UNO board via Serial Port. The respective arduino sketch needs to be uploaded to the board in order for this code to funcion. You will find an example inside the **arduino_sketch** folder.

# Build
qtrgbledcontroller uses qmake for building. To build it run:  
``mkdir build && cd build``

From the *build* folder, run:  
``
path/to/your/Qt/bin/qmake ../qtrgbledcontroller/
``  

then:  
``make && make install``

This will create the *qtrgbledcontroller* executable under the *bin* directory inside the build folder.

# Running the application
From the *build* folder, run
``
./bin/qtrgbledcontroller
``


# License
This software is available under the following license:  
MIT
