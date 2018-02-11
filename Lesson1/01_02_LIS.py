# Longest increasing sub-sequence
# by Yiyang 11/02/18


# main
seqValues = []

seqLen = int(input("Enter the length of the sequence: "))
for i in range(seqLen):
    seqValues.append(int(input()))

LISValues = []                  # initialisation of the transition function with default value = 0
for i in range(seqLen):
    LISValues.append(0)

# use a double loop to find the LIS of each subproblem
for i in range(seqLen):         # for LIS value of the i-th element
    _max = 0                    # set the max of LIS value of 1 to (i-1)-th to 0
    for j in range(i):          # scan through every element before it to find max
        if seqValues[i] > seqValues[j] and LISValues[j] > _max:
            _max = LISValues[j]
    
    LISValues[i] = _max + 1     # update LIS value for the i-th

LISResult = 0
for i in range(seqLen):
    if LISValues[i] > LISResult:
        LISResult = LISValues[i]

print("The length of the longest increasing sub-sequence is", LISResult)
