# imports
import sys
import lib.pysdl2.sdl2.ext as ext

RESOURCES = ext.Resources(__file__, "res")


# Main function
def main():
    print(sys.path)
    # initialize wrapper
    ext.init()

    # create
    window = ext.Window("Hello World!", size=(640, 480))
    window.show()


# Execute main function
if __name__ == '__main__':
    main()
