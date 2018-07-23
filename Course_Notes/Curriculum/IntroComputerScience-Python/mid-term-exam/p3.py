#!/usr/local/bin/python3

def uniqueValues(aDict):
    
    result = []
    kl = list(aDict.keys())
    vl = list(aDict.values())
    checked = []

    for i in range(len(kl)):
        temp = aDict[kl[i]]
        if temp not in vl[i+1:] and temp not in checked:
            result.append(kl[i])
        checked.append(temp)
    
    res = sorted(result)
    print(res)        
    return res

# Test Cases
uniqueValues({'1': 1, '2': 2, '3': 1})
uniqueValues({'1': 1, '2': 2, '3': 1, '4': 3, '5': 100})
uniqueValues({1: 1, 2: 2, 3: 3})
