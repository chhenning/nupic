import numbers

input = 10
if not isinstance(input, numbers.Number):
    print('it is not a number')
else:
    print('it is a number')
