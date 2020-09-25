import csv
from operator import itemgetter

if __name__ == '__main__':
    cars = []
    result1 = 0
    result2 = []

    f = open('cars.csv', 'r')  # 파일을 open한다.
    data = csv.reader(f)

    for car in data:
        if car[0] == 'Volkswagen' and car[5] == 'Gas' and car[2] == 'sedan' in car:
            result1 += 1
        if car[0] == 'BMW' in car:
            result2.append(car)

    print('2-1번 문제: {}'.format(result1))
    print('2-2번 문제')
    print(*sorted(result2, key=itemgetter(-2)), sep='\n')

    f.close()
