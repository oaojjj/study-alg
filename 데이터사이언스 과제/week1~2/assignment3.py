import csv
import operator

if __name__ == '__main__':
    cars = []
    cars2 = []

    f = open('cars.csv', 'r')  # 파일을 open한다.
    head = f.readline().split(',')
    data = csv.reader(f)

    # 마지막 Model\n 값에 '\n'개행을 빼줌
    head[len(head) - 1] = head[len(head) - 1].replace('\n', '')

    for car in data:
        cars.append({head[i]: car[i] for i in range(0, len(head))})

    print('# 1')
    print(*cars, sep='\n')

    cars2 = [car for car in cars if
             (car['Price'] != 'NA') and (float(car['Price']) > 20000) and (float(car['Price']) < 50000) and (
                     float(car['Year']) > 2000) and (car['Body'] == 'sedan') and (car['Engine Type'] == 'Gas')]

    print('# 2')
    print(*sorted(cars2, key=lambda car: car['Price']), sep='\n')

    print('# 3')
    print({car['Brand'] for car in cars})
