f = open("data.txt")
#data = [[0 for i in range(100)]for j in range(100)]
data = []
cache = []
for i in range(3):
    f.readline()
for i in range(100):
    t = f.readline()
    for j in t.split():
        if int(j) != -1:
            cache.append(int(j))
    data.append(cache)
    cache = []
print(data)

