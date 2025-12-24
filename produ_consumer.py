import threading
import time
import queue

buffer = queue.Queue(5)

def producer():
    for vehicle in range(1, 11):
        buffer.put(vehicle)
        print(f"Vehicle {vehicle} entered toll plaza")
        time.sleep(0.5)

def consumer():
    for _ in range(10):
        vehicle = buffer.get()
        print(f"Toll processed for vehicle {vehicle}")
        time.sleep(1)

t1 = threading.Thread(target=producer)
t2 = threading.Thread(target=consumer)

t1.start()
t2.start()

t1.join()
t2.join()
