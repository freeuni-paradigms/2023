def getDivisors(n):
    # d = []
    for i in xrange(1, n+1):
        if n % i == 0:
            # d.append(i)
            yield i
    return

def mysum(l):
    return 0


def foo(x):
    yield 1
    if x == 2:
        yield 2
    yield 3
    return
