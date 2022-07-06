# save below code inside the DaemonThread.py file

import threading
import time
import logging

logging.basicConfig(level=logging.DEBUG,
                    format='%(threadName)s: %(message)s')

def log(msg):
    logging.debug(msg)

def n():
    log('Starting')
    for i in range(100000):
        pass
    log('Exiting')

def d():
    log('Starting')
    for i in range(100000000000000):log
    """here we can't use the log method since log method is defined inside the MainThread and it will exit 
        after completing the non-daemon thread so it will raise the NameError on the log."""
    logging.debug('Exiting')

if __name__ == '__main__':

    t = threading.Thread(name='non-daemon', target=n)
    d = threading.Thread(name='daemon', target=d)
    d.setDaemon(True)

    d.start()
    t.start()
    print("Daemon thread is alive: ", d.is_alive())
    log("Exiting!")
    exit()
    log('Hello!')  # log won't run, since the MainThread is killed.


    """
    In Result we will get:

    ---------------------------------
        daemon: Starting
        non-daemon: Starting
        non-daemon: Exiting
        Daemon thread is alive:  True
        MainThread: Exiting!
    ---------------------------------
    We will not see the Hello log message, neither we will see the Exiting message from the Daemon Thread.
    """