# DDR-Clone

#### Video

[![Watch the video](res/videos/VIDEO.mp4)]

#### Building

`$ git clone --recurse-submodules -b mirrorverse https://github.com/aup9qmb/DDR-Clone.git\`
`$ cd DDR-Clone `  
`$ cd lib/pygame && python3 setup.py install`
`$ cd ../essentia && python3 setup.py install`

Run with `$ python main.py` out of the root directory of the repository.

##### Error fixes

If getting `libGL error: MESA-LOADER: failed to open iris` while running with an 
anaconda installation, taken from [here](https://forum.manjaro.org/t/libgl-error-mesa-loader/69746):
````
#Enter the storage location of Anaconda libstdc++

$ cd /home/[user]/anaconda3/lib/ 
$ mkdir backup  #Create a new folder to keep the original libstdc++
$ mv libstd* backup  # Put all libstdc++ files into the folder, including soft links
#Copy the c++ dynamic link library of the system here
$ cp /usr/lib/x86_64-linux-gnu/libstdc++.so.6  ./
$ ln -s libstdc++.so.6 libstdc++.so
$ ln -s libstdc++.so.6 libstdc++.so.6.0.19
````

If getting `RuntimeWarning: Your system is avx2 capable but pygame was not built 
with support for it.`:
`python3 -m pip install -U pygame --user`

#### References

- [fizzd, How To Make A Rhythm Game (Technical Guide)](https://fizzd.notion.site/How-To-Make-A-Rhythm-Game-Technical-Guide-ed09f5e09752451f97501ebddf68cf8a)
- Dance Dance Revolution 4thMIX, 5thMIX Graphics (c)2000, 2001 Konami
- [Pygame](https://www.pygame.org/docs/)
- [Essentia](https://essentia.upf.edu/)