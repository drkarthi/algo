import math

def heapify(l):
	n = len(l)
	for d in range(math.floor(math.log(n,2)), 0, -1):
		for i in range(pow(2,d)-1, pow(2,d+1)-1):
			if(i >= n):
				break
			p = math.floor((i-1)/2)
			if l[i] < l[p]:
				temp = l[i]
				l[i] = l[p]
				l[p] = temp
	return l

def delete(h):
	min_element = h.pop(0)
	h = heapify(h)
	return h, min_element

def insert(h, element):
	h.append(element)
	h = heapify(h)
	return h

def find_smallest_range(l1, l2, l3):
	l = [l1,l2,l3]
	h = [l[x].pop(0) for x in range(len(l))]
	a = min(h)
	b = max(h)
	element_to_list = {h[x]: x for x in range(len(l))}
	h = heapify(h)
	while(True):
		h, min_element = delete(h)
		list_del = element_to_list[min_element]
		if l[list_del] == []:
			return a,b
		new_element = l[list_del].pop(0)
		h = insert(h, new_element)
		a = min(h)
		b = max(h)
		element_to_list[new_element] = list_del
		h = heapify(h)
	return a,b

l = [3,15,24,22,14,36,12]
h = heapify(l)
h, min_element = delete(h)
h = insert(h,13)
print(h)

l1 = [4,10,15,24,26]
l2 = [0,9,12,20]
l3 = [5,18,22,30]
a,b = find_smallest_range(l1, l2, l3)
print("Smallest Range: ", (a,b))