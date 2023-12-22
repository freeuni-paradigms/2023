# from divisors import getDivisors as getDiv
import divisors as dd

# print(dd.getDivisors(10))
# # print(dd.getDivisors([1, 2, 3]))

# print("Free Uni")

# print(dd.mysum([1, 2, 3]))

# print(xrange(1, 100, 2))

# x = xrange(1, 100, 2)
# print(x.__iter__().next())
# # print(x())
# # print(x())


for i in dd.getDivisors(10):
    print(i)

for i in dd.foo(10):
    print(i)
