def permute(s):
	chars = hash_str(s)
	perms = helper(chars)
	return perms

def hash_str(s):
	counts = {}
	for ch in s:
		counts[ch] = counts.get(ch,0) + 1
	return counts

def helper(chars):
	if len(chars) == 0:
		return ['']
	perms = []
	for key in chars:
		fch = key
		new_chars = chars.copy()
		if new_chars[key] > 1:
			new_chars[key] -= 1
		else:
			new_chars.pop(key, None)
		sub_perms = [fch + x for x in helper(new_chars)]
		for item in sub_perms:
			perms.append(item)
	return perms

print(permute("abbccc"))