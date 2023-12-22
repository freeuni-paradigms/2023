class Point(object):
    def __init__(self, x, y):
        self._x = x
        self._y = y


# p = Point(1, 3)
# print(p._x)
# p._x = 5
# print(p._x)


class CounterIterator(object):
    def __init__(self, limit):
        self.limit = limit
        self.cur = 0

    def __next__(self):
        ret = self.cur
        self.cur += 1
        if ret >= self.limit:
            raise StopIteration
        return ret


class Counter(object):
    def __init__(self, limit):
        self.limit = limit
        self.cur = 0

    def __iter__(self):
        # return CounterIterator(self.limit)
        return self

    def __next__(self):
        ret = self.cur
        self.cur += 1
        if ret >= self.limit:
            raise StopIteration
        return ret

# list comprehension
print([x*x for x in Counter(10) if x%2 == 0])

# map comprehension
print({x: x*x for x in Counter(10) if x%2 == 0})

# r = []
# for x in Counter(10):
#     r.append(x*x)
# print(r)

# for i in Counter(10):
#     print(i)

# # c = Counter(10)
# # print(next(c))
# # print(next(c))
# # print(next(c))

# def CounterGen():
#     yield 1
#     yield 2
#     yield 3
#     return

# x = CounterGen()
# print(next(x))
# print(next(x))
# print(next(x))
# try:
#     print(next(x))
# except e:
#     print("-----")
#     print(e)
#     print("-----")
# print(next(x))
