# arduino-Project
Arduino project for NUS Makerthon 2020

This simple project was to build something with arduino that can help to improve social interactions.

The device is something that can be retroactively installed at existing playgrounds. 
It aims to bring children in the neighbourhood together and improve interaction within the neighbourhood community and activity through interesting teamwork oriented gameplay loops. 

The base idea is that someone would cycle/turn a wheel, which is the dynamo, to power the arduino. 
The arduino will then light up random leds (which also have a corresponding button) around the playground, which the other children will need to get to a lighted led and press the button to earn points (displayed on a lcd) [everything requires minimal power].

The device can also be easily modified to include different types of gameplay that builds on the fundamental idea of team oriented 'whack-a-mole'.

In this small scale prototype, we are showing some ways to implement the device.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

The "1arduino1team" folder contains the code and schematic to run a single arduino uno/mega for a single team that flashes random lights for the team to chase, where 1 person needs to power the arduino for both teams.
The "1arduino2teams" folder contains the code to run a single arduino mega (schematic is similar to the above with minor changes) for 2 teams that flashes random lights for each team to chase, where each team has to designate a person to power the arduino for their team.

The Demo.mp4 shows a demonstration of how the 1arduino2teams code works and could be applied.