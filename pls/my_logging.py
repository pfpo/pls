
import logging

logging.basicConfig( filename="/home/martim/Desktop/pls/pygls.log", filemode="w", level=logging.DEBUG)

old_print = print
print = logging.debug