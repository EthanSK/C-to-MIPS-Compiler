def main():
    i = 5
    n = 0
    while i > 0:
        i = i - 1
        n = n + i

    return n

if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)