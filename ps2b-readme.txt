/**********************************************************************
 *  N-Body Simulation ps2b-readme.txt template
 **********************************************************************/
Name: Jacob George
Hours to complete assignment: 10 Hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
This assignment made me draw out my celestial bodies onto a window like ps2a, but now using the bodies x and y positions, velocities, and mass
I have to simulate an orbit with the bodies moving counter-clockwise using physics calculations. The bodies are made up of a vector of shared pointers to Celestial Bodies and
I successfully calculate the proper data for each Celestial Body given.

/**********************************************************************
 *  If you created your own universe for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
Did not create my own universe

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Dr. Daly's Class Discord Server
Tutors: 
Ben F - Helped me understand I need to calculate the netforce for every celestial body first, and then use each indiviual netforce to find a bodies position, acceleration, and velocity
Seneca A - Helped me understand how my main function calls step and how deltaTime/total_amount_of_time works
Dr. Daly's Office Hours - Dr. Daly helped output my data correctly and helped me fix my scaling equations
Class Notes on Physics Calculations

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
The window size is still hardcoded to use a 500x500 window. If the graders want to use a different window size, they need to change it in NBody.cpp when universe u on line 10 as well as in 
CelestialBody.h in the newSetPosition function. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 How to run:
 make
 ./NBody 157788000.0 25000.0 < planets.txt
 make clean

 You can use any txt file, deltaTime value and total time value