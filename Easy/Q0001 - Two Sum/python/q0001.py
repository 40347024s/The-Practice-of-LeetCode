def twoSum(nums, target):
    seen = {}
    for i, val in enumerate(nums):
        res = target - val
        if seen.get(res) != None:
            break
        else:
            seen[val] = i

    return [seen[res], i]

if __name__=='__main__':
    testcase = [
        [[2, 7, 11, 15], 9],
        [[3, 2, 4], 6],
        [[3, 3], 6]
    ]
    for nums, target in testcase:
        print(twoSum(nums, target))



    