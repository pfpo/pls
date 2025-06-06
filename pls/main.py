import sys
from .server import server
from .debug import debug


def main():
    server.start_io()


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "-d":
        debug()
    else:
        main()
