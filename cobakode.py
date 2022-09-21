from queue import PriorityQueue #library untuk mengurus antrian prioritas
from collections import defaultdict #library sebagai kontainer yang menyimpan objek dan nilainya

andi = []
# Heuristic Function based on Manhattan Distance
def h(point1, point2):
    x, y = point1 #titik pertama
    a, b = point2 #titik kedua
    return abs(x-a)+abs(y-b) #hitung nilai heuristik

# Priority Queue for getting minimum F_score node always in log(n) time
pq = PriorityQueue()

# inisialisasi Grid of 10*10
g = [[0 for i in range(7)] for j in range(14)] #memunculkan 10 kolom dan 10 baris

# inisialisasi titik Start and End and obstacle
start = (1, 5)#bisa diperoleh lewat scan barcode dari agv
end = (10, 1)#bisa diperoleh lewat scan barcode dari konveyor
obstacle = [(1,2), (1,4), (1,6), (4,2), (4,4), (4,6), (7,2), (7,4), (7,6), (10,2), (10,4), (10,6), (13,2), (13,4), (13,6)]
# tandai Source = 1, dan End = 2
g[end[0]][end[1]] = 2 #menandai titik koordinat 9 (end 0), 5 (end 1)
g[start[0]][start[1]] = 1 #menandai titik koordinat 0 (start 0), 0 (start 1)

# tandai obstacles using digit 3
for obs in obstacle:
    g[obs[0]][obs[1]] = 3
for t in g:
    print(t) 
# # g_score of nodes using dictionary with default value "inf"
# g_score = defaultdict(lambda: float("inf")) #defaultdict akan memunculkan nilai "inf" jika object tidak ditemukan
# g_score[start] = 0 #tetapkan nilai 0 untuk g_score titik start(0,0)

# # g_score of nodes using dictionary with default value "inf"
# f_score = defaultdict(lambda: float("inf"))
# f_score[start] = g_score[start] + h(start, end) #nilai h pada titik start (0,0) didapatkan dari rumus di baris 5

# # put start node into Priority Queue
# pq.put((0, start)) #menambahkan nilai 0 untuk objek bernama start

# # Hash set for checking if node is in Priority Queue in Time O(1)
# pq_hash = set() #membuat set list bernama pq_hash berisi koordinat
# pq_hash.add(start)#menambah objek start(koordinat)

# # Dictionary to keep track of the path we came from
# came_from = dict() #membuat set list bernama came_from

# # flag to know if we got to end or not, if we did then f = 1 and we check that at last
# f = 0

# # Main loop until Queue is not empty, selama list pq(baris 39) tidak kosong lakukan task ini
# while not pq.empty():

#     # get current node with its f_score eg. (f_score, (node_x, node_y))
#     current = pq.get() #berisi nilai (f(nodex, node y))

# #current[0] berisi nilai f_score, current[1]=koordinat
# #current[1,0] berisi nilai koordinat yang pertama atau ke-0 atau x
# #current[1,1] berisi nilai koordinat yang kedua atau ke-1 atau y

#     # if node is the end, flag = 1 and break the loop
#     if g[current[1][0]][current[1][1]]==2: #jika koordinat (0,0) adalah 2
#         print("last reached\n")
#         f = 1
#         break

#     # for traversing in 4 directions, up, down, right, left in order
#     x = [0, 0, 1, -1]
#     y = [1, -1, 0, 0]

#     # remove the node from set too cause set basically tracks pq, pindahkan node dari pq saat selesai dikalkulasi
#     pq_hash.remove(current[1])

#     # traversing 4 neighbor nodes
#     for r, c in zip(x, y): #r dan c adalah list berisi nilai x(baris 68) yang akan mengecek kiri dan kanan dan nilai y(baris 69) yang akan mengecek atas dan bawah

#         # check if node is in boundaries of grid
#         if 0<=current[1][0]+r<=9 and 0<=current[1][1]+c<=9:#jika koord x+r (4 nilai r akan dicek satu persatu) lebih dari 0 dan kurang dari 9 dan koord y lebih dari 0 dan kurang dari 9

#             # let temporary g_score be 1 + g_score of the node we came from i.e current node
#             temp_g_score = current[0] + 1 #current[0] adalah nilai g awal, misal dari start maka current[0] adalah 0

#             # if tempp_g_score is less than the score we had for this node, set that score
#             if temp_g_score < g_score[(r+current[1][0], c+current[1][1])]: #apabila temp g score yg diset (perkiraaan) di awal lebih kecil daripada score yang dihitung, maka tetapkan score yg dihitung sebagai temp g score baru
#                 g_score[(r+current[1][0], c+current[1][1])] = temp_g_score

#                 # to keep track of where we came from to this node
#                 came_from[(r+current[1][0], c+current[1][1])] = current[1]

#                 # f_score = g_score + h_score of the node
#                 f_score[(r+current[1][0], c+current[1][1])] = g_score[(r+current[1][0], c+current[1][1])] + h((r+current[1][0], c+current[1][1]), end)

#                 if ((r+current[1][0], c+current[1][1]) not in pq_hash):
#                     pq.put((f_score[(r+current[1][0], c+current[1][1])], (r+current[1][0], c+current[1][1])))
