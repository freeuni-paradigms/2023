class MyObject(object):
    def __init__(self):
        self.__cur = 0

    def __iter__(self):
        return self

    def __call__(self):
        return self.__cur

    def __next__(self):
        self.__cur += 1
        if self.__cur == 10:
            raise StopIteration
        return self.__cur * self.__cur

m = MyObject()
print(m())
for i in m:
    print(i)


def create_adder(delta):
    return lambda x: x + delta

a = create_adder(5)
print(a(10))


def adder(fn):
    def wrapper(*args, **kwargs):
        return 5 + fn(*args, **kwargs)
    return wrapper

@adder
def sum(a, b):
    return a + b

print(sum(1, 3))
