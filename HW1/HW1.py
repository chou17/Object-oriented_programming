import math

f = open('python_result.txt', 'w')
n = 1
while True:
    length1, length2, length3 = map(
        float, (input('Please enter the lengths of the triangle: ').split()))
    if length1 == -1 and length2 == -1 and length3 == -1:
        break
    elif (length1 <= 0 or length2 <= 0 or length3 <= 0) or not(length1+length2 > length3 and length2+length3 > length1 and length3+length1 > length2):
        print('The input is not legal.')
        f.write('Question {0} inputs are, length1 = {1}, length2 = {2}, length3 = {3}. The input is not legal.\n'.format(
            n, length1, length2, length3))
        n += 1
        continue
    semiperimeter = (length1 + length2 + length3) / 2
    area = math.sqrt(semiperimeter * (semiperimeter - length1) *
                     (semiperimeter - length2) * (semiperimeter - length3))
    result = math.ceil(area*10000.0)/10000.0
    print('The area of this triangle is: {} '.format(result))
    f.write('Question {0} inputs are, length1 = {1}, length2 = {2}, length3 = {3}. The area of this triangle is {4}.\n'.format(
        n, length1, length2, length3, result))
    n += 1
f.close()
