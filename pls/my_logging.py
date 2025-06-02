import logging
import os
import platformdirs

LOG_DIR = platformdirs.user_log_dir("pls")
os.makedirs(LOG_DIR, exist_ok=True)  
LOG_FILE = os.path.join(LOG_DIR,"pls.log")
print(LOG_FILE)
logging.basicConfig(
    filename=LOG_FILE, filemode="w", level=logging.ERROR
)

old_print = print
print = logging.debug
