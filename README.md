# :basketball: RG049-shootit
ShootIT is a basketball game developed using [OpenGl and Glut](https://www.opengl.org/resources/libraries/glut/) library written in C.

ShootIt is developed as a project for Computer graphics course at the [Faculty of Mathematics](http://www.matf.bg.ac.rs/eng/) in Belgrade, Serbia.
![logo](https://github.com/dimaria95/shootit/blob/master/screenshots/logo_1.png)

## :computer: Getting Started

These instructions will get you a copy of the game up and running on your local machine. This version is mainly tested on Ubuntu.

### Prerequisites

What things you need to install the software and how to install them

**Install freeglut**

```sh
$ apt-get install freeglut3-dev
```

### Install and run the game

How to install and run the game

1. Download the repository
2. Go to src folder and run
```
$ make
$ ./shootit
```

## :video_game: Gameplay

Ball is generated randomly on the field, and the time on the semaphore begins.
A player has 90 seconds to score as many points as he can.
Angle and strength shot can be altered using keyboard.
As soon as the ball hits the floor a new one is generated. Score is printed on the scoreboard.
Ball that is generated can be regular basketball or a bowling ball. Naturally the bowling ball is heavier and hence needs a greater shot power to score.
Changing the angle and strength of the shot can be seen as small balls that represent in what direction is the ball heading.
If hard mode is activated this shot assistance is not visible.
Player can see the field from all angles and change the lighting.

## :joystick: Controls
| **Key** | **Description** |
| :---  | :--- |
| `a` `s` | Changing the camera location |
| `w` `a` | Changing the angle of the shot |
| `j` `k` | Increasing/Decreasing the strength of the shot |
| `l` | Turn on/off head lighting |
| `h` | Turn on/off hard mode |
| `space` | Shoot the ball |
| `ESC` | Exit |

![gameplay](https://github.com/dimaria95/shootit/blob/master/screenshots/Screen%20Shot%202018-01-15%20at%206.20.43%20PM.png)

## :wrench: Built using
* [OpenGl and Glut](https://www.opengl.org/resources/libraries/glut/)
* [LogoMakr](http://logomakr.com) for making the logo

## :mortar_board: Author

* **Nikola Dimić** -  [dimaria95](https://github.com/dimaria95/)

## :book: License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

 
