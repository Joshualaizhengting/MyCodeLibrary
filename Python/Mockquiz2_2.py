def longest_subarray(arr, K):
#add you codes
    left = 0
    count = 0
    max_count = 0

    for right in range(len(arr)):
        #sliding window
        """
        keep expanding right
        if right == 0 -> increase count
        if count > K -> shrink the window
        keep track of the count of max window length at this point
        return max of max window length and current window length at the end
        """

        if arr[right] == 0:
            count += 1
        
        while count > K:
            if arr[left] == 0:
                count -= 1
            left += 1
    
        max_count = max(max_count, right-left + 1)

    return max_count
            
        


arr = list(map(int, input().split()))
K = int(input())

print(longest_subarray(arr, K))