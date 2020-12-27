def binary_search(data_list, begin, end, target):
    mid = (begin + end) / 2

    if begin > end:  # base case - not found
        return None

    elif data_list[mid] == target:  # base case - found
        return mid
    
    elif data_list[mid] > target:  # base case - lower range
        return binary_search(data_list, begin, mid-1, target)

    elif data_list[mid] < target: # base case - upper range
        return binary_search(data_list, mid+1, end, target)

def main():
    length = None
    data_list = list()
    target = None
    
    with open('input', 'r') as fd:
        length = int(fd.readline())
        data_list = [int(i) for i in fd.readline().split(' ')]
        target = int(fd.readline())

    found_index = binary_search(data_list, 0, length-1, target)
    print(found_index)

if __name__ == '__main__':
    main()
