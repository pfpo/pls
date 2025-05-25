import logging

logging.basicConfig(
    filename="/home/martim/Desktop/pls/pygls.log", filemode="w", level=logging.ERROR
)

old_print = print
print = logging.debug
