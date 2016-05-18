import math

def int_to_binary(n, num_elements):
	binary_digits = []
	for x in range(num_elements):
		digit = n%2
		binary_digits.append(digit)
		n = n >> 1
	return binary_digits

def generate_subsets(s):
	num_possibilities = pow(2,len(s))
	subsets = {}
	for x in range(num_possibilities):
		subsets[x] = []
		print("x = ", x)
		binary_digits = int_to_binary(x, len(s))
		print("Binary digits: ", binary_digits)
		for i in range(len(s)):
			if(binary_digits[i]==1):
				subsets[x].append(s[i])
	return subsets

a = set([1,2,3,4,5])
subsets = generate_subsets(list(a))
print(subsets)