tomato-skype-spark
==================

Pomodro.app + Skype + Python + Spark.io = A great way to get stuff done at work

## Backstory

I worked remotely as a software developer for a few years, and having a family, it seemed that someone was coming into the office at the most inopportune time.

Like any good geek, I came up with a technical solution to a social problem. I created a system with an off-the shelf Arduino Duemilanove, a pair of XBees, and a homebuilt arduino clone with some ultrabright LEDs. I made a nice enclosure, and wrote a Python script that read Skype's status and would light up a red light when I was in Do-Not-Disturb mode, and a green when I was available.

I put the light in the hallway on the way to the office and voilà, when I was on important calls, or otherwise busy, my family knew I was off limits. It worked great! (Too bad I don't have any pictures... dang!)

Although that was a perfectly fine solution, it was kind of pricey for what it did (~$30 for the Arduino Duemilanove, ~$50 for the pair of XBees, ~$10 for the home-built Arduino clone). It made it financially difficult for my friends to buy and technically difficult for my friends to build.

Boom! Fast forward 3-ish years. [spark.io](http://spark.io) comes out with an awesome little microcontroller, with a sweet form factor and an onboard wifi chip. It's a great package, and super affordable at ~$40.

Time to put an even cooler system together for less hassle and less moolah!

This time it needs to also integrate into my focus- and time-management system: [The Pomodoro Technique](http://pomodorotechnique.com).

## Components

* [spark core](https://www.spark.io/dev-kits)
* [RGB LED board from SparkFun](https://www.sparkfun.com/products/11588)
* Python 2.7
* [Pomodoro.app](https://github.com/ugol/pomodoro)
* [Skype4Py](https://github.com/awahlig/skype4py)
* [Skype](http://www.skype.com)
* Macbook running OSX 10.8 Mountain Lion

## Procedure

* Pomodoro.app uses Applescript to set my Skype status
** During a pomodoro, my status is DnD.
** During a break, my status is set to available
* spark_skype_status.py listens for status changes (it's event-driven)
** when the status goes to DnD, send a message via a HTTP POST to Spark Cloud
** Spark Cloud sends message to Spark Core device, turning the correct lights on/off

## Caveats

* Pomodoro.app isn't supported any more from original developer. You have to build it yerself nowdays.
* Skype4Py, the Python library that talks to Skype, won't run in 64 bit mode
** official instructions say to use arch -i386 to force 32 bit.
** I found better luck using virtualenv to create a virtual environment and then stripping the universal binary of the 64 bit version.
