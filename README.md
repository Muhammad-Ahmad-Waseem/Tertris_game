# Tertris_game
This code is done on arduino UNO using 8-by-8 LED matrix. It has logics for 6 different shapes


You need to connect arduino UNo to led matrix with pins described in row and column array at start

Find schemetic file for your matrix and connect row 0 - row 7 pins to row[0] - row[7] pins of ardu-
ino. similarly connect column as well but use resistors before connecting them.

Connect a joy stick. Connect right/left analogue data pin of joystick to A0 of arduino and up/down 
data pin of JOY stick to A1 of arduino.

Use power from arduino where required and upload code. Enjoy your game.

Game logics:
move one step right: move joystick to right
move one step left: move joystick to left
move down with speed : move joystick down.

(if you keep right/left/down position of joystick constant, it will do that specific task continuosly)
