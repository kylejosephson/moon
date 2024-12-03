###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Alvey, CS165
# Author:
#     Kyle Josephson
# Summary:
#     I created an explosion to happen when the lander crashes.
#     This project was awesome and I learned a lot.  I really
#     didn't have an problems.  I studyed a lot and learned
#     about OpenGL and how to draw some.  It is a beginning.
# Above and Beyond
#     I created an explotion that appears on the screen
#     when the lander crashes.  I created a bool in lander
#     class and set the game to draw the explosion. I mapped
#     out all the points for OpenGL to draw.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
#    lander.o      Handles the lander in the game
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
lander.o: lander.cpp lander.h point.h velocity.h
	g++ -c lander.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
