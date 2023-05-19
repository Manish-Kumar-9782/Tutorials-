import os
ROOT = os.getcwd()
DATA_PATH = os.path.join(ROOT, "data")
BLOCK_LENGTH = 100

if __name__ == "__main__":
    print("data path: ", DATA_PATH)