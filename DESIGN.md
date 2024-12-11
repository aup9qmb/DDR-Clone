# DDR-Clone Design

### Overview

The fundamental mechanics of DDR is that a song plays, and 
syncronized to the beat are a sequence of arrows that move 
upwards at speed until they are either off the screen (if no 
corresponding player input was given) or overlapped with the 
receptor (if the arrow key was pressed). Points are accumulated
based on how accurate the button presses are, with popups 
displaying the value of occasional presses (PERFECT!, 
GOOD, MISS,...). 


### System Architecture
````
.
DDR-Clone/
    lib/            # external libraries
        pygame/
        essentia/
    res/            # assets and resources
        audio/
        images/
    src/            # functions used in main
        afx.py          # audio effects
        entities.py     # game objects
        utils.py        # coordinate, colors, etc
        window.py       # initializes game + window
    main.py
````


### Screen Objects and Actions

Objects (currently) include:
- ordered dictionary of background layers {image object, position}
- n * arrow (← ↑ → ↓) entities 
- inactive receptor arrows

Available Actions:
- looking <3
