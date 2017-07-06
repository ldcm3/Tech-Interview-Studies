def liningPeople(data):
	data.sort(key=lambda x:x[1])
	data.sort(key=lambda x:x[0], reverse=True)
	print data
	
	result = []
	for h, t in data:
		result.insert(t, (h, t))
	return result
	
print(liningPeople([(7, 0),(4, 4),(7,1), (5, 0), (6,1), (5, 2)]))
