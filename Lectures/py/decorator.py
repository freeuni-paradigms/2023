def multiplier(x):
    return lambda y: x * y

m = multiplier(5)
# print(m(10))

def logger(func):
    def wrapper(*args, **kwargs):
        print("CALLING WITH")
        print(args)
        print(kwargs)
        ret = func(*args, **kwargs)
        print("DONE")
        return ret
    return wrapper


def sum(x, y):
    return x + y


@logger
def foo(x, y, a=5, b=10):
    return "FreeUni!"

wrappedsum = logger(sum)
print(wrappedsum(3, 5))

# wrappedfoo = logger(foo)
# print(wrappedfoo(1, 2, b=3, a=4))
print(foo(1, 2, b=3, a=4))



class MyCallable(object):
    def __init__(self):
        self.x = 5
        self.y = 10

    def __call__(self, z):
        return self.x + self.y + z

o = MyCallable()
print(o(100))
B
