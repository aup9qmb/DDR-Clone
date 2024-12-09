# DDR-Clone

```
I shall be telling this with a sigh
Somewhere ages and ages hence:
Two roads diverged in a wood, and I—
I took the one not traveled by,
```

## Building

### External Dependencies

CS50 codespace has all of these included, and others are statically linked.

- cmake
- clang
- libwayland-dev
- libxkbcommon-dev
- xorg-dev
- mesa-common-dev
- libx11-dev
- libxrandr-dev
- libxi-dev xorg-dev


`$ git clone --recurse-submodules https://github.com/aup9qmb/DDR-Clone.git`\
`$ cd DDR-Clone && make`

The game binary, once built with `$ make`, can be found in `./bin/`.

Run with `$ ./bin/game` or `$ make run` out of the root directory of the repository.[^1]

[^1]: Fear of failure may be a poor reason not to try, but try and fail both I did.

#### References

- [glfw](https://www.glfw.org/)
- [glad](https://glad.dav1d.de/)
- [cglm](https://github.com/recp/cglm)
- [openal-soft](https://github.com/kcat/openal-soft)
- [astera](https://github.com/tek256/astera)
- [jdah, minecraft-weekend](https://www.youtube.com/watch?v=4O0_-1NaWnY)
- [fizzd, How To Make A Rhythm Game (Technical Guide)](https://fizzd.notion.site/How-To-Make-A-Rhythm-Game-Technical-Guide-ed09f5e09752451f97501ebddf68cf8a)
- [de Vries, learnOpenGL](https://learnopengl.com/)
- [openAL dev guide](https://www.openal.org/documentation/OpenAL_Programmers_Guide.pdf)
