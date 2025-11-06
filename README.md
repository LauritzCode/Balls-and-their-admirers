# Balls and Their Admirers
Each ball has a random starting position, a random color, a random initial velocity and most importantly a randomly assigned “admired” ball which it follows throughout the simulation. 
The movement is handled in balls_update, where each ball adjusts its velocity a little bit toward the position of the ball it follows, 
and then damping slows the velocity slightly so things stay smooth and controlled. Because all balls follow different balls in a random network, 
they first drift around almost at random before gradually being pulled toward one another. 

Over time the motion becomes calmer and the balls slowly converge into a final cluster. Drawing is done in balls_draw, where each ball is rendered with a soft glow effect using layered transparent circles. 
The update loop combined with the glow and custom background creates a kind of galaxy like motion where its swirling and and slowly collapsing together until everything ends in one or a few blobs.
