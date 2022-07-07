#DaemonThread2.py

# In this section we will use the join() method to tell MainThread the wait for all threads to complete it's work
# it includes the non-daemon and daemon threads.


# save below code inside the DaemonThread.py file

import threading
import time
import logging

logging.basicConfig(level=logging.DEBUG,
                    format='%(threadName)s: %(message)s')

def log(msg):
    logging.debug(msg)

def n():
    st_time = time.perf_counter()
    log('Starting')
    for i in range(100000):
        pass
    end_time = time.perf_counter()
    extime = round(end_time - st_time, 4)
    log(f'Exiting: total thread time-> {extime}')

def d():
    st_time = time.perf_counter()
    log('Starting')
    for i in range(10000000):
        pass
    """here we can't use the log method since log method is defined inside the MainThread and it will exit 
        after completing the non-daemon thread so it will raise the NameError on the log."""
    end_time = time.perf_counter()
    extime = round(end_time - st_time, 4)
    logging.debug(f'Exiting: total thread time-> {extime}')

if __name__ == '__main__':

    t_thread = threading.Thread(name='non-daemon', target=n)
    d_thread = threading.Thread(name='daemon', target=d)
    d_thread.setDaemon(True)

    d_thread.start()
    t_thread.start()
    print("Daemon thread is alive: ", d_thread.is_alive())
    d_thread.join()
    t_thread.join()
    log("Exiting!")
    exit()	
    log('Hello!')  # log won't run, since the MainThread is killed.


    """
    In Result we will get:

    ---------------------------------
        daemon: Starting
        non-daemon: Starting
        non-daemon: Exiting: total thread time-> 0.0177
        Daemon thread is alive:  True
        daemon: Exiting: total thread time-> 0.1916
        MainThread: Exiting!
    ---------------------------------
    Now in this case, since we have used the join method on both thread we will see the exiting method from Daemon thread.
    """