# Autonomous Claw
This is the test and final code for the APSC 101 autonomous claw project. The objectives of the claw are to pick up a variety of items and transport them accurately and efficiently.

## Programs
[`servo_sonar.ino`](https://github.com/MatthewChow03/Autonomous-Claw/blob/main/servo_sonar.ino) a program to position a servo's angle based on sonar height

[`distance_algorithm_v1.ino`](https://github.com/MatthewChow03/Autonomous-Claw/blob/main/distance_algorithm_v1.ino) a program that opens and closes a claw with LED indicators of the algorithm's state

[`timeout_algorithm.ino`](https://github.com/MatthewChow03/Autonomous-Claw/blob/main/timeout_algorithm.ino) implementation of a timeout to reopen and close the claw when an object is unsuccessfully picked up

[`timeout_algorithm_v2.ino`](https://github.com/MatthewChow03/Autonomous-Claw/blob/main/timeout_algorithm_v2.ino) fixed issue where timeout v1 would get stuck in the green phase, changed do while to a while loop

[`simple_algorithm.ino`](https://github.com/MatthewChow03/Autonomous-Claw/blob/main/simple_algorithm.ino) a reliable program that switches between opening and closing whenever the claw is close to the ground


## Video Demos
<!---
<details>
<summary> Video Demo </summary>
--->  

Running the [`distance_algorithm_v1.ino`](https://github.com/MatthewChow03/Autonomous-Claw/blob/main/distance_algorithm_v1.ino) code, this video shows the basic functionality for the sonar to recognize being in pickup, moving, and dropoff states.

https://user-images.githubusercontent.com/74833839/150493338-888c102b-f443-4ee9-8b32-2c06b01a9727.mp4

Running the [`timeout_algorithm_v2.ino`](https://github.com/MatthewChow03/Autonomous-Claw/blob/main/timeout_algorithm_v2.ino) program which is fully functional and fully tested. In order, the video demonstrates a normal operation, the claw functioning while unstable, and the a failed attempt to grab an object in which the claw opens and closes again before dropping off on the other side.

https://user-images.githubusercontent.com/74833839/151141633-180c00d1-04fc-4373-be09-1d7a417e316b.mp4

Using [`simple_algorithm.ino`](https://github.com/MatthewChow03/Autonomous-Claw/blob/main/simple_algorithm.ino) this video demonstrates the program flashed to a prototype claw.

https://user-images.githubusercontent.com/74833839/151746374-dcb52fc9-937d-4920-8e40-bcdd2537f0e4.mp4

<!---
</details>
--->  
