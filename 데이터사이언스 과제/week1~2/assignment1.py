def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i
        while (j > 0) & (arr[j - 1] > key):
            arr[j] = arr[j - 1]
            j -= 1
        arr[j] = key
    return arr


def merge_sort(arr):
    if len(arr) > 1:
        m = len(arr) // 2
        l = arr[:m]
        r = arr[m:]
        return merge(merge_sort(l), merge_sort(r))
    else:
        return arr


def merge(l, r):
    i = j = 0
    temp = []

    while (i < len(l)) & (j < len(r)):
        if l[i] < r[j]:
            temp.append(l[i])
            i += 1
        else:
            temp.append(r[j])
            j += 1

    while i < len(l):
        temp.append(l[i])
        i += 1

    while j < len(r):
        temp.append(r[j])
        j += 1

    return temp


if __name__ == '__main__':
    array = [3, 6, 4, 1, 2, 7, 9, 10]
    print(insertion_sort(array.copy()))
    print(merge_sort(array.copy()))
