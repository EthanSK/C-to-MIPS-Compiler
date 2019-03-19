def func():
    return 5

def main():
    return func()

if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)